//============================================================================================
/**
 * @file	wordset.h
 * @brief	�P��Z�b�g�I�u�W�F�N�g
 * @author	taya
 * @date	2005.09.28
 *
 */
//============================================================================================
#ifndef __WORDSET_H__
#define __WORDSET_H__

#include  "system/pm_str.h"
#include  "system/msgdata.h"
#include  "poketool/poke_tool.h"	// POKEMON_PASO_PARAM �Q�Ɠ�
#include  "field/field_common.h"	// FIELDSYS_WORK �Q��
#include  "system/mystatus.h"		// MYSTATUS �Q��
#include  "gflib/number_str.h"
#include  "system/savedata_def.h"
#include  "poketool/boxdata.h"
#include  "system/pms_word.h"
#include  "battle/battle_common.h"
#include  "application/wifi_lobby/wflby_def.h"

enum {
	WORDSET_DEFAULT_SETNUM = 8,		// �f�t�H���g�o�b�t�@��
	WORDSET_DEFAULT_BUFLEN = 32,	// �f�t�H���g�o�b�t�@���i�������j

	WORDSET_COUNTRY_BUFLEN = 64,	// ���n�於�p�o�b�t�@���i�������j(WORDSET_CreateEx�Ŏw��)
};



typedef struct _WORDSET		WORDSET;


//------------------------------------------------------------------
/**
 * 
 *
 * @param   heapID		
 *
 * @retval  extern WORDSET*		
 */
//------------------------------------------------------------------
extern WORDSET*  WORDSET_Create( u32 heapID );


//------------------------------------------------------------------
/**
 * 
 *
 * @param   word_max		
 * @param   buflen		
 * @param   heapID		
 *
 * @retval  extern WORDSET*		
 */
//------------------------------------------------------------------
extern WORDSET* WORDSET_CreateEx( u32 word_max, u32 buflen, u32 heapID );


//------------------------------------------------------------------
/**
 * 
 *
 * @param   wordset		
 *
 * @retval  extern void		
 */
//------------------------------------------------------------------
extern void WORDSET_Delete( WORDSET* wordset );

//------------------------------------------------------------------
/**
 * 
 *
 * @param   wordset		
 * @param   dstbuf		
 * @param   srcbuf		
 *
 * @retval  extern void		
 */
//------------------------------------------------------------------
extern void WORDSET_ExpandStr( const WORDSET* wordset, STRBUF* dstbuf, const STRBUF* srcbuf );


//------------------------------------------------------------------
/**
 * �����o�b�t�@��S�ċ󕶎���ŃN���A����
 *
 * @param   wordset		WORDSET�|�C���^
 */
//------------------------------------------------------------------
extern void WORDSET_ClearAllBuffer( WORDSET* wordset );


extern void WORDSET_RegisterPlayerName( WORDSET* wordset, u32 bufID, const MYSTATUS* status );
extern void WORDSET_RegisterRivalName( WORDSET* wordset,  u32 bufID, const SAVEDATA * savedata );
extern void WORDSET_RegisterSupportName( WORDSET* wordset, u32 bufID, const SAVEDATA * savedata );
extern void WORDSET_RegisterMonumentName( WORDSET* wordset, u32 bufID, const SAVEDATA * savedata );
extern void WORDSET_RegisterPokeMonsName( WORDSET* wordset, u32 bufID, POKEMON_PASO_PARAM* ppp );
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/12/11
// �s�芥���t���̃|�P�����������������Ă���֐���ǉ�
extern void WORDSET_RegisterPokeMonsNameIndefinate( WORDSET* wordset, u32 bufID, POKEMON_PASO_PARAM* ppp );
extern void WORDSET_RegisterPokeMonsNameIndefinateByNo( WORDSET* wordset, u32 bufID, u32 monsno );
// ----------------------------------------------------------------------------
extern void WORDSET_RegisterPokeNickName( WORDSET* wordset, u32 bufID, POKEMON_PASO_PARAM* ppp );
extern void WORDSET_RegisterPokeOyaName( WORDSET* wordset,  u32 bufID, POKEMON_PASO_PARAM* ppp );
extern void WORDSET_RegisterNumber( WORDSET* wordset, u32 bufID, s32 number, u32 keta, NUMBER_DISPTYPE dispType, NUMBER_CODETYPE codeType );
extern void WORDSET_RegisterWazaName( WORDSET* wordset, u32 bufID, u32 wazaID );
extern void WORDSET_RegisterRibbonName( WORDSET* wordset, u32 bufID, u32 ribbonID );
extern void WORDSET_RegisterTokuseiName( WORDSET* wordset, u32 bufID, u32 tokuseiID );
extern void WORDSET_RegisterSeikaku( WORDSET * wordset, u32 bufID, u32 seikakuID );
extern void WORDSET_RegisterItemName( WORDSET* wordset, u32 bufID, u32 itemID );
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/10/13
// �����t���E�����`�̃A�C�e���������������Ă���X�N���v�g���߂�ǉ�
extern void WORDSET_RegisterItemNameIndefinate( WORDSET* wordset, u32 bufID, u32 itemID );
extern void WORDSET_RegisterItemNamePlural( WORDSET* wordset, u32 bufID, u32 itemID );
// ----------------------------------------------------------------------------
extern void WORDSET_RegisterItemPocketName( WORDSET* wordset, u32 bufID, u32 pocketID );
extern void WORDSET_RegisterItemPocketWithIcon( WORDSET* wordset, u32 bufID, u32 pocketID );
extern void WORDSET_RegisterPokeTypeName( WORDSET* wordset, u32 bufID, u32 typeID );
extern void WORDSET_RegisterPokeStatusName( WORDSET* wordset, u32 bufID, u32 statusID );
extern void WORDSET_RegisterBadConditionName( WORDSET* wordset, u32 bufID, u32 conditionID );
extern void WORDSET_RegisterSeedTasteName( WORDSET* wordset, u32 bufID, u32 tasteID );
extern void WORDSET_RegisterPlaceName( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterPoketchAppName( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterTrTypeName( WORDSET* wordset, u32 bufID, u32 strID );
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/12/19
// �s�芥���t���̃g���[�i�[�^�C�v�������������Ă���X�N���v�g���߂�ǉ�
extern void WORDSET_RegisterTrTypeNameIndefinate( WORDSET* wordset, u32 bufID, u32 strID );
// ----------------------------------------------------------------------------
extern void WORDSET_RegisterTrTypeNameBattle( WORDSET* wordset, u32 bufID, TRAINER_DATA *tr_data );
extern void WORDSET_RegisterTrainerName( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterTowerTrainerName( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterTrainerNameBattle( WORDSET* wordset, u32 bufID, TRAINER_DATA *tr_data );
extern void WORDSET_RegisterWord( WORDSET* wordset, u32 bufID, const STRBUF* word, u32 sex, BOOL single_flag, u32 lang );
extern void WORDSET_RegisterUGItemName( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterUGTrapName( WORDSET* wordset, u32 bufID, u32 strID );
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/11/27
// �s�芥���t���̒n���A�C�e���E㩖������������Ă���֐���ǉ�
extern void WORDSET_RegisterUGItemNameIndefinate( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterUGTrapNameIndefinate( WORDSET* wordset, u32 bufID, u32 strID );
// ----------------------------------------------------------------------------
extern void WORDSET_RegisterJudgeName( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterContestRank( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterContestType( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterSecretQuestion( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterSecretAnswer( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterUGGoodsName( WORDSET* wordset, u32 bufID, u32 strID );
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/11/27
// �s�芥���t���̒n���O�b�Y�������������Ă���֐���ǉ�
extern void WORDSET_RegisterUGGoodsNameIndefinate( WORDSET* wordset, u32 bufID, u32 strID );
// ----------------------------------------------------------------------------
extern void WORDSET_RegisterPokeMonsSex( WORDSET* wordset, u32 bufID, u8 sex);
extern void WORDSET_RegisterBoxTrayName( WORDSET* wordset, u32 bufID, const BOX_DATA* boxData, u32 trayNumber );
extern void WORDSET_RegisterGymName( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterTimeType( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterCountryName( WORDSET* wordset, u32 bufID, u32 strID );
extern void WORDSET_RegisterLocalPlaceName( WORDSET* wordset, u32 bufID, u32 countryID, u32 placeID );
extern void WORDSET_RegisterPMSWord( WORDSET* wordset, u32 bufID, PMS_WORD word );
extern void WORDSET_RegisterSealName( WORDSET* wordset, u32 bufID, u32 strID );
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2007/01/26
// �����`�̃V�[���������������Ă���֐���ǉ�
extern void WORDSET_RegisterSealNamePlural( WORDSET* wordset, u32 bufID, u32 strID );
// ----------------------------------------------------------------------------
extern void WORDSET_RegisterPokeGetPlace( WORDSET* wordset, u32 bufID, u32 placeNumber );
extern void WORDSET_RegisterPorutoName( WORDSET* wordset, u32 bufID, u32 porutoID );
extern void WORDSET_RegisterAccessoryName( WORDSET* wordset, u32 bufID, u32 acID );
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/12/11
// �s�芥���t���̃A�N�Z�T���[�������������Ă���֐���ǉ�
extern void WORDSET_RegisterAccessoryNameIndefinate(WORDSET* wordset, u32 bufID, u32 acID );
// ----------------------------------------------------------------------------
extern void WORDSET_RegisterImageClibBgName( WORDSET* wordset, u32 bufID, u32 bgID );
extern void WORDSET_RegisterGroupName(WORDSET * ws, SAVEDATA * sv, int gid, int bufID, int name_type);
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/12/29
// ���̖��O�i�̒Z�k�`�j�������Ă���֐���ǉ�
void WORDSET_RegisterMonthName( WORDSET* wordset, u32 bufID, u32 month );
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/11/24
// �w��o�b�t�@�̐擪�������L���s�^���C�Y����֐���ǉ�
extern void WORDSET_Capitalize( WORDSET* wordset, u32 bufID );
// ----------------------------------------------------------------------------
extern void WORDSET_RegisterWiFiLobbyGameName( WORDSET* wordset, u32 bufID, WFLBY_GAMETYPE type );
extern void WORDSET_RegisterWiFiLobbyEventName( WORDSET* wordset, u32 bufID, WFLBY_EVENTGMM_TYPE type );
extern void WORDSET_RegisterWiFiLobbyItemName( WORDSET* wordset, u32 bufID, WFLBY_ITEMTYPE type );
extern void WORDSET_RegisterWiFiLobbyAisatsuJapan( WORDSET* wordset, u32 bufID, u32 time_zone );
extern void WORDSET_RegisterWiFiLobbyAisatsuEnglish( WORDSET* wordset, u32 bufID, u32 time_zone );
extern void WORDSET_RegisterWiFiLobbyAisatsuFrance( WORDSET* wordset, u32 bufID, u32 time_zone );
extern void WORDSET_RegisterWiFiLobbyAisatsuItaly( WORDSET* wordset, u32 bufID, u32 time_zone );
extern void WORDSET_RegisterWiFiLobbyAisatsuGerMany( WORDSET* wordset, u32 bufID, u32 time_zone );
extern void WORDSET_RegisterWiFiLobbyAisatsuSpain( WORDSET* wordset, u32 bufID, u32 time_zone );

extern void WORDSET_RegisterFurniture( WORDSET * wordset, u32 bufID, u32 furnitureID );

extern void WORDSET_RegisterTobariDepartFloorNo( WORDSET* wordset, u32 bufID, u32 floorID ); // plat_us_match
#endif