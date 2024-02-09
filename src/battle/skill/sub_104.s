
//============================================================================
/**
 *
 *@file		sub_104.s
 *@brief	�퓬�V�[�P���X
 *			�V��n�p���V�[�P���X
 *@author	HisashiSogabe
 *@data		2006.01.27
 *
 */
//============================================================================
	.text

	.include	"waza_seq_def.h"

SUB_104:
	GOSUB				SUB_SEQ_MESSAGE_WORK
	STATUS_EFFECT_WORK	SIDE_MINE,BUF_PARA_TEMP_WORK
	SERVER_WAIT
	VALUE				VAL_SET,BUF_PARA_CLIENT_NO_AGI,0
TenkouDamageLoop:
	CLIENT_NO_GET_AGI	BUF_PARA_CLIENT_WORK
	TENKOU_DAMAGE		SIDE_WORK
	IF					IF_FLAG_EQ,BUF_PARA_TEMP_WORK,TENKOU_URUOIBODY,UruoiBodySeq
	IF					IF_FLAG_EQ,BUF_PARA_HP_CALC_WORK,0,TenkouDamageNext
	IF					IF_FLAG_C,BUF_PARA_HP_CALC_WORK,0,Kaifuku
	//�����}�W�b�N�K�[�h�́A�_���[�W���󂯂Ȃ�
	TOKUSEI_CHECK		TOKUSEI_HAVE,SIDE_WORK,TOKUSYU_MAZIKKUGAADO,TenkouDamageNext
	IF					IF_FLAG_BIT,BUF_PARA_FIELD_CONDITION,FIELD_CONDITION_HARE_ALL,KansouhadaDamage
Damage:
	MESSAGE				WeatherDamageMineMsg,TAG_WAZA_NICK,SIDE_WORK,SIDE_WORK
	BRANCH				HPCalc
KansouhadaDamage:
	IF					IF_FLAG_EQ,BUF_PARA_TEMP_WORK,TENKOU_SUNPOWER,SunPowerMsg
	MESSAGE				KansouhadaDamageMineMsg,TAG_NICK_TOKU,SIDE_WORK,SIDE_CLIENT_WORK
	BRANCH				HPCalc
SunPowerMsg:
	MESSAGE				TokuseiHPDecMineMsg,TAG_NICK_TOKU,SIDE_WORK,SIDE_CLIENT_WORK
HPCalc:
	SERVER_WAIT
	WAIT				MSG_WAIT
	GOSUB				SUB_SEQ_HP_CALC
	//�C�₵�Ă�����A�C��G�t�F�N�g��
	IF					IF_FLAG_NBIT,BUF_PARA_SERVER_STATUS_FLAG,SERVER_STATUS_FLAG_KIZETSU,TenkouDamageNext
	GOSUB				SUB_SEQ_KIZETSU
	BRANCH				TenkouDamageNext
Kaifuku:
	VALUE				VAL_BIT,BUF_PARA_SERVER_STATUS_FLAG,SERVER_STATUS_FLAG_NO_BLINK
	GOSUB				SUB_SEQ_HP_CALC
	MESSAGE				TokuseiHPKaifukuMineMsg,TAG_NICK_TOKU,SIDE_WORK,SIDE_CLIENT_WORK
	SERVER_WAIT
	WAIT				MSG_WAIT
TenkouDamageNext:
	VALUE				VAL_ADD,BUF_PARA_CLIENT_NO_AGI,1
	CLIENT_SET_MAX_LOOP	BUF_PARA_CLIENT_NO_AGI,TenkouDamageLoop
SUB_104_END:
	SEQ_END

UruoiBodySeq:
	GOSUB				SUB_SEQ_DAPPI
	BRANCH				TenkouDamageNext