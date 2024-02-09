//==============================================================================
/**
 * @file	we_320.s
 * @brief	くさぶえ			320
 * @author	goto
 * @date	2005.07.13(水)
 *
 * ここに色々な解説等を書いてもよい
 *
 */
//==============================================================================
	
	.text
	
	.include	"west.h"

	.global		WEST_KUSABUE
	
// =============================================================================
//
//
//	■くさぶえ			320
//
//
// =============================================================================
#define KUSABUE_RES_NO		(0)
#define KUSABUE_RES_NUM		(1)
#define KUSABUE_ACT_NUM		(15)

#define KUSABUE_BG_PAL_FADE	( 0 )
#define KUSABUE_BG_PAL_FADE_WAIT	(1)
//#define KUSABUE_BG_PAL_FADE_COL	(0x0)
#define KUSABUE_BG_PAL_FADE_COL	(WE_PAL_GREEN)
WEST_KUSABUE:

	SIDE_JP		0, SIDE_MINE, SIDE_ENEMY
	
	SEQEND

SIDE_MINE:

	LOAD_PARTICLE_DROP	0,W_320_SPA

	///<背景変更
	FUNC_CALL	WEST_SP_WE_HAIKEI_PAL_FADE, 5, KUSABUE_BG_PAL_FADE, KUSABUE_BG_PAL_FADE_WAIT, 0, 8, KUSABUE_BG_PAL_FADE_COL,
	WAIT_FLAG
	ADD_PARTICLE 	0,W_320_320_ONPU_BEAM, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_L320SP, OPERATOR_AXIS_AT_320, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE
	
	SE_FLOW_LR		SEQ_SE_DP_W320

	WAIT_PARTICLE
	EXIT_PARTICLE	0,

	///<背景変更
	FUNC_CALL	WEST_SP_WE_HAIKEI_PAL_FADE, 5, KUSABUE_BG_PAL_FADE, KUSABUE_BG_PAL_FADE_WAIT, 8, 0, KUSABUE_BG_PAL_FADE_COL, 0, 0, 0
	WAIT_FLAG

	SEQEND
	
SIDE_ENEMY:

	LOAD_PARTICLE_DROP	0,W_320_SPA

	///<背景変更
	FUNC_CALL	WEST_SP_WE_HAIKEI_PAL_FADE, 5, KUSABUE_BG_PAL_FADE, KUSABUE_BG_PAL_FADE_WAIT, 0, 8, KUSABUE_BG_PAL_FADE_COL,
	WAIT_FLAG
	ADD_PARTICLE 	0,W_320_320_ONPU_BEAM, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_L320SP, OPERATOR_AXIS_AT_320, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	SE_FLOW_LR		SEQ_SE_DP_W320

	WAIT_PARTICLE
	EXIT_PARTICLE	0,

	///<背景変更
	FUNC_CALL	WEST_SP_WE_HAIKEI_PAL_FADE, 5, KUSABUE_BG_PAL_FADE, KUSABUE_BG_PAL_FADE_WAIT, 8, 0, KUSABUE_BG_PAL_FADE_COL, 0, 0, 0
	WAIT_FLAG

	SEQEND
