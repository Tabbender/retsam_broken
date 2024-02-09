
//============================================================================
/**
 *
 *@file		sub_106.s
 *@brief	戦闘シーケンス
 *			メロメロ追加効果シーケンス
 *@author	HisashiSogabe
 *@data		2006.01.31
 *
 */
//============================================================================
	.text

	.include	"waza_seq_def.h"

SUB_106:
	//特性どんかんを持ってる場合は、メロメロにならない
	KATAYABURI_TOKUSEI_CHECK	TOKUSEI_HAVE,SIDE_TSUIKA,TOKUSYU_DONKAN,NoMeromero
	IF				IF_FLAG_BIT,BUF_PARA_WAZA_STATUS_FLAG,WAZA_STATUS_FLAG_NOHIT_CHG,Umakukimaran
	MEROMERO		Umakukimaran
	GOSUB			SUB_SEQ_WAZA_OUT_EFF
//特性追加の場合、専用メッセージへ
	IF				IF_FLAG_EQ,BUF_PARA_TSUIKA_TYPE,ADD_STATUS_TOKUSEI,TokuseiMsg
//装備アイテムの場合、専用メッセージへ
	IF				IF_FLAG_EQ,BUF_PARA_TSUIKA_TYPE,ADD_STATUS_SOUBIITEM,SoubiItemMsg
NormalMsg:
	MESSAGE			MeromeroMineMsg,TAG_NICK,SIDE_TSUIKA
	BRANCH			SUB_106_NEXT
TokuseiMsg:
	MESSAGE			TokuseiMeromeroM2MMsg,TAG_NICK_TOKU_NICK,SIDE_WORK,SIDE_CLIENT_WORK,SIDE_TSUIKA
	BRANCH			SUB_106_NEXT
SoubiItemMsg:
	STATUS_EFFECT	SIDE_WORK,STATUS_ITEM_POKE
	SERVER_WAIT
	MESSAGE			ItemMeromeroM2MMsg,TAG_NICK_ITEM_NICK,SIDE_WORK,SIDE_CLIENT_WORK,SIDE_TSUIKA
SUB_106_NEXT:
	SERVER_WAIT
	WAIT			MSG_WAIT
	//装備アイテム「あかいいと」のために追加効果があったフラグを立てる
	VALUE			VAL_BIT,BUF_PARA_OSTF_STATUS_FLAG_TSUIKA,OSTF_STATUS_FLAG_MEROMERO
	SEQ_END

NoMeromero:
//特性追加の場合、専用メッセージへ
	IF				IF_FLAG_EQ,BUF_PARA_TSUIKA_TYPE,ADD_STATUS_TOKUSEI,TokuseiNoMeromero
//装備アイテムの場合、専用メッセージへ
	IF				IF_FLAG_EQ,BUF_PARA_TSUIKA_TYPE,ADD_STATUS_SOUBIITEM,SoubiItemNoMeromero
	ATTACK_MESSAGE
	SERVER_WAIT
	WAIT			MSG_WAIT
	MESSAGE			DonkanMineMsg,TAG_NICK_TOKU,SIDE_TSUIKA,SIDE_TSUIKA
	SERVER_WAIT
	WAIT			MSG_WAIT
	//技の起動に失敗フラグを立てる
	//VALUE			VAL_BIT,BUF_PARA_WAZA_STATUS_FLAG,WAZA_STATUS_FLAG_SIPPAI_RENZOKU_CHECK
	VALUE			VAL_BIT,BUF_PARA_WAZA_STATUS_FLAG,WAZA_STATUS_FLAG_SIPPAI
	SEQ_END

TokuseiNoMeromero:
//特性追加の場合は、メッセージなし
	IF				IF_FLAG_EQ,BUF_PARA_TSUIKA_TYPE,ADD_STATUS_TOKUSEI,SUB_106_RET
	MESSAGE			TokuseiNoTokuseiM2MMsg,TAG_NICK_TOKU_NICK_TOKU,SIDE_TSUIKA,SIDE_TSUIKA,SIDE_WORK,SIDE_CLIENT_WORK
	SERVER_WAIT
	WAIT			MSG_WAIT
	SEQ_END

SoubiItemNoMeromero:
	MESSAGE			TokuseiNoItemMineMsg,TAG_NICK_TOKU_ITEM,SIDE_TSUIKA,SIDE_TSUIKA,SIDE_CLIENT_WORK
	SERVER_WAIT
	WAIT			MSG_WAIT
	SEQ_END

Umakukimaran:
//特性追加の場合は、メッセージなし
	IF				IF_FLAG_EQ,BUF_PARA_TSUIKA_TYPE,ADD_STATUS_TOKUSEI,SUB_106_RET
	VALUE			VAL_BIT,BUF_PARA_WAZA_STATUS_FLAG,WAZA_STATUS_FLAG_UMAKUKIMARAN
SUB_106_RET:
	SEQ_END

