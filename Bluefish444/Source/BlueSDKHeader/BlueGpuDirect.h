/**
*  @file       BlueGpuDirect.h
*  @brief      BlueGpuDirect API to access NVIDIA's GpuDirect functionality
*  @copyright  (C) Copyright 2017-2023 Bluefish Technologies Pty Ltd. All Rights Reserved. Proprietary and confidential information.
**/

#ifndef HG_BLUE_GPUDIRECT
#define HG_BLUE_GPUDIRECT


#ifdef __linux__
    #include "BlueVelvetC.h"
    #define BLUEGPUDIRECT_API
#endif

#ifdef _WIN32
    #ifdef BLUEGPUDIRECT_EXPORTS
        #define BLUEGPUDIRECT_API __declspec(dllexport)
    #else
        #define BLUEGPUDIRECT_API __declspec(dllimport)
    #endif
#endif


typedef void* BLUE_GPUDIRECT_HANDLE;


typedef enum _EBLUE_GPUDIRECT_CONTEXT_TYPE
{
    GPUDIRECT_CONTEXT_TYPE_OPENGL=0,
    GPUDIRECT_CONTEXT_TYPE_CUDA=1,
    GPUDIRECT_CONTEXT_TYPE_DX9=2,
    GPUDIRECT_CONTEXT_TYPE_DX10=3,
    GPUDIRECT_CONTEXT_TYPE_DX11=4
}EBLUE_GPUDIRECT_CONTEXT_TYPE;

typedef enum _EBLUE_GPUDIRECT_TEXTURE_TYPE
{
    GPUDIRECT_TEXTURE_TYPE_TEXTURE=0,
    GPUDIRECT_TEXTURE_TYPE_BUFFER=1
}EBLUE_GPUDIRECT_TEXTURE_TYPE;

typedef enum _BGD_STATUS
{
    BGD_NO_ERROR =							0,
    BGD_NO_BLUE_DEVICE_ERROR =				1,
    BGD_MEMORY_FORMAT_NOT_SUPPORTED_ERROR =	2,
    BGD_BGDHANDLE_ERROR =				3,
    BGD_CONTEXT_ERROR =					4,
    BGD_CONTEXT_INIT_ERROR =			5,
    BGD_CONTEXT_EXIT_ERROR =			6,
    BGD_CONTEXT_REQUIREMENTS_ERROR =	7,
    BGD_GPU_TEXTURE_ERROR =				8,
    BGD_BUFFERS_ERROR =					9,
    BGD_BUFFER_NO_SIZE_ERROR =			10,
    BGD_LOCKING_BUFFERS_ERROR =			11,
    BGD_CREATE_BUFFER_ERROR =			12,
    BGD_BIND_TEXTURE_ERROR =			13,
    BGD_UNBIND_TEXTURE_ERROR =			14,
    BGD_TEXTURE_HANDLE_ERROR =			15,
    BGD_SYNC_OBJECT_ERROR =				16,
    BGD_TRANSFER_ERROR	=				17
}BGD_STATUS;


extern "C"
{
    //Init functions
    BLUEGPUDIRECT_API BLUE_GPUDIRECT_HANDLE bfGpuDirect_Init(	int CardId,
                                                                EBlueVideoChannel VideoChannel,															
                                                                void* pGpuDevice,
                                                                EBLUE_GPUDIRECT_CONTEXT_TYPE eContext,
                                                                void* gpuTextures,
                                                                unsigned int NumTextures,
                                                                unsigned int NumChunks,
                                                                EBLUE_GPUDIRECT_TEXTURE_TYPE eTextureType = GPUDIRECT_TEXTURE_TYPE_TEXTURE);
    BLUEGPUDIRECT_API BLUE_GPUDIRECT_HANDLE bfGpuDirect_InitWithDefaultVideoMode(	int CardId,
                                                                                    EBlueVideoChannel VideoChannel,															
                                                                                    void* pGpuDevice,
                                                                                    EBLUE_GPUDIRECT_CONTEXT_TYPE eContext,
                                                                                    void* gpuTextures,
                                                                                    unsigned int NumTextures,
                                                                                    unsigned int NumChunks,
                                                                                    EBLUE_GPUDIRECT_TEXTURE_TYPE eTextureType,
                                                                                    EVideoMode eDefaultVideoInputMode);	//used for input channels when no valid input signal is currently available
    BLUEGPUDIRECT_API BLUE_GPUDIRECT_HANDLE bfGpuDirect_InitWithDefaultVideoModeExt(int CardId,
                                                                                    EBlueVideoChannel VideoChannel,
                                                                                    void* pGpuDevice,
                                                                                    EBLUE_GPUDIRECT_CONTEXT_TYPE eContext,
                                                                                    void* gpuTextures,
                                                                                    unsigned int NumTextures,
                                                                                    unsigned int NumChunks,
                                                                                    EBLUE_GPUDIRECT_TEXTURE_TYPE eTextureType,
                                                                                    EVideoModeExt eDefaultVideoInputModeExt);	//used for input channels when no valid input signal is currently available
    BLUEGPUDIRECT_API void bfGpuDirect_Destroy(BLUE_GPUDIRECT_HANDLE pHandle);

    //DMA functions
    BLUEGPUDIRECT_API int bfGpuDirect_TransferInputFrameToGPU(BLUE_GPUDIRECT_HANDLE pHandle, unsigned long BufferId, void* hTexture);
    BLUEGPUDIRECT_API int bfGpuDirect_TransferOutputFrameToSDI(BLUE_GPUDIRECT_HANDLE pHandle, unsigned long BufferId, void* hTexture);

    //Texture locking - needs to be done in rendering thread
    BLUEGPUDIRECT_API int bfGpuDirect_BeginProcessing(BLUE_GPUDIRECT_HANDLE pHandle, void* hTexture);
    BLUEGPUDIRECT_API int bfGpuDirect_EndProcessing(BLUE_GPUDIRECT_HANDLE pHandle, void* hTexture);

    //Error handling - for normal mode
    BLUEGPUDIRECT_API int bfGpuDirect_GetLastError(BLUE_GPUDIRECT_HANDLE pHandle, int* pLowLevelError);

    //RAW mode: init functions
    BLUEGPUDIRECT_API BLUE_GPUDIRECT_HANDLE bfGpuDirect_InitRaw(void* pGpuDevice, EBLUE_GPUDIRECT_CONTEXT_TYPE eContext);
    BLUEGPUDIRECT_API void bfGpuDirect_DestroyRaw(BLUE_GPUDIRECT_HANDLE pHandle);
    BLUEGPUDIRECT_API int bfGpuDirect_RegisterTextureRaw(BLUE_GPUDIRECT_HANDLE pHandle, int iWidth, int iHeight, EMemoryFormat eMemoryFormat, void* hTexture, EBLUE_GPUDIRECT_TEXTURE_TYPE eTextureType = GPUDIRECT_TEXTURE_TYPE_TEXTURE);
    BLUEGPUDIRECT_API int bfGpuDirect_GetTextureAddressRaw(BLUE_GPUDIRECT_HANDLE pHandle, void* hTexture, void** ppAddress);
    //RAW mode: transfer functions
    BLUEGPUDIRECT_API int bfGpuDirect_DownloadFromTextureRaw(BLUE_GPUDIRECT_HANDLE pHandle, void* hTexture);
    BLUEGPUDIRECT_API int bfGpuDirect_UploadToTextureRaw(BLUE_GPUDIRECT_HANDLE pHandle, void* hTexture);
    //RAW mode - Texture locking: needs to be done in rendering thread
    BLUEGPUDIRECT_API int bfGpuDirect_BeginProcessingRaw(BLUE_GPUDIRECT_HANDLE pHandle, void* hTexture);
    BLUEGPUDIRECT_API int bfGpuDirect_EndProcessingRaw(BLUE_GPUDIRECT_HANDLE pHandle, void* hTexture);

    //Error handling - for RAW mode
    BLUEGPUDIRECT_API int bfGpuDirect_GetLastErrorRaw(BLUE_GPUDIRECT_HANDLE pHandle, int* pLowLevelError);

}	//extern "C"





#endif //HG_BLUE_GPUDIRECT

