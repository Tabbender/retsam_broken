//==============================================================================
/**
 * @file	codein.h
 * @brief	�������̓C���^�[�t�F�[�X
 * @author	goto
 * @date	2007.07.11(��)
 *
 * �����ɐF�X�ȉ�����������Ă��悢
 *
 */
//==============================================================================
#ifndef __CODEIN_H__
#define __CODEIN_H__

#include "gflib/strbuf.h"
#include "savedata/config.h"
#include "gflib/button_man.h"

#define CODE_BLOCK_MAX		( 4 )		///< ���̓u���b�N�ő吔

// -----------------------------------------
//
//	�Ăяo�����ŊǗ����郏�[�N
//
// -----------------------------------------
typedef struct {
	
//	int			heap_id;					///< �g�p����HEAPID
	int			word_len;					///< ���͕�����	// 0x3b8
	int			block[ CODE_BLOCK_MAX + 1 ];///< ���̓u���b�N�@xx-xxxx-xxx �Ƃ� // 0x3bc
	
	int			end_state;					///< �I�����̏�� // 0x3d0
	STRBUF*		strbuf;						///< �󗓂Ȃ�o�b�t�@�����łȂ���΃f�t�H���g�l // 0x3d4
	
	CONFIG*		cfg;						///< window_type�擾�p // 0x3d8

	int unk24; // 0x3dc
    u32 unk28; // 0x3e0
    u32 unk2c; // 0x3e4
    u32 unk30; // 0x3e8
    // 0x3ec
} CODEIN_PARAM;

extern const PROC_DATA CodeInput_ProcData;

extern CODEIN_PARAM*	CodeInput_ParamCreate( int heap_id, int word_len, int block[], CONFIG* cfg, u32 a4, u32 a5 );
extern void				CodeInput_ParamDelete( CODEIN_PARAM* codein_param );
extern CODEIN_PARAM* sub_2089400( int heap_id, int word_len, int block[], CONFIG* cfg, u32 a4, u32 a5 );
extern CODEIN_PARAM* sub_208941C( int heap_id, int word_len, int block[], CONFIG* cfg, u32 a4, u32 a5, u32 a6, u32 a7 );


//--------------------------------------------------------------
/**
 * @brief	xxxx-xxxx-xxxx �̃u���b�N��`�����
 *
 * @param	block[]	
 *
 * @retval	static inline	
 *
 */
//--------------------------------------------------------------
static inline void CodeIn_BlockDataMake_4_4_4( int block[] )
{
#if 1
	block[ 0 ] = 4;
	block[ 1 ] = 4;
	block[ 2 ] = 4;
    block[ 3 ] = 0; // MatchComment: add this line
#else
	block[ 0 ] = 2;
	block[ 1 ] = 5;
	block[ 2 ] = 5;
#endif
}


//--------------------------------------------------------------
/**
 * @brief	xx-xxxxx-xxxxx �̃u���b�N��`�����
 *
 * @param	block[]	
 *
 * @retval	static inline	
 *
 */
//--------------------------------------------------------------
static inline void CodeIn_BlockDataMake_2_5_5( int block[] )
{
	block[ 0 ] = 2;
	block[ 1 ] = 5;
	block[ 2 ] = 5;
}

#endif	///< __CODEIN_H__
