//============================================================================================
/**
 * @file	report.c
 * @brief	�Z�[�u�֘A
 * @author	tamada GAME FREAK inc.
 * @date	2005.12.05
 *
 * �u���|�[�g�������v�̏��E�B���h�E�̐���֐��Ȃǂ�����
 *
 * �C���\��F
 *	�v���C���Ԃ����A���^�C���ōX�V����
 *	�Q�[���J�n���̃E�B���h�E�ł��������e�����������悤�ɊO���C���^�[�t�F�C�X�����
 *
 */
//============================================================================================

#include "common.h"

#include "fieldsys.h"

#include "fld_bmp.h"
#include "system/window.h"
#include "system/fontproc.h"

#include "report.h"
#include "zonedata.h"
#include "savedata/savedata.h"

#include "field/situation.h"
#include "situation_local.h"
#include "savedata/mystatus.h"
#include "savedata/zukanwork.h"
#include "savedata/playtime.h"

#include "system/msgdata.h"
#include "system/wordset.h"
#include "system/msgdata_util.h"

#include "msgdata/msg.naix"
#include "msgdata/msg_report.h"


#include "ev_mapchange.h"		//DOOR_ID_JUMP_CODE�̂���
#include "field_poketch.h"

#include "fieldobj.h"
#include "fielddata/maptable/zone_id.h"
#include "communication/comm_state.h"

//============================================================================================
//
//			��`
//
//============================================================================================
typedef struct INFO_PARAM {
	int zukan_count;
	int place_name_id;
	MYSTATUS * my;
	PLAYTIME * playtime;
}INFO_PARAM;

//--------------------------------------------------------------------
/**
 * @brief	���|�[�g���E�B���h�E���䃏�[�N�̒�`
 */
//--------------------------------------------------------------------
struct REPORT_INFO{
	FIELDSYS_WORK * fsys;		///<�Q�[�����䃏�[�N�ւ̃|�C���^
	int heapID;					///<�g�p����q�[�vID
	u8 frame_no;				///<�g�p����BG�t���[���w��
	GF_BGL_INI * bgl;			///<�g�p����BG���䃏�[�N�ւ̃|�C���^
	GF_BGL_BMPWIN * win;		///<BMP���䃏�[�N�ւ̃|�C���^
	WORDSET * word;				///<�P�ꃂ�W���[�����䃏�[�N�ւ̃|�C���^
	MSGDATA_MANAGER * msgman;	///<MSG�f�[�^�}�l�[�W���ւ̃|�C���^
	INFO_PARAM iprm;
	int width;
	int height;
};

//--------------------------------------------------------------------
//--------------------------------------------------------------------
enum {
	RINFO_WIN_PX = 1,
	RINFO_WIN_PY = 1,
	RINFO_WIN_SX = 15,
	RINFO_WIN_SY = 10,
	
	RINFO_MSG_PAL = FLD_MENU_WIN_PAL,
	RINFO_WIN_PAL = MENU_WIN_PAL,
	RINFO_WIN_CGX = MENU_WIN_CGX_NUM,

	//�͂��E�������E�B���h�E�AMSG�E�B���h�E�Ƌ����ł���z�u�Œ�`
	RINFO_MSG_CGX = FLD_YESNO_WIN_CGX - (RINFO_WIN_SX * RINFO_WIN_SY),
};

// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/11/28
// �E�B���h�E�̕����Œ�ɕύX���A�p�����^���E�񂹕\����
#define RINFO_WIN_WIDTH		(13)
// ----------------------------------------------------------------------------

//�P�ꖄ�ߍ��݃^�OID�Breport.gmm�Ƃ�����ƑΉ�����悤�Ɉێ����Ȃ���΂Ȃ�Ȃ�
enum {
	RINFO_WORD_PLACENAME = 0,
	RINFO_WORD_PLAYERNAME,
	RINFO_WORD_BADGE_NUM,
	RINFO_WORD_ZUKAN_NUM,
	RINFO_WORD_PLAYTIME_H,
	RINFO_WORD_PLAYTIME_M,
};

enum {
	RINFO_KETA_BADGE_NUM = 1,
	RINFO_KETA_ZUKAN_NUM = 3,
	RINFO_KETA_PLAYTIME_H = 3,
	RINFO_KETA_PLAYTIME_M = 2,
};

static const int MsgID[] = {
	PLACE_NAME,
	HERO_NAME,
	BADGE_NUM,
	ZUKAN_NUM,
	PLAY_TIME,
};
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/11/28
// �E�B���h�E�̕����Œ�ɕύX���A�p�����^���E�񂹕\����
static const int ValueID[] = {
//	PLACE_NAME,
	HERO_NAME_VALUE,
	BADGE_NUM_VALUE,
	ZUKAN_NUM_VALUE,
	PLAY_TIME_VALUE,
};
// ----------------------------------------------------------------------------
//==============================================================================
//	�v���g�^�C�v�錾
//==============================================================================
static void Field_SaveParam(FIELDSYS_WORK * fsys);

//============================================================================================
//
//			�֐�
//
//============================================================================================
//--------------------------------------------------------------------
/**
 * @brief	�\���p�����[�^�̐ݒ�
 * @param	iprm	�\���p�����[�^�ێ����[�N�ւ̃|�C���^
 * @param	fsys	�Q�[�����䃏�[�N�ւ̃|�C���^
 * 
 */
//--------------------------------------------------------------------
static void makeinfo(INFO_PARAM * iprm, const FIELDSYS_WORK * fsys)
{
	SAVEDATA * sv = fsys->savedata;
	LOCATION_WORK * now = Situation_GetNowLocation(SaveData_GetSituation(sv));
	ZUKAN_WORK * zw = SaveData_GetZukanWork(sv);

	iprm->place_name_id = ZoneData_GetPlaceNameID(now->zone_id);

	if (ZukanWork_GetZukanGetFlag(zw)) {
		iprm->zukan_count = ZukanWork_GetZukanPokeSeeCount(zw);
	} else {
		iprm->zukan_count = 0;
	}
	iprm->my = SaveData_GetMyStatus(sv);
	iprm->playtime = SaveData_GetPlayTime(sv);
}
//--------------------------------------------------------------------
/**
 * @brief	�Z�[�u�f�[�^���\���ɕK�v�ȒP�ꐶ��
 * @param	word	�P�ꃂ�W���[�����䃏�[�N�ւ̃|�C���^
 * @param	iprm	�\���p�����[�^�ێ����[�N�ւ̃|�C���^
 */
//--------------------------------------------------------------------
static void makewords(WORDSET * word, const INFO_PARAM * iprm)
{
	int keta, type, count;

	WORDSET_RegisterPlaceName(word, RINFO_WORD_PLACENAME, iprm->place_name_id);

	WORDSET_RegisterPlayerName(word, RINFO_WORD_PLAYERNAME, iprm->my);

	WORDSET_RegisterNumber(word, RINFO_WORD_BADGE_NUM,
			MyStatus_GetBadgeCount(iprm->my),
			RINFO_KETA_BADGE_NUM, NUMBER_DISPTYPE_LEFT, NUMBER_CODETYPE_DEFAULT);

	if (iprm->zukan_count >= 100) {
		keta = RINFO_KETA_ZUKAN_NUM;
		type = NUMBER_DISPTYPE_LEFT;
	} else if (iprm->zukan_count >= 10) {
		keta = RINFO_KETA_ZUKAN_NUM;
		type = NUMBER_DISPTYPE_SPACE;
	} else {
		keta = RINFO_KETA_ZUKAN_NUM - 1;
		type = NUMBER_DISPTYPE_SPACE;
	}
	WORDSET_RegisterNumber(word, RINFO_WORD_ZUKAN_NUM,
			iprm->zukan_count,
			keta, type, NUMBER_CODETYPE_DEFAULT);

	count = PLAYTIME_GetHour(iprm->playtime);
	if (count >= 100) {
		keta = RINFO_KETA_PLAYTIME_H;
		type = NUMBER_DISPTYPE_LEFT;
	} else if (count >= 10) {
		keta = RINFO_KETA_PLAYTIME_H;
		type = NUMBER_DISPTYPE_SPACE;
	} else {
		keta = RINFO_KETA_PLAYTIME_H - 1;
		type = NUMBER_DISPTYPE_SPACE;
	}
	WORDSET_RegisterNumber(word, RINFO_WORD_PLAYTIME_H,
			count,
			keta, type, NUMBER_CODETYPE_DEFAULT);
	WORDSET_RegisterNumber(word, RINFO_WORD_PLAYTIME_M,
			PLAYTIME_GetMinute(iprm->playtime),
			RINFO_KETA_PLAYTIME_M, NUMBER_DISPTYPE_ZERO, NUMBER_CODETYPE_DEFAULT);

}

//--------------------------------------------------------------------
/**
 * @brief	�E�B���h�E���̎擾
 * @param	riw		���|�[�g���E�B���h�E���䃏�[�N�ւ̃|�C���^
 * @return	int		�\���E�B���h�E�̕��i�L�����P�ʁj
 */
//--------------------------------------------------------------------
static int CountWidth(const REPORT_INFO * riw)
{
	int id, width, max;
	STRBUF * msg;
	max = 0;
	for (id = 0; id < NELEMS(MsgID); id++) {
		msg = MSGDAT_UTIL_AllocExpandString(riw->word, riw->msgman, id, riw->heapID);
		width = FontProc_GetPrintStrWidth(FONT_SYSTEM, msg,
				FontHeaderGet(FONT_SYSTEM, FONT_HEADER_SPACE_X));
		if (width > max) {
			max = width;
		}
		STRBUF_Delete(msg);
	}
	//�L�����P�ʂ̕��i�]��؂�グ�j��Ԃ�
	return (max + 7) / 8;
}

//--------------------------------------------------------------------
/**
 * @brief	�E�B���h�E�����̎擾
 * @param	iprm	�\���p�����[�^�ێ����[�N�ւ̃|�C���^
 * @return	int		�\���E�B���h�E�̍����i�L�����P�ʁj
 */
//--------------------------------------------------------------------
static int CountHeight(const INFO_PARAM * iprm)
{
	if (iprm->zukan_count != 0) {
		return RINFO_WIN_SY;
	} else {
		return RINFO_WIN_SY - 2;
	}
}

//--------------------------------------------------------------------
/**
 * @brief	���|�[�g���̕������\������
 * @param	riw		���|�[�g���E�B���h�E���䃏�[�N�ւ̃|�C���^
 */
//--------------------------------------------------------------------
static void printinfo(const REPORT_INFO * riw)
{
	STRBUF * msg;
	int x, y;
	int my;
	int i;

	my = FontHeaderGet(FONT_SYSTEM, FONT_HEADER_SIZE_Y)
				+ FontHeaderGet(FONT_SYSTEM, FONT_HEADER_SPACE_Y);
	// ----------------------------------------------------------------------------
	// localize_spec_mark(LANG_ALL) imatake 2006/11/28
	// �E�B���h�E�̕����Œ�ɕύX���A�p�����^���E�񂹕\����
	y = 0;
	msg = MSGDAT_UTIL_AllocExpandString(riw->word, riw->msgman, MsgID[0], riw->heapID);
	GF_STR_PrintSimple(riw->win, FONT_SYSTEM, msg, 0, y, MSG_NO_PUT, NULL);
	STRBUF_Delete(msg);
	for (i = 1; i < NELEMS(MsgID); i++) {
		if (MsgID[i] == ZUKAN_NUM && riw->iprm.zukan_count == 0) {
			//������\�����Ȃ�
			continue;
		}
		y += my;
		msg = MSGMAN_AllocString(riw->msgman, MsgID[i]);
		GF_STR_PrintSimple(riw->win, FONT_SYSTEM, msg, 0, y, MSG_NO_PUT, NULL);
		STRBUF_Delete(msg);
		msg = MSGDAT_UTIL_AllocExpandString(riw->word, riw->msgman, ValueID[i-1], riw->heapID);
		x = RINFO_WIN_WIDTH * 8 - FontProc_GetPrintStrWidth(FONT_SYSTEM, msg, FontHeaderGet(FONT_SYSTEM, FONT_HEADER_SPACE_X));
		GF_STR_PrintSimple(riw->win, FONT_SYSTEM, msg, x, y, MSG_NO_PUT, NULL);
		STRBUF_Delete(msg);
	}
	// ----------------------------------------------------------------------------
}

//--------------------------------------------------------------------
/**
 * @brief	���|�[�g���E�B���h�E�F�E�B���h�E�\��
 * @param	riw		���|�[�g���E�B���h�E���䃏�[�N�ւ̃|�C���^
 */
//--------------------------------------------------------------------
void ReportInfo_WriteWindow(REPORT_INFO * riw)
{
	//BMP���䃏�[�N���m��
	riw->win = sys_AllocMemory(riw->heapID, sizeof(GF_BGL_BMPWIN));
	//bitmap�̈��ǉ�
	GF_BGL_BmpWinAdd(riw->bgl, riw->win, riw->frame_no,
			RINFO_WIN_PX, RINFO_WIN_PY, riw->width, riw->height,
			RINFO_MSG_PAL, RINFO_MSG_CGX);
	//�E�B���h�E�g�L�����A�p���b�g���Z�b�g
	MenuWinGraphicSet(
		riw->bgl, riw->frame_no, RINFO_WIN_CGX, RINFO_WIN_PAL, MENU_TYPE_SYSTEM, riw->heapID); 
	//�E�B���h�E�g����h��Ԃ�
	GF_BGL_BmpWinDataFill(riw->win, FontHeaderGet(FONT_SYSTEM, FONT_HEADER_B_COLOR));
	//���e��`��
	printinfo(riw);
	//�E�B���h�E�g�`��
	BmpMenuWinWrite(riw->win, WINDOW_TRANS_ON, RINFO_WIN_CGX, RINFO_WIN_PAL);
}

//--------------------------------------------------------------------
/**
 * @brief	���|�[�g���E�B���h�E�F�E�B���h�E����
 * @param	riw		���|�[�g���E�B���h�E���䃏�[�N�ւ̃|�C���^
 */
//--------------------------------------------------------------------
void ReportInfo_EraseWindow(REPORT_INFO * riw)
{
	//�E�B���h�E����
	BmpMenuWinClear(riw->win, WINDOW_TRANS_ON);
	//bitmap�̈���폜
	GF_BGL_BmpWinDel(riw->win);
	//BMP���䃏�[�N���폜
	sys_FreeMemoryEz(riw->win);
}

//--------------------------------------------------------------------
/**
 * @brief	���|�[�g���E�B���h�E�F����
 * @param	fsys			�Q�[�����䃏�[�N�ւ̃|�C���^
 * @param	heapID			�g�p����q�[�vID
 * @param	frame_no		�\���Ɏg�p����BG�t���[���w��
 * @return	REPORT_INFO		�����������|�[�g���E�B���h�E���䃏�[�N�ւ̃|�C���^
 */
//--------------------------------------------------------------------
REPORT_INFO * ReportInfo_Create(FIELDSYS_WORK * fsys, int heapID, u8 frame_no)
{
	REPORT_INFO * riw;

	riw = sys_AllocMemory(heapID, sizeof(REPORT_INFO));
	riw->fsys = fsys;
	riw->heapID = heapID;
	riw->frame_no = frame_no;
	riw->bgl = fsys->bgl;
	riw->word = WORDSET_Create(heapID);
	riw->msgman = MSGMAN_Create(MSGMAN_TYPE_DIRECT, ARC_MSG, NARC_msg_report_dat, heapID);

	makeinfo(&riw->iprm, riw->fsys);
	makewords(riw->word, &riw->iprm);
	// ----------------------------------------------------------------------------
	// localize_spec_mark(LANG_ALL) imatake 2006/11/28
	// �E�B���h�E�̕����Œ�ɕύX���A�p�����^���E�񂹕\����
	riw->width = RINFO_WIN_WIDTH;
	// ----------------------------------------------------------------------------
	//GF_ASSERT(riw->width <= RINFO_WIN_SX);
	riw->height = CountHeight(&riw->iprm);
	//GF_ASSERT(riw->height <= RINFO_WIN_SY);
	return riw;
}

//--------------------------------------------------------------------
/**
 * @brief	���|�[�g���E�B���h�E�F�폜
 * @param	riw		���|�[�g���E�B���h�E���䃏�[�N�ւ̃|�C���^
 */
//--------------------------------------------------------------------
void ReportInfo_Delete(REPORT_INFO * riw)
{
	MSGMAN_Delete(riw->msgman);
	WORDSET_Delete(riw->word);
	sys_FreeMemoryEz(riw);
}


//============================================================================================
//============================================================================================
//--------------------------------------------------------------------
/**
 * @brief	�t�B�[���h�ł̃Z�[�u����
 * @param	fsys			�Q�[�����䃏�[�N�ւ̃|�C���^
 * @retval	TRUE
 * @retval	FALSE
 */
//--------------------------------------------------------------------
BOOL Field_Save(FIELDSYS_WORK * fsys)
{
	Field_SaveParam(fsys);
	
	if (SaveData_Save(fsys->savedata) == SAVE_RESULT_OK) {
		return TRUE;
	} else {
		//SAVE_RESULT_OK�ȊO�̏ꍇ�͂Ȃ�ɂ���
		//���삪���������̂Ŏ��s�Ƃ݂Ȃ�
		return FALSE;
	}
}

//--------------------------------------------------------------------
/**
 * @brief	�t�B�[���h�ł̃Z�[�u�����p�̃p�����[�^�Z�b�g����
 * @param	fsys			�Q�[�����䃏�[�N�ւ̃|�C���^
 * @retval	TRUE
 * @retval	FALSE
 */
//--------------------------------------------------------------------
static void Field_SaveParam(FIELDSYS_WORK * fsys)
{
	//�t�B�[���h���샂�f���̃Z�[�u
	Field_SaveFieldObj(fsys);

	// �|�P�b�`�֘A�f�[�^�̃Z�[�u
	Field_SendPoketchInfo( fsys, POKETCH_SEND_SAVE, 0 );

	//�ʒu����������
	fsys->location->grid_x = Player_NowGPosXGet( fsys->player );
	fsys->location->grid_z = Player_NowGPosZGet( fsys->player );
	fsys->location->door_id = DOOR_ID_JUMP_CODE;
	fsys->location->dir = Player_DirGet( fsys->player );
}

//--------------------------------------------------------------
/**
 * @brief   �o�g�����R�[�_�[�ŃZ�[�u����������ׁA�t�B�[���h�I���O�Ƀt�B�[���h����
 * 			�Z�[�u���[�N�֏������ޏ���
 *
 * @param   fsys		
 */
//--------------------------------------------------------------
void Field_SaveParam_BattleRecorder(FIELDSYS_WORK *fsys)
{
	if(fsys == NULL){
		GF_ASSERT(0);
		return;
	}
	
	switch(fsys->location->zone_id){
	case ZONE_ID_UNION:
	case ZONE_ID_DIRECT2:
	case ZONE_ID_DIRECT4:
		return;
	}
	
	if(CommStateIsInitializeOtherPoketch() == TRUE){	//�ی�
		return;
	}
	
	Field_SaveParam(fsys);
}