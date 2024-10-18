/*
 * Copyright MediaZ Teknoloji A.S. All Rights Reserved.
 */

#pragma once

#include <Nodos/PluginHelpers.hpp>

#include "Device.hpp"

namespace bf
{

struct SelectChannelCommand
{
	BLUE_S32 DeviceId : 4;
	EBlueVideoChannel Channel : 5;
	EVideoModeExt VideoMode : 12;
	operator uint32_t() const { return *(uint32_t*)this; }
};
static_assert(sizeof(SelectChannelCommand) == sizeof(uint32_t));

struct FormatDescriptor
{
	EVideoModeExt Format;
	u32 Width, Height;
	u8 Interlaced : 1;
};

inline EBlueVideoChannel inputIdxToChannel(unsigned int nIndex)
{
	EBlueVideoChannel inputChannel = BLUE_VIDEOCHANNEL_INVALID;
	switch (nIndex)
	{
	case 1:
		inputChannel = BLUE_VIDEO_INPUT_CHANNEL_A;
		break;
	case 2:
		inputChannel = BLUE_VIDEO_INPUT_CHANNEL_B;
		break;
	case 3:
		inputChannel = BLUE_VIDEO_INPUT_CHANNEL_C;
		break;
	case 4:
		inputChannel = BLUE_VIDEO_INPUT_CHANNEL_D;
		break;
	case 5:
		inputChannel = BLUE_VIDEO_INPUT_CHANNEL_E;
		break;
	case 6:
		inputChannel = BLUE_VIDEO_INPUT_CHANNEL_F;
		break;
	case 7:
		inputChannel = BLUE_VIDEO_INPUT_CHANNEL_G;
		break;
	case 8:
		inputChannel = BLUE_VIDEO_INPUT_CHANNEL_H;
		break;
	}
	return inputChannel;
}

inline EBlueVideoChannel outputIdxToChannel(unsigned int nIndex)
{
	EBlueVideoChannel outputChannel = BLUE_VIDEOCHANNEL_INVALID;
	switch (nIndex)
	{
	case 1:
		outputChannel = BLUE_VIDEO_OUTPUT_CHANNEL_A;
		break;
	case 2:
		outputChannel = BLUE_VIDEO_OUTPUT_CHANNEL_B;
		break;
	case 3:
		outputChannel = BLUE_VIDEO_OUTPUT_CHANNEL_C;
		break;
	case 4:
		outputChannel = BLUE_VIDEO_OUTPUT_CHANNEL_D;
		break;
	case 5:
		outputChannel = BLUE_VIDEO_OUTPUT_CHANNEL_E;
		break;
	case 6:
		outputChannel = BLUE_VIDEO_OUTPUT_CHANNEL_F;
		break;
	case 7:
		outputChannel = BLUE_VIDEO_OUTPUT_CHANNEL_G;
		break;
	case 8:
		outputChannel = BLUE_VIDEO_OUTPUT_CHANNEL_H;
		break;
	}
	return outputChannel;
}

inline nos::fb::vec2u UnpackU64(uint64_t val)
{
	return nos::fb::vec2u((val >> 32) & 0xFFFFFFFF, val & 0xFFFFFFFF);
}

inline uint64_t PackU64(nos::fb::vec2u val)
{
	return static_cast<uint64_t>(val.x()) << 32 | val.y();
}

inline auto EnumerateFormats()
{
	struct FormatDescriptor
	{
		EVideoModeExt Format;
		nos::fb::vec2u DeltaSeconds;
		u32 Width, Height;
		u8 Interlaced : 1;
	};

	std::unordered_map<uint64_t, std::unordered_map<uint64_t, std::vector<FormatDescriptor>>> extDeltaSecDescMap;
	for (auto fmt = VID_FMT_EXT_1080I_5000; fmt < VID_FMT_EXT_LAST_ENTRY_V1; fmt = EVideoModeExt(fmt + 1))
	{
		if (bfcUtilsIsVideoModePsF(fmt))
			continue;
		bool interlaced = !bfcUtilsIsVideoModeProgressive(fmt);
		BLUE_U32 w, h;
		bfcGetVideoWidth(fmt, &w);
		bfcGetVideoHeight(fmt, UPD_FMT_FRAME, &h);
		uint32_t dividend = bfcUtilsGetFpsForVideoMode(fmt) * (bfcUtilsIsVideoMode1001Framerate(fmt) ? 1000 : 1);
		uint32_t divisor = bfcUtilsIsVideoMode1001Framerate(fmt) ? 1001 : 1;
		auto desc = FormatDescriptor{
			.Format = fmt,
			.DeltaSeconds = {dividend, divisor},
			.Width = w,
			.Height = h,
			.Interlaced = interlaced,
		};
		extDeltaSecDescMap[PackU64({w, h})][PackU64(desc.DeltaSeconds)].push_back(desc);
	}
	return extDeltaSecDescMap;
}

inline void EnumerateInputChannels(flatbuffers::FlatBufferBuilder& fbb, std::vector<flatbuffers::Offset<nos::ContextMenuItem>>& devices)
{
	BLUE_S32 nDeviceCou = bfcUtilsGetDeviceCount();
	blue_device_info BfDeviceInfo;
	std::vector<flatbuffers::Offset<nos::ContextMenuItem>> inChannels;

	BluefishDevice::ForEachDevice([&](BluefishDevice& device) {
		BErr bErr = bfcUtilsGetDeviceInfo(device.GetId(), &BfDeviceInfo);
		for (unsigned int chIndex = 1; chIndex <= BfDeviceInfo.SdiConnectorCountInput; chIndex++)
		{
			EBlueVideoChannel ch = inputIdxToChannel(chIndex);
			//if (!IsInputChannel(ch))
			//	continue;
			SelectChannelCommand command = {
				.DeviceId = device.GetId(),
				.Channel = ch
			};
			std::string channelName = bfcUtilsGetStringForVideoChannel(ch);
			ReplaceString(channelName, "Input ", "");
			if (device.CanChannelDoInput(ch))
				inChannels.push_back(nos::CreateContextMenuItemDirect(fbb, channelName.c_str(), command));
			if (!inChannels.empty())
			{
				if (nDeviceCou > 1)
				{
					std::string strCard = "Card " + std::to_string(device.GetId()) + " Input";
					devices.push_back(nos::CreateContextMenuItemDirect(fbb, strCard.data(), 0, &inChannels));
				}
				else
				{
					devices.push_back(nos::CreateContextMenuItemDirect(fbb, "Input", 0, &inChannels));
				}
			}
		}
	});
}

inline void EnumerateOutputChannels(flatbuffers::FlatBufferBuilder& fbb, std::vector<flatbuffers::Offset<nos::ContextMenuItem>>& devices)
{
	BLUE_S32 nDeviceCou = bfcUtilsGetDeviceCount();
	blue_device_info BfDeviceInfo;
	std::vector<flatbuffers::Offset<nos::ContextMenuItem>> outChannels;

	BluefishDevice::ForEachDevice([&](BluefishDevice& device) {
		BErr bErr = bfcUtilsGetDeviceInfo(device.GetId(), &BfDeviceInfo);

//		std::vector<flatbuffers::Offset<nos::ContextMenuItem>> outChannels;
		for (unsigned int chIndex = 1; chIndex <= BfDeviceInfo.SdiConnectorCountOutput; chIndex++)
		{
			EBlueVideoChannel ch = outputIdxToChannel(chIndex);
			SelectChannelCommand command = {
				.DeviceId = device.GetId(),
				.Channel = ch
			};
			//if (IsInputChannel(ch))
			//	continue;
			std::string channelName = bfcUtilsGetStringForVideoChannel(ch);
			ReplaceString(channelName, "Output ", "");
			std::vector<flatbuffers::Offset<nos::ContextMenuItem>> extents;
			static auto descriptors = EnumerateFormats();
			for (auto& [extPacked, deltaSecDescMap] : descriptors)
			{
				auto extent = UnpackU64(extPacked);
				std::vector<flatbuffers::Offset<nos::ContextMenuItem>> frameRates;
				for (auto& [deltaSecPacked, descs] : deltaSecDescMap)
				{
					auto deltaSec = UnpackU64(deltaSecPacked);
					std::vector<flatbuffers::Offset<nos::ContextMenuItem>> formats;
					for (auto& desc : descs)
					{
						command.VideoMode = desc.Format;
						auto name = desc.Interlaced ? "Interlaced" : "Progressive";
						formats.push_back(nos::CreateContextMenuItemDirect(fbb, name, command));
					}
					if (!formats.empty())
					{
						float frameRate = static_cast<float>(deltaSec.x()) / static_cast<float>(deltaSec.y());
						char buf[16] = {};
						std::sprintf(buf, "%.2f", frameRate);
						frameRates.push_back(nos::CreateContextMenuItemDirect(fbb, buf, 0, &formats));
					}
				}
				if (!frameRates.empty())
				{
					char buf[32] = {};
					std::sprintf(buf, "%dx%d", extent.x(), extent.y());
					extents.push_back(nos::CreateContextMenuItemDirect(fbb, buf, 0, &frameRates));
				}
			}
			if (!extents.empty())
				outChannels.push_back(nos::CreateContextMenuItemDirect(fbb, channelName.c_str(), 0, &extents));
		}

		if (nDeviceCou > 1)
		{
			if (!outChannels.empty())
			{
				std::string strCard = "Card " + std::to_string(device.GetId()) + " Output";
				devices.push_back(nos::CreateContextMenuItemDirect(fbb, strCard.data(), 0, &outChannels));
			}
		}
		else
		{
			if (!outChannels.empty())
				devices.push_back(nos::CreateContextMenuItemDirect(fbb, "Output", 0, &outChannels));
		}
	});
}

}
