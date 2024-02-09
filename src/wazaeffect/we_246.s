//==============================================================================
/**
 * @file	we_246.s
 * @brief	げんしのちから			246
 * @author	goto
 * @date	2005.07.13(水)
 *
 * ここに色々な解説等を書いてもよい
 *
 */
//==============================================================================
	
	.text
	
	.include	"west.h"

	.global		WEST_GENSINOTIKARA
	
// =============================================================================
//
//
//	■げんしのちから			246
//
//
// =============================================================================
WEST_GENSINOTIKARA:
	LOAD_PARTICLE_DROP	0,W_246_SPA
	
	CONTEST_JP		CONTEST
		
	SE_L			SEQ_SE_DP_W082

	ADD_PARTICLE 	0,W_246_246_STONE_UP, EMTFUNC_ATTACK_POS
	
	WAIT			10
	
	ADD_PARTICLE 	0,W_246_246_STONE_BEAM, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_SP, OPERATOR_AXIS_AT, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	WAIT			20
	SE_FLOW_LR		SEQ_SE_DP_050
	
	WAIT			20
	ADD_PARTICLE 	0,W_246_HIT_MARK01,		EMTFUNC_DEFENCE_POS
	ADD_PARTICLE 	0,W_246_IWA_BREAK01,	EMTFUNC_DEFENCE_POS
	
	SE_R			SEQ_SE_DP_W120
	FUNC_CALL		WEST_SP_WT_SHAKE, 5, SHAKE_M_X, 0, SHAKE_M_WAIT, SHAKE_M_NUM,  WE_TOOL_E1 | WE_TOOL_SSP,
	
	WAIT_PARTICLE
	EXIT_PARTICLE	0,
	
	SEQEND

CONTEST:

	SE_L			SEQ_SE_DP_W082

	ADD_PARTICLE 	0,W_246_246_STONE_UP, EMTFUNC_ATTACK_POS
	
	WAIT			10
	
	ADD_PARTICLE 	0,W_246_246_STONE_BEAM, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_SP, OPERATOR_AXIS_SET, OPERATOR_FLD_GRAVITY_MAG, OPERATOR_CAMERA_NONE
	EX_DATA			OPERATOR_FLD_EX_DATA_NUM, OPERATOR_FLD_SET, OPERATOR_EX_REVERCE_OFF, -120, -41, 0

	WAIT			20
	SE_FLOW_LR		SEQ_SE_DP_050
	
	WAIT			20
	ADD_PARTICLE 	0,W_246_HIT_MARK01,		EMTFUNC_DEFENCE_POS
	ADD_PARTICLE 	0,W_246_IWA_BREAK01,	EMTFUNC_DEFENCE_POS
	
	SE_R			SEQ_SE_DP_W120
	FUNC_CALL		WEST_SP_WT_SHAKE, 5, SHAKE_M_X, 0, SHAKE_M_WAIT, SHAKE_M_NUM,  WE_TOOL_E1 | WE_TOOL_SSP,
	
	WAIT_PARTICLE
	EXIT_PARTICLE	0,
	
	SEQEND