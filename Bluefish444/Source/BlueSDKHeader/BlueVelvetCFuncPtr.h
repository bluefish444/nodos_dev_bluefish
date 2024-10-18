/*
  Copyright (c) Bluefish444. All rights reserved.

  NOTE: Please add
        #define IMPLEMENTATION_BLUEVELVETC_FUNC_PTR
        before including this file so that all the SDK functions are defined
        in your project. If including this header files from multiple c/c++
        files make sure that only one c/c++ file which includs this header
        file defines IMPLEMENTATION_BLUEVELVETC_FUNC_PTR
        For V6.5.1 function support please also define
        #define LOAD_FUNC_PTR_V6_5_1 before including this file

        #define IMPLEMENTATION_BLUEVELVETC_CONVERSION_FUNC_PTR
        before including this file so that all conversion functions are defined
        in your project. If including this header files from multiple c/c++
        files make sure that only one c/c++ file which includs this header
        file defines IMPLEMENTATION_BLUEVELVETC_CONVERSION_FUNC_PTR
*/

#ifndef HG_BLUEVELVETC_FUNC_PTR
#define HG_BLUEVELVETC_FUNC_PTR


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

#if defined (_WIN32)
    #define GET_PROCADDR_FOR_FUNC(module, available, name)\
    {\
      name = (pFunc_##name)GetProcAddress(module, #name);\
      if(!name)\
      {\
        *available = false;\
        OutputDebugStringA(#name);\
      }\
    }
    
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #include <Windows.h>
    #include "BlueDriver_p.h"
#elif defined (__linux__)
    #define GET_PROCADDR_FOR_FUNC(module, available, name) { name = (pFunc_##name)dlsym(module, #name); if(!name) { *available = false; } }

    #include <dlfcn.h>
    #define __cdecl

    #include "../../hal/BlueTypes.h"
    #include "../../hal/BlueDriver_p.h"

#endif


typedef void* BLUEVELVETC_HANDLE;
typedef void* BFC_SYNC_INFO;
#define BLUE_OK(a)      (!a)    /* Test for succcess of a method returning BErr */
#define BLUE_FAIL(a)    (a)     /* Test for failure of a method returning BErr */


/* FUNCTION PROTOTYPES FOR BLUEVELVETC */
#if defined(__cplusplus)
extern "C" {
#endif
    typedef const char* (__cdecl *pFunc_bfcGetVersion)();
    typedef const wchar_t* (__cdecl *pFunc_bfcGetVersionW)();
    typedef BLUEVELVETC_HANDLE(__cdecl *pFunc_bfcFactory)();
    typedef BLUE_VOID(__cdecl *pFunc_bfcDestroy)(BLUEVELVETC_HANDLE pHandle);
    typedef BErr(__cdecl *pFunc_bfcEnumerate)(BLUEVELVETC_HANDLE pHandle, BLUE_S32* pDeviceCount);
    typedef BErr(__cdecl *pFunc_bfcQueryCardType)(BLUEVELVETC_HANDLE pHandle, BLUE_S32* pCardType, BLUE_S32 DeviceID);
    typedef BErr(__cdecl *pFunc_bfcAttach)(BLUEVELVETC_HANDLE pHandle, BLUE_S32 DeviceId);
    typedef BErr(__cdecl *pFunc_bfcSetMultiLinkMode)(BLUEVELVETC_HANDLE pHandle, blue_multi_link_info_struct* pMultiLinkInfo);
    typedef BErr(__cdecl *pFunc_bfcQueryMultiLinkMode)(BLUEVELVETC_HANDLE pHandle, blue_multi_link_info_struct* pMultiLinkInfo);
    typedef BErr(__cdecl *pFunc_bfcDetach)(BLUEVELVETC_HANDLE pHandle);
    typedef BErr(__cdecl *pFunc_bfcQueryCardProperty32)(BLUEVELVETC_HANDLE pHandle, const BLUE_S32 Property, BLUE_U32* pValue32);
    typedef BErr(__cdecl *pFunc_bfcSetCardProperty32)(BLUEVELVETC_HANDLE pHandle, const BLUE_S32 Property, const BLUE_U32 Value32);
    typedef BErr(__cdecl *pFunc_bfcQueryCardProperty64)(BLUEVELVETC_HANDLE pHandle, const BLUE_S32 Property, BLUE_U64* pValue64);
    typedef BErr(__cdecl *pFunc_bfcSetCardProperty64)(BLUEVELVETC_HANDLE pHandle, const BLUE_S32 Property, const BLUE_U64 Value64);
    typedef BErr(__cdecl *pFunc_bfcGetCardSerialNumber)(BLUEVELVETC_HANDLE pHandle, BLUE_S8* pSerialNumber, BLUE_U32 StringSize);
    typedef BErr(__cdecl *pFunc_bfcGetCardHwFwVersions)(BLUEVELVETC_HANDLE pHandle, hardware_firmware_versions* pVersions);
    typedef BErr(__cdecl *pFunc_bfcGetSdiConnectorSignalInfo)(BLUEVELVETC_HANDLE pHandle, EBlueConnectorIdentifier ConnectorId, sdi_connector_signal_info* pInfo);
    typedef BErr(__cdecl *pFunc_bfcWaitVideoSync)(BLUEVELVETC_HANDLE pHandle, sync_options* pSyncData, BFC_SYNC_INFO SyncInfo);
    typedef BErr(__cdecl *pFunc_bfcWaitVideoInputSync)(BLUEVELVETC_HANDLE pHandle, unsigned long UpdateType, unsigned long* pFieldCount);
    typedef BErr(__cdecl *pFunc_bfcWaitVideoOutputSync)(BLUEVELVETC_HANDLE pHandle, unsigned long UpdateType, unsigned long* pFieldCount);
    typedef BErr(__cdecl *pFunc_bfcGetVideoOutputCurrentFieldCount)(BLUEVELVETC_HANDLE pHandle, unsigned long* pFieldCount);
    typedef BErr(__cdecl *pFunc_bfcGetVideoInputCurrentFieldCount)(BLUEVELVETC_HANDLE pHandle, unsigned long* pFieldCount);
    typedef BErr(__cdecl *pFunc_bfcVideoCaptureStart)(BLUEVELVETC_HANDLE pHandle);
    typedef BErr(__cdecl *pFunc_bfcVideoCaptureStop)(BLUEVELVETC_HANDLE pHandle);
    typedef BErr(__cdecl *pFunc_bfcVideoPlaybackStart)(BLUEVELVETC_HANDLE pHandle, BLUE_S32 Step, BLUE_S32 Loop);
    typedef BErr(__cdecl *pFunc_bfcVideoPlaybackStop)(BLUEVELVETC_HANDLE pHandle, BLUE_S32 Wait, BLUE_S32 Flush);
    typedef BErr(__cdecl *pFunc_bfcVideoPlaybackAllocate)(BLUEVELVETC_HANDLE pHandle, BLUE_VOID** pAddress, unsigned long* pBufferID, unsigned long* pUnderrun);
    typedef BErr(__cdecl *pFunc_bfcVideoPlaybackPresent)(BLUEVELVETC_HANDLE pHandle, unsigned long* UniqueID, unsigned long BufferID, unsigned long Count, BLUE_S32 Keep, BLUE_S32 Odd);
    typedef BErr(__cdecl *pFunc_bfcVideoPlaybackRelease)(BLUEVELVETC_HANDLE pHandle, unsigned long BufferID);
#if defined (_WIN32)
    typedef BErr(__cdecl *pFunc_bfcGetCaptureVideoFrameInfoEx)(BLUEVELVETC_HANDLE pHandle, OVERLAPPED* pOverlap, struct blue_videoframe_info_ex* pVideoFrameInfo, BLUE_S32 iCompostLater, BLUE_U32* CaptureFifoSize);
#elif defined(__linux__)
    typedef BErr(__cdecl *pFunc_bfcGetCaptureVideoFrameInfoEx)(BLUEVELVETC_HANDLE pHandle, struct blue_videoframe_info_ex* pVideoFrameInfo);
#endif
    typedef BErr(__cdecl *pFunc_bfcRenderBufferCapture)(BLUEVELVETC_HANDLE pHandle, unsigned long BufferID);
    typedef BErr(__cdecl *pFunc_bfcRenderBufferUpdate)(BLUEVELVETC_HANDLE pHandle, unsigned long BufferID);
    typedef BErr(__cdecl *pFunc_bfcGetRenderBufferCount)(BLUEVELVETC_HANDLE pHandle, unsigned long* pCount);
    typedef BErr(__cdecl *pFunc_bfcEncodeHancFrameEx)(BLUEVELVETC_HANDLE pHandle, BLUE_U32 CardType, struct hanc_stream_info_struct* pHancEncodeInfo, BLUE_VOID* pAudioBuffer, BLUE_U32 AudioChannels, BLUE_U32 AudioSamples, BLUE_U32 SampleType, BLUE_U32 AudioFlags);
    typedef BErr(__cdecl *pFunc_bfcEncodeHancFrameWithUCZ)(BLUEVELVETC_HANDLE pHandle, BLUE_U32 CardType, struct hanc_stream_info_struct* pHancEncodeInfo, BLUE_VOID* pAudioBuffer, BLUE_U32 AudioChannels, BLUE_U32 AudioSamples, BLUE_U32 SampleType, BLUE_U8* pUCZBuffer);
    typedef BErr(__cdecl *pFunc_bfcDecodeHancFrameEx)(BLUEVELVETC_HANDLE pHandle, BLUE_U32 CardType, BLUE_U32* pHancBuffer, struct hanc_decode_struct* pHancDecodeInfo);
    typedef BFC_SYNC_INFO(__cdecl *pFunc_bfcSyncInfoCreate)(BLUEVELVETC_HANDLE pHandle);
    typedef BErr(__cdecl *pFunc_bfcSyncInfoDelete)(BLUEVELVETC_HANDLE pHandle, BFC_SYNC_INFO SyncInfo);
    typedef BErr(__cdecl *pFunc_bfcSyncInfoWait)(BLUEVELVETC_HANDLE pHandle, BFC_SYNC_INFO SyncInfo, const BLUE_U32 nTimeOutInMilliSec);
    typedef BErr(__cdecl *pFunc_bfcSyncInfoWaitWithSyncOptions)(BLUEVELVETC_HANDLE pHandle, BFC_SYNC_INFO SyncInfo, sync_options* pSyncOptions, const BLUE_U32 TimeOutInMilliSec);
    typedef BErr(__cdecl *pFunc_bfcDmaReadFromCardAsync)(BLUEVELVETC_HANDLE pHandle, BLUE_U8* pData, unsigned long Size, BFC_SYNC_INFO SyncInfo, unsigned long BufferID, unsigned long Offset);
    typedef BErr(__cdecl *pFunc_bfcDmaWriteToCardAsync)(BLUEVELVETC_HANDLE pHandle, BLUE_U8* pData, unsigned long Size, BFC_SYNC_INFO SyncInfo, unsigned long BufferID, unsigned long Offset);
    typedef BErr(__cdecl *pFunc_bfcSerialPortWaitForInputData)(BLUEVELVETC_HANDLE pHandle, BLUE_U32 PortFlags, BLUE_U32* pBufferLength);
    typedef BErr(__cdecl *pFunc_bfcSerialPortRead)(BLUEVELVETC_HANDLE pHandle, BLUE_U32 nPortFlags, BLUE_U8* pBuffer, BLUE_U32 ReadLength);
    typedef BErr(__cdecl *pFunc_bfcSerialPortWrite)(BLUEVELVETC_HANDLE pHandle, BLUE_U32 nPortFlags, BLUE_U8* pBuffer, BLUE_U32 WriteLength);
#if defined (_WIN32)
    typedef BErr(__cdecl *pFunc_bfcGetReferenceClockPhaseSettings)(BLUEVELVETC_HANDLE pHandle, BLUE_U32* pHPhase, BLUE_U32* pVPhase, BLUE_U32* pHPhaseMax, BLUE_U32* pVPhaseMax);
    typedef BErr(__cdecl *pFunc_bfcLoadOutputLUT1D)(BLUEVELVETC_HANDLE pHandle, struct blue_1d_lookup_table_struct* pLutData);
#endif
    typedef BErr(__cdecl *pFunc_bfcGetVideoWidth)(BLUE_S32 VideoMode, BLUE_U32* pWidth);
    typedef BErr(__cdecl *pFunc_bfcGetVideoHeight)(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_U32* pHeight);
    typedef BErr(__cdecl *pFunc_bfcGetVideoBytesPerLineV2)(BLUE_S32 VideoMode, BLUE_S32 MemoryFormat, BLUE_U32* pBytesPerLine);
    typedef BErr(__cdecl *pFunc_bfcGetVideoBytesPerFrame)(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pBytesPerFrame);
    typedef BErr(__cdecl *pFunc_bfcGetVideoBytesPerFrameGolden)(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pGoldenBytes);
    typedef BErr(__cdecl *pFunc_bfcGetVideoInfo)(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pWidth, BLUE_U32* pHeight, BLUE_U32* pBytesPerLine, BLUE_U32* pBytesPerFrame, BLUE_U32* pGoldenBytes);
    typedef BErr(__cdecl *pFunc_bfcGetVancWidth)(BLUE_S32 VideoMode, BLUE_U32* pWidth);
    typedef BErr(__cdecl *pFunc_bfcGetVancHeight)(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_U32* pHeight);
    typedef BErr(__cdecl *pFunc_bfcGetVancBytesPerLineV2)(BLUE_S32 VideoMode, BLUE_S32 MemoryFormat, BLUE_U32* pBytesPerLine);
    typedef BErr(__cdecl *pFunc_bfcGetVancBytesPerFrame)(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pBytesPerFrame);
    typedef BErr(__cdecl *pFunc_bfcGetVancInfo)(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pWidth, BLUE_U32* pHeight, BLUE_U32* pBytesPerLine, BLUE_U32* pBytesPerFrame);
    typedef BErr(__cdecl *pFunc_bfcGetBytesForGroupPixels)(EMemoryFormat MemoryFormat, BLUE_U32 VideoWidth, BLUE_U32* pVideoPitchBytes);
#if defined (_WIN32)
    typedef BErr(__cdecl *pFunc_bfcGetWindowsDriverHandle)(BLUEVELVETC_HANDLE pHandle, HANDLE* pDriverHandle);
    typedef BErr(__cdecl *pFunc_bfcSetDynamicMemoryFormatChange)(BLUEVELVETC_HANDLE pHandle, OVERLAPPED* pOverlap, BLUE_U32 nUniqueId, EMemoryFormat MemoryFormat);
#elif defined(__linux__)
    typedef BErr(__cdecl *pFunc_bfcGetFileHandle)(BLUEVELVETC_HANDLE pHandle, BLUE_U32* pFileHandle);
#endif

    typedef void*(__cdecl *pFunc_bfAlloc)(BLUE_U32 nMemorySize);
    typedef void(__cdecl *pFunc_bfFree)(BLUE_U32 nMemSize, BLUE_VOID* pMemory); 
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForCardType)(const BLUE_S32 CardType);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForCardType)(const BLUE_S32 CardType);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForBlueProductId)(const BLUE_U32 ProductId);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForBlueProductId)(const BLUE_U32 ProductId);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForVideoMode)(const BLUE_U32 VideoMode);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForVideoMode)(const BLUE_U32 VideoMode);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForMemoryFormat)(const BLUE_U32 MemoryFormat);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForMemoryFormat)(const BLUE_U32 MemoryFormat);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForUpdateFormat)(const BLUE_U32 UpdateFormat);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForUpdateFormat)(const BLUE_U32 UpdateFormat);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForVideoEngine)(const BLUE_U32 VideoEngine);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForVideoEngine)(const BLUE_U32 VideoEngine);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForMr2Node)(const BLUE_U32 Mr2Node);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForMr2Node)(const BLUE_U32 Mr2Node);
    typedef BErr(__cdecl *pFunc_bfcUtilsGetMR2Routing)(const BLUEVELVETC_HANDLE pHandle, BLUE_U32* pSrcNode, const BLUE_U32 DestNode, BLUE_U32* LinkType);
    typedef BErr(__cdecl *pFunc_bfcUtilsSetMR2Routing)(const BLUEVELVETC_HANDLE pHandle, const BLUE_U32 SrcNode, const BLUE_U32 DestNode, const BLUE_U32 LinkType);
    typedef BErr(__cdecl *pFunc_bfcUtilsGetAudioOutputRouting)(const BLUEVELVETC_HANDLE pHandle, const BLUE_U32 AudioConnectorType, BLUE_U32* pAudioSourceChannelId, BLUE_U32 AudioConnectorId);
    typedef BErr(__cdecl *pFunc_bfcUtilsSetAudioOutputRouting)(const BLUEVELVETC_HANDLE pHandle, const BLUE_U32 AudioConnectorType, BLUE_U32 AudioSourceChannelId, BLUE_U32 AudioConnectorId);
    typedef bool(__cdecl *pFunc_bfcUtilsIsVideoModeProgressive)(const BLUE_U32 VideoMode);
    typedef bool(__cdecl *pFunc_bfcUtilsIsVideoModePsF)(const BLUE_U32 VideoMode);
    typedef bool(__cdecl *pFunc_bfcUtilsIsVideoMode1001Framerate)(const BLUE_U32 VideoMode);
    typedef BLUE_S32(__cdecl *pFunc_bfcUtilsGetFpsForVideoMode)(const BLUE_U32 VideoMode);
    typedef BLUE_S32(__cdecl *pFunc_bfcUtilsGetVideoModeExtForFrameInfoV2)(const BLUE_U32 Width, const BLUE_U32 Height, const BLUE_U32 Rate, const BLUE_U32 bIs1001, const scan_mode ScanMode, BLUE_U32* pVideoModeExt);
    typedef BLUE_S32(__cdecl *pFunc_bfcUtilsGetFrameInfoForVideoModeExtV2)(const BLUE_U32 VideoModeExt, BLUE_U32* pWidth, BLUE_U32* pHeight, BLUE_U32* pRate, BLUE_U32* pIs1001, scan_mode* pScanmode);
    typedef BLUE_S32(__cdecl *pFunc_bfcUtilsGetAudioSamplesPerFrame)(const BLUE_U32 VideoMode, const BLUE_U32 FrameNo);
    typedef BErr(__cdecl *pFunc_bfcUtilsInitVancBuffer)(BLUE_U32 nCardType, BLUE_U32 VideoMode, BLUE_U32 PixelsPerLine, BLUE_U32 nLinesPerFrame, BLUE_U32* pVancBuffer);
    typedef BErr(__cdecl *pFunc_bfcUtilsVancPktExtract)(BLUE_U32 nCardType, BLUE_U32 nVancPktType, BLUE_U32* pSrcVancBuffer, BLUE_U32 nSrcVancBufferSize, BLUE_U32 PixelsPerLine, BLUE_U32 nVancPktDid, BLUE_U16* pVancPktSdid, BLUE_U16* pVancPktDataLength, BLUE_U16* pVancPktData, BLUE_U16* pVancPktLineNo);
    typedef BErr(__cdecl *pFunc_bfcUtilsVancPktInsert)(BLUE_U32 CardType, BLUE_U32 VancPktType, BLUE_U32 VancPktLineNumber, BLUE_U32* pVancPktBuffer, BLUE_U32 VancPktElementCount, BLUE_U32* pDestVancBuffer, BLUE_U32 PixelsPerLine);
    typedef BLUE_S32(__cdecl *pFunc_bfcUtilsDecodeEia708bPkt)(BLUE_U32 CardType, BLUE_U16* pVancPacketData, BLUE_U16 PacketUdwCount, BLUE_U16 EiaPacketSubtype, BLUE_U8* pDecodedString);
    typedef EEpochRoutingElements(__cdecl *pFunc_bfcUtilsConvertVideoChannelToMr2Node)(EBlueVideoChannel VideoChannel);
    typedef EBlueConnectorIdentifier(__cdecl *pFunc_bfcUtilsConvertMr2NodeToBlueConnectorId)(EEpochRoutingElements Mr2Node);
#if defined(LOAD_FUNC_PTR_V6_5_0)
    typedef BErr(__cdecl *pFunc_bfcAutoCaptureCreateInternalBuffers)(BLUEVELVETC_HANDLE pHandle, EBlueBufferComponent ComponentFlags);
    typedef BErr(__cdecl *pFunc_bfcAutoCaptureDestroyInternalBuffers)(BLUEVELVETC_HANDLE pHandle);
    typedef BErr(__cdecl *pFunc_bfcAutoCaptureRegisterExternalBuffer)(BLUEVELVETC_HANDLE pHandle, BLUE_VOID* pBuffer, BLUE_U32 Size, EBlueBufferComponent ComponentFlags);
    typedef BErr(__cdecl *pFunc_bfcAutoCaptureRegisterExternalBufferArray)(BLUEVELVETC_HANDLE pHandle, BLUE_VOID** ppBufferArray, BLUE_U32 ElementCount, BLUE_U32 ElementSize, EBlueBufferComponent ComponentFlags);
    typedef BErr(__cdecl *pFunc_bfcAutoCaptureRemoveExternalBuffersFromPool)(BLUEVELVETC_HANDLE pHandle);
    typedef BErr(__cdecl *pFunc_bfcAutoCaptureGetFilledBuffer)(BLUEVELVETC_HANDLE pHandle, blue_auto_buffer_info* pBufferInfo, EBlueReturnMode ReturnMode);
    typedef BErr(__cdecl *pFunc_bfcAutoCaptureReturnBuffer)(BLUEVELVETC_HANDLE pHandle, blue_auto_buffer_info* pBufferInfo);
    typedef BErr(__cdecl *pFunc_bfcWaitExternalLtcInputSync)(BLUEVELVETC_HANDLE pHandle, blue_external_ltc_input_sync_struct* pSyncStruct);
    typedef BErr(__cdecl *pFunc_bfcGetMaximumOutputPhaseOffset)(BLUE_S32 VideoMode, BLUE_U32* pMaxOffset);
    typedef BErr(__cdecl *pFunc_bfcGetMaximumOutputPhaseSettings)(BLUE_S32 VideoMode, BLUE_U32* pMaxLines, BLUE_U32* pMaxHorizontalPixelOffset, BLUE_U32* pMaxHorizontalDelayNanoseconds);
    typedef BErr(__cdecl *pFunc_bfcSetOutputPhaseOffset)(BLUEVELVETC_HANDLE pHandle, BLUE_U32 Offset);
    typedef BErr(__cdecl *pFunc_bfcGetOutputPhaseOffset)(BLUEVELVETC_HANDLE pHandle, BLUE_U32* pOffset);
    typedef BErr(__cdecl *pFunc_bfcSetOutputPhaseOffsetTimeDelay)(BLUEVELVETC_HANDLE pHandle, BLUE_U32 LineOffset, BLUE_U32 HorizontalDelayNanoseconds);
    typedef BErr(__cdecl *pFunc_bfcSetOutputPhaseOffsetPixels)(BLUEVELVETC_HANDLE pHandle, BLUE_U32 LineOffset, BLUE_U32 HorizontalPixelOffset); 
    
    typedef BLUE_S32(__cdecl *pFunc_bfcUtilsGetDeviceCount)();
    typedef BErr(__cdecl *pFunc_bfcUtilsGetDeviceInfo)(BLUE_S32 DeviceId, blue_device_info* pDeviceInfo);
    typedef BLUE_VOID(__cdecl *pFunc_bfcUtilsConvertFrameCountToRP188TimeCode)(BLUE_U32 FrameCount, BLUE_U32 FrameRate, BLUE_U32 bIsDropFrame, BLUE_U64* pRP188Vitc, BLUE_U64* pRP188Ltc);
    typedef blue_setup_info(__cdecl *pFunc_bfcUtilsGetDefaultSetupInfoInput)(EBlueVideoChannel VideoInputChannel);
    typedef blue_setup_info(__cdecl *pFunc_bfcUtilsGetDefaultSetupInfoOutput)(EBlueVideoChannel VideoOutputChannel, EVideoModeExt VideoModeExt);
    typedef BErr(__cdecl *pFunc_bfcUtilsValidateSetupInfo)(blue_setup_info* pSetupInfo);
    typedef BErr(__cdecl *pFunc_bfcUtilsGetRecommendedSetupInfoInput)(BLUEVELVETC_HANDLE pHandle, blue_setup_info* pSetupInfo, EBlueUhdPreference UhdPreference);
    typedef BErr(__cdecl *pFunc_bfcUtilsSetupInput)(BLUEVELVETC_HANDLE pHandle, blue_setup_info* pSetupInfo);
    typedef BErr(__cdecl *pFunc_bfcUtilsSetupOutput)(BLUEVELVETC_HANDLE pHandle, blue_setup_info* pSetupInfo);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForSignalLinkType)(const EBlueSignalLinkType SignalLinkType);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForSignalLinkType)(const EBlueSignalLinkType SignalLinkType);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForVideoChannel)(const EBlueVideoChannel VideoChannel);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForVideoChannel)(const EBlueVideoChannel VideoChannel);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForSignalFormatType)(const EDualLinkSignalFormatType SignalFormatType);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForSignalFormatType)(const EDualLinkSignalFormatType SignalFormatType);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForSignalColorSpace)(const EConnectorSignalColorSpace SignalColorSpace);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForSignalColorSpace)(const EConnectorSignalColorSpace SignalColorSpace);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForTransportType)(const EHdSdiTransport TransporType);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGeWtStringForTransportType)(const EHdSdiTransport TransporType);
    typedef char*(__cdecl *pFunc_bfcUtilsGetStringForSubImageMapping)(const ESubImageMapping ImageMapping);
    typedef wchar_t*(__cdecl *pFunc_bfcUtilsGetWStringForSubImageMapping)(const ESubImageMapping ImageMapping);
    typedef const char*     (__cdecl *pFunc_bfcUtilsGetStringForDataRange)(const ERGBDataRange DataRange);
    typedef const wchar_t*  (__cdecl *pFunc_bfcUtilsGetWStringForDataRange)(const ERGBDataRange DataRange);
    typedef const char*     (__cdecl *pFunc_bfcUtilsGetStringForTransportSampling)(const ETransportSampling TransportSampling);
    typedef const wchar_t*  (__cdecl *pFunc_bfcUtilsGetWStringForTransportSampling)(const ETransportSampling  TransportSampling);
    typedef const char*     (__cdecl *pFunc_bfcUtilsGetStringForTransportColorSpace)(const EConnectorSignalColorSpace TransportColorSpace);
    typedef const wchar_t*  (__cdecl *pFunc_bfcUtilsGetWStringForTransportColorSpace)(const EConnectorSignalColorSpace TransportColorSpace);
    typedef const char*     (__cdecl *pFunc_bfcUtilsGetStringForColorimetry)(const ETransportColorimetry TransportColorimetry);
    typedef const wchar_t*  (__cdecl *pFunc_bfcUtilsGetWStringForColorimetry)(const ETransportColorimetry TransportColorimetry);
    typedef const char*     (__cdecl *pFunc_bfcUtilsGetStringForTransferFunc)(const ETransportTransferFunc TransferFunc);
    typedef const wchar_t*  (__cdecl *pFunc_bfcUtilsGetWStringForTransferFunc)(const ETransportTransferFunc TransferFunc);
    typedef const char*     (__cdecl *pFunc_bfcUtilsGetStringForBErr)(const BErr ErrorCode);
    typedef const wchar_t*  (__cdecl *pFunc_bfcUtilsGetWStringForBErr)(const BErr ErrorCode);
    typedef const char*     (__cdecl *pFunc_bfcUtilsGetStringForReferenceSource)(const EBlueGenlockSource ReferenceSource);
    typedef const wchar_t*  (__cdecl *pFunc_bfcUtilsGetWStringForReferenceSource)(const EBlueGenlockSource ReferenceSource);
    typedef const char*     (__cdecl *pFunc_bfcUtilsGetStringForBFLockSignalType)(const EBFLockSignalType SignalType);
    typedef const wchar_t*  (__cdecl *pFunc_bfcUtilsGetWStringForBFLockSignalType)(const EBFLockSignalType SignalType);
    typedef EBlueVideoChannel(__cdecl *pFunc_bfcUtilsConvertMr2NodeToVideoChannel)(EEpochRoutingElements Mr2Node);
    typedef BErr(__cdecl *pFunc_bfcUtilsConvertTimeDelayToOutputPhaseOffset)(BLUE_S32 VideoMode, BLUE_U32 LineOffset, BLUE_U32 HorizontalDelayNanoseconds, BLUE_U32* pOffset);
    typedef BErr(__cdecl *pFunc_bfcUtilsConvertPixelOffsetToOutputPhaseOffset)(BLUE_S32 VideoMode, BLUE_U32 LineOffset, BLUE_U32 HorizontalPixelOffset, BLUE_U32* pOffset);
    typedef BErr(__cdecl *pFunc_bfcUtilsConvertOutputPhaseOffsetToPixelOffset)(BLUE_S32 VideoMode, BLUE_U32 Offset, BLUE_U32* pLineOffset, BLUE_U32* pHorizontalPixelOffset);
    typedef BErr(__cdecl *pFunc_bfcUtilsConvertOutputPhaseOffsetToTimeDelay)(BLUE_S32 VideoMode, BLUE_U32 Offset, BLUE_U32* pLineOffset, BLUE_U32* pHorizontalDelayNanoseconds);
#endif

#if defined(LOAD_FUNC_PTR_V6_5_1)
    typedef BErr           (__cdecl *pFunc_bfcUtilsInitVancBufferV2)(BLUE_VOID* pVancBuffer, BLUE_U32 BufferSize);
    typedef const char*    (__cdecl *pFunc_bfcUtilsGetStringForConversionType)(const EBlueConversionType ConversionType);
    typedef const wchar_t* (__cdecl *pFunc_bfcUtilsGetWStringForConversionType)(const EBlueConversionType ConversionType);
#endif

#if defined(LOAD_FUNC_PTR_V6_5_3)
    typedef BErr            (__cdecl* pFunc_bfcUtilsGetSetupInfoForInputSignal)(BLUEVELVETC_HANDLE pHandle, blue_setup_info* pSetupInfo, EBlueUhdPreference UhdPreference);
    typedef const char*     (__cdecl* pFunc_bfcUtilsGetStringForColorDiff)(const EBlueColorDiff ColorDiff);
    typedef const wchar_t*  (__cdecl* pFunc_bfcUtilsGetWStringForColorDiff)(const EBlueColorDiff ColorDiff);
    typedef BErr            (__cdecl* pFunc_bfcGetPcbSerialNumber)(BLUEVELVETC_HANDLE pHandle, BLUE_S8* pSerialNumber, BLUE_U32 StringSize);
#endif

#if defined(__cplusplus)
}   /*  extern "C" */
#endif

#ifdef IMPLEMENTATION_BLUEVELVETC_FUNC_PTR
pFunc_bfcGetVersion bfcGetVersion;
pFunc_bfcGetVersionW bfcGetVersionW;
pFunc_bfcFactory bfcFactory;
pFunc_bfcDestroy bfcDestroy;
pFunc_bfcEnumerate bfcEnumerate;
pFunc_bfcQueryCardType bfcQueryCardType;
pFunc_bfcAttach bfcAttach;
pFunc_bfcSetMultiLinkMode bfcSetMultiLinkMode;
pFunc_bfcQueryMultiLinkMode bfcQueryMultiLinkMode;
pFunc_bfcDetach bfcDetach;
pFunc_bfcQueryCardProperty32 bfcQueryCardProperty32;
pFunc_bfcQueryCardProperty64 bfcQueryCardProperty64;
pFunc_bfcSetCardProperty32 bfcSetCardProperty32;
pFunc_bfcSetCardProperty64 bfcSetCardProperty64;
pFunc_bfcGetCardSerialNumber bfcGetCardSerialNumber;
pFunc_bfcGetCardHwFwVersions bfcGetCardHwFwVersions;
pFunc_bfcWaitVideoSync  bfcWaitVideoSync;
pFunc_bfcWaitVideoInputSync bfcWaitVideoInputSync;
pFunc_bfcWaitVideoOutputSync bfcWaitVideoOutputSync;
pFunc_bfcGetVideoOutputCurrentFieldCount bfcGetVideoOutputCurrentFieldCount;
pFunc_bfcGetVideoInputCurrentFieldCount bfcGetVideoInputCurrentFieldCount;
pFunc_bfcVideoCaptureStart bfcVideoCaptureStart;
pFunc_bfcVideoCaptureStop bfcVideoCaptureStop;
pFunc_bfcVideoPlaybackStart bfcVideoPlaybackStart;
pFunc_bfcVideoPlaybackStop bfcVideoPlaybackStop;
pFunc_bfcVideoPlaybackAllocate bfcVideoPlaybackAllocate;
pFunc_bfcVideoPlaybackPresent bfcVideoPlaybackPresent;
pFunc_bfcVideoPlaybackRelease bfcVideoPlaybackRelease;
pFunc_bfcGetCaptureVideoFrameInfoEx bfcGetCaptureVideoFrameInfoEx;
pFunc_bfcRenderBufferCapture bfcRenderBufferCapture;
pFunc_bfcRenderBufferUpdate bfcRenderBufferUpdate;
pFunc_bfcGetRenderBufferCount bfcGetRenderBufferCount;
pFunc_bfcEncodeHancFrameEx bfcEncodeHancFrameEx;
pFunc_bfcEncodeHancFrameWithUCZ bfcEncodeHancFrameWithUCZ;
pFunc_bfcDecodeHancFrameEx bfcDecodeHancFrameEx;
pFunc_bfcSyncInfoCreate bfcSyncInfoCreate;
pFunc_bfcSyncInfoDelete bfcSyncInfoDelete;
pFunc_bfcSyncInfoWait bfcSyncInfoWait;
pFunc_bfcSyncInfoWaitWithSyncOptions bfcSyncInfoWaitWithSyncOptions;
pFunc_bfcDmaReadFromCardAsync bfcDmaReadFromCardAsync;
pFunc_bfcDmaWriteToCardAsync bfcDmaWriteToCardAsync;
pFunc_bfcSerialPortWaitForInputData bfcSerialPortWaitForInputData;
pFunc_bfcSerialPortRead bfcSerialPortRead;
pFunc_bfcSerialPortWrite bfcSerialPortWrite;
#if defined(_WIN32)
pFunc_bfcGetReferenceClockPhaseSettings bfcGetReferenceClockPhaseSettings;
pFunc_bfcLoadOutputLUT1D bfcLoadOutputLUT1D;
#endif
pFunc_bfcGetVideoWidth bfcGetVideoWidth;
pFunc_bfcGetVideoHeight bfcGetVideoHeight;
pFunc_bfcGetVideoBytesPerLineV2 bfcGetVideoBytesPerLineV2;
pFunc_bfcGetVideoBytesPerFrame bfcGetVideoBytesPerFrame;
pFunc_bfcGetVideoBytesPerFrameGolden bfcGetVideoBytesPerFrameGolden;
pFunc_bfcGetVideoInfo bfcGetVideoInfo;
pFunc_bfcGetVancWidth bfcGetVancWidth;
pFunc_bfcGetVancHeight bfcGetVancHeight;
pFunc_bfcGetVancBytesPerLineV2 bfcGetVancBytesPerLineV2;
pFunc_bfcGetVancBytesPerFrame bfcGetVancBytesPerFrame;
pFunc_bfcGetVancInfo bfcGetVancInfo;
pFunc_bfcGetBytesForGroupPixels bfcGetBytesForGroupPixels;
#if defined(_WIN32)
pFunc_bfcGetWindowsDriverHandle bfcGetWindowsDriverHandle;
pFunc_bfcSetDynamicMemoryFormatChange bfcSetDynamicMemoryFormatChange;
#elif defined(__linux__)
pFunc_bfcGetFileHandle bfcGetFileHandle;
#endif
pFunc_bfcGetSdiConnectorSignalInfo bfcGetSdiConnectorSignalInfo;

/* BlueVelvetC utils functions */
pFunc_bfAlloc bfAlloc;
pFunc_bfFree bfFree;
pFunc_bfcUtilsGetStringForCardType bfcUtilsGetStringForCardType;
pFunc_bfcUtilsGetWStringForCardType bfcUtilsGetWStringForCardType;
pFunc_bfcUtilsGetStringForBlueProductId bfcUtilsGetStringForBlueProductId;
pFunc_bfcUtilsGetWStringForBlueProductId bfcUtilsGetWStringForBlueProductId;
pFunc_bfcUtilsGetStringForVideoMode bfcUtilsGetStringForVideoMode;
pFunc_bfcUtilsGetWStringForVideoMode bfcUtilsGetWStringForVideoMode;
pFunc_bfcUtilsGetStringForMemoryFormat bfcUtilsGetStringForMemoryFormat;
pFunc_bfcUtilsGetWStringForMemoryFormat bfcUtilsGetWStringForMemoryFormat;
pFunc_bfcUtilsGetStringForUpdateFormat bfcUtilsGetStringForUpdateFormat;
pFunc_bfcUtilsGetWStringForUpdateFormat bfcUtilsGetWStringForUpdateFormat;
pFunc_bfcUtilsGetStringForVideoEngine bfcUtilsGetStringForVideoEngine;
pFunc_bfcUtilsGetWStringForVideoEngine bfcUtilsGetWStringForVideoEngine;
pFunc_bfcUtilsGetStringForMr2Node bfcUtilsGetStringForMr2Node;
pFunc_bfcUtilsGetWStringForMr2Node bfcUtilsGetWStringForMr2Node;
pFunc_bfcUtilsGetMR2Routing bfcUtilsGetMR2Routing;
pFunc_bfcUtilsSetMR2Routing bfcUtilsSetMR2Routing;
pFunc_bfcUtilsGetAudioOutputRouting bfcUtilsGetAudioOutputRouting;
pFunc_bfcUtilsSetAudioOutputRouting bfcUtilsSetAudioOutputRouting;
pFunc_bfcUtilsIsVideoModeProgressive bfcUtilsIsVideoModeProgressive;
pFunc_bfcUtilsIsVideoModePsF bfcUtilsIsVideoModePsF;
pFunc_bfcUtilsIsVideoMode1001Framerate bfcUtilsIsVideoMode1001Framerate;
pFunc_bfcUtilsGetFpsForVideoMode bfcUtilsGetFpsForVideoMode;
pFunc_bfcUtilsGetVideoModeExtForFrameInfoV2 bfcUtilsGetVideoModeExtForFrameInfoV2;
pFunc_bfcUtilsGetFrameInfoForVideoModeExtV2 bfcUtilsGetFrameInfoForVideoModeExtV2;
pFunc_bfcUtilsGetAudioSamplesPerFrame bfcUtilsGetAudioSamplesPerFrame;
pFunc_bfcUtilsInitVancBuffer bfcUtilsInitVancBuffer;
pFunc_bfcUtilsVancPktExtract bfcUtilsVancPktExtract;
pFunc_bfcUtilsVancPktInsert bfcUtilsVancPktInsert;
pFunc_bfcUtilsDecodeEia708bPkt bfcUtilsDecodeEia708bPkt;
pFunc_bfcUtilsConvertVideoChannelToMr2Node bfcUtilsConvertVideoChannelToMr2Node;
pFunc_bfcUtilsConvertMr2NodeToBlueConnectorId bfcUtilsConvertMr2NodeToBlueConnectorId;

#if defined(LOAD_FUNC_PTR_V6_5_0)
pFunc_bfcAutoCaptureCreateInternalBuffers bfcAutoCaptureCreateInternalBuffers;
pFunc_bfcAutoCaptureDestroyInternalBuffers bfcAutoCaptureDestroyInternalBuffers;
pFunc_bfcAutoCaptureRegisterExternalBuffer bfcAutoCaptureRegisterExternalBuffer;
pFunc_bfcAutoCaptureRegisterExternalBufferArray bfcAutoCaptureRegisterExternalBufferArray;
pFunc_bfcAutoCaptureRemoveExternalBuffersFromPool bfcAutoCaptureRemoveExternalBuffersFromPool;
pFunc_bfcAutoCaptureGetFilledBuffer bfcAutoCaptureGetFilledBuffer;
pFunc_bfcAutoCaptureReturnBuffer bfcAutoCaptureReturnBuffer;
pFunc_bfcWaitExternalLtcInputSync bfcWaitExternalLtcInputSync;
pFunc_bfcGetMaximumOutputPhaseOffset bfcGetMaximumOutputPhaseOffset;
pFunc_bfcGetMaximumOutputPhaseSettings bfcGetMaximumOutputPhaseSettings;
pFunc_bfcSetOutputPhaseOffset bfcSetOutputPhaseOffset;
pFunc_bfcGetOutputPhaseOffset bfcGetOutputPhaseOffset;
pFunc_bfcSetOutputPhaseOffsetTimeDelay bfcSetOutputPhaseOffsetTimeDelay;
pFunc_bfcSetOutputPhaseOffsetPixels bfcSetOutputPhaseOffsetPixels; 

pFunc_bfcUtilsGetDeviceCount bfcUtilsGetDeviceCount;
pFunc_bfcUtilsGetDeviceInfo bfcUtilsGetDeviceInfo;
pFunc_bfcUtilsConvertFrameCountToRP188TimeCode bfcUtilsConvertFrameCountToRP188TimeCode;
pFunc_bfcUtilsGetDefaultSetupInfoInput  bfcUtilsGetDefaultSetupInfoInput;
pFunc_bfcUtilsGetDefaultSetupInfoOutput bfcUtilsGetDefaultSetupInfoOutput;
pFunc_bfcUtilsValidateSetupInfo bfcUtilsValidateSetupInfo;
pFunc_bfcUtilsGetRecommendedSetupInfoInput  bfcUtilsGetRecommendedSetupInfoInput;
pFunc_bfcUtilsSetupInput  bfcUtilsSetupInput;
pFunc_bfcUtilsSetupOutput bfcUtilsSetupOutput;
pFunc_bfcUtilsGetStringForSignalLinkType bfcUtilsGetStringForSignalLinkType;
pFunc_bfcUtilsGetWStringForSignalLinkType bfcUtilsGetWStringForSignalLinkType;
pFunc_bfcUtilsGetStringForVideoChannel bfcUtilsGetStringForVideoChannel;
pFunc_bfcUtilsGetWStringForVideoChannel bfcUtilsGetWStringForVideoChannel;
pFunc_bfcUtilsGetStringForSignalFormatType bfcUtilsGetStringForSignalFormatType;
pFunc_bfcUtilsGetWStringForSignalFormatType bfcUtilsGetWStringForSignalFormatType;
pFunc_bfcUtilsGetStringForSignalColorSpace bfcUtilsGetStringForSignalColorSpace;
pFunc_bfcUtilsGetWStringForSignalColorSpace bfcUtilsGetWStringForSignalColorSpace;
pFunc_bfcUtilsGetStringForTransportType bfcUtilsGetStringForTransportType;
pFunc_bfcUtilsGeWtStringForTransportType bfcUtilsGeWtStringForTransportType;
pFunc_bfcUtilsGetStringForSubImageMapping bfcUtilsGetStringForSubImageMapping;
pFunc_bfcUtilsGetWStringForSubImageMapping bfcUtilsGetWStringForSubImageMapping;
pFunc_bfcUtilsGetStringForDataRange bfcUtilsGetStringForDataRange;
pFunc_bfcUtilsGetWStringForDataRange bfcUtilsGetWStringForDataRange;
pFunc_bfcUtilsGetStringForTransportSampling bfcUtilsGetStringForTransportSampling;
pFunc_bfcUtilsGetWStringForTransportSampling bfcUtilsGetWStringForTransportSampling;
pFunc_bfcUtilsGetStringForTransportColorSpace bfcUtilsGetStringForTransportColorSpace;
pFunc_bfcUtilsGetWStringForTransportColorSpace bfcUtilsGetWStringForTransportColorSpace;
pFunc_bfcUtilsGetStringForColorimetry bfcUtilsGetStringForColorimetry;
pFunc_bfcUtilsGetWStringForColorimetry bfcUtilsGetWStringForColorimetry;
pFunc_bfcUtilsGetStringForTransferFunc bfcUtilsGetStringForTransferFunc;
pFunc_bfcUtilsGetWStringForTransferFunc bfcUtilsGetWStringForTransferFunc;
pFunc_bfcUtilsGetStringForBErr bfcUtilsGetStringForBErr;
pFunc_bfcUtilsGetWStringForBErr bfcUtilsGetWStringForBErr;
pFunc_bfcUtilsGetStringForReferenceSource bfcUtilsGetStringForReferenceSource;
pFunc_bfcUtilsGetWStringForReferenceSource bfcUtilsGetWStringForReferenceSource;
pFunc_bfcUtilsGetStringForBFLockSignalType bfcUtilsGetStringForBFLockSignalType;
pFunc_bfcUtilsGetWStringForBFLockSignalType bfcUtilsGetWStringForBFLockSignalType;
pFunc_bfcUtilsConvertMr2NodeToVideoChannel bfcUtilsConvertMr2NodeToVideoChannel;
pFunc_bfcUtilsConvertTimeDelayToOutputPhaseOffset bfcUtilsConvertTimeDelayToOutputPhaseOffset;
pFunc_bfcUtilsConvertPixelOffsetToOutputPhaseOffset bfcUtilsConvertPixelOffsetToOutputPhaseOffset;
pFunc_bfcUtilsConvertOutputPhaseOffsetToPixelOffset bfcUtilsConvertOutputPhaseOffsetToPixelOffset;
pFunc_bfcUtilsConvertOutputPhaseOffsetToTimeDelay bfcUtilsConvertOutputPhaseOffsetToTimeDelay;
#endif

#if defined(LOAD_FUNC_PTR_V6_5_1)
pFunc_bfcUtilsInitVancBufferV2 bfcUtilsInitVancBufferV2;
pFunc_bfcUtilsGetStringForConversionType bfcUtilsGetStringForConversionType;
pFunc_bfcUtilsGetWStringForConversionType bfcUtilsGetWStringForConversionType;
#endif
#if defined(LOAD_FUNC_PTR_V6_5_3)
pFunc_bfcUtilsGetSetupInfoForInputSignal bfcUtilsGetSetupInfoForInputSignal;
pFunc_bfcUtilsGetStringForColorDiff bfcUtilsGetStringForColorDiff;
pFunc_bfcUtilsGetWStringForColorDiff bfcUtilsGetWStringForColorDiff;
pFunc_bfcGetPcbSerialNumber bfcGetPcbSerialNumber;
#endif

bool LoadFunctionPointersBasic_BlueVelvetC()
{
    bool bAllFunctionsAvailable = false;
#if defined(_WIN32)
#if defined(_WIN64)
#if defined(_DEBUG)
    HMODULE hLib = LoadLibraryExA("BlueVelvetC64_d.dll", NULL, 0);
#else
    HMODULE hLib = LoadLibraryExA("BlueVelvetC64.dll", NULL, 0);
#endif
#else
#if defined(_DEBUG)
    HMODULE hLib = LoadLibraryExA("BlueVelvetC_d.dll", NULL, 0);
#else
    HMODULE hLib = LoadLibraryExA("BlueVelvetC.dll", NULL, 0);
#endif
#endif
#endif


#if defined(__linux__)
    void* hLib = dlopen("libBlueVelvetC64.so", RTLD_LAZY | RTLD_GLOBAL);
#endif

    if(hLib)
    {
        bAllFunctionsAvailable = true;
        do
        {
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVersion);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVersionW);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcFactory);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcDestroy);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcEnumerate);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcQueryCardType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcAttach);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcDetach);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcQueryCardProperty32);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcQueryCardProperty64);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSetCardProperty32);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSetCardProperty64);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetCardSerialNumber);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetCardHwFwVersions);
#if defined(_WIN32)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetWindowsDriverHandle);
#elif defined(__linux__)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetFileHandle);
#endif
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfAlloc);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfFree);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForCardType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForCardType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForBlueProductId);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForBlueProductId);

        } while(0);
    }

    return bAllFunctionsAvailable;
}

bool LoadFunctionPointers_BlueVelvetC()
{
    bool bAllFunctionsAvailable = false;
#if defined(_WIN32)
    #if defined(_WIN64)
        #if defined(_DEBUG)
            HMODULE hLib = LoadLibraryExA("BlueVelvetC64_d.dll", NULL, 0);
        #else
            HMODULE hLib = LoadLibraryExA("BlueVelvetC64.dll", NULL, 0);
        #endif
    #else
        #if defined(_DEBUG)
            HMODULE hLib = LoadLibraryExA("BlueVelvetC_d.dll", NULL, 0);
        #else
            HMODULE hLib = LoadLibraryExA("BlueVelvetC.dll", NULL, 0);
        #endif
    #endif
#endif


#if defined(__linux__)
    void* hLib = dlopen("libBlueVelvetC64.so", RTLD_LAZY | RTLD_GLOBAL);
#endif

    if(hLib)
    {
        bAllFunctionsAvailable = true;
        do
        {
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVersion);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVersionW);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcFactory);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcDestroy);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcEnumerate);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcQueryCardType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcAttach);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSetMultiLinkMode);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcQueryMultiLinkMode);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcDetach);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcQueryCardProperty32);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcQueryCardProperty64);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSetCardProperty32);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSetCardProperty64);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetCardSerialNumber);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetCardHwFwVersions);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcWaitVideoSync);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcWaitVideoInputSync);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcWaitVideoOutputSync);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVideoOutputCurrentFieldCount);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVideoInputCurrentFieldCount);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcVideoCaptureStart);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcVideoCaptureStop);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcVideoPlaybackStart);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcVideoPlaybackStop);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcVideoPlaybackAllocate);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcVideoPlaybackPresent);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcVideoPlaybackRelease);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetCaptureVideoFrameInfoEx);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcRenderBufferCapture);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcRenderBufferUpdate);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetRenderBufferCount);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcEncodeHancFrameEx);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcEncodeHancFrameWithUCZ);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcDecodeHancFrameEx);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSyncInfoCreate);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSyncInfoDelete);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSyncInfoWait);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSyncInfoWaitWithSyncOptions);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcDmaReadFromCardAsync);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcDmaWriteToCardAsync);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSerialPortWaitForInputData);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSerialPortRead);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSerialPortWrite);
#if defined(_WIN32)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetReferenceClockPhaseSettings);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcLoadOutputLUT1D);
#endif
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVideoWidth);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVideoHeight);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVideoBytesPerLineV2);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVideoBytesPerFrame);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVideoBytesPerFrameGolden);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVideoInfo);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVancWidth);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVancHeight);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVancBytesPerLineV2);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVancBytesPerFrame);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetVancInfo);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetBytesForGroupPixels);
#if defined(_WIN32)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetWindowsDriverHandle);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSetDynamicMemoryFormatChange);
#elif defined(__linux__)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetFileHandle);
#endif
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetSdiConnectorSignalInfo);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfAlloc);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfFree);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForCardType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForCardType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForBlueProductId);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForBlueProductId);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForVideoMode);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForVideoMode);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForMemoryFormat);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForMemoryFormat);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForUpdateFormat);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForUpdateFormat);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForVideoEngine);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForVideoEngine);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForMr2Node);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForMr2Node);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetMR2Routing);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsSetMR2Routing);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetAudioOutputRouting);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsSetAudioOutputRouting);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsIsVideoModeProgressive);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsIsVideoModePsF);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsIsVideoMode1001Framerate);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetFpsForVideoMode);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetVideoModeExtForFrameInfoV2);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetFrameInfoForVideoModeExtV2);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetAudioSamplesPerFrame);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsInitVancBuffer);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsVancPktExtract);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsVancPktInsert);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsDecodeEia708bPkt);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsConvertVideoChannelToMr2Node);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsConvertMr2NodeToBlueConnectorId);
#if defined(LOAD_FUNC_PTR_V6_5_0)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcAutoCaptureCreateInternalBuffers);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcAutoCaptureDestroyInternalBuffers);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcAutoCaptureRegisterExternalBuffer);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcAutoCaptureRegisterExternalBufferArray);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcAutoCaptureRemoveExternalBuffersFromPool);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcAutoCaptureGetFilledBuffer);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcAutoCaptureReturnBuffer); 
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcWaitExternalLtcInputSync);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetMaximumOutputPhaseOffset);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetMaximumOutputPhaseSettings);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSetOutputPhaseOffset);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetOutputPhaseOffset);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSetOutputPhaseOffsetTimeDelay);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcSetOutputPhaseOffsetPixels);
            
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetDeviceCount);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetDeviceInfo);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsConvertFrameCountToRP188TimeCode);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetDefaultSetupInfoInput);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetDefaultSetupInfoOutput);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsValidateSetupInfo);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetRecommendedSetupInfoInput);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsSetupInput);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsSetupOutput);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForSignalLinkType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForSignalLinkType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForVideoChannel);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForVideoChannel);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForSignalFormatType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForSignalFormatType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForSignalColorSpace);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForSignalColorSpace);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForTransportType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGeWtStringForTransportType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForSubImageMapping);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForSubImageMapping);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForDataRange);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForDataRange);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForTransportSampling);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForTransportSampling);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForTransportColorSpace);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForTransportColorSpace);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForColorimetry);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForColorimetry);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForTransferFunc);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForTransferFunc);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForBErr);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForBErr);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForReferenceSource);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForReferenceSource);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForBFLockSignalType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForBFLockSignalType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsConvertMr2NodeToVideoChannel);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsConvertTimeDelayToOutputPhaseOffset);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsConvertPixelOffsetToOutputPhaseOffset);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsConvertOutputPhaseOffsetToPixelOffset);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsConvertOutputPhaseOffsetToTimeDelay);
#endif
#if defined(LOAD_FUNC_PTR_V6_5_1)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsInitVancBufferV2);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForConversionType);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForConversionType);
#endif
#if defined(LOAD_FUNC_PTR_V6_5_3)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetSetupInfoForInputSignal);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetStringForColorDiff);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcUtilsGetWStringForColorDiff);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcGetPcbSerialNumber);
#endif

        } while(0);
    }

    return bAllFunctionsAvailable;
}
#endif /* IMPLEMENTATION_BLUEVELVETC_FUNC_PTR */


typedef void* BFC_CONVERSION_HANDLE;

/* FUNCTION PROTOTYPES FOR BLUEVELVETC CONVERSION FUNCTIONS */
#if defined(__cplusplus)
extern "C" {
#endif

    typedef BFC_CONVERSION_HANDLE(__cdecl* pFunc_bfcConversionFactory)();
    typedef BLUE_VOID(__cdecl* pFunc_bfcConversionDestroy)(BFC_CONVERSION_HANDLE pHandle);
    typedef BLUE_S32(__cdecl* pFunc_bfcConversionGetAvailableThreadCount)(BFC_CONVERSION_HANDLE pHandle, BLUE_S32* pMaxThreadCount, BLUE_U32* pCurrentThreadCount);
    typedef BLUE_S32(__cdecl* pFunc_bfcConversionSetThreadCountLimit)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 MaxThreadCount);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_SquareDivisionToTsi_2VUY)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_SquareDivisionToTsi_ARGB32)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_SquareDivisionToTsi_RGB)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_SquareDivisionToTsi_BGR48)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_SquareDivisionToTsi_V210)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_TsiToSquareDivision_2VUY)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_TsiToSquareDivision_V210)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_TsiToSquareDivision_ARGB32)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);        
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_TsiToSquareDivision_RGB)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_TsiToSquareDivision_BGR48)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_Single4KV210ToAligned4KV210Quadrants_SSE2)(BFC_CONVERSION_HANDLE pHandle, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_Single4KV210AlignedQuadrantsToNative4KV210)(BFC_CONVERSION_HANDLE pHandle, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_HalfFloatRGBATo16bitRGBA)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_HalfFloatRGBATo16bitRGB)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_FloatRGBATo16bitRGBA)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_FloatRGBATo16bitRGB)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
#if defined(LOAD_FUNC_PTR_V6_5_0)
    typedef BErr(__cdecl* pFunc_bfcConvert_YUVSTo8bitRGBA)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL bDoFlip, BLUE_S32 RGBDataRange); 
    typedef BErr(__cdecl* pFunc_bfcConvert_2VUYTo8bitRGBA)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL bDoFlip, BLUE_S32 RGBDataRange);
    typedef BErr(__cdecl* pFunc_bfcConvert_V210To8bitRGBA)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip, BLUE_S32 RGBDataRange);
    typedef BErr(__cdecl* pFunc_bfcConvert_V210To8bitRGB)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip, BLUE_S32 RGBDataRange);
    /* typedef BErr(__cdecl* pFunc_bfcConvert_V216To8bitRGBA)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL bDoFlip, BLUE_S32 RGBDataRange); */
    /* typedef BErr(__cdecl* pFunc_bfcConvert_Y216To8bitRGBA)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL bDoFlip, BLUE_S32 RGBDataRange); */
    /* typedef BErr(__cdecl* pFunc_bfcConvert_CineonLETo8bitRGBA)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL bDoFlip, BLUE_S32 RGBDataRange); */
#endif
#if defined(LOAD_FUNC_PTR_V6_5_1)
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_SquareDivisionToTsi_BGRA64)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_TsiToSquareDivision_BGRA64)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_SquareDivisionToTsi_V216)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_SquareDivisionToTsi_Y216)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_SquareDivisionToTsi_CineonLE)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_TsiToSquareDivision_V216)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_TsiToSquareDivision_Y216)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    typedef BLUE_S32(__cdecl* pFunc_bfcConvert_TsiToSquareDivision_CineonLE)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
#endif
#if defined(LOAD_FUNC_PTR_V6_5_3)
    typedef BErr(__cdecl* pFunc_bfcConvert_VUYATo8bitRGBA)(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL bDoFlip, BLUE_S32 RGBDataRange);
#endif

#if defined(__cplusplus)
} /* extern "C" */
#endif

#ifdef IMPLEMENTATION_BLUEVELVETC_CONVERSION_FUNC_PTR
pFunc_bfcConversionFactory                                  bfcConversionFactory;
pFunc_bfcConversionDestroy                                  bfcConversionDestroy;
pFunc_bfcConversionGetAvailableThreadCount                  bfcConversionGetAvailableThreadCount;
pFunc_bfcConversionSetThreadCountLimit                      bfcConversionSetThreadCountLimit;
pFunc_bfcConvert_SquareDivisionToTsi_2VUY                   bfcConvert_SquareDivisionToTsi_2VUY;
pFunc_bfcConvert_SquareDivisionToTsi_V210                   bfcConvert_SquareDivisionToTsi_V210;
pFunc_bfcConvert_SquareDivisionToTsi_ARGB32                 bfcConvert_SquareDivisionToTsi_ARGB32;
pFunc_bfcConvert_SquareDivisionToTsi_RGB                    bfcConvert_SquareDivisionToTsi_RGB;
pFunc_bfcConvert_SquareDivisionToTsi_BGR48                  bfcConvert_SquareDivisionToTsi_BGR48;
pFunc_bfcConvert_TsiToSquareDivision_2VUY                   bfcConvert_TsiToSquareDivision_2VUY;
pFunc_bfcConvert_TsiToSquareDivision_V210                   bfcConvert_TsiToSquareDivision_V210;
pFunc_bfcConvert_TsiToSquareDivision_ARGB32                 bfcConvert_TsiToSquareDivision_ARGB32;
pFunc_bfcConvert_TsiToSquareDivision_RGB                    bfcConvert_TsiToSquareDivision_RGB;
pFunc_bfcConvert_TsiToSquareDivision_BGR48                  bfcConvert_TsiToSquareDivision_BGR48;
pFunc_bfcConvert_Single4KV210ToAligned4KV210Quadrants_SSE2  bfcConvert_Single4KV210ToAligned4KV210Quadrants_SSE2;
pFunc_bfcConvert_Single4KV210AlignedQuadrantsToNative4KV210 bfcConvert_Single4KV210AlignedQuadrantsToNative4KV210;
pFunc_bfcConvert_HalfFloatRGBATo16bitRGBA                   bfcConvert_HalfFloatRGBATo16bitRGBA;
pFunc_bfcConvert_HalfFloatRGBATo16bitRGB                    bfcConvert_HalfFloatRGBATo16bitRGB;
pFunc_bfcConvert_FloatRGBATo16bitRGBA                       bfcConvert_FloatRGBATo16bitRGBA;
pFunc_bfcConvert_FloatRGBATo16bitRGB                        bfcConvert_FloatRGBATo16bitRGB;
#if defined(LOAD_FUNC_PTR_V6_5_0)
pFunc_bfcConvert_YUVSTo8bitRGBA                             bfcConvert_YUVSTo8bitRGBA; 
pFunc_bfcConvert_2VUYTo8bitRGBA                             bfcConvert_2VUYTo8bitRGBA;
pFunc_bfcConvert_V210To8bitRGBA                             bfcConvert_V210To8bitRGBA;
pFunc_bfcConvert_V210To8bitRGB                              bfcConvert_V210To8bitRGB;
/* pFunc_bfcConvert_V216To8bitRGBA                          bfcConvert_V216To8bitRGBA; */
/* pFunc_bfcConvert_Y216To8bitRGBA                          bfcConvert_Y216To8bitRGBA; */
/* pFunc_bfcConvert_CineonLETo8bitRGBA                      bfcConvert_CineonLETo8bitRGBA; */
#endif
#if defined(LOAD_FUNC_PTR_V6_5_1)
pFunc_bfcConvert_SquareDivisionToTsi_BGRA64                 bfcConvert_SquareDivisionToTsi_BGRA64;
pFunc_bfcConvert_TsiToSquareDivision_BGRA64                 bfcConvert_TsiToSquareDivision_BGRA64;
pFunc_bfcConvert_SquareDivisionToTsi_V216                   bfcConvert_SquareDivisionToTsi_V216;
pFunc_bfcConvert_SquareDivisionToTsi_Y216                   bfcConvert_SquareDivisionToTsi_Y216;
pFunc_bfcConvert_SquareDivisionToTsi_CineonLE               bfcConvert_SquareDivisionToTsi_CineonLE;
pFunc_bfcConvert_TsiToSquareDivision_V216                   bfcConvert_TsiToSquareDivision_V216;
pFunc_bfcConvert_TsiToSquareDivision_Y216                   bfcConvert_TsiToSquareDivision_Y216;
pFunc_bfcConvert_TsiToSquareDivision_CineonLE               bfcConvert_TsiToSquareDivision_CineonLE;
#endif
#if defined(LOAD_FUNC_PTR_V6_5_3)
pFunc_bfcConvert_VUYATo8bitRGBA                             bfcConvert_VUYATo8bitRGBA;
#endif

bool LoadFunctionPointers_BlueConversion()
{
    bool bAllFunctionsAvailable = false;
#if defined(_WIN32)
    #if defined(_WIN64)
        #if defined(_DEBUG)
            HMODULE hLib = LoadLibraryExA("BlueVelvetC64_d.dll", NULL, 0);
        #else
            HMODULE hLib = LoadLibraryExA("BlueVelvetC64.dll", NULL, 0);
        #endif
    #else
        #if defined(_DEBUG)
            HMODULE hLib = LoadLibraryExA("BlueVelvetC_d.dll", NULL, 0);
        #else
            HMODULE hLib = LoadLibraryExA("BlueVelvetC.dll", NULL, 0);
        #endif
    #endif
#endif

#if defined(__linux__)
    void* hLib = dlopen("libBlueVelvetC64.so", RTLD_LAZY | RTLD_GLOBAL);
#endif

    if(hLib)
    {
        bAllFunctionsAvailable = true;
        do
        {
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConversionFactory);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConversionDestroy);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConversionGetAvailableThreadCount);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConversionSetThreadCountLimit);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_SquareDivisionToTsi_2VUY);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_SquareDivisionToTsi_V210);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_SquareDivisionToTsi_ARGB32);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_SquareDivisionToTsi_RGB);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_SquareDivisionToTsi_BGR48);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_TsiToSquareDivision_2VUY);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_TsiToSquareDivision_V210);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_TsiToSquareDivision_ARGB32);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_TsiToSquareDivision_RGB);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_TsiToSquareDivision_BGR48);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_Single4KV210ToAligned4KV210Quadrants_SSE2);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_Single4KV210AlignedQuadrantsToNative4KV210);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_HalfFloatRGBATo16bitRGBA);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_HalfFloatRGBATo16bitRGB);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_FloatRGBATo16bitRGBA);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_FloatRGBATo16bitRGB);
#if defined(LOAD_FUNC_PTR_V6_5_0)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_YUVSTo8bitRGBA); 
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_2VUYTo8bitRGBA);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_V210To8bitRGBA);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_V210To8bitRGB);
            /* GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_V216To8bitRGBA); */
            /* GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_Y216To8bitRGBA); */
            /* GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_CineonLETo8bitRGBA); */
#endif
#if defined(LOAD_FUNC_PTR_V6_5_1)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_SquareDivisionToTsi_BGRA64);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_TsiToSquareDivision_BGRA64);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_SquareDivisionToTsi_V216);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_SquareDivisionToTsi_Y216);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_SquareDivisionToTsi_CineonLE);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_TsiToSquareDivision_V216);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_TsiToSquareDivision_Y216);
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_TsiToSquareDivision_CineonLE);
#endif
#if defined(LOAD_FUNC_PTR_V6_5_3)
            GET_PROCADDR_FOR_FUNC(hLib, &bAllFunctionsAvailable, bfcConvert_VUYATo8bitRGBA);
#endif

        } while(0);
    }

    return bAllFunctionsAvailable;
}
#endif /* IMPLEMENTATION_BLUEVELVETC_CONVERSION_FUNC_PTR */

#endif /* HG_BLUEVELVETC_FUNC_PTR */

