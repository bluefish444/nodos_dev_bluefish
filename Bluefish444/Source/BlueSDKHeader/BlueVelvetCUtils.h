/**
 *  @file       BlueVelvetCExternHelper.h
 *  @brief      Utility functions for BlueVelvetC API
 *  @copyright  (C) Copyright 2017-2023 Bluefish Technologies Pty Ltd. All Rights Reserved. Proprietary and confidential information.
**/

#ifndef HG_BLUEVELVETC_UTILS
#define HG_BLUEVELVETC_UTILS

#include "BlueVelvetC.h"



#if defined(__cplusplus)
extern "C" {
#endif

/* Memory Allocation and Free'ing of page Aligned memory */
    BLUEVELVETC_API BLUE_VOID*      bfAlloc(BLUE_U32 MemorySize);
    BLUEVELVETC_API BLUE_VOID       bfFree(BLUE_U32 MemSize, BLUE_VOID* pMemory);

/* Get strings that give information about the card or card state */
    BLUEVELVETC_API const char*     bfcUtilsGetStringForCardType(const BLUE_S32 CardType);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForCardType(const BLUE_S32 CardType);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForBlueProductId(const BLUE_U32 ProductId);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForBlueProductId(const BLUE_U32 ProductId);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForVideoMode(const BLUE_U32 VideoMode);        /* supports EVideoMode and EVideoModeExt */
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForVideoMode(const BLUE_U32 VideoMode);       /* supports EVideoMode and EVideoModeExt */
    BLUEVELVETC_API const char*     bfcUtilsGetStringForMemoryFormat(const BLUE_U32 MemoryFormat);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForMemoryFormat(const BLUE_U32 MemoryFormat);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForUpdateFormat(const BLUE_U32 UpdateFormat);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForUpdateFormat(const BLUE_U32 UpdateFormat);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForVideoEngine(const BLUE_U32 VideoEngine);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForVideoEngine(const BLUE_U32 VideoEngine);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForMr2Node(const BLUE_U32 Mr2Node);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForMr2Node(const BLUE_U32 Mr2Node);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForSignalLinkType(const EBlueSignalLinkType SignalLinkType);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForSignalLinkType(const EBlueSignalLinkType SignalLinkType);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForVideoChannel(const EBlueVideoChannel VideoChannel);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForVideoChannel(const EBlueVideoChannel VideoChannel);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForSignalFormatType(const EDualLinkSignalFormatType SignalFormatType);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForSignalFormatType(const EDualLinkSignalFormatType SignalFormatType);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForSignalColorSpace(const EConnectorSignalColorSpace SignalColorSpace);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForSignalColorSpace(const EConnectorSignalColorSpace SignalColorSpace);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForTransportType(const EHdSdiTransport TransporType);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGeWtStringForTransportType(const EHdSdiTransport TransporType);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForSubImageMapping(const ESubImageMapping ImageMapping);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForSubImageMapping(const ESubImageMapping ImageMapping);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForDataRange(const ERGBDataRange DataRange);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForDataRange(const ERGBDataRange DataRange);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForTransportSampling(const ETransportSampling  TransportSampling);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForTransportSampling(const ETransportSampling  TransportSampling);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForTransportColorSpace(const EConnectorSignalColorSpace TransportColorSpace);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForTransportColorSpace(const EConnectorSignalColorSpace TransportColorSpace);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForColorimetry(const ETransportColorimetry TransportColorimetry);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForColorimetry(const ETransportColorimetry TransportColorimetry);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForTransferFunc(const ETransportTransferFunc TransferFunc);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForTransferFunc(const ETransportTransferFunc TransferFunc);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForColorDiff(const EBlueColorDiff ColorDiff);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForColorDiff(const EBlueColorDiff ColorDiff);

    BLUEVELVETC_API const char*     bfcUtilsGetStringForBErr(const BErr ErrorCode);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForBErr(const BErr ErrorCode);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForReferenceSource(const EBlueGenlockSource ReferenceSource);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForReferenceSource(const EBlueGenlockSource ReferenceSource);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForBFLockSignalType(const EBFLockSignalType SignalType);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForBFLockSignalType(const EBFLockSignalType SignalType);
    BLUEVELVETC_API const char*     bfcUtilsGetStringForConversionType(const EBlueConversionType ConversionType);
    BLUEVELVETC_API const wchar_t*  bfcUtilsGetWStringForConversionType(const EBlueConversionType ConversionType);

/* Change MR2 Routing               using the EEpochRoutingElements enum values as src and dest  */
    BLUEVELVETC_API BErr            bfcUtilsGetMR2Routing(const BLUEVELVETC_HANDLE pHandle, BLUE_U32* pSrcNode, const BLUE_U32 DestNode, BLUE_U32* pLinkType);
    BLUEVELVETC_API BErr            bfcUtilsSetMR2Routing(const BLUEVELVETC_HANDLE pHandle, const BLUE_U32 SrcNode, const BLUE_U32 DestNode, const BLUE_U32 LinkType);

/* Get/Set Audio routing.  */
    BLUEVELVETC_API BErr            bfcUtilsGetAudioOutputRouting(const BLUEVELVETC_HANDLE pHandle, const BLUE_U32 AudioConnectorType, BLUE_U32* AudioSourceChannelId, BLUE_U32 AudioConnectorId);
    BLUEVELVETC_API BErr            bfcUtilsSetAudioOutputRouting(const BLUEVELVETC_HANDLE pHandle, const BLUE_U32 AudioConnectorType, BLUE_U32 AudioSourceChannelId, BLUE_U32 AudioConnectorId);

/* General Video format helper funcs */
    BLUEVELVETC_API bool            bfcUtilsIsVideoModeProgressive(const BLUE_U32 VideoMode);   /* supports EVideoMode and EVideoModeExt */
    BLUEVELVETC_API bool            bfcUtilsIsVideoModePsF(const BLUE_U32 VideoMode);           /* supports EVideoMode and EVideoModeExt */
    BLUEVELVETC_API bool            bfcUtilsIsVideoMode1001Framerate(const BLUE_U32 VideoMode); /* supports EVideoMode and EVideoModeExt */
    BLUEVELVETC_API BLUE_S32        bfcUtilsGetFpsForVideoMode(const BLUE_U32 VideoMode);       /* supports EVideoMode and EVideoModeExt, returns closest interger FPS, use bfcUtilsIsVideoMode1001Framerate(), to determine if div 1001 is needed. */

/* Get the Bluefish _EVideoModeExt for the given width, height, fps and scan mode */
    BLUEVELVETC_API BErr            bfcUtilsGetVideoModeExtForFrameInfoV2(const BLUE_U32 Width, const BLUE_U32 Height, const BLUE_U32 FrameRate, const BLUE_U32 bFrameRateIs1001, const scan_mode ScanMode, BLUE_U32* pVideoModeExt);
    BLUEVELVETC_API BErr            bfcUtilsGetFrameInfoForVideoModeExtV2(const BLUE_U32 VideoModeExt, BLUE_U32* pWidth, BLUE_U32* pHeight, BLUE_U32* pFrameRate, BLUE_U32* pFrameRateIs1001, scan_mode* pScanMode);

/* Get the number of Audio Packets for a given frame of video in a specific mode. */
    BLUEVELVETC_API BLUE_S32        bfcUtilsGetAudioSamplesPerFrame(const BLUE_U32 VideoMode, const BLUE_U32 FrameNumber); /* supports EVideoMode and EVideoModeExt */

/*******************************************************************************************************************************************/
/* Utility functions for setting up a channel for capture/playback. These functions are often referred to as "The Simple Setup Functions". */
/*******************************************************************************************************************************************/
/**
 *  @fn bfcUtilsGetDefaultSetupInfoInput
 * 
 *  @brief Retrieves a blue_setup_info struct based on the current input signal; might be invalid
 * 
 *  This function returns a valid blue_setup_info struct based on the video input channel passed in, but NOT based on the current input signal.
 *  To retrieve a valid blue_setup_info struct based on the current signal call bfcUtilsGetSetupInfoForInputSignal() and/or bfcUtilsGetRecommendedSetupInfoInput()
 * 
 * @param   VideoInputChannel   in
 *
 * @return  blue_setup_info based on video input channel passed in
 */
    BLUEVELVETC_API blue_setup_info bfcUtilsGetDefaultSetupInfoInput(EBlueVideoChannel VideoInputChannel);

/**
 *  @fn bfcUtilsGetDefaultSetupInfoOutput
 * 
 *  @brief Retrieves a blue_setup_info struct based on the current output signal; might be invalid
 * 
 *  This function returns a valid blue_setup_info struct based on the video output channel and video mode passed in.
 * 
 * @param   VideoOutputChannel  in
 * @param   VideoModeExt        in
 *                              Video mode to user for playback
 *
 * @return  blue_setup_info based on video input channel passed in
 */
    BLUEVELVETC_API blue_setup_info bfcUtilsGetDefaultSetupInfoOutput(EBlueVideoChannel VideoOutputChannel, EVideoModeExt VideoModeExt);

/**
 *  @fn bfcUtilsValidateSetupInfo
 * 
 *  @brief Validates a blue_setup_info struct to verify the struct is valid
 * 
 *  @param  pSetupInfo      in
 */
    BLUEVELVETC_API BErr bfcUtilsValidateSetupInfo(blue_setup_info* pSetupInfo);

/**
 *  @fn bfcUtilsGetSetupInfoForInputSignal
 * 
 *  @brief Retrieves a blue_setup_info struct based on the current input signal; might be invalid
 *
 *  This function might fail if there is no valid input signal or the input VPID is incorrect/not supported.
 *  In this case call bfcUtilsGetRecommendedSetupInfoInput() to retrieve a valid/recommended blue_setup_info struct.
 *  Once blue_setup_info is set up, call bfcUtilsSetupInput() to set up the input channel accordingly
 * 
 *  @param  pHandle         in
 *                          Can be NULL for a once off call, but for better performance this should be a valid handle
 *                          If pHandle instance is not attached this call will attach the handle to the card/channel specified in pSetupInfo
 *  @param  pSetupInfo      in/out
 *                          Pointer to a user owned blue_setup_info struct; this struct should be initialised with bfcUtilsGetDefaultSetupInfoInput()
 *                          After returning from this function members can be overriden to the user's specific needs
 *  @param  UhdPreference   in
 *                          Hint for UHD preference
 *  @return                 BErr (0 for success, negative values for error) */
    BLUEVELVETC_API BErr bfcUtilsGetSetupInfoForInputSignal(BLUEVELVETC_HANDLE pHandle, blue_setup_info* pSetupInfo, EBlueUhdPreference UhdPreference);

/**
 *  @fn bfcUtilsGetRecommendedSetupInfoInput
 * 
 *  @brief Retrieves a valid/recommended blue_setup_info struct based on the current input signal, even if the input signal or VPID are invalid
 *
 *  If the function bfcUtilsGetSetupInfoForInputSignal fails, bfcUtilsGetRecommendedSetupInfoInput() will return a valid and recommended blue_setup_info struct.
 *  The user should pass in a valid/expected video mode, so that this function can set up the input channel in preparation for a valid signal.
 *  Once blue_setup_info is set up, call bfcUtilsSetupInput() to set up the input channel accordingly
 * 
 *  @param  pHandle         in
 *                          Can be NULL for a once off call, but for better performance this should be a valid handle
 *                          If pHandle instance is not attached this call will attach the handle to the card/channel specified in pSetupInfo
 *  @param  pSetupInfo      in/out
 *                          Pointer to a user owned blue_setup_info struct; this struct should be initialised with bfcUtilsGetDefaultSetupInfoInput()
 *  @param  UhdPreference   in
 *                          Hint for UHD preference
 *  @return                 BErr (0 for success, negative values for error) */
    BLUEVELVETC_API BErr bfcUtilsGetRecommendedSetupInfoInput(BLUEVELVETC_HANDLE pHandle, blue_setup_info* pSetupInfo, EBlueUhdPreference UhdPreference);

/**
 *  @fn bfcUtilsSetupInput
 * 
 *  @brief Sets up an input channel based on the blue_setup_info struct passed in
 *
 *  This function will set up the input card properties for the channel(s) specified in pSetupInfo; it will change the required routing as well
 * 
 *  @param  pHandle         in
 *                          Can be NULL for a once off call, but for better performance this should be a valid handle
 *                          If pHandle instance is not attached this call will attach the handle to the card/channel specified in pSetupInfo
 *  @param  pSetupInfo      in
 *                          Pointer to a user owned blue_setup_info struct.
 *                          This struct should be initialised with bfcUtilsGetDefaultSetupInfoInput(), bfcUtilsGetSetupInfoForInputSignal() or
 *                          bfcUtilsGetRecommendedSetupInfoInput(), but members can be overriden to the user's specific needs
 *  @return                 BErr (0 for success, negative values for error) */
    BLUEVELVETC_API BErr bfcUtilsSetupInput(BLUEVELVETC_HANDLE pHandle, blue_setup_info* pSetupInfo);

/**
 *  @fn bfcUtilsSetupOutput
 * 
 *  @brief Sets up an input channel based on the blue_setup_info struct passed in
 *
 *  This function will set up the output card properties for the channel specified in pSetupInfo; it will change the required routing as well
 * 
 *  @param  pHandle         in
 *                          Can be NULL for a once off call, but for better performance this should be a valid handle
 *                          If pHandle instance is not attached this call will attach the handle to the card/channel specified in pSetupInfo
 *  @param  pSetupInfo      in
 *                          Pointer to a user owned blue_setup_info struct.
 *                          This struct should be initialised with bfcUtilsGetDefaultSetupInfoOutput(), but members can be overriden to the user's specific needs
 *  @return                 BErr (0 for success, negative values for error) */
    BLUEVELVETC_API BErr bfcUtilsSetupOutput(BLUEVELVETC_HANDLE pHandle, blue_setup_info* pSetupInfo);

/*******************************************/
/* Reference phase offset helper functions */
/*******************************************/
    BLUEVELVETC_API BErr            bfcUtilsConvertTimeDelayToOutputPhaseOffset(BLUE_S32 VideoMode, BLUE_U32 LineOffset, BLUE_U32 HorizontalDelayNanoseconds, BLUE_U32* pOffset);
    BLUEVELVETC_API BErr            bfcUtilsConvertPixelOffsetToOutputPhaseOffset(BLUE_S32 VideoMode, BLUE_U32 LineOffset, BLUE_U32 HorizontalPixelOffset, BLUE_U32* pOffset);
    BLUEVELVETC_API BErr            bfcUtilsConvertOutputPhaseOffsetToPixelOffset(BLUE_S32 VideoMode, BLUE_U32 Offset, BLUE_U32* pLineOffset, BLUE_U32* pHorizontalPixelOffset);
    BLUEVELVETC_API BErr            bfcUtilsConvertOutputPhaseOffsetToTimeDelay(BLUE_S32 VideoMode, BLUE_U32 Offset, BLUE_U32* pLineOffset, BLUE_U32* pHorizontalDelayNanoseconds);

/********/
/* misc */
/********/
    BLUEVELVETC_API EEpochRoutingElements    bfcUtilsConvertVideoChannelToMr2Node(EBlueVideoChannel VideoChannel);
    BLUEVELVETC_API EBlueVideoChannel        bfcUtilsConvertMr2NodeToVideoChannel(EEpochRoutingElements Mr2Node);
    BLUEVELVETC_API EBlueConnectorIdentifier bfcUtilsConvertMr2NodeToBlueConnectorId(EEpochRoutingElements Mr2Node);
    BLUEVELVETC_API BLUE_VOID                bfcUtilsConvertFrameCountToRP188TimeCode(BLUE_U32 FrameCount, BLUE_U32 FrameRate, BLUE_U32 bIsDropFrame, BLUE_U64* pRP188Vitc, BLUE_U64* pRP188Ltc);

    BLUEVELVETC_API BLUE_S32                 bfcUtilsGetDeviceCount();
    BLUEVELVETC_API BErr                     bfcUtilsGetDeviceInfo(BLUE_S32 DeviceId, blue_device_info* pDeviceInfo);

/* HANC / VANC utils */

/**
 @brief enumerator used by VANC manipulation function on HD cards to notify whether
 VANC pakcet shoule be inserted/extracted from VANC Y buffers or VANC CbCr buffer.
 This enumerator will only be used on  HD video modes as it is the only with
 2 type of ANC bufers ir Y and CbCr. On SD Modes the ANC data is inserted across
 both Y anc CbCr values.
 
 */
    enum BlueVancPktTypeEnum
    {
        BlueVancPktYComp =      0,  /**< ANC pkt should be inserted/extracted from the Y component buffer (HD/UHD video modes) */
        BlueVancPktCbcrComp =   1,  /**< ANC pkt should be inserted/extracted from the CbCr component buffer (HD/UHD video modes) */
        BlueVancPktAllComp =    2   /**< ANC pkt should be inserted/extracted from all components (SD video modes)*/
    };

/*!
 @brief Use this function to initialise VANC buffer before inserting any packets into the buffer. Assumes that the VANC buffer is V210 packing.
 @param pVancBuffer ptr to vanc buffer to be initialised
 @param BufferSize size of buffer to be initialised; must be multiple of 128 bytes = 48 pixels (V210 spec)
 */
    BLUEVELVETC_API BErr bfcUtilsInitVancBufferV2(BLUE_VOID* pVancBuffer, BLUE_U32 BufferSize); 

/*!
 @brief this function can be used to extract ANC packet from HD cards. Currently we can only extract packets in the VANC space. Assumes that the VANC buffer is V210 packing.
 @param CardType type of the card from which the vanc buffer was captured.
 @param vanc_pkt_type This parameter denotes whether to search for the VANC packet in Y Space or Cb/Cr Space.
 The values this parameter accepts are defined in the enumerator #BlueVancPktTypeEnum
 @param src_vanc_buffer Vanc buffer which was captured from bluefish card
 @param src_vanc_buffer_size size of the vanc buffer which should be parsed for the specified vanc packet
 @param pixels_per_line specifies how many pixels are there in each line of VANC buffer
 @param vanc_pkt_did specifies the DID of the Vanc packet which should be extracted from the buffer
 @param vanc_pkt_sdid Returns the SDID of the extracted VANC packet
 @param vanc_pkt_data_length returns the size of the extracted VANC packet. The size is specifed as number of UDW words
 that was  contained in the packet
 @param vanc_pkt_data_ptr pointer to UDW of the VANC packets . The 10 bit UDW words are packed in a 16 bit integer. The bottom 10 bit of the
 16 bit word contains the UDW data.
 @param vanc_pkt_line_no line number  where the packet was found .
 
 @remarks.
 
 */
    BLUEVELVETC_API BErr bfcUtilsVancPktExtract(BLUE_U32 CardType,
                                                BLUE_U32 VancPktType,
                                                BLUE_U32* pSrcVancBuffer,
                                                BLUE_U32 SrcVancBufferSize,
                                                BLUE_U32 PixelsPerLine,
                                                BLUE_U32 VancPktDid,
                                                BLUE_U16* pVancPktSdid,
                                                BLUE_U16* pVancPktDataLength,
                                                BLUE_U16* pVancPktData,
                                                BLUE_U16* pVancPktLineNo);

/**
 @brief Use this function to insert ANC packets into the VANC buffer. Assumes that the pVancPktBuffer VANC buffer is V210 packing
 @param CardType Card type being used
 @param VancPktType Values of type BlueVancPktTypeEnum to encode components in Y-space only (HD/UHD) or both Y-space and Cb/Cr-space (SD only)
 @param VancPktLineNumber Line in which the VANC packet should be inserted
 @param pVancPktBuffer Pointer to buffer which holds the ANC packet data to be encoded; 10 bit data should be represented and padded to 16 bits (unlike the BLUE_U32 data type suggests)
 @param VancPktElementCount Number of 16 bit words to be inserted and represented in VancPktLineNumber; including the checksum, ADF, SDID, DID and Data Count
 @param pDestVancBuffer VANC buffer into which the ANC packet will be inserted into
 @param PixelsPerLine Specifies how many pixels there are in each line of VANC buffer
 */
    BLUEVELVETC_API BErr bfcUtilsVancPktInsert(BLUE_U32 CardType,
                                               BLUE_U32 VancPktType,
                                               BLUE_U32 VancPktLineNumber,
                                               BLUE_U32* pVancPktBuffer,
                                               BLUE_U32 VancPktElementCount,
                                               BLUE_U32* pDestVancBuffer,
                                               BLUE_U32 PixelsPerLine);

    BLUEVELVETC_API BLUE_U32 bfcUtilsDecodeEia708bPkt(BLUE_U32 CardType, BLUE_U16* pVancPacketData, BLUE_U16 PacketUdwCount, BLUE_U16 EiaPacketSubtype, BLUE_U8* pDecodedString);


    /* ************************************************************************************************************************************************************************************************************************************************************************************************* */
    /* D E P R E C A T E D    F U N C T I O N S ****/
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcUtilsGetVideoModeExtForFrameInfo instead.")   BLUE_S32 bfcUtilsGetVideoModeForFrameInfo(const BLUE_U32 Width, const BLUE_U32 Height, const BLUE_U32 Rate, const BLUE_U32 bIs1001, const BLUE_U32 bIsProgressive, BLUE_U32* pVideoMode);
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcUtilsGetFrameInfoForVideoModeExt instead.")   BLUE_S32 bfcUtilsGetFrameInfoForVideoMode(const BLUE_U32 VideoMode, BLUE_U32* pWidth, BLUE_U32* pHeight, BLUE_U32* pRate, BLUE_U32* pIs1001, BLUE_U32* pIsProgressive);
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcUtilsGetVideoModeExtForFrameInfoV2 instead.") BErr bfcUtilsGetVideoModeExtForFrameInfo(const BLUE_U32 Width, const BLUE_U32 Height, const BLUE_U32 Rate, const BLUE_U32 bIs1001, const BLUE_U32 bIsProgressive, BLUE_U32* pVideoModeExt);
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcUtilsGetFrameInfoForVideoModeExtV2 instead.") BErr bfcUtilsGetFrameInfoForVideoModeExt(const BLUE_U32 VideoModeExt, BLUE_U32* pWidth, BLUE_U32* pHeight, BLUE_U32* pRate, BLUE_U32* pIs1001, BLUE_U32* pIsProgressive);
    BLUEVELVETC_API_DEPRECATED("Deprecated. Use bfcUtilsInitVancBufferV2 instead.")              BErr bfcUtilsInitVancBuffer(BLUE_U32 CardType, BLUE_U32 VideoMode, BLUE_U32 PixelsPerLine, BLUE_U32 LinesPerFrame, BLUE_U32* pVancBuffer);
    /* D E P R E C A T E D    F U N C T I O N S ****/
    /* ************************************************************************************************************************************************************************************************************************************************************************************************* */

#if defined(__cplusplus)
} /* extern "C" */
#endif

#endif /* HG_BLUEVELVETC_UTILS */
