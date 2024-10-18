﻿// Copyright MediaZ Teknoloji A.S. All Rights Reserved.

#include "ChannelNode.hpp"
#include "ChannelHelpers.hpp"
#include "Device.hpp"

namespace bf
{

ChannelNode::ChannelNode(const nosFbNode* node): NodeContext(node)
{
	auto err = BluefishDevice::InitializeDevices();
	if (BERR_NO_ERROR != err)
	{
		SetNodeStatusMessage(std::string("Error during device initialization: ") + bfcUtilsGetStringForBErr(err), nos::fb::NodeStatusMessageType::FAILURE);
		return;
	}
	LoadChannelInfo(node);
}

void ChannelNode::LoadChannelInfo(const nosFbNode* node)
{
	if (auto* pins = node->pins())
	{
		nos::bluefish::TChannelInfo info;
		for (auto const* pin : *pins)
		{
			auto name = pin->name()->c_str();
			if (0 == strcmp(name, "Channel"))
			{
				ChannelPinId = *pin->id();
				flatbuffers::GetRoot<nos::bluefish::ChannelInfo>(pin->data()->data())->UnPackTo(&info);
			}
		}
		UpdateChannel(std::move(info));
	}
}

ChannelNode::~ChannelNode()
{
	CloseChannel();
}

void ChannelNode::OnNodeMenuRequested(const nosContextMenuRequest* request)
{
	flatbuffers::FlatBufferBuilder fbb;
		
	std::vector<flatbuffers::Offset<nos::ContextMenuItem>> items, devices;
	if (INPUT & GetChannelTypeFlags())
		EnumerateInputChannels(fbb, devices);
	if (OUTPUT & GetChannelTypeFlags())
		EnumerateOutputChannels(fbb, devices);
	if (!devices.empty())
		items.push_back(nos::CreateContextMenuItemDirect(fbb, "Open Channel", 0, &devices));

	if (items.empty())
		return;

	HandleEvent(nos::CreateAppEvent(fbb, nos::app::CreateAppContextMenuUpdateDirect(fbb, &NodeId, request->pos(), request->instigator(), &items)));
}

void ChannelNode::OnMenuCommand(nosUUID itemID, uint32_t cmd)
{
	SelectChannelCommand& command = reinterpret_cast<SelectChannelCommand&>(cmd);
	auto device = BluefishDevice::GetDevice(command.DeviceId);
	if (!device)
	{
		nosEngine.LogE("No such Bluefish444 device found: %d", command.DeviceId);
		return;
	}
	if (IsInputChannel(command.Channel))
	{
		BErr err{};
		auto setup = device->GetSetupInfoForInput(command.Channel, err);
		command.VideoMode = setup.VideoModeExt;
		if (err != BERR_NO_ERROR)
		{
			nosEngine.LogE("Unable to get input setup info: %s", bfcUtilsGetStringForBErr(err));
			return;
		}
		else if (setup.SignalLinkType != SIGNAL_LINK_TYPE_SINGLE_LINK)
		{
			nosEngine.LogE("Unable to open input channel: Only SingleLink is supported for now.");
			return;
		}
	}
	std::string pinName = "SingleLink " +  std::to_string(GetChannelNumber(command.Channel));

	nos::bluefish::TChannelInfo channelPin{};
	nos::bluefish::TDeviceId d;
	d.serial = device->GetSerial();
	d.name = device->GetName();
	nos::bluefish::TChannelId c;
	c.name = bfcUtilsGetStringForVideoChannel(command.Channel);
	c.id = static_cast<int>(command.Channel);
	channelPin.device = std::make_unique<nos::bluefish::TDeviceId>(std::move(d));
	channelPin.channel = std::make_unique<nos::bluefish::TChannelId>(std::move(c));
	channelPin.video_mode = static_cast<int>(command.VideoMode);
	channelPin.video_mode_name = bfcUtilsGetStringForVideoMode(command.VideoMode);
	BLUE_U32 width, height, frameRate, frameRateIs1001;
	scan_mode scanMode;
	auto err = bfcUtilsGetFrameInfoForVideoModeExtV2(command.VideoMode, &width, &height, &frameRate, &frameRateIs1001, &scanMode);
	channelPin.resolution = std::make_unique<nos::fb::vec2u>(width, height);
	if (bfcUtilsIsVideoModeProgressive(command.VideoMode) || bfcUtilsIsVideoModePsF(command.VideoMode))
		channelPin.interlaced = false;
	else
		channelPin.interlaced = true;
	nosEngine.SetPinValue(ChannelPinId, nos::Buffer::From(channelPin));
	UpdateChannel(std::move(channelPin));
}

void ChannelNode::OnNodeUpdated(const nos::fb::Node* updatedNode)
{
	LoadChannelInfo(updatedNode);
}

void ChannelNode::OnPinValueChanged(nos::Name pinName, nosUUID pinId, nosBuffer value)
{
	if (pinName == NOS_NAME("Channel"))
	{
		nos::bluefish::TChannelInfo newInfo;
		flatbuffers::GetRoot<nos::bluefish::ChannelInfo>(value.Data)->UnPackTo(&newInfo);
		UpdateChannel(std::move(newInfo));
	}
}

void ChannelNode::UpdateChannel(nos::bluefish::TChannelInfo info)
{
	if (info == ChannelInfo)
		return;
	CloseChannel();
	ChannelInfo = std::move(info);
	OpenChannel();
}

void ChannelNode::OpenChannel()
{
	if (!ChannelInfo.device || !ChannelInfo.channel)
		return;
	auto device = BluefishDevice::GetDevice(ChannelInfo.device->serial);
	if (!device)
	{
		if (!ChannelInfo.device->serial.empty())
			UpdateStatus(nos::fb::NodeStatusMessageType::FAILURE, "Unable to find Bluefish444 device:" + ChannelInfo.device->serial);
		else
			UpdateStatus(nos::fb::NodeStatusMessageType::INFO, "Right click node to see and select channels");
		return;
	}
	EVideoModeExt mode = static_cast<EVideoModeExt>(ChannelInfo.video_mode);
	auto channel = static_cast<EBlueVideoChannel>(ChannelInfo.channel->id);
	std::string channelStr = bfcUtilsGetStringForVideoChannel(channel);
	std::string modeStr = bfcUtilsGetStringForVideoMode(mode);
	blue_setup_info setupInfo;
	if (IsInputChannel(channel))
	{
		nosEngine.LogI("Route input %s", channelStr.c_str());
		setupInfo = bfcUtilsGetDefaultSetupInfoInput(channel);
	}
	else
	{
		nosEngine.LogI("Route output %s with video mode %s", channelStr.c_str(), modeStr.c_str());
		setupInfo = bfcUtilsGetDefaultSetupInfoOutput(channel, mode);
	}

	auto err = device->OpenChannel(channel, setupInfo);
	if (BERR_NO_ERROR == err)
	{
		modeStr = bfcUtilsGetStringForVideoMode(setupInfo.VideoModeExt);
		UpdateStatus(nos::fb::NodeStatusMessageType::INFO, channelStr + " " + modeStr);
	}
	else
	{
		UpdateStatus(nos::fb::NodeStatusMessageType::FAILURE, "Unable to open channel " + channelStr + ": " + bfcUtilsGetStringForBErr(err));
		nosEngine.SetPinValue(ChannelPinId, nos::Buffer::From(nos::bluefish::TChannelInfo{}));
	}
	nosEngine.RecompilePath(NodeId);
}

void ChannelNode::CloseChannel()
{
	if (!ChannelInfo.device || !ChannelInfo.channel)
		return;
	auto device = BluefishDevice::GetDevice(ChannelInfo.device->serial);
	if (!device)
	{
		UpdateStatus(nos::fb::NodeStatusMessageType::FAILURE, "Unable to find Bluefish444 device:" + ChannelInfo.device->serial);
		return;
	}
	device->CloseChannel(static_cast<EBlueVideoChannel>(ChannelInfo.channel->id));
}

void ChannelNode::UpdateStatus(nos::fb::NodeStatusMessageType type, std::string text)
{
	auto device = BluefishDevice::GetDevice(ChannelInfo.device->serial);
	std::vector<nos::fb::TNodeStatusMessage> messages;
	if (device)
	{
		messages.push_back(nos::fb::TNodeStatusMessage{{}, device->GetName(), type});
	}
	messages.push_back(nos::fb::TNodeStatusMessage{{}, text, type});
	SetNodeStatusMessages(messages);
}

nosResult RegisterChannelNode(nosNodeFunctions* outFunctions)
{
	NOS_BIND_NODE_CLASS(NOS_NAME("Channel"), ChannelNode, outFunctions)
	return NOS_RESULT_SUCCESS;
}

}