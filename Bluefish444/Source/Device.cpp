// Copyright MediaZ Teknoloji A.S. All Rights Reserved.

#include "Device.hpp"

// stl
#include <sstream>

#include "Nodos/Modules.h"

namespace bf
{
SdkInstance::SdkInstance()
{
	Handle = bfcFactory();
}

SdkInstance::~SdkInstance()
{
	Detach();
	bfcDestroy(Handle);
}

BErr SdkInstance::Attach(BluefishDevice* device)
{
	return Attach(device->GetId());
}

BErr SdkInstance::Attach(BLUE_S32 deviceId)
{
	auto err = bfcAttach(Handle, deviceId);
	if (BERR_NO_ERROR != err)
		nosEngine.LogE("Error while attaching device %d: %s", deviceId, bfcUtilsGetStringForBErr(err));
	else
		AttachedDevice = deviceId;
	return err;
}

BErr SdkInstance::Detach()
{
	if (AttachedDevice)
	{
		auto err = bfcDetach(Handle);
		if (BERR_NO_ERROR != err)
			nosEngine.LogE("Error while detaching device %d: %s", *AttachedDevice, bfcUtilsGetStringForBErr(err));
		AttachedDevice = std::nullopt;
		return err;
	}
	return BERR_NO_ERROR;
}

BErr BluefishDevice::InitializeDevices()
{
	static bool initialized = false;
	if (initialized)
		return BERR_NO_ERROR;
	auto instance = bfcFactory();
	
	BLUE_S32 deviceCount;
	if (auto err = bfcEnumerate(instance, &deviceCount))
		return err;
	if (deviceCount > 0)
	{
		for (int deviceId = 1; deviceId <= deviceCount; ++deviceId)
		{
			BErr deviceInitErr;
			auto device = std::make_shared<BluefishDevice>(deviceId, deviceInitErr);
			if (BERR_NO_ERROR != deviceInitErr)
			{
				nosEngine.LogE("Error during device initialization: %s", bfcUtilsGetStringForBErr(deviceInitErr));
				continue;
			}
			Devices[device->GetSerial()] = std::move(device);
		}
	}
	
	bfcDestroy(instance);
	initialized = true;
	return BERR_NO_ERROR;
}


BluefishDevice::BluefishDevice(BLUE_S32 deviceId, BErr& error) : Id(deviceId), Instance()
{
	error = Instance.Attach(Id);
	if (BERR_NO_ERROR != error)
		return;
	bfcUtilsGetDeviceInfo(Id, &Info);
	bfcSetCardProperty32(Instance, VIDEO_BLACKGENERATOR, ENUM_BLACKGENERATOR_OFF);
	bfcSetCardProperty32(Instance, VIDEO_IMAGE_ORIENTATION, ImageOrientation_Normal);
}

BluefishDevice::~BluefishDevice()
{
	Channels.clear();
}

bool BluefishDevice::CanChannelDoInput(EBlueVideoChannel channel)
{
	blue_setup_info setup = bfcUtilsGetDefaultSetupInfoInput(channel);
	setup.DeviceId = GetId();
	auto err = bfcUtilsGetSetupInfoForInputSignal(nullptr, &setup, UHD_PREFERENCE_DEFAULT);
	return BERR_NO_ERROR == err;
}

blue_setup_info BluefishDevice::GetSetupInfoForInput(EBlueVideoChannel channel, BErr& err) const
{
	blue_setup_info setup = bfcUtilsGetDefaultSetupInfoInput(channel);
	setup.DeviceId = GetId();
	//err = bfcUtilsGetSetupInfoForInputSignal(nullptr, &setup, UHD_PREFERENCE_DEFAULT);
	//if (BERR_NO_ERROR != err)
	{
		err = bfcUtilsGetRecommendedSetupInfoInput(Instance, &setup, UHD_PREFERENCE_DEFAULT);
		if (BERR_NO_ERROR != err)
			return setup;
	}
	setup.SignalLinkType = SIGNAL_LINK_TYPE_SINGLE_LINK; // Support only single link for now
	setup.MemoryFormat = MEM_FMT_2VUY;
	setup.UpdateMethod = UPD_FMT_FRAME;
	if (setup.VideoModeExt < VID_FMT_EXT_2160P_2398)
		setup.VideoEngine = VIDEO_ENGINE_AUTO_CAPTURE;
	else
		setup.VideoEngine = VIDEO_ENGINE_AUTO_CAPTURE_UHD;
	setup.TransportSampling = Signal_FormatType_422;
	return setup;
}

bool BluefishDevice::SetupChannel(EBlueVideoChannel channel, EMemoryFormat pixelFormat)
{
	auto it = Channels.find(channel);
	if (it != Channels.end())
	{
		blue_setup_info setup = it->second->GetSetupInfo();
		if (setup.MemoryFormat != pixelFormat)
		{
			setup.MemoryFormat = pixelFormat;
			OpenChannel(channel, setup);
		}
	}
	return true;
}

bool BluefishDevice::ChannelExist(EBlueVideoChannel channel)
{
	auto it = Channels.find(channel);
	if (it != Channels.end())
	{
		return true;
	}
	return false;
}

BErr BluefishDevice::OpenChannel(EBlueVideoChannel channel, blue_setup_info& SetupInfo)
{
	CloseChannel(channel);
	BErr error;
	auto chObject = std::make_unique<Channel>(this, channel, SetupInfo, error);
	if (BERR_NO_ERROR != error)
		return error;
	Channels[channel] = std::move(chObject);
	return error;
}

void BluefishDevice::CloseChannel(EBlueVideoChannel channel)
{
	auto it = Channels.find(channel);
	if (it != Channels.end())
		Channels.erase(it);
}

bool BluefishDevice::DMAWriteFrame(EBlueVideoChannel channel, uint32_t bufferId, uint8_t* inBuffer, uint32_t size, uint32_t fieldCount) const
{
	if (Channels.size() == 0)
	{
		nosEngine.LogE("DMA Read: Channel %s not open!", bfcUtilsGetStringForVideoChannel(channel));
		return false;
	}
	auto it = Channels.find(channel);
	if (it == Channels.end())
	{
		nosEngine.LogE("DMA Write: Channel %s not open!", bfcUtilsGetStringForVideoChannel(channel));
		return false;
	}
	return it->second->DMAWriteFrame(bufferId, inBuffer, size, fieldCount);
}

bool BluefishDevice::DMAReadFrame(EBlueVideoChannel channel, uint32_t startCaptureBufferId, uint32_t readBufferId, uint8_t* outBuffer, uint32_t size, uint32_t* fieldCount) const
{
	if (Channels.size() == 0)
	{
		nosEngine.LogE("DMA Read: Channel %s not open!", bfcUtilsGetStringForVideoChannel(channel));
		return false;
	}
	auto it = Channels.find(channel);
	if (it == Channels.end())
	{
		nosEngine.LogE("DMA Read: Channel %s not open!", bfcUtilsGetStringForVideoChannel(channel));
		return false;
	}
	return it->second->DMAReadFrame(startCaptureBufferId, readBufferId, outBuffer, size, fieldCount);
}

bool BluefishDevice::WaitVBI(EBlueVideoChannel channel, unsigned long& fieldCount) const
{
	if (Channels.size() == 0)
	{
		nosEngine.LogE("DMA Read: Channel %s not open!", bfcUtilsGetStringForVideoChannel(channel));
		return false;
	}
	auto it = Channels.find(channel);
	if (it == Channels.end())
	{
		nosEngine.LogE("Wait VBI: Channel %s not open!", bfcUtilsGetStringForVideoChannel(channel));
		return false;
	}
	return it->second->WaitVBI(fieldCount);
}

std::array<uint32_t, 2> BluefishDevice::GetDeltaSeconds(EBlueVideoChannel channel) const
{
	auto it = Channels.find(channel);
	if (it == Channels.end())
		return {0, 0};
	return it->second->GetDeltaSeconds();
}

std::shared_ptr<BluefishDevice> BluefishDevice::GetDevice(std::string const& serial)
{
	auto it = Devices.find(serial);
	if (it == Devices.end())
		return nullptr;
	return it->second;
}

std::shared_ptr<BluefishDevice> BluefishDevice::GetDevice(BLUE_S32 id)
{
	for (auto& [serial, device] : Devices)
	{
		if (device->GetId() == id)
			return device;
	}
	return nullptr;
}

void BluefishDevice::ForEachDevice(std::function<void(BluefishDevice&)>&& func)
{
	for (auto& [serial, device] : Devices)
		func(*device);
}

std::string BluefishDevice::GetSerial() const
{
	std::stringstream ss;
	for (int i = 0; i < 32; ++i)
	{
		auto c = Info.CardSerialNumber[i];
		if (!c)
			break;
		ss << c;
	}
	return ss.str();
}

std::string BluefishDevice::GetName() const
{
	return bfcUtilsGetStringForCardType(Info.CardType);
}

Channel::Channel(BluefishDevice* device, EBlueVideoChannel channel, blue_setup_info& bfSetup, BErr& err)
	: Device(device), VideoChannel(channel), Instance()
{
	memcpy(&setupInfo, &bfSetup, sizeof(blue_setup_info));
	setupInfo.DeviceId = Device->GetId();
	UnderrunLast = 0;
	FramesDMAed = 0;
	if (IsInputChannel(channel))
	{
		setupInfo.VideoChannelInput = channel;
		err = bfcUtilsGetRecommendedSetupInfoInput(Instance, &setupInfo, UHD_PREFERENCE_DEFAULT);
		setupInfo.MemoryFormat = bfSetup.MemoryFormat;
		if (bfcUtilsIsVideoModeProgressive(setupInfo.VideoModeExt) || bfcUtilsIsVideoModePsF(setupInfo.VideoModeExt))
			setupInfo.UpdateMethod = UPD_FMT_FRAME;
		else
			setupInfo.UpdateMethod = UPD_FMT_FIELD;
		if (BERR_NO_ERROR != err)
			return;
		err = bfcUtilsValidateSetupInfo(&setupInfo);
		if (BERR_NO_ERROR != err)
			return;
		err = bfcUtilsSetupInput(Instance, &setupInfo);
		memcpy(&bfSetup, &setupInfo, sizeof(blue_setup_info));
		err = bfcAutoCaptureCreateInternalBuffers(Instance, EBlueBufferComponent(BUFFER_COMPONENT_VIDEO | BUFFER_COMPONENT_VANC | BUFFER_COMPONENT_HANC));
		err = bfcVideoCaptureStart(Instance);
	}
	else
	{
		setupInfo.VideoEngine = VIDEO_ENGINE_DUPLEX;
		if (bfcUtilsIsVideoModeProgressive(setupInfo.VideoModeExt) || bfcUtilsIsVideoModePsF(setupInfo.VideoModeExt))
			setupInfo.UpdateMethod = UPD_FMT_FRAME;
		else
			setupInfo.UpdateMethod = UPD_FMT_FIELD;

		//if (0)
		//{
		//	setupInfo.MemoryFormat = MEM_FMT_RGBA_16_16_16_16;
		//}

		err = bfcUtilsValidateSetupInfo(&setupInfo);
		if (BERR_NO_ERROR != err)
			return;
		err = bfcUtilsSetupOutput(Instance, &setupInfo);
		err = bfcVideoPlaybackStart(Instance, 1, 0);
	}
	uint32_t dividend = bfcUtilsGetFpsForVideoMode(setupInfo.VideoModeExt) * (bfcUtilsIsVideoMode1001Framerate(setupInfo.VideoModeExt) ? 1000 : 1);
	uint32_t divisor = bfcUtilsIsVideoMode1001Framerate(setupInfo.VideoModeExt) ? 1001 : 1;
	DeltaSeconds = { divisor, dividend };
}

Channel::~Channel()
{
	BErr Err;
	if (IsInputChannel(VideoChannel))
	{
		Err = bfcVideoCaptureStop(Instance);
		Err = bfcAutoCaptureDestroyInternalBuffers(Instance);
	}
	else
	{
		Err = bfcVideoPlaybackStop(Instance, 0, 0);
	}
}

blue_setup_info Channel::GetSetupInfo() const
{
	return setupInfo;
}

bool Channel::DMAWriteFrame(uint32_t bufferId, uint8_t* inBuffer, uint32_t size, uint32_t fieldCount)
{
	unsigned long BufferID = 0;
	void* pAddressNotUsed;
	unsigned long UniqueID = 0;
	unsigned long Underrun = 0;
	auto ret = bfcVideoPlaybackAllocate(Instance, &pAddressNotUsed, &BufferID, &Underrun);
	if (BLUE_OK(ret))
	{
		if (FramesDMAed > 0)
		{
			auto diff = Underrun - UnderrunLast;
			if (setupInfo.UpdateMethod == UPD_FMT_FIELD)
			{
				if (diff > 1)
				{
					nosEngine.LogW("%s dropped %d frames", bfcUtilsGetStringForVideoChannel(setupInfo.VideoChannelOutput), diff);
				}
			}
			else
			{
				if (diff > 2)
				{
					nosEngine.LogW("%s dropped %d frames", bfcUtilsGetStringForVideoChannel(setupInfo.VideoChannelOutput), (diff - 2) / 2);
				}
			}
		}
		UnderrunLast = Underrun;

		BLUE_S32 BytesCopied = 0;
		if (setupInfo.UpdateMethod == UPD_FMT_FRAME)
		{
			BytesCopied = bfcDmaWriteToCardAsync(Instance, (BLUE_U8*)inBuffer, size, nullptr, BlueImage_DMABuffer(BufferID, BLUE_DATA_IMAGE), 0);
			bfcVideoPlaybackPresent(Instance, &UniqueID, BlueBuffer_Image(BufferID), 1, 0, 0);
		}
		else
		{
			BytesCopied = bfcDmaWriteToCardAsync(Instance, (BLUE_U8*)inBuffer, size, nullptr, BlueImage_DMABuffer(BufferID, BLUE_DMA_DATA_TYPE_IMAGE_FIELD), 0);
			bfcVideoPlaybackPresent(Instance, &UniqueID, BlueBuffer_Image(BufferID), 1, 0, fieldCount % 2);
		}
		FramesDMAed++;
	}
	else
	{
		unsigned long fieldC;
		bfcWaitVideoOutputSync(Instance, setupInfo.UpdateMethod, &fieldC);
		nosEngine.LogW("%s dropped %d frames", bfcUtilsGetStringForVideoChannel(setupInfo.VideoChannelOutput), 1);
	}
	return ret == BERR_NO_ERROR;
}

bool Channel::DMAReadFrame(uint32_t startCaptureBufferId, uint32_t readBufferId, uint8_t* outBuffer, uint32_t size, uint32_t* fieldCount)
{
	blue_auto_buffer_info BufferInfo = {};
	BufferInfo.CardBufferId = -1;
	BErr Err = bfcAutoCaptureGetFilledBuffer(Instance, &BufferInfo, RETURN_MODE_BLOCKING);
	if (BLUE_OK(Err) && (BufferInfo.CardBufferId >= 0))
	{
		BLUE_U32 Value32 = VID_FMT_EXT_INVALID;
		bfcQueryCardProperty32(Instance, VIDEO_MODE_EXT_INPUT, &Value32);
		if (Value32 == VID_FMT_EXT_INVALID)
		{
			printf("[%s:%d] Invalid input signal\n", __FUNCTION__, __LINE__);
			// do not process this buffer, but return it
			BErr Err = bfcAutoCaptureReturnBuffer(Instance, &BufferInfo);
			if (Err)
				printf("ERROR from bfcAutoCaptureReturnBuffer: %s", bfcUtilsGetStringForBErr(Err));
		}
		else
		{
			BLUE_U64 CurrentBtcTime = 0ULL;
			bfcQueryCardProperty64(Instance, BTC_TIMER, &CurrentBtcTime);

			if (!BufferInfo.BufferIncomplete)
			{
				if (BufferInfo.VideoModeExt != setupInfo.VideoModeExt)
				{
					// re-initialise input setup AutoCapture including memory buffers
					printf("Video mode changed from %s to %s; re-init required!\n", bfcUtilsGetStringForVideoMode(setupInfo.VideoModeExt), bfcUtilsGetStringForVideoMode(BufferInfo.VideoModeExt));
					Err = bfcAutoCaptureReturnBuffer(Instance, &BufferInfo);
					return false;
				}
				else
				{
					if (BufferInfo.pBufferVideo)
					{
						if (size < BufferInfo.SizeVideo)
							memcpy(outBuffer, BufferInfo.pBufferVideo, size);
						else
							memcpy(outBuffer, BufferInfo.pBufferVideo, BufferInfo.SizeVideo);

						//		BLUE_VOID* pVideoBufferToUse = BufferInfo.pBufferVideo;
						//		if (Width > 2048 && InputSetup.VideoSubImageMapping == IMAGE_MAPPING_TWO_SAMPLE_INTERLEAVE)
						//			pVideoBufferToUse = Do2SIDecode(hBVCC, InputSetup.VideoModeExt, InputSetup.MemoryFormat, (unsigned char*)BufferInfo.pBufferVideo);

						//		// This is where end users should do the actual work on the video buffer (The actual function might need more argument or more information about the video buffer) 
						//		ProcessVideoBuffer((BLUE_U8*)pVideoBufferToUse, BufferInfo.SizeVideo);
					}
					else
					{
						printf("NO BUFFER! Video Mode %s\n", bfcUtilsGetStringForVideoMode(BufferInfo.VideoModeExt));
					}
				}
			}
			else
			{
				// you can choose to display the incomplete frame to show at least something (for debugging purposes ?)
				// or you can choose to render the last frame again or a black frame
				printf("Buffer incomplete\n");
			}
			*fieldCount = BufferInfo.FieldCount;
			Err = bfcAutoCaptureReturnBuffer(Instance, &BufferInfo);
		}
	}


	//auto err = bfcRenderBufferCapture(Instance, BlueBuffer_Image(startCaptureBufferId));
	//if (err != BERR_NO_ERROR)
	//	nosEngine.LogE("DMA Read: Cannot set capture buffer to %d", startCaptureBufferId);
	//auto ret = bfcDmaReadFromCardAsync(Instance, outBuffer, size, nullptr, BlueImage_DMABuffer(readBufferId, BLUE_DMA_DATA_TYPE_IMAGE_FRAME), 0);
	if (Err < 0)
	{
		nosEngine.LogE("DMA Read returned with '%s'", bfcUtilsGetStringForBErr(Err));
		return false;
	}
	return Err == BERR_NO_ERROR;
}

bool Channel::WaitVBI(unsigned long& fieldCount) const
{
	return BERR_NO_ERROR == (IsInputChannel(VideoChannel)
		                         ? bfcWaitVideoInputSync(Instance, UPD_FMT_FRAME, &fieldCount)
		                         : bfcWaitVideoOutputSync(Instance, UPD_FMT_FRAME, &fieldCount));
}

}