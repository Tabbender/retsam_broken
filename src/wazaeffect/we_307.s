//==============================================================================
/**
 * @file	we_307.s
 * @brief	�u���X�g�o�[��			307
 * @author	goto
 * @date	2005.07.13(��)
 *
 * �����ɐF�X�ȉ�����������Ă��悢
 *
 */
//==============================================================================
	
	.text
	
	.include	"west.h"

	.global		WEST_BURASUTOBAAN
	
// =============================================================================
//
//
//	���u���X�g�o�[��			307
//
//
// =============================================================================
#define WE307_RX_1		(48)
#define WE307_RY_1		(24)
#define WE307_RX_2		(64)
#define WE307_RY_2		(WE307_RY_1)
#define WE307_RX_3		(92)
#define WE307_RY_3		(WE307_RY_1)
#define WE307_WAIT		(7)
#define WE307_WAIT_M	(8)
#define WE307_RAD_B		(360 / 8)
#define WE307_RAD_S(n)	(45 + (n * WE307_RAD_B))
#define WE307_RAD_E(n)	(45 + (n * WE307_RAD_B))

///< �Ȃ񂶂Ⴑ��ᥥ�
#define WE307_RADM_S(n)	(270 - (45 + ((8-n) * WE307_RAD_B)))
#define WE307_RADM_E(n)	(270 - (45 + ((8-n) * WE307_RAD_B)))

#define WE307_NUM		(10)
#define WE307_TR	(0)	///< 0 = ����

WEST_BURASUTOBAAN:
	
	SIDE_JP		0, SIDE_MINE, SIDE_ENEMY

	SEQEND


SIDE_MINE:
/*
	WORK_CLEAR
	WORK_SET		WEDEF_GP_INDEX_SPEED_R,  1
	WORK_SET		WEDEF_GP_INDEX_SCREEN_R, 1
	HAIKEI_CHG		BG_ID_200, WEDEF_HAIKEI_MODE_FADE | WEDEF_HAIKEI_SBIT_NONE
	HAIKEI_CHG_WAIT
*/	

	LOAD_PARTICLE_DROP	0,W_307_SPA
	LOAD_PARTICLE_DROP	1,W_053_SPA

	FUNC_CALL		WEST_SP_WE_HAIKEI_PAL_FADE, 5, 0, 1, 0, 12, WE_PAL_RED_BROWN,
	WAIT_FLAG

	SE_REPEAT_L		SEQ_SE_DP_W085,1,2

	POKEOAM_RES_INIT
	POKEOAM_RES_LOAD	WEDEF_POKE_RES_0
	POKEOAM_RES_LOAD	WEDEF_POKE_RES_1

	POKEOAM_DROP		WEDEF_DROP_M1, WEDEF_POKE_AUTO_OFF, WEDEF_POKE_CAP_ID_0, WEDEF_POKE_RES_0
	POKEOAM_DROP		WEDEF_DROP_M2, WEDEF_POKE_AUTO_OFF, WEDEF_POKE_CAP_ID_1, WEDEF_POKE_RES_1	
	FUNC_CALL			WEST_SP_POKE_OAM_VIEW,	5, WEDEF_POKE_CAP_ID_0, 31, WT_BF_3DFRAME, 0, WEDEF_DROP_M1
	FUNC_CALL			WEST_SP_POKE_OAM_VIEW,	5, WEDEF_POKE_CAP_ID_1, 30, WT_BF_3DFRAME, 0, WEDEF_DROP_M2
	
	ADD_PARTICLE_EMIT_SET	0, 3, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 3, WE307_RADM_S(1), WE307_RADM_E(1), WE307_RADM_S(1), WE307_RADM_E(1), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 4, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 4, WE307_RADM_S(1), WE307_RADM_E(1), WE307_RADM_S(1), WE307_RADM_E(1), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 5, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 5, WE307_RADM_S(1), WE307_RADM_E(1), WE307_RADM_S(1), WE307_RADM_E(1), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 6, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 6, WE307_RADM_S(2), WE307_RADM_E(2), WE307_RADM_S(2), WE307_RADM_E(2), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 7, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 7, WE307_RADM_S(2), WE307_RADM_E(2), WE307_RADM_S(2), WE307_RADM_E(2), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 8, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 8, WE307_RADM_S(2), WE307_RADM_E(2), WE307_RADM_S(2), WE307_RADM_E(2), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RADM_S(3), WE307_RADM_E(3), WE307_RADM_S(3), WE307_RADM_E(3), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RADM_S(3), WE307_RADM_E(3), WE307_RADM_S(3), WE307_RADM_E(3), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RADM_S(3), WE307_RADM_E(3), WE307_RADM_S(3), WE307_RADM_E(3), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RADM_S(4), WE307_RADM_E(4), WE307_RADM_S(4), WE307_RADM_E(4), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RADM_S(4), WE307_RADM_E(4), WE307_RADM_S(4), WE307_RADM_E(4), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RADM_S(4), WE307_RADM_E(4), WE307_RADM_S(4), WE307_RADM_E(4), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0,12, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,12, WE307_RADM_S(5), WE307_RADM_E(5), WE307_RADM_S(5), WE307_RADM_E(5), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,13, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,13, WE307_RADM_S(5), WE307_RADM_E(5), WE307_RADM_S(5), WE307_RADM_E(5), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,14, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,14, WE307_RADM_S(5), WE307_RADM_E(5), WE307_RADM_S(5), WE307_RADM_E(5), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0

	WAIT			WE307_WAIT_M
	SE_REPEAT_L		SEQ_SE_DP_W085,1,2
	
	ADD_PARTICLE_EMIT_SET	0, 3, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 3, WE307_RADM_S(1), WE307_RADM_E(1), WE307_RADM_S(1), WE307_RADM_E(1), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 4, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 4, WE307_RADM_S(1), WE307_RADM_E(1), WE307_RADM_S(1), WE307_RADM_E(1), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 5, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 5, WE307_RADM_S(1), WE307_RADM_E(1), WE307_RADM_S(1), WE307_RADM_E(1), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 6, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 6, WE307_RADM_S(2), WE307_RADM_E(2), WE307_RADM_S(2), WE307_RADM_E(2), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 7, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 7, WE307_RADM_S(2), WE307_RADM_E(2), WE307_RADM_S(2), WE307_RADM_E(2), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 8, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 8, WE307_RADM_S(2), WE307_RADM_E(2), WE307_RADM_S(2), WE307_RADM_E(2), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RADM_S(3), WE307_RADM_E(3), WE307_RADM_S(3), WE307_RADM_E(3), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RADM_S(3), WE307_RADM_E(3), WE307_RADM_S(3), WE307_RADM_E(3), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RADM_S(3), WE307_RADM_E(3), WE307_RADM_S(3), WE307_RADM_E(3), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RADM_S(4), WE307_RADM_E(4), WE307_RADM_S(4), WE307_RADM_E(4), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RADM_S(4), WE307_RADM_E(4), WE307_RADM_S(4), WE307_RADM_E(4), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RADM_S(4), WE307_RADM_E(4), WE307_RADM_S(4), WE307_RADM_E(4), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0,12, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,12, WE307_RADM_S(5), WE307_RADM_E(5), WE307_RADM_S(5), WE307_RADM_E(5), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,13, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,13, WE307_RADM_S(5), WE307_RADM_E(5), WE307_RADM_S(5), WE307_RADM_E(5), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,14, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,14, WE307_RADM_S(5), WE307_RADM_E(5), WE307_RADM_S(5), WE307_RADM_E(5), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0

	WAIT			WE307_WAIT_M
	SE_REPEAT_L		SEQ_SE_DP_W085,1,2

	ADD_PARTICLE_EMIT_SET	0, 3, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 3, WE307_RADM_S(1), WE307_RADM_E(1), WE307_RADM_S(1), WE307_RADM_E(1), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 4, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 4, WE307_RADM_S(1), WE307_RADM_E(1), WE307_RADM_S(1), WE307_RADM_E(1), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 5, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 5, WE307_RADM_S(1), WE307_RADM_E(1), WE307_RADM_S(1), WE307_RADM_E(1), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 6, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 6, WE307_RADM_S(2), WE307_RADM_E(2), WE307_RADM_S(2), WE307_RADM_E(2), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 7, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 7, WE307_RADM_S(2), WE307_RADM_E(2), WE307_RADM_S(2), WE307_RADM_E(2), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 8, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 8, WE307_RADM_S(2), WE307_RADM_E(2), WE307_RADM_S(2), WE307_RADM_E(2), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RADM_S(3), WE307_RADM_E(3), WE307_RADM_S(3), WE307_RADM_E(3), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RADM_S(3), WE307_RADM_E(3), WE307_RADM_S(3), WE307_RADM_E(3), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RADM_S(3), WE307_RADM_E(3), WE307_RADM_S(3), WE307_RADM_E(3), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RADM_S(4), WE307_RADM_E(4), WE307_RADM_S(4), WE307_RADM_E(4), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RADM_S(4), WE307_RADM_E(4), WE307_RADM_S(4), WE307_RADM_E(4), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RADM_S(4), WE307_RADM_E(4), WE307_RADM_S(4), WE307_RADM_E(4), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0,12, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,12, WE307_RADM_S(5), WE307_RADM_E(5), WE307_RADM_S(5), WE307_RADM_E(5), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,13, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,13, WE307_RADM_S(5), WE307_RADM_E(5), WE307_RADM_S(5), WE307_RADM_E(5), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,14, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,14, WE307_RADM_S(5), WE307_RADM_E(5), WE307_RADM_S(5), WE307_RADM_E(5), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	
	WAIT			WE307_WAIT_M
	SE_R			SEQ_SE_DP_W379
	ADD_PARTICLE 	1,W_053_053_FIRE_HIT, EMTFUNC_DEFENCE_POS	
	FUNC_CALL		WEST_SP_WE_SSP_POKE_PAL_FADE, 6,  WE_TOOL_E1, 0, 1, WE_PAL_RED, WEDEF_FADE_PARAM, 0
	FUNC_CALL		WEST_SP_WT_SHAKE, 5, SHAKE_M_X, 0, SHAKE_M_WAIT, SHAKE_M_NUM,  WE_TOOL_E1 | WE_TOOL_SSP,

	WAIT_PARTICLE
	EXIT_PARTICLE	0,
	EXIT_PARTICLE	1,

	WAIT_FLAG
	POKEOAM_DROP_RESET	WEDEF_POKE_CAP_ID_0
	POKEOAM_DROP_RESET	WEDEF_POKE_CAP_ID_1

	POKEOAM_RES_FREE
	
	FUNC_CALL		WEST_SP_WE_HAIKEI_PAL_FADE, 5, 0, 1, 12, 0, WE_PAL_RED_BROWN,
	WAIT_FLAG
/*
	WORK_CLEAR
	WORK_SET		WEDEF_GP_INDEX_SPEED_R,  1
	WORK_SET		WEDEF_GP_INDEX_SCREEN_R, 1
	HAIKEI_RECOVER	BG_ID_200, WEDEF_HAIKEI_RC_MODE_FADE | WEDEF_HAIKEI_SBIT_NONE
	HAIKEI_CHG_WAIT	
*/
	SEQEND
	
	
SIDE_ENEMY:
/*
	WORK_CLEAR
	WORK_SET		WEDEF_GP_INDEX_SPEED_R,  1
	WORK_SET		WEDEF_GP_INDEX_SCREEN_R, 1
	HAIKEI_CHG		BG_ID_200, WEDEF_HAIKEI_MODE_FADE | WEDEF_HAIKEI_SBIT_NONE
	HAIKEI_CHG_WAIT
*/	

	LOAD_PARTICLE_DROP	0,W_307_SPA
	LOAD_PARTICLE_DROP	1,W_053_SPA

	FUNC_CALL		WEST_SP_WE_HAIKEI_PAL_FADE, 5, 0, 1, 0, 12, WE_PAL_RED_BROWN,
	WAIT_FLAG
	
	SE_REPEAT_L		SEQ_SE_DP_W085,1,2
	
	ADD_PARTICLE_EMIT_SET	0, 3, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 3, WE307_RAD_S(1), WE307_RAD_E(1), WE307_RAD_S(1), WE307_RAD_E(1), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 4, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 4, WE307_RAD_S(1), WE307_RAD_E(1), WE307_RAD_S(1), WE307_RAD_E(1), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 5, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 5, WE307_RAD_S(1), WE307_RAD_E(1), WE307_RAD_S(1), WE307_RAD_E(1), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 6, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 6, WE307_RAD_S(2), WE307_RAD_E(2), WE307_RAD_S(2), WE307_RAD_E(2), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 7, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 7, WE307_RAD_S(2), WE307_RAD_E(2), WE307_RAD_S(2), WE307_RAD_E(2), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 8, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 8, WE307_RAD_S(2), WE307_RAD_E(2), WE307_RAD_S(2), WE307_RAD_E(2), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RAD_S(3), WE307_RAD_E(3), WE307_RAD_S(3), WE307_RAD_E(3), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RAD_S(3), WE307_RAD_E(3), WE307_RAD_S(3), WE307_RAD_E(3), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RAD_S(3), WE307_RAD_E(3), WE307_RAD_S(3), WE307_RAD_E(3), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RAD_S(4), WE307_RAD_E(4), WE307_RAD_S(4), WE307_RAD_E(4), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RAD_S(4), WE307_RAD_E(4), WE307_RAD_S(4), WE307_RAD_E(4), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RAD_S(4), WE307_RAD_E(4), WE307_RAD_S(4), WE307_RAD_E(4), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0,12, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,12, WE307_RAD_S(5), WE307_RAD_E(5), WE307_RAD_S(5), WE307_RAD_E(5), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,13, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,13, WE307_RAD_S(5), WE307_RAD_E(5), WE307_RAD_S(5), WE307_RAD_E(5), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,14, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,14, WE307_RAD_S(5), WE307_RAD_E(5), WE307_RAD_S(5), WE307_RAD_E(5), WE307_RX_1, WE307_RY_1, WE307_WAIT, WE307_TR, 0

	WAIT			WE307_WAIT_M
	SE_REPEAT_L		SEQ_SE_DP_W085,1,2

	ADD_PARTICLE_EMIT_SET	0, 3, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 3, WE307_RAD_S(1), WE307_RAD_E(1), WE307_RAD_S(1), WE307_RAD_E(1), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 4, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 4, WE307_RAD_S(1), WE307_RAD_E(1), WE307_RAD_S(1), WE307_RAD_E(1), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 5, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 5, WE307_RAD_S(1), WE307_RAD_E(1), WE307_RAD_S(1), WE307_RAD_E(1), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 6, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 6, WE307_RAD_S(2), WE307_RAD_E(2), WE307_RAD_S(2), WE307_RAD_E(2), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 7, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 7, WE307_RAD_S(2), WE307_RAD_E(2), WE307_RAD_S(2), WE307_RAD_E(2), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 8, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 8, WE307_RAD_S(2), WE307_RAD_E(2), WE307_RAD_S(2), WE307_RAD_E(2), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RAD_S(3), WE307_RAD_E(3), WE307_RAD_S(3), WE307_RAD_E(3), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RAD_S(3), WE307_RAD_E(3), WE307_RAD_S(3), WE307_RAD_E(3), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RAD_S(3), WE307_RAD_E(3), WE307_RAD_S(3), WE307_RAD_E(3), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RAD_S(4), WE307_RAD_E(4), WE307_RAD_S(4), WE307_RAD_E(4), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RAD_S(4), WE307_RAD_E(4), WE307_RAD_S(4), WE307_RAD_E(4), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RAD_S(4), WE307_RAD_E(4), WE307_RAD_S(4), WE307_RAD_E(4), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0,12, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,12, WE307_RAD_S(5), WE307_RAD_E(5), WE307_RAD_S(5), WE307_RAD_E(5), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,13, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,13, WE307_RAD_S(5), WE307_RAD_E(5), WE307_RAD_S(5), WE307_RAD_E(5), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,14, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,14, WE307_RAD_S(5), WE307_RAD_E(5), WE307_RAD_S(5), WE307_RAD_E(5), WE307_RX_2, WE307_RY_2, WE307_WAIT, WE307_TR, 0

	WAIT			WE307_WAIT_M
	SE_REPEAT_L		SEQ_SE_DP_W085,1,2

	ADD_PARTICLE_EMIT_SET	0, 3, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 3, WE307_RAD_S(1), WE307_RAD_E(1), WE307_RAD_S(1), WE307_RAD_E(1), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 4, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 4, WE307_RAD_S(1), WE307_RAD_E(1), WE307_RAD_S(1), WE307_RAD_E(1), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 5, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 5, WE307_RAD_S(1), WE307_RAD_E(1), WE307_RAD_S(1), WE307_RAD_E(1), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 6, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 6, WE307_RAD_S(2), WE307_RAD_E(2), WE307_RAD_S(2), WE307_RAD_E(2), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 7, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 7, WE307_RAD_S(2), WE307_RAD_E(2), WE307_RAD_S(2), WE307_RAD_E(2), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0, 8, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 8, WE307_RAD_S(2), WE307_RAD_E(2), WE307_RAD_S(2), WE307_RAD_E(2), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RAD_S(3), WE307_RAD_E(3), WE307_RAD_S(3), WE307_RAD_E(3), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RAD_S(3), WE307_RAD_E(3), WE307_RAD_S(3), WE307_RAD_E(3), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RAD_S(3), WE307_RAD_E(3), WE307_RAD_S(3), WE307_RAD_E(3), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0, 9, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM, 9, WE307_RAD_S(4), WE307_RAD_E(4), WE307_RAD_S(4), WE307_RAD_E(4), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,10, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,10, WE307_RAD_S(4), WE307_RAD_E(4), WE307_RAD_S(4), WE307_RAD_E(4), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,11, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,11, WE307_RAD_S(4), WE307_RAD_E(4), WE307_RAD_S(4), WE307_RAD_E(4), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	
	ADD_PARTICLE_EMIT_SET	0,12, W_307_307_FIRE1,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,12, WE307_RAD_S(5), WE307_RAD_E(5), WE307_RAD_S(5), WE307_RAD_E(5), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,13, W_307_307_FIRE2,		EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,13, WE307_RAD_S(5), WE307_RAD_E(5), WE307_RAD_S(5), WE307_RAD_E(5), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	ADD_PARTICLE_EMIT_SET	0,14, W_307_307_FIREBALL,	EMTFUNC_ATTACK_POS
	FUNC_CALL				WEST_SP_EMIT_ROTATION, WE307_NUM,14, WE307_RAD_S(5), WE307_RAD_E(5), WE307_RAD_S(5), WE307_RAD_E(5), WE307_RX_3, WE307_RY_3, WE307_WAIT, WE307_TR, 0
	
	WAIT			WE307_WAIT_M
	SE_R			SEQ_SE_DP_W379
	ADD_PARTICLE 	1,W_053_053_FIRE_HIT, EMTFUNC_DEFENCE_POS	
	FUNC_CALL		WEST_SP_WE_SSP_POKE_PAL_FADE, 6,  WE_TOOL_E1, 0, 1, WE_PAL_RED, WEDEF_FADE_PARAM, 0
	FUNC_CALL		WEST_SP_WT_SHAKE, 5, SHAKE_M_X, 0, SHAKE_M_WAIT, SHAKE_M_NUM,  WE_TOOL_E1 | WE_TOOL_SSP,

	WAIT_PARTICLE
	EXIT_PARTICLE	0,
	EXIT_PARTICLE	1,
	
	FUNC_CALL		WEST_SP_WE_HAIKEI_PAL_FADE, 5, 0, 1, 12, 0, WE_PAL_RED_BROWN,
	WAIT_FLAG
/*
	WORK_CLEAR
	WORK_SET		WEDEF_GP_INDEX_SPEED_R,  1
	WORK_SET		WEDEF_GP_INDEX_SCREEN_R, 1
	HAIKEI_RECOVER	BG_ID_200, WEDEF_HAIKEI_RC_MODE_FADE | WEDEF_HAIKEI_SBIT_NONE
	HAIKEI_CHG_WAIT	
*/
	SEQEND