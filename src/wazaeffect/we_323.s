//==============================================================================
/**
 * @file	we_323.s
 * @brief	�����ӂ�			323
 * @author	goto
 * @date	2005.07.13(��)
 *
 * �����ɐF�X�ȉ�����������Ă��悢
 *
 */
//==============================================================================
	
	.text
	
	.include	"west.h"

	.global		WEST_SIOHUKI
	
// =============================================================================
//
//
//	�������ӂ�			323
//
//
// =============================================================================
WEST_SIOHUKI:
	LOAD_PARTICLE_DROP	0,W_323_SPA
		
	///< �k�ޓ���	
	FUNC_CALL		WEST_SP_WE_SSP_POKE_SCALE_UPDOWN, 8, (WE_TOOL_M1 | WE_TOOL_SSP), 100, 110, 100,  80, 100, (5 << 16) | 1, (5 << 16) | 5
	SE_L			SEQ_SE_DP_W029
	WAIT_FLAG

	FUNC_CALL		WEST_SP_WE_SSP_POKE_SCALE_UPDOWN, 8, (WE_TOOL_M1 | WE_TOOL_SSP), 100, 100, 100, 120, 100, (0 << 16) | 1, (5 << 16) | 5
	
	ADD_PARTICLE 	0,W_323_323_WATER_UP1, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_SP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	ADD_PARTICLE 	0,W_323_323_WATER_UP2, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_SP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	WAIT			10
	SE_L			SEQ_SE_DP_W291
	WAIT			5

	ADD_PARTICLE 	0,W_323_323_WATER_DOWN1, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	ADD_PARTICLE 	0,W_323_323_WATER_DOWN2, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	ADD_PARTICLE 	0,W_323_323_WATER_HIT, EMTFUNC_DF_SIDE
	
	///< �_���[�W�U��
	WAIT			2
	SE_R			SEQ_SE_DP_W057
	FUNC_CALL		WEST_SP_WT_SHAKE, 5, 1, 0, 1, 13,  WE_TOOL_E1 | WE_TOOL_SSP,
	FUNC_CALL		WEST_SP_WT_SHAKE, 5, 1, 0, 1, 13,  WE_TOOL_E2 | WE_TOOL_SSP,

	WAIT_FLAG

	WAIT_PARTICLE
	EXIT_PARTICLE	0,
	
	SEQEND