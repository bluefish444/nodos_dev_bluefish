/**
 *  @file       BlueVelvetCConversion.h
 *  @brief      BlueVelvetCConversion API
 *  @copyright  (C) Copyright 2017-2023 Bluefish Technologies Pty Ltd. All Rights Reserved. Proprietary and confidential information.
**/

#ifndef HG_BLUEVELVETC_CONVERSION
#define HG_BLUEVELVETC_CONVERSION

#if defined (__linux__)
    #include "BlueVelvetC.h"
#endif

typedef void* BFC_CONVERSION_HANDLE;

#if defined(__cplusplus)
extern "C" {
#endif

    /* init functions */
    BLUEVELVETC_API BFC_CONVERSION_HANDLE bfcConversionFactory();
    BLUEVELVETC_API BLUE_VOID bfcConversionDestroy(BFC_CONVERSION_HANDLE pHandle);
    BLUEVELVETC_API BErr bfcConversionGetAvailableThreadCount(BFC_CONVERSION_HANDLE pHandle, BLUE_U32* pMaxThreadCount, BLUE_U32* pCurrentThreadCount);
    BLUEVELVETC_API BErr bfcConversionSetThreadCountLimit(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 MaxThreadCount);     /* optional; limits the usable thread count; must be smaller than maximum available thread count. */

    /* TSI conversion functions */
    BLUEVELVETC_API BErr bfcConvert_SquareDivisionToTsi_2VUY(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);   /* Handles 2-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_SquareDivisionToTsi_V216(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);   /* Handles 2-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_SquareDivisionToTsi_Y216(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);   /* Handles 2-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_SquareDivisionToTsi_V210(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);   /* Handles V210/Y210 pixel formats (16 bytes per 6 pixel) */
    BLUEVELVETC_API BErr bfcConvert_SquareDivisionToTsi_RGB(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);    /* Handles 3-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_SquareDivisionToTsi_ARGB32(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer); /* Handles 4-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_SquareDivisionToTsi_BGR48(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);  /* Handles 6-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_SquareDivisionToTsi_BGRA64(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer); /* Handles 8-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_SquareDivisionToTsi_CineonLE(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);   /* Handles 2-bytes-per-pixel formats */

    BLUEVELVETC_API BErr bfcConvert_TsiToSquareDivision_2VUY(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);    /* Handles 2-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_TsiToSquareDivision_V216(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);    /* Handles 2-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_TsiToSquareDivision_Y216(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);    /* Handles 2-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_TsiToSquareDivision_V210(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);    /* Handles V210/Y210 pixel formats (16 bytes per 6 pixel) */
    BLUEVELVETC_API BErr bfcConvert_TsiToSquareDivision_RGB(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);     /* Handles 3-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_TsiToSquareDivision_ARGB32(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);  /* Handles 4-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_TsiToSquareDivision_BGR48(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);   /* Handles 6-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_TsiToSquareDivision_BGRA64(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);  /* Handles 8-bytes-per-pixel formats */
    BLUEVELVETC_API BErr bfcConvert_TsiToSquareDivision_CineonLE(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);    /* Handles 2-bytes-per-pixel formats */

    /* 4k V210 re-alignment (assumes a V210 4128 x 2160 source image and a destination buffer to hold 4 x 2064 x 1080 x 8 / 3 bytes); uses SSE2 */
    BLUEVELVETC_API BErr bfcConvert_Single4KV210ToAligned4KV210Quadrants_SSE2(BFC_CONVERSION_HANDLE pHandle, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);

    /* Takes a single V210 4128x2160 V210 buffer (as captured with BVC ML) and merges it to a native 4128x2160 (actually 4096 + 32 pixels padding) buffer; uses SSE2 */
    BLUEVELVETC_API BErr bfcConvert_Single4KV210AlignedQuadrantsToNative4KV210(BFC_CONVERSION_HANDLE pHandle, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);

    /* Float formats to integer RGB and RGBA functions */
    BLUEVELVETC_API BErr bfcConvert_HalfFloatRGBATo16bitRGBA(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    BLUEVELVETC_API BErr bfcConvert_HalfFloatRGBATo16bitRGB(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    BLUEVELVETC_API BErr bfcConvert_FloatRGBATo16bitRGBA(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);
    BLUEVELVETC_API BErr bfcConvert_FloatRGBATo16bitRGB(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer);

    /* YUV formats to integer RGB and RGBA functions */
    BLUEVELVETC_API BErr bfcConvert_YUVSTo8bitRGBA(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip, BLUE_S32 RGBDataRange);
    BLUEVELVETC_API BErr bfcConvert_2VUYTo8bitRGBA(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip, BLUE_S32 RGBDataRange);
    BLUEVELVETC_API BErr bfcConvert_VUYATo8bitRGBA(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip, BLUE_S32 RGBDataRange);
    /* BLUEVELVETC_API  BErr bfcConvert_2VUYTo8bitRGB(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip);*/
    BLUEVELVETC_API BErr bfcConvert_V210To8bitRGBA(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip, BLUE_S32 RGBDataRange);
    BLUEVELVETC_API BErr bfcConvert_V210To8bitRGB(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip, BLUE_S32 RGBDataRange);
    /* BLUEVELVETC_API  BErr bfcConvert_V216To8bitRGBA(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip, BLUE_S32 RGBDataRange);*/
    /* BLUEVELVETC_API  BErr bfcConvert_Y216To8bitRGBA(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip, BLUE_S32 RGBDataRange);*/
    /* BLUEVELVETC_API  BErr bfcConvert_CineonLETo8bitRGBA(BFC_CONVERSION_HANDLE pHandle, BLUE_U32 Width, BLUE_U32 Height, BLUE_VOID* pSrcBuffer, BLUE_VOID* pDstBuffer, BLUE_BOOL DoFlip, BLUE_S32 RGBDataRange);*/

#if defined(__cplusplus)
} /* extern "C" */
#endif

#endif /* HG_BLUEVELVETC_CONVERSION */

