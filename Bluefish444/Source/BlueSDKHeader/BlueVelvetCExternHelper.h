/**
 *  @file       BlueVelvetCExternHelper.h
 *  @brief      Helper file for loading BlueVelvetC API function pointers
 *  @copyright  (C) Copyright 2017-2023 Bluefish Technologies Pty Ltd. All Rights Reserved. Proprietary and confidential information.
**/

#if defined(LOAD_FUNC_PTR_V6_5_3)
    #if !defined(LOAD_FUNC_PTR_V6_5_1)
        #define LOAD_FUNC_PTR_V6_5_1
    #endif
    #if !defined(LOAD_FUNC_PTR_V6_5_0)
        #define LOAD_FUNC_PTR_V6_5_0
    #endif
#elif defined(LOAD_FUNC_PTR_V6_5_1)
    #if !defined(LOAD_FUNC_PTR_V6_5_0)
        #define LOAD_FUNC_PTR_V6_5_0
    #endif
#endif


extern pFunc_bfcGetVersion bfcGetVersion;
extern pFunc_bfcGetVersionW bfcGetVersionW;
extern pFunc_bfcFactory bfcFactory;
extern pFunc_bfcDestroy bfcDestroy;
extern pFunc_bfcEnumerate bfcEnumerate;
extern pFunc_bfcQueryCardType bfcQueryCardType;
extern pFunc_bfcAttach bfcAttach;
extern pFunc_bfcSetMultiLinkMode bfcSetMultiLinkMode;
extern pFunc_bfcQueryMultiLinkMode bfcQueryMultiLinkMode;
extern pFunc_bfcDetach bfcDetach;
extern pFunc_bfcQueryCardProperty32 bfcQueryCardProperty32;
extern pFunc_bfcQueryCardProperty64 bfcQueryCardProperty64;
extern pFunc_bfcSetCardProperty32 bfcSetCardProperty32;
extern pFunc_bfcSetCardProperty64 bfcSetCardProperty64;
extern pFunc_bfcGetCardSerialNumber bfcGetCardSerialNumber;
extern pFunc_bfcGetCardHwFwVersions bfcGetCardHwFwVersions;
extern pFunc_bfcWaitVideoSync bfcWaitVideoSync;
extern pFunc_bfcWaitVideoInputSync bfcWaitVideoInputSync;
extern pFunc_bfcWaitVideoOutputSync bfcWaitVideoOutputSync;
extern pFunc_bfcGetVideoOutputCurrentFieldCount bfcGetVideoOutputCurrentFieldCount;
extern pFunc_bfcGetVideoInputCurrentFieldCount bfcGetVideoInputCurrentFieldCount;
extern pFunc_bfcVideoCaptureStart bfcVideoCaptureStart;
extern pFunc_bfcVideoCaptureStop bfcVideoCaptureStop;
extern pFunc_bfcVideoPlaybackStart bfcVideoPlaybackStart;
extern pFunc_bfcVideoPlaybackStop bfcVideoPlaybackStop;
extern pFunc_bfcVideoPlaybackAllocate bfcVideoPlaybackAllocate;
extern pFunc_bfcVideoPlaybackPresent bfcVideoPlaybackPresent;
extern pFunc_bfcVideoPlaybackRelease bfcVideoPlaybackRelease;
extern pFunc_bfcGetCaptureVideoFrameInfoEx bfcGetCaptureVideoFrameInfoEx;
extern pFunc_bfcRenderBufferCapture bfcRenderBufferCapture;
extern pFunc_bfcRenderBufferUpdate bfcRenderBufferUpdate;
extern pFunc_bfcGetRenderBufferCount bfcGetRenderBufferCount;
extern pFunc_bfcEncodeHancFrameEx bfcEncodeHancFrameEx;
extern pFunc_bfcEncodeHancFrameWithUCZ bfcEncodeHancFrameWithUCZ;
extern pFunc_bfcDecodeHancFrameEx bfcDecodeHancFrameEx;
extern pFunc_bfcSyncInfoCreate bfcSyncInfoCreate;
extern pFunc_bfcSyncInfoDelete bfcSyncInfoDelete;
extern pFunc_bfcSyncInfoWait bfcSyncInfoWait;
extern pFunc_bfcSyncInfoWaitWithSyncOptions bfcSyncInfoWaitWithSyncOptions;
extern pFunc_bfcDmaReadFromCardAsync bfcDmaReadFromCardAsync;
extern pFunc_bfcDmaWriteToCardAsync bfcDmaWriteToCardAsync;
extern pFunc_bfcSerialPortWaitForInputData bfcSerialPortWaitForInputData;
extern pFunc_bfcSerialPortRead bfcSerialPortRead;
extern pFunc_bfcSerialPortWrite bfcSerialPortWrite;
#if defined(_WIN32)
extern pFunc_bfcGetReferenceClockPhaseSettings bfcGetReferenceClockPhaseSettings;
extern pFunc_bfcLoadOutputLUT1D bfcLoadOutputLUT1D;
#endif
extern pFunc_bfcGetVideoWidth bfcGetVideoWidth;
extern pFunc_bfcGetVideoHeight bfcGetVideoHeight;
extern pFunc_bfcGetVideoBytesPerLineV2 bfcGetVideoBytesPerLineV2;
extern pFunc_bfcGetVideoBytesPerFrame bfcGetVideoBytesPerFrame;
extern pFunc_bfcGetVideoBytesPerFrameGolden bfcGetVideoBytesPerFrameGolden;
extern pFunc_bfcGetVideoInfo bfcGetVideoInfo;
extern pFunc_bfcGetVancWidth bfcGetVancWidth;
extern pFunc_bfcGetVancHeight bfcGetVancHeight;
extern pFunc_bfcGetVancBytesPerLineV2 bfcGetVancBytesPerLineV2;
extern pFunc_bfcGetVancBytesPerFrame bfcGetVancBytesPerFrame;
extern pFunc_bfcGetVancInfo bfcGetVancInfo;
extern pFunc_bfcGetBytesForGroupPixels bfcGetBytesForGroupPixels;
#if defined(_WIN32)
extern pFunc_bfcGetWindowsDriverHandle bfcGetWindowsDriverHandle;
extern pFunc_bfcSetDynamicMemoryFormatChange bfcSetDynamicMemoryFormatChange;
#elif defined(__linux__)
extern pFunc_bfcGetFileHandle bfcGetFileHandle;
#endif
extern pFunc_bfcGetSdiConnectorSignalInfo bfcGetSdiConnectorSignalInfo;

#if defined(LOAD_FUNC_PTR_V6_5_0)
extern pFunc_bfcAutoCaptureCreateInternalBuffers bfcAutoCaptureCreateInternalBuffers;
extern pFunc_bfcAutoCaptureDestroyInternalBuffers bfcAutoCaptureDestroyInternalBuffers;
extern pFunc_bfcAutoCaptureRegisterExternalBuffer bfcAutoCaptureRegisterExternalBuffer;
extern pFunc_bfcAutoCaptureRegisterExternalBufferArray bfcAutoCaptureRegisterExternalBufferArray;
extern pFunc_bfcAutoCaptureRemoveExternalBuffersFromPool bfcAutoCaptureRemoveExternalBuffersFromPool;
extern pFunc_bfcAutoCaptureGetFilledBuffer bfcAutoCaptureGetFilledBuffer;
extern pFunc_bfcAutoCaptureReturnBuffer bfcAutoCaptureReturnBuffer;
extern pFunc_bfcWaitExternalLtcInputSync bfcWaitExternalLtcInputSync;
extern pFunc_bfcGetMaximumOutputPhaseOffset bfcGetMaximumOutputPhaseOffset;
extern pFunc_bfcGetMaximumOutputPhaseSettings bfcGetMaximumOutputPhaseSettings;
extern pFunc_bfcSetOutputPhaseOffset bfcSetOutputPhaseOffset;
extern pFunc_bfcGetOutputPhaseOffset bfcGetOutputPhaseOffset;
extern pFunc_bfcSetOutputPhaseOffsetTimeDelay bfcSetOutputPhaseOffsetTimeDelay;
extern pFunc_bfcSetOutputPhaseOffsetPixels bfcSetOutputPhaseOffsetPixels;
#endif

/* BlueVelvetC utils functions */
extern pFunc_bfAlloc bfAlloc;
extern pFunc_bfFree bfFree;
extern pFunc_bfcUtilsGetStringForCardType bfcUtilsGetStringForCardType;
extern pFunc_bfcUtilsGetWStringForCardType bfcUtilsGetWStringForCardType;
extern pFunc_bfcUtilsGetStringForBlueProductId bfcUtilsGetStringForBlueProductId;
extern pFunc_bfcUtilsGetWStringForBlueProductId bfcUtilsGetWStringForBlueProductId;
extern pFunc_bfcUtilsGetStringForVideoMode bfcUtilsGetStringForVideoMode;
extern pFunc_bfcUtilsGetWStringForVideoMode bfcUtilsGetWStringForVideoMode;
extern pFunc_bfcUtilsGetStringForMemoryFormat bfcUtilsGetStringForMemoryFormat;
extern pFunc_bfcUtilsGetWStringForMemoryFormat bfcUtilsGetWStringForMemoryFormat;
extern pFunc_bfcUtilsGetStringForUpdateFormat bfcUtilsGetStringForUpdateFormat;
extern pFunc_bfcUtilsGetWStringForUpdateFormat bfcUtilsGetWStringForUpdateFormat;
extern pFunc_bfcUtilsGetStringForVideoEngine bfcUtilsGetStringForVideoEngine;
extern pFunc_bfcUtilsGetWStringForVideoEngine bfcUtilsGetWStringForVideoEngine;
extern pFunc_bfcUtilsGetStringForMr2Node bfcUtilsGetStringForMr2Node;
extern pFunc_bfcUtilsGetWStringForMr2Node bfcUtilsGetWStringForMr2Node;
extern pFunc_bfcUtilsGetMR2Routing bfcUtilsGetMR2Routing;
extern pFunc_bfcUtilsSetMR2Routing bfcUtilsSetMR2Routing;
extern pFunc_bfcUtilsGetAudioOutputRouting bfcUtilsGetAudioOutputRouting;
extern pFunc_bfcUtilsSetAudioOutputRouting bfcUtilsSetAudioOutputRouting;
extern pFunc_bfcUtilsIsVideoModeProgressive bfcUtilsIsVideoModeProgressive;
extern pFunc_bfcUtilsIsVideoModePsF bfcUtilsIsVideoModePsF;
extern pFunc_bfcUtilsIsVideoMode1001Framerate bfcUtilsIsVideoMode1001Framerate;
extern pFunc_bfcUtilsGetFpsForVideoMode bfcUtilsGetFpsForVideoMode;
extern pFunc_bfcUtilsGetVideoModeExtForFrameInfoV2 bfcUtilsGetVideoModeExtForFrameInfoV2;
extern pFunc_bfcUtilsGetFrameInfoForVideoModeExtV2 bfcUtilsGetFrameInfoForVideoModeExtV2;
extern pFunc_bfcUtilsGetAudioSamplesPerFrame bfcUtilsGetAudioSamplesPerFrame;
extern pFunc_bfcUtilsInitVancBuffer bfcUtilsInitVancBuffer;
extern pFunc_bfcUtilsVancPktExtract bfcUtilsVancPktExtract;
extern pFunc_bfcUtilsVancPktInsert bfcUtilsVancPktInsert;
extern pFunc_bfcUtilsDecodeEia708bPkt bfcUtilsDecodeEia708bPkt;
extern pFunc_bfcUtilsConvertVideoChannelToMr2Node bfcUtilsConvertVideoChannelToMr2Node;
extern pFunc_bfcUtilsConvertMr2NodeToBlueConnectorId bfcUtilsConvertMr2NodeToBlueConnectorId;
#if defined(LOAD_FUNC_PTR_V6_5_0)
extern pFunc_bfcUtilsGetDeviceCount bfcUtilsGetDeviceCount;
extern pFunc_bfcUtilsGetDeviceInfo bfcUtilsGetDeviceInfo;
extern pFunc_bfcUtilsConvertFrameCountToRP188TimeCode bfcUtilsConvertFrameCountToRP188TimeCode;
extern pFunc_bfcUtilsGetDefaultSetupInfoInput  bfcUtilsGetDefaultSetupInfoInput;
extern pFunc_bfcUtilsGetDefaultSetupInfoOutput bfcUtilsGetDefaultSetupInfoOutput;
extern pFunc_bfcUtilsValidateSetupInfo bfcUtilsValidateSetupInfo;
extern pFunc_bfcUtilsGetRecommendedSetupInfoInput bfcUtilsGetRecommendedSetupInfoInput;
extern pFunc_bfcUtilsSetupInput  bfcUtilsSetupInput;
extern pFunc_bfcUtilsSetupOutput bfcUtilsSetupOutput;
extern pFunc_bfcUtilsGetStringForSignalLinkType bfcUtilsGetStringForSignalLinkType;
extern pFunc_bfcUtilsGetWStringForSignalLinkType bfcUtilsGetWStringForSignalLinkType;
extern pFunc_bfcUtilsGetStringForVideoChannel bfcUtilsGetStringForVideoChannel;
extern pFunc_bfcUtilsGetWStringForVideoChannel bfcUtilsGetWStringForVideoChannel;
extern pFunc_bfcUtilsGetStringForSignalFormatType bfcUtilsGetStringForSignalFormatType;
extern pFunc_bfcUtilsGetWStringForSignalFormatType bfcUtilsGetWStringForSignalFormatType;
extern pFunc_bfcUtilsGetStringForSignalColorSpace bfcUtilsGetStringForSignalColorSpace;
extern pFunc_bfcUtilsGetWStringForSignalColorSpace bfcUtilsGetWStringForSignalColorSpace;
extern pFunc_bfcUtilsGetStringForTransportType bfcUtilsGetStringForTransportType;
extern pFunc_bfcUtilsGeWtStringForTransportType bfcUtilsGeWtStringForTransportType;
extern pFunc_bfcUtilsGetStringForSubImageMapping bfcUtilsGetStringForSubImageMapping;
extern pFunc_bfcUtilsGetWStringForSubImageMapping bfcUtilsGetWStringForSubImageMapping;
extern pFunc_bfcUtilsGetStringForDataRange bfcUtilsGetStringForDataRange;
extern pFunc_bfcUtilsGetWStringForDataRange bfcUtilsGetWStringForDataRange;
extern pFunc_bfcUtilsGetStringForTransportSampling bfcUtilsGetStringForTransportSampling;
extern pFunc_bfcUtilsGetWStringForTransportSampling bfcUtilsGetWStringForTransportSampling;
extern pFunc_bfcUtilsGetStringForTransportColorSpace bfcUtilsGetStringForTransportColorSpace;
extern pFunc_bfcUtilsGetWStringForTransportColorSpace bfcUtilsGetWStringForTransportColorSpace;
extern pFunc_bfcUtilsGetStringForColorimetry bfcUtilsGetStringForColorimetry;
extern pFunc_bfcUtilsGetWStringForColorimetry bfcUtilsGetWStringForColorimetry;
extern pFunc_bfcUtilsGetStringForTransferFunc bfcUtilsGetStringForTransferFunc;
extern pFunc_bfcUtilsGetWStringForTransferFunc bfcUtilsGetWStringForTransferFunc;
extern pFunc_bfcUtilsGetStringForBErr bfcUtilsGetStringForBErr;
extern pFunc_bfcUtilsGetWStringForBErr bfcUtilsGetWStringForBErr;
extern pFunc_bfcUtilsGetStringForReferenceSource bfcUtilsGetStringForReferenceSource;
extern pFunc_bfcUtilsGetWStringForReferenceSource bfcUtilsGetWStringForReferenceSource;
extern pFunc_bfcUtilsGetStringForBFLockSignalType bfcUtilsGetStringForBFLockSignalType;
extern pFunc_bfcUtilsGetWStringForBFLockSignalType bfcUtilsGetWStringForBFLockSignalType;
extern pFunc_bfcUtilsConvertMr2NodeToVideoChannel bfcUtilsConvertMr2NodeToVideoChannel;
extern pFunc_bfcUtilsConvertTimeDelayToOutputPhaseOffset bfcUtilsConvertTimeDelayToOutputPhaseOffset;
extern pFunc_bfcUtilsConvertPixelOffsetToOutputPhaseOffset bfcUtilsConvertPixelOffsetToOutputPhaseOffset;
extern pFunc_bfcUtilsConvertOutputPhaseOffsetToPixelOffset bfcUtilsConvertOutputPhaseOffsetToPixelOffset;
extern pFunc_bfcUtilsConvertOutputPhaseOffsetToTimeDelay bfcUtilsConvertOutputPhaseOffsetToTimeDelay;
#endif
#if defined(LOAD_FUNC_PTR_V6_5_1)
extern pFunc_bfcUtilsInitVancBufferV2 bfcUtilsInitVancBufferV2;
extern pFunc_bfcUtilsGetStringForConversionType;
extern pFunc_bfcUtilsGetWStringForConversionType;
#endif
#if defined(LOAD_FUNC_PTR_V6_5_3)
extern pFunc_bfcUtilsGetSetupInfoForInputSignal bfcUtilsGetSetupInfoForInputSignal;
extern pFunc_bfcUtilsGetStringForColorDiff bfcUtilsGetStringForColorDiff;
extern pFunc_bfcUtilsGetWStringForColorDiff bfcUtilsGetWStringForColorDiff;
extern pFunc_bfcGetPcbSerialNumber bfcGetPcbSerialNumber;
#endif

extern bool LoadFunctionPointersBasic_BlueVelvetC();
extern bool LoadFunctionPointers_BlueVelvetC();



/* BLUEVELVETC CONVERSION FUNCTIONS */
extern pFunc_bfcConversionFactory                                   bfcConversionFactory;
extern pFunc_bfcConversionDestroy                                   bfcConversionDestroy;
extern pFunc_bfcConversionGetAvailableThreadCount                   bfcConversionGetAvailableThreadCount;
extern pFunc_bfcConversionSetThreadCountLimit                       bfcConversionSetThreadCountLimit;
extern pFunc_bfcConvert_SquareDivisionToTsi_2VUY                    bfcConvert_SquareDivisionToTsi_2VUY;
extern pFunc_bfcConvert_SquareDivisionToTsi_V210                    bfcConvert_SquareDivisionToTsi_V210;
extern pFunc_bfcConvert_SquareDivisionToTsi_ARGB32                  bfcConvert_SquareDivisionToTsi_ARGB32;
extern pFunc_bfcConvert_SquareDivisionToTsi_RGB                     bfcConvert_SquareDivisionToTsi_RGB;
extern pFunc_bfcConvert_SquareDivisionToTsi_BGR48                   bfcConvert_SquareDivisionToTsi_BGR48;
extern pFunc_bfcConvert_TsiToSquareDivision_2VUY                    bfcConvert_TsiToSquareDivision_2VUY;
extern pFunc_bfcConvert_TsiToSquareDivision_V210                    bfcConvert_TsiToSquareDivision_V210;
extern pFunc_bfcConvert_TsiToSquareDivision_ARGB32                  bfcConvert_TsiToSquareDivision_ARGB32;
extern pFunc_bfcConvert_TsiToSquareDivision_RGB                     bfcConvert_TsiToSquareDivision_RGB;
extern pFunc_bfcConvert_TsiToSquareDivision_BGR48                   bfcConvert_TsiToSquareDivision_BGR48;
extern pFunc_bfcConvert_Single4KV210ToAligned4KV210Quadrants_SSE2   bfcConvert_Single4KV210ToAligned4KV210Quadrants_SSE2;
extern pFunc_bfcConvert_Single4KV210AlignedQuadrantsToNative4KV210  bfcConvert_Single4KV210AlignedQuadrantsToNative4KV210;
extern pFunc_bfcConvert_HalfFloatRGBATo16bitRGBA                    bfcConvert_HalfFloatRGBATo16bitRGBA;
extern pFunc_bfcConvert_HalfFloatRGBATo16bitRGB                     bfcConvert_HalfFloatRGBATo16bitRGB;
extern pFunc_bfcConvert_FloatRGBATo16bitRGBA                        bfcConvert_FloatRGBATo16bitRGBA;
extern pFunc_bfcConvert_FloatRGBATo16bitRGB                         bfcConvert_FloatRGBATo16bitRGB;
#if defined(LOAD_FUNC_PTR_V6_5_0)
extern pFunc_bfcConvert_YUVSTo8bitRGBA                              bfcConvert_YUVSTo8bitRGBA;
extern pFunc_bfcConvert_2VUYTo8bitRGBA                              bfcConvert_2VUYTo8bitRGBA;
extern pFunc_bfcConvert_V210To8bitRGBA                              bfcConvert_V210To8bitRGBA;
extern pFunc_bfcConvert_V210To8bitRGB                               bfcConvert_V210To8bitRGB;
//extern pFunc_bfcConvert_V216To8bitRGBA                              bfcConvert_V216To8bitRGBA;
//extern pFunc_bfcConvert_Y216To8bitRGBA                              bfcConvert_Y216To8bitRGBA;
//extern pFunc_bfcConvert_CineonLETo8bitRGBA                          bfcConvert_CineonLETo8bitRGBA;
#endif
#if defined(LOAD_FUNC_PTR_V6_5_1)
extern pFunc_bfcConvert_SquareDivisionToTsi_BGRA64                  bfcConvert_SquareDivisionToTsi_BGRA64;
extern pFunc_bfcConvert_TsiToSquareDivision_BGRA64                  bfcConvert_TsiToSquareDivision_BGRA64;
extern pFunc_bfcConvert_SquareDivisionToTsi_V216                    bfcConvert_SquareDivisionToTsi_V216;
extern pFunc_bfcConvert_SquareDivisionToTsi_Y216                    bfcConvert_SquareDivisionToTsi_Y216;
extern pFunc_bfcConvert_SquareDivisionToTsi_CineonLE                bfcConvert_SquareDivisionToTsi_CineonLE;
extern pFunc_bfcConvert_TsiToSquareDivision_V216                    bfcConvert_TsiToSquareDivision_V216;
extern pFunc_bfcConvert_TsiToSquareDivision_Y216                    bfcConvert_TsiToSquareDivision_Y216;
extern pFunc_bfcConvert_TsiToSquareDivision_CineonLE                bfcConvert_TsiToSquareDivision_CineonLE;
#endif
#if defined(LOAD_FUNC_PTR_V6_5_3)
extern pFunc_bfcConvert_VUYATo8bitRGBA                              bfcConvert_VUYATo8bitRGBA;
#endif
extern bool LoadFunctionPointers_BlueConversion();

