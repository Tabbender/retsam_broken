//==============================================================================
/**
 * @file	we_074.s
 * @brief	�������傤			74
 * @author	goto
 * @date	2005.07.13(��)
 *
 * �����ɐF�X�ȉ�����������Ă��悢
 *
 */
//==============================================================================
	
	.text
	
	.include	"west.h"

	.global		WEST_SEITYOU
	
// =============================================================================
//
//
//	���������傤			74
//
//
// =============================================================================
WEST_SEITYOU:
	
	FUNC_CALL		WEST_SP_WE_074, 0,0,0,0,0,0,0,0,0
	SE_L			SEQ_SE_DP_W036
	
	WAIT_FLAG

	SEQEND