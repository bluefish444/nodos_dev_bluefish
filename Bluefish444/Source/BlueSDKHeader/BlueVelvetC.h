/*  Copyright (c) Bluefish444. All rights reserved. */

#ifndef HG_BLUEVELVETC
#define HG_BLUEVELVETC


#if defined (_WIN32)
    #include "BlueDriver_p.h"
    #ifdef BLUEVELVETC_EXPORTS
        #define BLUEVELVETC_API __declspec(dllexport)
        #define BLUEVELVETC_API_DEPRECATED(s) __declspec(dllexport)
    #else
        #define BLUEVELVETC_API __declspec(dllimport)
        #define BLUEVELVETC_API_DEPRECATED(s) __declspec(dllimport, deprecated(s))
    #endif

#elif defined (__linux__)
    #define BLUEVELVETC_API
    #include <BlueDriver_p.h>

    #ifdef BLUEVELVETC_EXPORTS
        #define BLUEVELVETC_API_DEPRECATED(s)
    #else
        #define BLUEVELVETC_API_DEPRECATED(s) [[deprecated(s)]]
    #endif
#endif


/*------------------------------------------------------------------------------------------------*/
typedef void* BLUEVELVETC_HANDLE;
typedef void* BFC_SYNC_INFO;

#define BFC_SYNC_INFO_WAIT_INFINITE 0xFFFFFFFF
#define BLUE_OK(a)                  (!a)    /* Test for succcess of a method returning BErr */
#define BLUE_FAIL(a)                (a)     /* Test for failure of a method returning BErr  */
/*------------------------------------------------------------------------------------------------*/


#if defined(__cplusplus)
extern "C" {
#endif

    /**
     * bfcGetVersion - return the current version of this SDK
     *
     * Example:
     *  printf("This version of bfc is: %s \n", bfcGetVersion());
     */
    BLUEVELVETC_API const char* bfcGetVersion();
    BLUEVELVETC_API const wchar_t* bfcGetVersionW();
    
    /**
     * bfcFactory - create an instance of the BlueVelvetC SDK
     *
     */
    BLUEVELVETC_API BLUEVELVETC_HANDLE bfcFactory();
    
    /**
     * bfcDestroy - Destroy an instance of the BlueVelvetC SDK
     *
     * Example:
     *      bfcDestroy(pBVC);
     */
    BLUEVELVETC_API BLUE_VOID bfcDestroy(BLUEVELVETC_HANDLE pHandle);
    
    /**
     * bfcEnumerate - return the number of Bluefish devices currently installed in the system
     *                  can be run prior to attaching to a specific device
     */
    BLUEVELVETC_API BErr bfcEnumerate(BLUEVELVETC_HANDLE pHandle, BLUE_S32* pDeviceCount);
    
    /**
     * bfcQueryCardType - Find out what card type is installed for the given Device location.
     *                  DeviceID is 1 indexed.
     *                  CardType maps to ECardType in BlueDriver_p.h
     * Get the card type of the Card indicated by DeviceID, if DeviceID is 0, then get the cardtype for that card that this pHandle is attached to.
     */
    BLUEVELVETC_API BErr bfcQueryCardType(BLUEVELVETC_HANDLE pHandle, BLUE_S32* pCardType, BLUE_S32 DeviceID);
    
    /** 
     * bfcAttach - Attach to a specific Device in the current system
     */
    BLUEVELVETC_API BErr bfcAttach(BLUEVELVETC_HANDLE pHandle, BLUE_S32 DeviceId);
    
    /**
     * bfcDetach - Detach the SDK instance.
     */
    BLUEVELVETC_API BErr bfcDetach(BLUEVELVETC_HANDLE pHandle);
    
    /**
     * bfcQueryCardProperty32/64 - Query a property of the hardware
     *                              Properties are defined by EBlueCardProperty in BlueDriver_p.h
     *
     * Example:   eg. to determine what memory format is set
     *      BLUE_U32 MemFmt;
     *      bfcQueryCardProperty32(pBVC, VIDEO_MEMORY_FORMAT, &MemFmt);
     */
    BLUEVELVETC_API BErr bfcQueryCardProperty32(BLUEVELVETC_HANDLE pHandle, const BLUE_S32 Property, BLUE_U32* pValue32);
    
    /**
     * bfcSetCardProperty32/64 - Set a property of the hardware
     *                              Properties are defined by EBlueCardProperty in BlueDriver_p.h
     *
     * Example:   eg. to set the memory format
     *      BLUE_UINT32 MemFmt = MEM_FMT_V210;
     *      bfcSetCardProperty32(pBVC, VIDEO_MEMORY_FORMAT, MemFmt);
     */
    BLUEVELVETC_API BErr bfcSetCardProperty32(BLUEVELVETC_HANDLE pHandle, const BLUE_S32 Property, const BLUE_U32 nValue32);
    BLUEVELVETC_API BErr bfcQueryCardProperty64(BLUEVELVETC_HANDLE pHandle, const BLUE_S32 Property, BLUE_U64* pValue64);
    BLUEVELVETC_API BErr bfcSetCardProperty64(BLUEVELVETC_HANDLE pHandle, const BLUE_S32 Property, const BLUE_U64 Value64);
    
    BLUEVELVETC_API BErr bfcGetCardSerialNumber(BLUEVELVETC_HANDLE pHandle, BLUE_S8* pCardSerialNumber, BLUE_U32 StringSize); /* StringSize must be at least 20 */
    BLUEVELVETC_API BErr bfcGetPcbSerialNumber(BLUEVELVETC_HANDLE pHandle, BLUE_S8* pPcbSerialNumber, BLUE_U32 StringSize); /* StringSize must be at least 20 */
    BLUEVELVETC_API BErr bfcGetCardHwFwVersions(BLUEVELVETC_HANDLE pHandle, hardware_firmware_versions* pVersions);
    
    BLUEVELVETC_API BErr bfcGetSdiConnectorSignalInfo(BLUEVELVETC_HANDLE pHandle, EBlueConnectorIdentifier ConnectorId, sdi_connector_signal_info* pInfo);

    /* Interrupt related functions */

    /**
     * bfcWaitVideoSync - A function that allows for synchronising with the video input interrupts of the card
     *                    The type of sync can be controlled by the properties of the sync_optionns struct that is passed in
     *                    Upon returning some of the structs data values will have been updated with useful info
     *                    The SyncInfo argument is currently ignored and the function always blocks
     */
    BLUEVELVETC_API BErr bfcWaitVideoSync(BLUEVELVETC_HANDLE pHandle, sync_options* pSyncData, BFC_SYNC_INFO SyncInfo);

    /**
     * bfcWaitVideoInputSync - A blocking function that allows you to synchronize with the video input interrupts of the card
     *                          ulUpdateType specifies what type of interrupt to wait for, of type EUpdateMethod
     *                          ulFieldCount - a returned value that gives the current fieldcount
     *
     */
    BLUEVELVETC_API BErr bfcWaitVideoInputSync(BLUEVELVETC_HANDLE pHandle, unsigned long UpdateType, unsigned long* pFieldCount);

    /**
     * bfcWaitVideoOutputSync - A blocking function that allows you to synchronize with the video output interrupts of the card
     *                          ulUpdateType specifies what type of interrupt to wait for, of type EUpdateMethod
     *                          ulFieldCount - a returned value that gives the current fieldcount
     *
     */
    BLUEVELVETC_API BErr bfcWaitVideoOutputSync(BLUEVELVETC_HANDLE pHandle, unsigned long UpdateType, unsigned long* pFieldCount);

    /**
    * bfcWaitExternalLtcInputSync - A blocking function that allows you to synchronize with the external ltc signal
    *                               pSyncStruct must point to a zero-initialised struct and will return timecode
    *                               validity and the actual timecode
    *
    */
    BLUEVELVETC_API BErr bfcWaitExternalLtcInputSync(BLUEVELVETC_HANDLE pHandle, blue_external_ltc_input_sync_struct* pSyncStruct);
    
    /**
     * bfcGetVideoOutputCurrentFieldCount - Returns the current output field count
     *                          ulFieldCount - a returned value that gives the current fieldcount
     *
     */
    BLUEVELVETC_API BErr bfcGetVideoOutputCurrentFieldCount(BLUEVELVETC_HANDLE pHandle, unsigned long* FieldCount);

    /**
     * bfcGetVideoInputCurrentFieldCount - Returns the current input fieldcount
     *                          ulFieldCount - a returned value that gives the current fieldcount
     *
     */
    BLUEVELVETC_API BErr bfcGetVideoInputCurrentFieldCount(BLUEVELVETC_HANDLE pHandle, unsigned long* FieldCount);
    
    /* FIFO functions */
    /**
     * bfcVideoCaptureStart - Start the video Capture engine, only available in FIFO mode.
     *
     */
    BLUEVELVETC_API BErr bfcVideoCaptureStart(BLUEVELVETC_HANDLE pHandle);

    /**
     * bfcVideoCaptureStop - Stop the video Capture engine.
     *
     */
    BLUEVELVETC_API BErr bfcVideoCaptureStop(BLUEVELVETC_HANDLE pHandle);

    /**
     * bfcVideoPlaybackStart - Start the video playback engine, only available in FIFO mode.
     *
     */
    BLUEVELVETC_API BErr bfcVideoPlaybackStart(BLUEVELVETC_HANDLE pHandle, BLUE_S32 Step, BLUE_S32 Loop);
    
    /**
     * bfcVideoPlaybackStop - Stop the video playback engine.
     *
     */
    BLUEVELVETC_API BErr bfcVideoPlaybackStop(BLUEVELVETC_HANDLE pHandle, BLUE_S32 Wait, BLUE_S32 Flush);
    
    /**
     * bfcVideoPlaybackAllocate - Get an ID for an empty card buffer from the playback engine.
     *
     */
    BLUEVELVETC_API BErr bfcVideoPlaybackAllocate(BLUEVELVETC_HANDLE pHandle, BLUE_VOID** pAddress, unsigned long* pBufferID, unsigned long* pUnderrun);
    
    /**
     * bfcVideoPlaybackPresent - Tell the playback system that we have finished copying data into the buffer and it is ready to be presented (i.e. displayed on the SDI output)
     *                          calling this function does not guaruntee that the specified buffer will be displayed on the next interrupt, depending if there are video buffers queued in the FIFO already or not
     *                          If multiple buffers are already marked as ready the specified buffer will be added to the end of the "present queue".
     *                          Once a buffer is presented, the FIFO automatically releases it and places it in the free/empty queue.
     *                          The "Odd" parameter shall be set to 0 for progressive video modes.
     *                          For interlaced video modes and update method UPD_FMT_FIELD the "Odd" must alternate between 0 (presenting field 1 = even field, which includes HANC if used) and 1 (presenting field 2 = odd field)
     */
    BLUEVELVETC_API BErr bfcVideoPlaybackPresent(BLUEVELVETC_HANDLE pHandle, unsigned long* pUniqueID, unsigned long BufferID, unsigned long Count, BLUE_S32 Keep, BLUE_S32 Odd);
    
    /**
     * bfcVideoPlaybackRelease - Release a buffer back onto the free/empty queue without it playing out the card
     *
     */
    BLUEVELVETC_API BErr bfcVideoPlaybackRelease(BLUEVELVETC_HANDLE pHandle, unsigned long BufferID);
    
    /**
     * bfcGetCaptureVideoFrameInfoEx - Checks if there is a captured frame buffer available in the capture queue.
     *                                  A bufferID of -1 indicates that no buffers are available.
     *                                  pCaptureFifoSize indicates the numbers of buffers currently stored on the card.
     */
#if defined (_WIN32)
    BLUEVELVETC_API BErr bfcGetCaptureVideoFrameInfoEx(BLUEVELVETC_HANDLE pHandle, OVERLAPPED* pOverlap, struct blue_videoframe_info_ex* pVideoFrameInfo, BLUE_S32 CompostLater, BLUE_U32* pCaptureFifoSize);
#elif defined(__linux__)
    BLUEVELVETC_API BErr bfcGetCaptureVideoFrameInfoEx(BLUEVELVETC_HANDLE pHandle, struct blue_videoframe_info_ex* pVideoFrameInfo);
#endif
    
    /* FRAMESTORE functions */
    /**
     * bfcRenderBufferCapture - Tell the card to capture the next incoming buffer to the bufferID specified.
     *                              The card does not start capturing until the next Interrupt for this channel and is not complete until the interrupta after that.
     */
    BLUEVELVETC_API BErr bfcRenderBufferCapture(BLUEVELVETC_HANDLE pHandle, unsigned long BufferID);

    /**
     * bfcRenderBufferUpdate - Tell the card to display the buffer specified by BufferID at the next interrupt.
     *
     */
    BLUEVELVETC_API BErr bfcRenderBufferUpdate(BLUEVELVETC_HANDLE pHandle, unsigned long BufferID);
    BLUEVELVETC_API BErr bfcGetRenderBufferCount(BLUEVELVETC_HANDLE pHandle, unsigned long* pCount);
    
    /* AUDIO Helper functions (BlueHancUtils) */
    BLUEVELVETC_API BErr bfcEncodeHancFrameEx(BLUEVELVETC_HANDLE pHandle, BLUE_U32 CardType, struct hanc_stream_info_struct* pHancEncodeInfo, BLUE_VOID* pAudioBuffer, BLUE_U32 AudioChannels, BLUE_U32 AudioSamples, BLUE_U32 SampleType, BLUE_U32 AudioFlags);    /* AudioFlags is not used */
    BLUEVELVETC_API BErr bfcEncodeHancFrameWithUCZ(BLUEVELVETC_HANDLE pHandle, BLUE_U32 CardType, struct hanc_stream_info_struct* pHancEncodeInfo, BLUE_VOID* pAudioBuffer, BLUE_U32 AudioChannels, BLUE_U32 AudioSamples, BLUE_U32 SampleType, BLUE_U8* pUCZBuffer);
    BLUEVELVETC_API BErr bfcDecodeHancFrameEx(BLUEVELVETC_HANDLE pHandle, BLUE_U32 CardType, BLUE_U32* pHancBuffer, struct hanc_decode_struct* pHancDecodeInfo);

    BLUEVELVETC_API BFC_SYNC_INFO bfcSyncInfoCreate(BLUEVELVETC_HANDLE pHandle);
    BLUEVELVETC_API BErr          bfcSyncInfoDelete(BLUEVELVETC_HANDLE pHandle, BFC_SYNC_INFO SyncInfo);
    BLUEVELVETC_API BLUE_S32      bfcSyncInfoWait(BLUEVELVETC_HANDLE pHandle, BFC_SYNC_INFO SyncInfo, const BLUE_U32 TimeOutInMilliSec);
    BLUEVELVETC_API BLUE_S32      bfcSyncInfoWaitWithSyncOptions(BLUEVELVETC_HANDLE pHandle, BFC_SYNC_INFO SyncInfo, sync_options* pSyncOptions, const BLUE_U32 TimeOutInMilliSec); /* Waits and returns the sync_options results from bfcWaitVideoSync when called asynchronously */

    /* Cross platform asynchronous DMA functions; */
    /* When called without BFC_SYNC_INFO object functions block until transfer has finished */
    /* --> return value: > 0: bytes transferred */
    /*                   < 0: error */
    /* If used with a BFC_SYNC_INFO object functions will return immediately and will need to followed by a call to bfcSyncInfoWait (which will then return the number of bytes transferred */
    /* --> return value: = 0: no error, transfer in progress */
    /*                   < 0: error */
    BLUEVELVETC_API BLUE_S32 bfcDmaReadFromCardAsync(BLUEVELVETC_HANDLE pHandle, BLUE_U8* pData, unsigned long Size, BFC_SYNC_INFO SyncInfo, unsigned long BufferID, unsigned long Offset);
    BLUEVELVETC_API BLUE_S32 bfcDmaWriteToCardAsync(BLUEVELVETC_HANDLE pHandle, BLUE_U8* pData, unsigned long Size, BFC_SYNC_INFO SyncInfo, unsigned long BufferID, unsigned long Offset);
    
    /* RS422 Serial Port Functions */
    BLUEVELVETC_API BErr     bfcSerialPortWaitForInputData(BLUEVELVETC_HANDLE pHandle, BLUE_U32 PortFlags, BLUE_U32* pBufferLength);
    BLUEVELVETC_API BLUE_S32 bfcSerialPortRead(BLUEVELVETC_HANDLE pHandle, BLUE_U32 nPortFlags, BLUE_U8* pBuffer, BLUE_U32 ReadLength);
    BLUEVELVETC_API BLUE_S32 bfcSerialPortWrite(BLUEVELVETC_HANDLE pHandle, BLUE_U32 nPortFlags, BLUE_U8* pBuffer, BLUE_U32 WriteLength);

#if defined (_WIN32)
    /* Miscellaneous functions */
    BLUEVELVETC_API BErr bfcLoadOutputLUT1D(BLUEVELVETC_HANDLE pHandle, struct blue_1d_lookup_table_struct* pLutData);
#endif

    /* VIDEO_ENGINE_AUTO_CAPTURE, VIDEO_ENGINE_AUTO_CAPTURE_UHD, VIDEO_ENGINE_AUTO_CAPTURE_PLAYTHROUGH and VIDEO_ENGINE_AUTO_CAPTURE_UHD_PLAYTHROUGH */
    /* Option 1: have the SDK create pinned memory buffers internally; a pointer to a filled buffer will be supplied when calling bfcAutoCaptureGetFilledBuffer */
    BLUEVELVETC_API BErr bfcAutoCaptureCreateInternalBuffers(BLUEVELVETC_HANDLE pHandle, EBlueBufferComponent ComponentFlags);
    BLUEVELVETC_API BErr bfcAutoCaptureDestroyInternalBuffers(BLUEVELVETC_HANDLE pHandle);
    /* Option 2: register your own memory buffers to be pinned (call this function multiple times; each time with the appropriate buffer component flag) */
    BLUEVELVETC_API BErr bfcAutoCaptureRegisterExternalBuffer(BLUEVELVETC_HANDLE pHandle, BLUE_VOID* pBuffer, BLUE_U32 Size, EBlueBufferComponent ComponentFlags);
    BLUEVELVETC_API BErr bfcAutoCaptureRegisterExternalBufferArray(BLUEVELVETC_HANDLE pHandle, BLUE_VOID** ppBufferArray, BLUE_U32 ElementCount, BLUE_U32 ElementSize, EBlueBufferComponent ComponentFlags);
    BLUEVELVETC_API BErr bfcAutoCaptureRemoveExternalBuffersFromPool(BLUEVELVETC_HANDLE pHandle);
    /* */
    BLUEVELVETC_API BErr bfcAutoCaptureGetFilledBuffer(BLUEVELVETC_HANDLE pHandle, blue_auto_buffer_info* pBufferInfo, EBlueReturnMode ReturnMode);    /* The returned data in pBufferInfo is to be treated as read only; ReturnMode determines if this function blocks until buffer is available or if it returns immediately (either buffer is available or not */
    BLUEVELVETC_API BErr bfcAutoCaptureReturnBuffer(BLUEVELVETC_HANDLE pHandle, blue_auto_buffer_info* pBufferInfo); /* pBufferInfo passed into this function must be the pointer to the unmodified data retrieved from bfcAutoCaptureGetFilledBuffer() */

    /* support EVideoMode and EVideoModeExt */
    BLUEVELVETC_API BErr bfcGetVideoWidth(BLUE_S32 VideoMode, BLUE_U32* pWidth);
    BLUEVELVETC_API BErr bfcGetVideoHeight(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_U32* pHeight);
    BLUEVELVETC_API BErr bfcGetVideoBytesPerLineV2(BLUE_S32 VideoMode, BLUE_S32 MemoryFormat, BLUE_U32* pBytesPerLine);
    BLUEVELVETC_API BErr bfcGetVideoBytesPerFrame(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pBytesPerFrame);
    BLUEVELVETC_API BErr bfcGetVideoBytesPerFrameGolden(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pGoldenBytes); /* Golden Bytes is the frame size in bytes with added padding to make the buffer size a multiple of the page size (4096 bytes) */
    BLUEVELVETC_API BErr bfcGetVideoInfo(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pWidth, BLUE_U32* pHeight, BLUE_U32* pBytesPerLine, BLUE_U32* pBytesPerFrame, BLUE_U32* pGoldenBytes);
    BLUEVELVETC_API BErr bfcGetVancWidth(BLUE_S32 VideoMode, BLUE_U32* pWidth);
    BLUEVELVETC_API BErr bfcGetVancHeight(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_U32* pHeight);
    BLUEVELVETC_API BErr bfcGetVancBytesPerLineV2(BLUE_S32 VideoMode, BLUE_S32 MemoryFormat, BLUE_U32* pBytesPerLine);
    BLUEVELVETC_API BErr bfcGetVancBytesPerFrame(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pBytesPerFrame);
    BLUEVELVETC_API BErr bfcGetVancInfo(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pWidth, BLUE_U32* pHeight, BLUE_U32* pBytesPerLine, BLUE_U32* pBytesPerFrame);  /* In HD and larger modes the MemoryFormat must be V210, as the VANC is always in V210 */
    BLUEVELVETC_API BErr bfcGetBytesForGroupPixels(EMemoryFormat MemoryFormat, BLUE_U32 VideoWidth, BLUE_U32* pVideoPitchBytes);

    /* Output phase max settings*/
    BLUEVELVETC_API BErr bfcGetMaximumOutputPhaseOffset(BLUE_S32 VideoMode, BLUE_U32* pMaxOffset);
    BLUEVELVETC_API BErr bfcGetMaximumOutputPhaseSettings(BLUE_S32 VideoMode, BLUE_U32* pMaxLines, BLUE_U32* pMaxHorizontalPixelOffset, BLUE_U32* pMaxHorizontalDelayNanoseconds);
    /* bfcSetOutputPhaseOffset() is the peferred function to change output phase offset
       It uses a raw phase offset value which is necessary for fine-tuning; any supported pohse offset can be achieved with the raw phase offset value
    */
    BLUEVELVETC_API BErr bfcSetOutputPhaseOffset(BLUEVELVETC_HANDLE pHandle, BLUE_U32 Offset);
    BLUEVELVETC_API BErr bfcGetOutputPhaseOffset(BLUEVELVETC_HANDLE pHandle, BLUE_U32* pOffset);
    /* following are more intuitive functions to change the output phase offset
       use bfcSetOutputPhaseOffset() for fine-tuning
       use the following helper functions to convert between the raw phase offset and line/pixel/time delay offsets
       bfcUtilsConvertTimeDelayToOutputPhaseOffset
       bfcUtilsConvertPixelOffsetToOutputPhaseOffset
       bfcUtilsConvertOutputPhaseOffsetToPixelOffset
       bfcUtilsConvertOutputPhaseOffsetToTimeDelay
    */
    BLUEVELVETC_API BErr bfcSetOutputPhaseOffsetTimeDelay(BLUEVELVETC_HANDLE pHandle, BLUE_U32 LineOffset, BLUE_U32 HorizontalDelayNanoseconds);
    BLUEVELVETC_API BErr bfcSetOutputPhaseOffsetPixels(BLUEVELVETC_HANDLE pHandle, BLUE_U32 LineOffset, BLUE_U32 HorizontalPixelOffset);

#if defined (_WIN32)
    /* AMD SDI-Link support  */
    BLUEVELVETC_API BErr bfcDmaWaitMarker(BLUEVELVETC_HANDLE pHandle, OVERLAPPED* pOverlap, BLUE_U32 VideoChannel, BLUE_U32 BufferId, BLUE_U32 Marker);
    BLUEVELVETC_API BErr bfcDmaReadToBusAddressWithMarker(BLUEVELVETC_HANDLE pHandle,
                                                          BLUE_U32 VideoChannel,
                                                          BLUE_U64 DataAddress,
                                                          BLUE_U32 Size,
                                                          OVERLAPPED* pOverlap,
                                                          BLUE_U32 BufferID,
                                                          unsigned long Offset,
                                                          BLUE_U64 MarkerAddress,
                                                          BLUE_U32 Marker);
    BLUEVELVETC_API BErr bfcDmaReadToBusAddress(BLUEVELVETC_HANDLE pHandle,
                                                BLUE_U32 VideoChannel,
                                                BLUE_U64 DataAddress,
                                                BLUE_U32 Size,
                                                OVERLAPPED* pOverlap,
                                                BLUE_U32 BufferID,
                                                unsigned long Offset);
    BLUEVELVETC_API BErr bfcDmaWriteMarker( BLUEVELVETC_HANDLE pHandle, BLUE_U64 MarkerAddress, BLUE_U32 Marker);

    /* misc */
    BLUEVELVETC_API BErr bfcGetWindowsDriverHandle(BLUEVELVETC_HANDLE pHandle, HANDLE* pDriverHandle);
    BLUEVELVETC_API BErr bfcSetDynamicMemoryFormatChange(BLUEVELVETC_HANDLE pHandle, OVERLAPPED* pOverlap, BLUE_U32 nUniqueId, EMemoryFormat MemoryFormat);
#elif defined(__linux__)
    BLUEVELVETC_API BErr bfcGetFileHandle(BLUEVELVETC_HANDLE pHandle, BLUE_U32* pFileHandle);
#endif

    /* ********************************************************************************************************************************************************************************************************************************************************************** */
    /* D E P R E C A T E D    F U N C T I O N S ****/
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcUtilsSetupInput and/or bfcUtilsSetupOutput for enabling UHD support.")   BErr bfcSetMultiLinkMode(BLUEVELVETC_HANDLE pHandle, blue_multi_link_info_struct* pMultiLinkInfo);                                                                          /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. ")                                                                              BLUE_S32 bfcQueryMultiLinkMode(BLUEVELVETC_HANDLE pHandle, blue_multi_link_info_struct* pMultiLinkInfo);                                                                    /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVideoWidth instead.")                                                 BErr bfcGetPixelsPerLine(EVideoMode VideoMode, BLUE_U32* pPixelsPerLine);                                                                                                   /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVideoHeight instead.")                                                BErr bfcGetLinesPerFrame(EVideoMode VideoMode, EUpdateMethod UpdateMethod, BLUE_U32* pLinesPerFrame);                                                                       /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVideoBytesPerLineV2 instead.")                                        BErr bfcGetBytesPerLine(EVideoMode VideoMode, EMemoryFormat MemoryFormat, BLUE_U32* pBytesPerLine);                                                                         /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVideoBytesPerFrame instead.")                                         BErr bfcGetBytesPerFrame(EVideoMode VideoMode, EMemoryFormat MemoryFormat, EUpdateMethod UpdateMethod, BLUE_U32* pBytesPerFrame);                                           /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVideoInfo instead.")                                                  BErr bfcGetGoldenValue(EVideoMode VideoMode, EMemoryFormat MemoryFormat, EUpdateMethod UpdateMethod, BLUE_U32* pGoldenFrameSize);                                           /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVancHeight instead.")                                                 BErr bfcGetVBILines(EVideoMode VideoMode, EDMADataType DataType, BLUE_U32* pVBILinesPerFrame);                                                                              /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVancInfo instead.")                                                   BErr bfcGetVANCGoldenValue(BLUE_U32 CardType, EVideoMode VideoMode, EMemoryFormat MemoryFormat, EDMADataType nDataFormat, BLUE_U32* pVANCGoldenValue);                      /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVancBytesPerLineV2 instead.")                                         BErr bfcGetVANCLineBytes(BLUE_U32 CardType, EVideoMode VideoMode, EMemoryFormat MemoryFormat, BLUE_U32* pVANCLineBytes);                                                    /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVancHeight instead.")                                                 BErr bfcGetVANCLineCount(BLUE_U32 CardType, EVideoMode VideoMode, EDMADataType DataFormat, BLUE_U32* pVANCLineCount);                                                       /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVideoBytesPerLineV2 instead.")                                        BErr bfcGetVideoBytesPerLine(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pBytesPerLine);                                                    /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetVancBytesPerLineV2 instead.")                                         BErr bfcGetVancBytesPerLine(BLUE_S32 VideoMode, BLUE_S32 UpdateMethod, BLUE_S32 MemoryFormat, BLUE_U32* pBytesPerLine);                                                     /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcGetCardHwFwVersions instead.")                                           BErr bfcGetCardFwVersion(BLUEVELVETC_HANDLE pHandle, BLUE_U32* pValue);                                                                                                     /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. See AN30_Reference.pdf for more info.")                                         BErr bfcGetReferenceClockPhaseSettings(BLUEVELVETC_HANDLE pHandle, BLUE_U32* pHPhase, BLUE_U32* pVPhase, BLUE_U32* pHPhaseMax, BLUE_U32* pVPhaseMax);
#if defined(_WIN32)
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcWaitVideoSync instead.")                                                 BErr bfcWaitVideoSyncAsync(BLUEVELVETC_HANDLE pHandle, OVERLAPPED* pOverlap, blue_video_sync_struct* pSyncData);                                                            /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcDmaReadFromCardAsync instead.")                                          BLUE_S32 bfcSystemBufferReadAsync(BLUEVELVETC_HANDLE pHandle, BLUE_U8* pPixels, unsigned long Size, OVERLAPPED* pOverlap, unsigned long BufferID, unsigned long Offset);    /* deprecated */
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcDmaWriteToCardAsync instead.")                                           BLUE_S32 bfcSystemBufferWriteAsync(BLUEVELVETC_HANDLE pHandle, BLUE_U8* pPixels, unsigned long Size, OVERLAPPED* pOverlap, unsigned long BufferID, unsigned long Offset);   /* deprecated */
#elif (__linux__)
    BLUEVELVETC_API BLUE_S32 bfcSystemBufferRead(BLUEVELVETC_HANDLE pHandle, unsigned char* pPixels, unsigned long Size, unsigned long BufferID, unsigned long Offset);                                                                                         /* deprecated */
    BLUEVELVETC_API BLUE_S32 bfcSystemBufferWrite(BLUEVELVETC_HANDLE pHandle, unsigned char* pPixels, unsigned long Size, unsigned long BufferID, unsigned long Offset);                                                                                        /* deprecated */
#endif
    /* D E P R E C A T E D    F U N C T I O N S ****/
    /* ********************************************************************************************************************************************************************************************************************************************************************** */

#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif  /* HG_BLUEVELVETC  */
