
//============================================================================
/**
 *
 *@file		sub_142.s
 *@brief	�퓬�V�[�P���X
 *			�͂������Ƃ��V�[�P���X
 *@author	HisashiSogabe
 *@data		2006.02.09
 *
 */
//============================================================================
	.text

	.include	"waza_seq_def.h"

SUB_142:
	//�݂���肪����ꍇ�́A���s
	MIGAWARI_CHECK	SIDE_DEFENCE,SUB_142_END
	//�����}���`�^�C�v�́A���܂����܂��
	IF_PSP			IF_FLAG_EQ,SIDE_DEFENCE,ID_PSP_speabino,TOKUSYU_MARUTITAIPU,SUB_142_END

	//�͂����񂾂܂̏ꍇ�͂��܂����܂��
	IF_PSP			IF_FLAG_EQ,SIDE_DEFENCE,ID_PSP_item,ITEM_HAKKINDAMA,SUB_142_END

	//�搧�����̏ꍇ�͂��܂����܂��
	IF_PSP			IF_FLAG_NE,SIDE_DEFENCE,ID_PSP_wkw_sensei_flag,0,SUB_142_END
	IF_PSP			IF_FLAG_NE,SIDE_DEFENCE,ID_PSP_wkw_once_agi_up,0,SUB_142_END

	HATAKIOTOSU		SUB_142_END
	MESSAGE_WORK
	SERVER_WAIT
	WAIT			MSG_WAIT
SUB_142_END:
	SEQ_END
