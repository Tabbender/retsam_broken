//==============================================================================
/**
 * @file	we_114.s
 * @brief	���낢����			114
 * @author	goto
 * @date	2005.07.13(��)
 *
 * �����ɐF�X�ȉ�����������Ă��悢
 *
 */
//==============================================================================
	
	.text
	
	.include	"west.h"

	.global		WEST_KUROIKIRI
	
// =============================================================================
//
//
//	�����낢����			114
//
//
// =============================================================================
WEST_KUROIKIRI:
	
	LOAD_PARTICLE_DROP	0,W_114_SPA
	ADD_PARTICLE 	0,W_114_114_KUROKIRI_MIST1, EMTFUNC_DUMMY

	SE_C			SEQ_SE_DP_W114

	WAIT_PARTICLE
	EXIT_PARTICLE	0,
	
	SEQEND