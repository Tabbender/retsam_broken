
//============================================================================
/**
 *
 *@file		sub_009.s
 *@brief	�퓬�V�[�P���X
 *			�|�P��������ւ��V�[�P���X
 *@author	HisashiSogabe
 *@data		2005.07.29
 *
 */
//============================================================================
	.text

	.include	"waza_seq_def.h"

SUB_009:
	//���������񂩂��ӂ��������Ă�����A��Ԉُ�𒼂�
	SIZENKAIHUKU_CHECK	SIDE_RESHUFFLE,SUB_009_START
	PSP_VALUE			VAL_SET,SIDE_RESHUFFLE,ID_PSP_condition,0
SUB_009_START:
	MODOSU_MESSAGE		SIDE_RESHUFFLE
	SERVER_WAIT
	GOSUB				SUB_SEQ_OIUCHI
//	IF					IF_FLAG_NBIT,BUF_PARA_SERVER_STATUS_FLAG,SERVER_STATUS_FLAG_KIZETSU,SUB_009_NEXT
	IF_PSP				IF_FLAG_NE,SIDE_RESHUFFLE,ID_PSP_hp,0,SUB_009_NEXT
//	GOSUB				SUB_SEQ_KIZETSU
	BRANCH				SUB_009_NEXT2
SUB_009_NEXT:
	POKEMON_RETURN		SIDE_RESHUFFLE
	SERVER_WAIT
	HP_GAUGE_OUT		SIDE_RESHUFFLE
	SERVER_WAIT
SUB_009_NEXT2:
	POKEMON_RESHUFFLE	SIDE_RESHUFFLE
	BALL_GAUGE_RESOURCE_LOAD
	BALL_GAUGE_SET		SIDE_RESHUFFLE
	SERVER_WAIT
	//TEMP_WORK��1�̎��́A�G���m���ł��ꂩ�����p�̃��b�Z�[�W���o��
	IF					IF_FLAG_EQ,BUF_PARA_TEMP_WORK,1,ENEMY_RESHUFFLE_MESSAGE
	KURIDASU_MESSAGE	SIDE_RESHUFFLE
	BRANCH				SUB_009_NEXT3
ENEMY_RESHUFFLE_MESSAGE:
	MESSAGE				AppearMsg_0,TAG_NICK,SIDE_RESHUFFLE
SUB_009_NEXT3:
	SERVER_WAIT
	BALL_GAUGE_OUT		SIDE_RESHUFFLE
	SERVER_WAIT
	BALL_GAUGE_RESOURCE_DELETE
	POKEMON_APPEAR		SIDE_RESHUFFLE
	WAIT_NO_SKIP		ENCOUNT_WAIT_RESHUFFLE
	HP_GAUGE_IN			SIDE_RESHUFFLE
	SERVER_WAIT
	GOSUB				SUB_SEQ_MAKIBISI_CHECK
#if AFTER_MASTER_070202_BT5_FIX
	//�C��t���O��sp->kizetsu_client���r���ăt���O�������Ă���̂ɌĂ΂ꂽ���̃X���[�`�F�b�N������
	//�C��N���C�A���g��0�`3�łȂ��ꍇ�͋C�₵���|�P�����͂��Ȃ��̂ŁA�X���[
	IF					IF_FLAG_C,BUF_PARA_KIZETSU_CLIENT,CLIENT_MAX-1,SUB_009_END
	VALUE_WORK			VAL_TO_BIT,BUF_PARA_TEMP_WORK,BUF_PARA_KIZETSU_CLIENT
	VALUE				VAL_LSH,BUF_PARA_TEMP_WORK,SERVER_STATUS_FLAG_KIZETSU_SHIFT
	IF_WORK				IF_FLAG_NBIT,BUF_PARA_SERVER_STATUS_FLAG,BUF_PARA_TEMP_WORK,SUB_009_END
#else //AFTER_MASTER_070202_BT5_FIX
	//�C�₵�Ă�����A�C��G�t�F�N�g��
	IF					IF_FLAG_NBIT,BUF_PARA_SERVER_STATUS_FLAG,SERVER_STATUS_FLAG_KIZETSU,SUB_009_END
#endif //AFTER_MASTER_070202_BT5_FIX
	GOSUB				SUB_SEQ_KIZETSU
SUB_009_END:
	SEQ_END