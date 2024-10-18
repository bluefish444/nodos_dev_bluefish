#ifndef HG_BLUE_HANCUTILS_HG
#define HG_BLUE_HANCUTILS_HG

#ifndef __linux__
#ifndef HANCUTILS_USE_STATIC_LIB
	#ifdef BLUEHANCUTILS_EXPORTS
		#define HANCUTILS_API __declspec(dllexport)
	#elif defined(__APPLE__)
		#define HANCUTILS_API
		#define //ATLTRACE	printf
	#else
		#define HANCUTILS_API __declspec(dllimport)
	#endif
#else
	#define HANCUTILS_API
#endif
#else
	#define HANCUTILS_API
typedef bool BOOL;	
#endif	
#include "BlueDriver_p.h"



#ifdef __cplusplus
extern "C"
{
#endif
/**
@defgroup hanc_manipilation_function Embedded audio
@{
*/

__declspec(deprecated("Deprecated. Do not use; use encode_hanc_frame_ex() instead."))
HANCUTILS_API BLUE_UINT32 encode_hanc_frame(struct hanc_stream_info_struct* hanc_stream_ptr,
											void* audio_pcm_ptr,
											BLUE_UINT32 no_audio_ch,
											BLUE_UINT32 no_audio_samples,
											BLUE_UINT32 nTypeOfSample,
											BLUE_UINT32 emb_audio_flag);

HANCUTILS_API BLUE_UINT32 encode_hanc_frame_ex( BLUE_UINT32 card_type,
												struct hanc_stream_info_struct* hanc_stream_ptr,
												void* audio_pcm_ptr,
												BLUE_UINT32 no_audio_ch,
												BLUE_UINT32 no_audio_samples,
												BLUE_UINT32 nTypeOfSample,
												BLUE_UINT32 emb_audio_flag);


HANCUTILS_API BLUE_UINT32 encode_hanc_frame_with_ucz(	BLUE_UINT32 card_type,
														struct hanc_stream_info_struct* hanc_stream_ptr,
														void* audio_pcm_ptr,
														BLUE_UINT32 no_audio_ch,
														BLUE_UINT32 no_audio_samples,
														BLUE_UINT32 nTypeOfSample,
														BLUE_UINT32 emb_audio_flag,
														BLUE_UINT8* pUCZBuffer);

HANCUTILS_API BLUE_UINT32 create_embed_audiosample(	void* raw_data_ptr,
													BLUE_UINT32* emb_data_ptr,
													BLUE_UINT32 channels_per_audio_sample,
													BLUE_UINT32 bytes_per_ch,
													BLUE_UINT32 no_samples,
													BLUE_UINT32 emb_audio_flags,
													BLUE_UINT8* Audio_Groups_DBN_Array,
													BLUE_UINT8* Audio_Groups_statusblock_Array);

__declspec(deprecated("Deprecated. Do not use."))
HANCUTILS_API BLUE_UINT32* get_embed_audio_distribution_array(BLUE_UINT32 video_mode, BLUE_UINT32 sequence_no);

__declspec(deprecated("Deprecated. Do not use."))
HANCUTILS_API bool hanc_stream_analyzer(BLUE_UINT32 *src_hanc_buffer,struct hanc_stream_info_struct * hanc_stream_ptr);
__declspec(deprecated("Deprecated. Do not use."))
HANCUTILS_API bool orac_hanc_stream_analyzer(BLUE_UINT32 card_type,BLUE_UINT32 *src_hanc_buffer,struct hanc_decode_struct * decode_ptr,char * analyzer_output_file);

HANCUTILS_API bool hanc_decoder_ex(BLUE_UINT32 card_type, BLUE_UINT32* src_hanc_buffer, struct hanc_decode_struct* hanc_decode_struct_ptr);

/**
@brief enumerator used by VANC manipulation function on HD cards to notify whether 
		VANC pakcet shoule be inserted/extracted from VANC Y buffers or VANC CbCr buffer.
		This enumerator will only be used on  HD video modes as it is the only with 
		2 type of ANC bufers ir Y and CbCr. On SD Modes the ANC data is inserted across 
		both Y anc CbCr values.
		
*/
enum blue_vanc_pkt_type_enum
{
	blue_vanc_pkt_y_comp=0,		/**< ANC pkt should be inserted/extracted from the Y component buffer*/
	blue_vanc_pkt_cbcr_comp=1,	/**< ANC pkt should be inserted/extracted from the CbCr component buffer*/
	blue_vanc_pkt_all_comp=2	/**< ANC pkt should be inserted/extracted from all components (SD video modes)*/
};

/*!
@brief Use this function to initialise VANC buffer before inserting any packets into the buffer
@param CardType type of bluefish  card to which this vanc buffer was transferred to.
@param nVideoMode video mode under which this vanc buffer will be used.
@param pixels_per_line width in pixels of the vanc buffer that has to be initialised.
@param lines_per_frame height of the vanc buffer that has to be initialised.
@param pVancBuffer vanc buffer which has to be initialised.
@remarks.

*/
HANCUTILS_API BLUE_UINT32 blue_init_vanc_buffer(BLUE_UINT32 CardType,BLUE_UINT32 nVideoMode,BLUE_UINT32 pixels_per_line,BLUE_UINT32 lines_per_frame,BLUE_UINT32 * pVancBuffer);
/*!
@brief this function can be used to extract ANC packet from HD cards. Currently we can only extract packets in the VANC space.
@param CardType type of the card from which the vanc buffer was captured.
@param vanc_pkt_type This parameter denotes whether to search for the VANC packet in Y Space or Cb/Cr Space.
					 The values this parameter accepts are defined in the enumerator #blue_vanc_pkt_type_enum
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
HANCUTILS_API BLUE_INT32  vanc_pkt_extract( BLUE_UINT32 CardType,
											BLUE_UINT32 vanc_pkt_type,
											BLUE_UINT32* src_vanc_buffer,
											BLUE_UINT32 src_vanc_buffer_size,
											BLUE_UINT32 pixels_per_line,
											BLUE_UINT32 vanc_pkt_did,
											BLUE_UINT16* vanc_pkt_sdid,
											BLUE_UINT16* vanc_pkt_data_length,
											BLUE_UINT16* vanc_pkt_data_ptr,
											BLUE_UINT16* vanc_pkt_line_no);

/**
@brief use this function to insert ANC packets into the VANC space of the HD cards.
@param CardType type of the card from which the vanc buffer was captured.
@param vanc_pkt_type This parameter denotes whether to search for the VANC packet in Y Space or Cb/Cr Space.
					 The values this parameter accepts are defined in the enumerator #blue_vanc_pkt_type_enum
@param vanc_pkt_line_no line in th VANC buffer where the ANC packet should inserted.
@param vanc_pkt_buffer vanc ANC packet which should be inserted into the VANC buffer.
@param vanc_pkt_buffer_size size of the ANC packet including the checksum ,ADF , SDID, DID and Data Count
@param dest_vanc_buffer VANC buffer into which the ANC packet will be inserted into.
@param pixels_per_line specifies how many pixels are there in each line of VANC buffer
*/
HANCUTILS_API BLUE_INT32 vanc_pkt_insert(	BLUE_UINT32 CardType,
											BLUE_UINT32 vanc_pkt_type,
											BLUE_UINT32 vanc_pkt_line_no,
											BLUE_UINT32* vanc_pkt_buffer,
											BLUE_UINT32 vanc_pkt_buffer_size,
											BLUE_UINT32* dest_vanc_buffer,
											BLUE_UINT32 pixels_per_line);

HANCUTILS_API BLUE_UINT32 decode_eia_708b_pkt(BLUE_UINT32 CardType,BLUE_UINT16 * vanc_pkt_data_ptr,BLUE_UINT16 pkt_udw_count,BLUE_UINT16 eia_pkt_subtype,BLUE_UINT8 * decoded_ch_str);


#ifdef __cplusplus
}
#endif

#endif //HG_BLUE_HANCUTILS_HG
