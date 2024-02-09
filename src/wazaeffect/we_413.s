//==============================================================================
/**
 * @file	we_001.s
 * @brief	�͂���
 * @author	goto
 * @date	2005.07.13(��)
 *
 * �����ɐF�X�ȉ�����������Ă��悢
 *
 */
//==============================================================================
	
	.text
	
	.include	"west.h"

	.global		WEST_Hataku
	
// =============================================================================
//
//
//	���͂���
//
//
// =============================================================================
///< turn2
WEST_413:

	LOAD_PARTICLE_DROP	0,W_413_SPA	
	
	///< �w�i
	WORK_SET		WEDEF_GP_INDEX_SPEED_X,  WEDEF_HAIKEI_SPEED_X
	WORK_SET		WEDEF_GP_INDEX_SPEED_Y,  WEDEF_HAIKEI_SPEED_Y
	WORK_SET		WEDEF_GP_INDEX_SPEED_R,  1
	WORK_SET		WEDEF_GP_INDEX_SCREEN_R, 1
	WORK_SET		WEDEF_GP_INDEX_FADE_TYPE,  0
	HAIKEI_CHG		BG_ID_143, WEDEF_HAIKEI_MODE_FADE | WEDEF_HAIKEI_SBIT_MOVE
	HAIKEI_CHG_WAIT

	///< �������t�F�[�h�|�P
	POKEOAM_RES_INIT
	POKEOAM_RES_LOAD	0,
	POKEOAM_DROP	WEDEF_DROP_M1, WEDEF_POKE_AUTO_OFF, WEDEF_POKE_CAP_ID_0, WEDEF_POKE_RES_0
	PT_DROP_EX		WEDEF_DROP_M2, WEDEF_DROP_M2,
	
	FUNC_CALL		WEST_SP_WE_CAP_ALPHA_FADE, 6, 1, 16, 0, 0, 16, 8, 0, 0
	WAIT 1
	FUNC_CALL		WEST_SP_WE_SSP_POKE_VANISH, 2, WE_TOOL_M1, 1
	WAIT_FLAG
	POKE_OAM_ENABLE	WEDEF_POKE_CAP_ID_0, 0,
	POKE_OAM_ENABLE	WEDEF_POKE_CAP_ID_EX, 0,

	SE_FLOW_LR		SEQ_SE_DP_W360C

	CONTEST_JP		CONTEST

	SIDE_JP			0,WEST_413_SIDE_MINE, WEST_413_SIDE_ENEMY

	SEQEND

///< side mine
WEST_413_SIDE_MINE:

	ADD_PARTICLE 	0,W_413_413_BIRD_FIRE1A, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE,OPERATOR_TARGET_DF, OPERATOR_POS_LSP, OPERATOR_AXIS_AT, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE
	
	ADD_PARTICLE 	0,W_413_413_BIRD_BALL,	EMTFUNC_ATTACK_POS

	WAIT			15
	SE_R			SEQ_SE_DP_186
	FUNC_CALL		WEST_SP_WT_SHAKE, 5, 4, 0, 1, 6,  WE_TOOL_E1 | WE_TOOL_SSP,
	POKE_FADE_EZ	WE_PAL_RED, WE_TOOL_E1, 1	

	ADD_PARTICLE 	0,W_413_413_KIAI_HIT1, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	ADD_PARTICLE 	0,W_413_413_KIAI_HIT2, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	ADD_PARTICLE 	0,W_413_413_HIT_MARK1, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE
	
	ADD_PARTICLE 	0,W_413_413_HIT_MARK2, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE
	
	ADD_PARTICLE 	0,W_413_413_HIT_MARK3, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE


	WAIT_PARTICLE
	EXIT_PARTICLE	0,

	POKE_OAM_ENABLE	WEDEF_POKE_CAP_ID_0, 1,
	POKE_OAM_ENABLE	WEDEF_POKE_CAP_ID_EX, 1,
	FUNC_CALL		WEST_SP_WE_CAP_ALPHA_FADE, 6, 1, 0, 16, 16, 0, 8, 0, 0
	WAIT			7
	FUNC_CALL		WEST_SP_WE_SSP_POKE_VANISH, 2, WE_TOOL_M1, 0

	WORK_SET		WEDEF_GP_INDEX_SPEED_X,  WEDEF_HAIKEI_SPEED_X
	WORK_SET		WEDEF_GP_INDEX_SPEED_Y,  WEDEF_HAIKEI_SPEED_Y
	WORK_SET		WEDEF_GP_INDEX_SPEED_R,  1
	WORK_SET		WEDEF_GP_INDEX_SCREEN_R, 1
	WORK_SET		WEDEF_GP_INDEX_FADE_TYPE,  0
	HAIKEI_RECOVER	BG_ID_143, WEDEF_HAIKEI_RC_MODE_FADE | WEDEF_HAIKEI_SBIT_STOP
	HAIKEI_CHG_WAIT

	POKEOAM_RES_FREE
	POKEOAM_DROP_RESET	WEDEF_POKE_CAP_ID_0
	PT_DROP_RESET_EX
	
	SEQEND
	
CONTEST:

	ADD_PARTICLE 	0,W_413_413_BIRD_FIRE1C, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE,OPERATOR_TARGET_DF, OPERATOR_POS_LSP, OPERATOR_AXIS_AT, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE
	
	ADD_PARTICLE 	0,W_413_413_BIRD_BALL,	EMTFUNC_ATTACK_POS

	WAIT			15
	SE_R			SEQ_SE_DP_186
	FUNC_CALL		WEST_SP_WT_SHAKE, 5, 4, 0, 1, 6,  WE_TOOL_E1 | WE_TOOL_SSP,
	POKE_FADE_EZ	WE_PAL_RED, WE_TOOL_E1, 1	

	ADD_PARTICLE 	0,W_413_413_KIAI_HIT1, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	///< 
	ADD_PARTICLE 	0,W_413_413_KIAI_HIT2, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	///< 
	ADD_PARTICLE 	0,W_413_413_HIT_MARK1, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE
	
	ADD_PARTICLE 	0,W_413_413_HIT_MARK2, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE
	
	ADD_PARTICLE 	0,W_413_413_HIT_MARK3, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE


	WAIT_PARTICLE
	EXIT_PARTICLE	0,

	POKE_OAM_ENABLE	WEDEF_POKE_CAP_ID_0, 1,
	POKE_OAM_ENABLE	WEDEF_POKE_CAP_ID_EX, 1,
	FUNC_CALL		WEST_SP_WE_CAP_ALPHA_FADE, 6, 1, 0, 16, 16, 0, 8, 0, 0
	WAIT			7
	FUNC_CALL		WEST_SP_WE_SSP_POKE_VANISH, 2, WE_TOOL_M1, 0

	WORK_SET		WEDEF_GP_INDEX_SPEED_X,  WEDEF_HAIKEI_SPEED_X
	WORK_SET		WEDEF_GP_INDEX_SPEED_Y,  WEDEF_HAIKEI_SPEED_Y
	WORK_SET		WEDEF_GP_INDEX_SPEED_R,  1
	WORK_SET		WEDEF_GP_INDEX_SCREEN_R, 1
	WORK_SET		WEDEF_GP_INDEX_FADE_TYPE,  0
	HAIKEI_RECOVER	BG_ID_143, WEDEF_HAIKEI_RC_MODE_FADE | WEDEF_HAIKEI_SBIT_STOP
	HAIKEI_CHG_WAIT

	POKEOAM_RES_FREE
	POKEOAM_DROP_RESET	WEDEF_POKE_CAP_ID_0
	PT_DROP_RESET_EX
	
	SEQEND

///< side enemy
WEST_413_SIDE_ENEMY:

	ADD_PARTICLE 	0,W_413_413_BIRD_FIRE1B, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE,OPERATOR_TARGET_DF, OPERATOR_POS_LSP, OPERATOR_AXIS_AT, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	ADD_PARTICLE 	0,W_413_413_BIRD_BALL,	EMTFUNC_ATTACK_POS
//	ADD_PARTICLE 	0,W_413_413_BIRD_BALL2,	EMTFUNC_ATTACK_POS
	
	WAIT			15
	SE_R			SEQ_SE_DP_186
	FUNC_CALL		WEST_SP_WT_SHAKE, 5, 4, 0, 1, 6,  WE_TOOL_E1 | WE_TOOL_SSP,
	POKE_FADE_EZ	WE_PAL_RED, WE_TOOL_E1, 1	

	ADD_PARTICLE 	0,W_413_413_KIAI_HIT1, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	///< 
	ADD_PARTICLE 	0,W_413_413_KIAI_HIT2, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE

	///< 
	ADD_PARTICLE 	0,W_413_413_HIT_MARK1, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE
	
	ADD_PARTICLE 	0,W_413_413_HIT_MARK2, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE
	
	ADD_PARTICLE 	0,W_413_413_HIT_MARK3, EMTFUNC_FIELD_OPERATOR
	EX_DATA			OPERATOR_DEF_DATA_NUM, OPERATOR_PRI_NONE, OPERATOR_TARGET_DF, OPERATOR_POS_EP, OPERATOR_AXIS_NONE, OPERATOR_FLD_NONE, OPERATOR_CAMERA_NONE


	WAIT_PARTICLE
	EXIT_PARTICLE	0,

	POKE_OAM_ENABLE	WEDEF_POKE_CAP_ID_0, 1,
	POKE_OAM_ENABLE	WEDEF_POKE_CAP_ID_EX, 1,
	FUNC_CALL		WEST_SP_WE_CAP_ALPHA_FADE, 6, 1, 0, 16, 16, 0, 8, 0, 0
	WAIT			7
	FUNC_CALL		WEST_SP_WE_SSP_POKE_VANISH, 2, WE_TOOL_M1, 0

	WORK_SET		WEDEF_GP_INDEX_SPEED_X,  WEDEF_HAIKEI_SPEED_X
	WORK_SET		WEDEF_GP_INDEX_SPEED_Y,  WEDEF_HAIKEI_SPEED_Y
	WORK_SET		WEDEF_GP_INDEX_SPEED_R,  1
	WORK_SET		WEDEF_GP_INDEX_SCREEN_R, 1
	WORK_SET		WEDEF_GP_INDEX_FADE_TYPE,  0
	HAIKEI_RECOVER	BG_ID_143, WEDEF_HAIKEI_RC_MODE_FADE | WEDEF_HAIKEI_SBIT_STOP
	HAIKEI_CHG_WAIT

	POKEOAM_RES_FREE
	POKEOAM_DROP_RESET	WEDEF_POKE_CAP_ID_0
	PT_DROP_RESET_EX
	
	SEQEND