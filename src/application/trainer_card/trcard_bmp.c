//============================================================================================
/**
 * @file	trcard_bmp.c
 * @bfief	�g���[�i�[�J�[�h���BMP�֘A
 * @author	Nozomu Saito
 * @date	05.11.15
 */
//============================================================================================
#include "common.h"
#include "savedata/playtime.h"
#include "system/fontproc.h"
#include "system/pm_str.h"
#include "system/buflen.h"
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/12/13
// �P�ʗނ� gmm �̃e�L�X�g�Ɉڍs
#include "system/wordset.h"
// ----------------------------------------------------------------------------
#include "strbuf_family.h"

#include "trcard_bmp.h"
#include "trcard_cgx_def.h"

#include "msgdata/msg_trainerscard.h"
#include "msgdata/msg.naix"

#define FONT_BG	(GF_BGL_FRAME3_S)

#define HOUR_DISP_MAX	(999)


////////////////////////////////////////////////////////////////
//�\��
////////////////////////////////////////////////////////////////
//�g���[�i�[NO					:34
#define WIN_TR_NO_PX	(2)
#define WIN_TR_NO_PY	(4)
#define WIN_TR_NO_SX	(17)
#define WIN_TR_NO_SY	(2)
#define WIN_TR_NO_CGX	(TR_BG_BASE+TR_BG_SIZE)

//���O							:34
#define WIN_NAME_PX	(2)
#define WIN_NAME_PY	(6)
#define WIN_NAME_SX	(17)
#define WIN_NAME_SY	(2)
#define WIN_NAME_CGX	(WIN_TR_NO_CGX+WIN_TR_NO_SX*WIN_TR_NO_SY)

//�����Â���					:34
#define WIN_MONEY_PX	(2)
#define WIN_MONEY_PY	(9)
#define WIN_MONEY_SX	(17)
#define WIN_MONEY_SY	(2)
#define WIN_MONEY_CGX	(WIN_NAME_CGX+WIN_NAME_SX*WIN_NAME_SY)

//������						:34
#define WIN_BOOK_PX	(2)
#define WIN_BOOK_PY	(12)
#define WIN_BOOK_SX	(17)
#define WIN_BOOK_SY	(2)
#define WIN_BOOK_CGX	(WIN_MONEY_CGX+WIN_MONEY_SX*WIN_MONEY_SY)

//�X�R�A						:34
#define WIN_SCORE_PX	(2)
#define WIN_SCORE_PY	(15)
#define WIN_SCORE_SX	(17)
#define WIN_SCORE_SY	(2)
#define WIN_SCORE_CGX	(WIN_BOOK_CGX+WIN_BOOK_SX*WIN_BOOK_SY)

//�v���C����					:56
#define WIN_TIME_PX	(2)
#define WIN_TIME_PY	(18)
#define WIN_TIME_SX	(28)
#define WIN_TIME_SY	(2)
#define WIN_TIME_CGX	(WIN_SCORE_CGX+WIN_SCORE_SX*WIN_SCORE_SY)

//�X�^�[�g����					:56
#define WIN_S_TIME_PX	(2)
#define WIN_S_TIME_PY	(20)
#define WIN_S_TIME_SX	(28)
#define WIN_S_TIME_SY	(2)
#define WIN_S_TIME_CGX	(WIN_TIME_CGX+WIN_TIME_SX*WIN_TIME_SY)
//////////////////////////////////////////////////////////////
//����
//////////////////////////////////////////////////////////////
//�ł�ǂ�����					:112
#define WIN_CLEAR_PX	(2)
#define WIN_CLEAR_PY	(2)
#define WIN_CLEAR_SX	(28)
#define WIN_CLEAR_SY	(4)
#define WIN_CLEAR_CGX	(SIGN_CGX+TR_SIGN_SIZE)
//�������					:56
#define WIN_COMM_PX	(2)
#define WIN_COMM_PY	(7)
#define WIN_COMM_SX	(28)
#define WIN_COMM_SY	(2)
#define WIN_COMM_CGX	(WIN_CLEAR_CGX+WIN_CLEAR_SX*WIN_CLEAR_SY)

//�ʐM�ΐ�						:56
#define WIN_BATTLE_PX	(2)
#define WIN_BATTLE_PY	(9)
#define WIN_BATTLE_SX	(28)
#define WIN_BATTLE_SY	(2)
#define WIN_BATTLE_CGX	(WIN_COMM_CGX+WIN_COMM_SX*WIN_COMM_SY)

//�ʐM����						:56
#define WIN_TRADE_PX	(2)
#define WIN_TRADE_PY	(11)
#define WIN_TRADE_SX	(28)
#define WIN_TRADE_SY	(2)
#define WIN_TRADE_CGX	(WIN_BATTLE_CGX+WIN_BATTLE_SX*WIN_BATTLE_SY)

#define TR_STRING_LEN	(32)		//���[�J���C�Y���l�����߂ɁB

#define TR_MSGCOLOR			(GF_PRINTCOLOR_MAKE( 1, 2, FBMP_COL_NULL ))
#define BMP_WIDTH_TYPE1	(8*17)
#define BMP_WIDTH_TYPE2	(8*28)

#define SEC_DISP_OFS	(2)		//�K���B���������Ɍ�����l�ŁB
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ENGLISH) imatake 2006/12/13
// �C�O�łł͉~�E�Ђ����폜
#define YEN_OFS			(0)		//�u�~�v�\�����E�X�y�[�X
#define HIKI_OFS		(0)		//�u�Ђ��v�\�����E�X�y�[�X
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ENGLISH) imatake 2006/12/13
// �P�ʗނ� gmm �̃e�L�X�g�Ɉڍs

#define TIME_OFS		(184)
#define TIME_WIDTH		(40)
#define COLON_OFS		(207 - 2)	// ��5�̃X�y�[�X���p�ӂł�����I�t�Z�b�g�͎��
#define COLON_WIDTH		(5)

#define WIN_OFS		(104 + 8)
#define LOSE_OFS	(168 + 8)

// ���l�������� WORDSET �̃o�b�t�@ID
enum {
	BUFID_HOUR,
	BUFID_MINUTE,
	BUFID_YEAR,
	BUFID_MONTH,
	BUFID_DAY,
	BUFID_MONEY,
	WORDMAX_ALL
};

#define WORDMAX_TIME	(BUFID_MINUTE + 1)
#define WORDMAX_DATE	(BUFID_DAY    + 1)

// ----------------------------------------------------------------------------

#define SEC_DISP_POS_X	(8*25)
#define MINITE_DISP_POS_X	(8*26)
#define HOUR_DISP_POS_X	(8*21)
#define MINITE_DISP_W	(8*2)
#define HOUR_DISP_W	(8*4)

static const BMPWIN_DAT TrCardBmpData[] =
{
	
	{	// 0:�g���[�i�[NO
		FONT_BG, WIN_TR_NO_PX, WIN_TR_NO_PY,
		WIN_TR_NO_SX, WIN_TR_NO_SY, TR_FONT_PAL, WIN_TR_NO_CGX
	},	
	{	// 1:���O
		FONT_BG, WIN_NAME_PX, WIN_NAME_PY,
		WIN_NAME_SX, WIN_NAME_SY, TR_FONT_PAL, WIN_NAME_CGX
	},
	{	// 2:�����Â���
		FONT_BG, WIN_MONEY_PX, WIN_MONEY_PY,
		WIN_MONEY_SX, WIN_MONEY_SY, TR_FONT_PAL, WIN_MONEY_CGX
	},	
	{	// 3:������
		FONT_BG, WIN_BOOK_PX, WIN_BOOK_PY,
		WIN_BOOK_SX, WIN_BOOK_SY, TR_FONT_PAL, WIN_BOOK_CGX
	},
	{	// 4:�X�R�A
		FONT_BG, WIN_SCORE_PX, WIN_SCORE_PY,
		WIN_SCORE_SX, WIN_SCORE_SY, TR_FONT_PAL, WIN_SCORE_CGX
	},
	{	//�@5:�v���C����
		FONT_BG, WIN_TIME_PX, WIN_TIME_PY,
		WIN_TIME_SX, WIN_TIME_SY, TR_FONT_PAL, WIN_TIME_CGX
	},
	{	//�@6:�J�n����
		FONT_BG, WIN_S_TIME_PX, WIN_S_TIME_PY,
		WIN_S_TIME_SX, WIN_S_TIME_SY, TR_FONT_PAL, WIN_S_TIME_CGX
	},
	
	{	//�@7:�ł�ǂ�����
		FONT_BG, WIN_CLEAR_PX, WIN_CLEAR_PY,
		WIN_CLEAR_SX, WIN_CLEAR_SY, TR_FONT_PAL, WIN_CLEAR_CGX
	},

	{	//�@8:�ʐM��
		FONT_BG, WIN_COMM_PX, WIN_COMM_PY,
		WIN_COMM_SX, WIN_COMM_SY, TR_FONT_PAL, WIN_COMM_CGX
	},
	{	//�@9:�ʐM�ΐ�
		FONT_BG, WIN_BATTLE_PX, WIN_BATTLE_PY,
		WIN_BATTLE_SX, WIN_BATTLE_SY, TR_FONT_PAL, WIN_BATTLE_CGX
	},
	{	//�@10:�ʐM����
		FONT_BG, WIN_TRADE_PX, WIN_TRADE_PY,
		WIN_TRADE_SX, WIN_TRADE_SY, TR_FONT_PAL, WIN_TRADE_CGX
	},
};

static void WriteNumData(	GF_BGL_BMPWIN *inWin,
							const u32 inBmpWidth,
							const u32 inRightSpace,
							const u32 inStartY,
							STRBUF *buff,
							const u32 inNum,
							const u8 inDigit,
							const NUMBER_DISPTYPE inDisptype);
static void WriteNumDataFill(	GF_BGL_BMPWIN *inWin,
								const u32 inBmpWidth,
								const u32 inRightSpace,
								const u32 inStartY,
								STRBUF *buff,
								const u32 inNum,
								const u8 inDigit,
								const NUMBER_DISPTYPE inDisptype,
								const u32 inFillSatrt,
								const u32 inFillWidth);
static void WriteStrData(	GF_BGL_BMPWIN *inWin,
							const u32 inBmpWidth,
							const u32 inRightSpace,
							const u32 inStartY,
							const STRBUF *buff);

//--------------------------------------------------------------------------------------------
/**
 * BMP�E�B���h�E�ǉ�
 *
 * @param	bgl		bgl
 * @param	win		BmpWin
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
void TRCBmp_AddTrCardBmp( GF_BGL_INI * bgl, GF_BGL_BMPWIN	*win )
{
#if 1
	u8 i;
	const BMPWIN_DAT * dat =TrCardBmpData;
	for(i=0;i<TR_CARD_WIN_MAX;i++){
		GF_BGL_BmpWinAddEx( bgl, &win[i], &dat[i] );
	}
	//�擪�L�������N���A�i�X�N���[���N���A����Ă�Ƃ���́A���̃L�����Ŗ��܂�j
	GF_BGL_CharFill( bgl, FONT_BG, 0, 1, 0 );
#endif
}


//--------------------------------------------------------------------------------------------
/**
 * BMP�E�B���h�E�j��
 *
 * @param	win		BmpWin
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
void TRCBmp_ExitTrCardBmpWin( GF_BGL_BMPWIN	*win )
{
	u16	i;

	for( i=0; i<TR_CARD_WIN_MAX; i++ ){
		GF_BGL_BmpWinDel( &win[i] );
	}
}

static const int MsgList[] = {
	MSG_TCARD_01,
	MSG_TCARD_02,
	MSG_TCARD_03,
	MSG_TCARD_04,
	MSG_TCARD_05,
	MSG_TCARD_06,
	MSG_TCARD_07,
	MSG_TCARD_08,
	MSG_TCARD_09,
	MSG_TCARD_10,
	MSG_TCARD_11,
};

//--------------------------------------------------------------------------------------------
/**
 * ���\���i�\�ʁj
 *
 * @param	win				BmpWin
 * @param	inTrCardData	�g���[�i�[�J�[�h�f�[�^
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
void TRCBmp_WriteTrWinInfo( GF_BGL_BMPWIN	*win, const TR_CARD_DATA *inTrCardData )
{
	u8 i;
	MSGDATA_MANAGER* man;
	STRBUF *msg_buf;
	
	GF_BGL_BmpWinFill(
		&win[0], 0, 0, 0,  WIN_TR_NO_SX*8,  WIN_TR_NO_SY*8 );
	GF_BGL_BmpWinFill(
		&win[1], 0, 0, 0,  WIN_NAME_SX*8,  WIN_NAME_SY*8 );
	GF_BGL_BmpWinFill(
		&win[2], 0, 0, 0,  WIN_MONEY_SX*8,  WIN_MONEY_SY*8 );
	GF_BGL_BmpWinFill(
		&win[3], 0, 0, 0,  WIN_BOOK_SX*8,  WIN_BOOK_SY*8 );
	GF_BGL_BmpWinFill(
		&win[4], 0, 0, 0,  WIN_SCORE_SX*8,  WIN_SCORE_SY*8 );
	GF_BGL_BmpWinFill(
		&win[5], 0, 0, 0,  WIN_TIME_SX*8,  WIN_TIME_SY*8 );
	GF_BGL_BmpWinFill(
		&win[6], 0, 0, 0,  WIN_S_TIME_SX*8,  WIN_S_TIME_SY*8 );

	man = MSGMAN_Create(MSGMAN_TYPE_NORMAL, ARC_MSG, NARC_msg_trainerscard_dat, HEAPID_TR_CARD);
	msg_buf = STRBUF_Create(TR_STRING_LEN, HEAPID_TR_CARD);
	for(i=0;i<7;i++){
		if ( (i!=3) ||
				(i==3)&&(inTrCardData->PokeBookFlg) ){	//������̂ݎ����Ă���Ƃ������\��
			MSGMAN_GetString(man, MsgList[i] ,msg_buf);
			GF_STR_PrintColor(&win[i], FONT_SYSTEM, msg_buf, 0, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
		}
	}
	
	{
		// ----------------------------------------------------------------------------
		// localize_spec_mark(LANG_ALL) imatake 2006/12/14
		// �P�ʗނ� gmm �̃e�L�X�g�Ɉڍs

		STRBUF *tmp_buf = STRBUF_Create(TR_STRING_LEN, HEAPID_TR_CARD);
		WORDSET *wordset = WORDSET_CreateEx(WORDMAX_ALL, WORDSET_DEFAULT_BUFLEN, HEAPID_TR_CARD);
		
		//ID
		WriteNumData(	&win[TRC_BMPWIN_TR_ID],
						BMP_WIDTH_TYPE1, 0, 0, msg_buf, inTrCardData->TrainerID, TR_ID_DIGIT,
						NUMBER_DISPTYPE_ZERO);
		
		//�Ȃ܂�
		STRBUF_SetStringCode( msg_buf, inTrCardData->TrainerName );
		WriteStrData(&win[TRC_BMPWIN_TR_NAME], BMP_WIDTH_TYPE1, 0, 0, msg_buf);

		//�����Â���
		{
			u32 xofs;
			WORDSET_RegisterNumber(wordset, BUFID_MONEY, inTrCardData->Money, MONEY_DIGIT, NUMBER_DISPTYPE_LEFT, NUMBER_CODETYPE_DEFAULT);
			MSGMAN_GetString(man, MSG_TCARD_15, tmp_buf);
			WORDSET_ExpandStr(wordset, msg_buf, tmp_buf);
			xofs = BMP_WIDTH_TYPE1 - FontProc_GetPrintStrWidth(FONT_SYSTEM, msg_buf, 0);
			GF_STR_PrintColor(&win[TRC_BMPWIN_MONEY], FONT_SYSTEM, msg_buf, xofs, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
		}

		//������
		if (inTrCardData->PokeBookFlg){	//�\���t���O�������Ă���Ƃ��̂ݕ\��	
			// MatchComment: new change in plat US
            u32 xofs;
            WORDSET_RegisterNumber(wordset, BUFID_MONEY, inTrCardData->PokeBook, MONS_NUM_DIGIT, NUMBER_DISPTYPE_LEFT, NUMBER_CODETYPE_DEFAULT);
            MSGMAN_GetString(man, MSG_TCARD_22, tmp_buf);
            WORDSET_ExpandStr(wordset, msg_buf, tmp_buf);
			xofs = BMP_WIDTH_TYPE1 - FontProc_GetPrintStrWidth(FONT_SYSTEM, msg_buf, 0);
			GF_STR_PrintColor(&win[TRC_BMPWIN_BOOK], FONT_SYSTEM, msg_buf, xofs, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
		}
		
		//�X�R�A
		WriteNumData(	&win[TRC_BMPWIN_SCORE],
						BMP_WIDTH_TYPE1, 0, 0, msg_buf, inTrCardData->Score, SCORE_DIGIT,
						NUMBER_DISPTYPE_SPACE);
		
		//�v���C����
		{
			u32 xofs;
			if ( inTrCardData->TimeUpdate) {	//�ʏ�
				WORDSET_RegisterNumber(wordset, BUFID_HOUR,   PLAYTIME_GetHour(inTrCardData->PlayTime),   TIME_H_DIGIT, NUMBER_DISPTYPE_SPACE, NUMBER_CODETYPE_DEFAULT);
				WORDSET_RegisterNumber(wordset, BUFID_MINUTE, PLAYTIME_GetMinute(inTrCardData->PlayTime), TIME_M_DIGIT, NUMBER_DISPTYPE_ZERO,  NUMBER_CODETYPE_DEFAULT);
				MSGMAN_GetString(man, MSG_TCARD_17, tmp_buf);
			} else {							//���ԍX�V���Ȃ��ꍇ�̂݁A�Œ�Łu�F�v�\��
				WORDSET_RegisterNumber(wordset, BUFID_HOUR,   inTrCardData->PlayTime_h, TIME_H_DIGIT, NUMBER_DISPTYPE_SPACE, NUMBER_CODETYPE_DEFAULT);
				WORDSET_RegisterNumber(wordset, BUFID_MINUTE, inTrCardData->PlayTime_m, TIME_M_DIGIT, NUMBER_DISPTYPE_ZERO,  NUMBER_CODETYPE_DEFAULT);
				MSGMAN_GetString(man, MSG_TCARD_16, tmp_buf);
			}
			WORDSET_ExpandStr(wordset, msg_buf, tmp_buf);
			xofs = BMP_WIDTH_TYPE2 - FontProc_GetPrintStrWidth(FONT_SYSTEM, msg_buf, 0);
			GF_STR_PrintColor(&win[TRC_BMPWIN_PLAY_TIME], FONT_SYSTEM, msg_buf, xofs, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
		}
		
		//�X�^�[�g����
		{
			u32 xofs;
			WORDSET_RegisterNumber(wordset, BUFID_YEAR,  inTrCardData->Start_y, DAY_DIGIT, NUMBER_DISPTYPE_ZERO, NUMBER_CODETYPE_DEFAULT);
			// ----------------------------------------------------------------------------
			// localize_spec_mark(LANG_ALL) imatake 2007/01/26
			// ���̕\����P��\�L�ɕύX
			WORDSET_RegisterMonthName( wordset, BUFID_MONTH, inTrCardData->Start_m );
			// ----------------------------------------------------------------------------
			WORDSET_RegisterNumber(wordset, BUFID_DAY,   inTrCardData->Start_d, DAY_DIGIT, NUMBER_DISPTYPE_ZERO, NUMBER_CODETYPE_DEFAULT);
			MSGMAN_GetString(man, MSG_TCARD_18, tmp_buf);
			WORDSET_ExpandStr(wordset, msg_buf, tmp_buf);
			xofs = BMP_WIDTH_TYPE2 - FontProc_GetPrintStrWidth(FONT_SYSTEM, msg_buf, 0);
			GF_STR_PrintColor(&win[TRC_BMPWIN_START_TIME], FONT_SYSTEM, msg_buf, xofs, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
		}

		STRBUF_Delete( tmp_buf );
		WORDSET_Delete( wordset );

		// ----------------------------------------------------------------------------

	}
	STRBUF_Delete( msg_buf );
	MSGMAN_Delete( man );
}

//--------------------------------------------------------------------------------------------
/**
 * ���\���i���ʁj
 *
 * @param	win				BmpWin
 * @param	inTrCardData	�g���[�i�[�J�[�h�f�[�^
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
void TRCBmp_WriteTrWinInfoRev( GF_BGL_BMPWIN	*win, const TR_CARD_DATA *inTrCardData  )
{
	u8 i;
	MSGDATA_MANAGER* man;
	STRBUF *msg_buf;

	GF_BGL_BmpWinFill(
		&win[7], 0, 0, 0,  WIN_CLEAR_SX*8,  WIN_CLEAR_SY*8 );
	GF_BGL_BmpWinFill(
		&win[8], 0, 0, 0,  WIN_COMM_SX*8,  WIN_COMM_SY*8 );
	GF_BGL_BmpWinFill(
		&win[9], 0, 0, 0,  WIN_BATTLE_SX*8,  WIN_BATTLE_SY*8 );
	GF_BGL_BmpWinFill(
		&win[10], 0, 0, 0,  WIN_TRADE_SX*8,  WIN_TRADE_SY*8 );

	man = MSGMAN_Create(MSGMAN_TYPE_NORMAL, ARC_MSG, NARC_msg_trainerscard_dat, HEAPID_TR_CARD);
	msg_buf = STRBUF_Create(TR_STRING_LEN, HEAPID_TR_CARD);
	
	for(i=7;i<TR_CARD_WIN_MAX;i++){
		MSGMAN_GetString(man, MsgList[i] ,msg_buf);
		GF_STR_PrintColor(&win[i], FONT_SYSTEM, msg_buf, 0, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
	}
	{
		// ----------------------------------------------------------------------------
		// localize_spec_mark(LANG_ALL) imatake 2006/12/14
		// �P�ʗނ� gmm �̃e�L�X�g�Ɉڍs

		STRBUF *tmp_buf = STRBUF_Create(TR_STRING_LEN, HEAPID_TR_CARD);
		WORDSET *wordset = WORDSET_CreateEx(WORDMAX_ALL, WORDSET_DEFAULT_BUFLEN, HEAPID_TR_CARD);

		//�a������
        {
            u32 xofs;

            // ----------------------------------------------------------------------------
            // localize_spec_mark(LANG_ALL) imatake 2007/02/13
            // �ł�ǂ�����O�̂ł�ǂ�����̓��t�\�����x�^�e�L�X�g�ɒu������

            if (inTrCardData->Clear_m != 0) {    //����0���łȂ���΁A�N���A�����Ƃ݂Ȃ�
                WORDSET_RegisterNumber(wordset, BUFID_YEAR, inTrCardData->Clear_y, YEAR_DIGIT, NUMBER_DISPTYPE_ZERO,
                                       NUMBER_CODETYPE_DEFAULT);
                // ----------------------------------------------------------------------------
                // localize_spec_mark(LANG_ALL) imatake 2007/01/26
                // ���̕\����P��\�L�ɕύX
                WORDSET_RegisterMonthName(wordset, BUFID_MONTH, inTrCardData->Clear_m);
                // ----------------------------------------------------------------------------
                WORDSET_RegisterNumber(wordset, BUFID_DAY, inTrCardData->Clear_d, DAY_DIGIT, NUMBER_DISPTYPE_ZERO,
                                       NUMBER_CODETYPE_DEFAULT);
                WORDSET_RegisterNumber(wordset, BUFID_HOUR, inTrCardData->ClearTime_h, TIME_H_DIGIT,
                                       NUMBER_DISPTYPE_SPACE, NUMBER_CODETYPE_DEFAULT);
                WORDSET_RegisterNumber(wordset, BUFID_MINUTE, inTrCardData->ClearTime_m, TIME_M_DIGIT,
                                       NUMBER_DISPTYPE_ZERO, NUMBER_CODETYPE_DEFAULT);
                MSGMAN_GetString(man, MSG_TCARD_18, tmp_buf);
                WORDSET_ExpandStr(wordset, msg_buf, tmp_buf);
            }
            else {
                MSGMAN_GetString(man, MSG_TCARD_13, tmp_buf);
                WORDSET_RegisterWord(wordset, BUFID_HOUR, tmp_buf, 0, FALSE, PM_LANG);
                WORDSET_RegisterWord(wordset, BUFID_MINUTE, tmp_buf, 0, FALSE, PM_LANG);
                MSGMAN_GetString(man, MSG_TCARD_18_2, msg_buf);
            }
            // �a������̓��t
            xofs = BMP_WIDTH_TYPE2 - FontProc_GetPrintStrWidth(FONT_SYSTEM, msg_buf, 0);
            GF_STR_PrintColor(&win[TRC_BMPWIN_CLEAR_TIME], FONT_SYSTEM, msg_buf, xofs, 0, MSG_ALLPUT, TR_MSGCOLOR,
                              NULL);

            // ----------------------------------------------------------------------------

            // �a������܂ł̃v���C����
            MSGMAN_GetString(man, MSG_TCARD_16, tmp_buf);
            WORDSET_ExpandStr(wordset, msg_buf, tmp_buf);
            xofs = BMP_WIDTH_TYPE2 - FontProc_GetPrintStrWidth(FONT_SYSTEM, msg_buf, 0);
            GF_STR_PrintColor(&win[TRC_BMPWIN_CLEAR_TIME], FONT_SYSTEM, msg_buf, xofs, 16, MSG_ALLPUT, TR_MSGCOLOR,
                              NULL);
        }

        //�ʐM��
        {
            u32 xofs;

            WORDSET_RegisterNumber(wordset, BUFID_MONEY, inTrCardData->CommNum, COMM_DIGIT, NUMBER_DISPTYPE_LEFT,  NUMBER_CODETYPE_DEFAULT);
            MSGMAN_GetString(man, 22, tmp_buf);
            WORDSET_ExpandStr(wordset, msg_buf, tmp_buf);
            xofs = BMP_WIDTH_TYPE2 - FontProc_GetPrintStrWidth(FONT_SYSTEM, msg_buf, 0);
            GF_STR_PrintColor(&win[TRC_BMPWIN_COMM_INFO], FONT_SYSTEM, msg_buf, xofs, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
        }

//        WriteNumData(	&win[TRC_BMPWIN_COMM_INFO],
//						BMP_WIDTH_TYPE2, 0, 0, msg_buf, inTrCardData->CommNum, COMM_DIGIT,
//						NUMBER_DISPTYPE_SPACE);
		
		//�ʐM�ΐ�
		MSGMAN_GetString(man, MSG_TCARD_19, msg_buf);
		GF_STR_PrintColor(&win[TRC_BMPWIN_BATTLE_INFO], FONT_SYSTEM, msg_buf, WIN_OFS,  0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
		WriteNumData(	&win[TRC_BMPWIN_BATTLE_INFO],
						BMP_WIDTH_TYPE2, 0, 0, msg_buf, inTrCardData->CommBattleLose, BATTLE_DIGIT,
						NUMBER_DISPTYPE_SPACE);
		MSGMAN_GetString(man, MSG_TCARD_20, msg_buf);
		GF_STR_PrintColor(&win[TRC_BMPWIN_BATTLE_INFO], FONT_SYSTEM, msg_buf, LOSE_OFS, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
		WriteNumData(	&win[TRC_BMPWIN_BATTLE_INFO],
						BMP_WIDTH_TYPE2, 8*8, 0, msg_buf, inTrCardData->CommBattleWin, BATTLE_DIGIT,
						NUMBER_DISPTYPE_SPACE);
		
		//�ʐM����
        {
            u32 xofs;

            WORDSET_RegisterNumber(wordset, BUFID_MONEY, inTrCardData->CommTrade, TRADE_DIGIT, NUMBER_DISPTYPE_LEFT,  NUMBER_CODETYPE_DEFAULT);
            MSGMAN_GetString(man, 22, tmp_buf);
            WORDSET_ExpandStr(wordset, msg_buf, tmp_buf);
            xofs = BMP_WIDTH_TYPE2 - FontProc_GetPrintStrWidth(FONT_SYSTEM, msg_buf, 0);
            GF_STR_PrintColor(&win[TRC_BMPWIN_TRADE_INFO], FONT_SYSTEM, msg_buf, xofs, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
        }
//		WriteNumData(	&win[TRC_BMPWIN_TRADE_INFO],
//						BMP_WIDTH_TYPE2, 0, 0, msg_buf, inTrCardData->CommTrade, TRADE_DIGIT,
//						NUMBER_DISPTYPE_SPACE);

		STRBUF_Delete( tmp_buf );
		WORDSET_Delete( wordset );

		// ----------------------------------------------------------------------------
	}
	STRBUF_Delete( msg_buf );
	MSGMAN_Delete( man );
}

//--------------------------------------------------------------------------------------------
/**
 * BMP�E�B���h�E��\��
 *
 * @param	win				BmpWin
 * @param	start			�ΏۃE�B���h�E�J�n�C���f�b�N�X
 * @param	end				�ΏۃE�B���h�E�ŏI�C���f�b�N�X
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
void TRCBmp_NonDispWinInfo(GF_BGL_BMPWIN	*win, const u8 start, const u8 end)
{
	u8 i;
	for(i=start;i<=end;i++){
		GF_BGL_BmpWinOff( &win[i] );
	}
}

//--------------------------------------------------------------------------------------------
/**
 * �����\��
 *
 * @param	win				BmpWin
 * @param	inBmpWidth		��
 * @param	inRightSpace	�E��
 * @param	inStartY		�\���J�nY�ʒu
 * @param	buff			�o�b�t�@
 * @param	inNum			����
 * @param	inDigit			����
 * @param	inDispType		�\���^�C�v
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
static void 
WriteNumData(	GF_BGL_BMPWIN *inWin,
							const u32 inBmpWidth,
							const u32 inRightSpace,
							const u32 inStartY,
							STRBUF *buff,
							const u32 inNum,
							const u8 inDigit,
							const NUMBER_DISPTYPE inDisptype)
{
	u32 len;

	STRBUF_SetNumber( buff, inNum, inDigit, inDisptype, NUMBER_CODETYPE_DEFAULT );
	len = FontProc_GetPrintStrWidth(FONT_SYSTEM,buff,0);

	GF_STR_PrintColor(	inWin, FONT_SYSTEM, buff,
						inBmpWidth-(len+inRightSpace), inStartY,
						MSG_ALLPUT, TR_MSGCOLOR, NULL);	
}

//--------------------------------------------------------------------------------------------
/**
 * �����\��(�㏑���p)
 *
 * @param	win				BmpWin
 * @param	inBmpWidth		��
 * @param	inRightSpace	�E��
 * @param	inStartY		�\���J�nY�ʒu
 * @param	buff			�o�b�t�@
 * @param	inNum			����
 * @param	inDigit			����
 * @param	inDispType		�\���^�C�v
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
static void 
WriteNumDataFill(	GF_BGL_BMPWIN *inWin,
					const u32 inBmpWidth,
					const u32 inRightSpace,
					const u32 inStartY,
					STRBUF *buff,
					const u32 inNum,
					const u8 inDigit,
					const NUMBER_DISPTYPE inDisptype,
					const u32 inFillSatrt,
					const u32 inFillWidth)
{
	u32 len;
	
	STRBUF_SetNumber( buff, inNum, inDigit, inDisptype, NUMBER_CODETYPE_DEFAULT );
	len = FontProc_GetPrintStrWidth(FONT_SYSTEM,buff,0);

	GF_BGL_BmpWinFill( inWin, 0, inFillSatrt, 0,  inFillWidth,  2*8 );

	GF_STR_PrintColor(	inWin, FONT_SYSTEM, buff,
						inBmpWidth-(len+inRightSpace), inStartY,
						MSG_ALLPUT, TR_MSGCOLOR, NULL);	
}

//--------------------------------------------------------------------------------------------
/**
 * ������\��
 *
 * @param	win				BmpWin
 * @param	inBmpWidth		��
 * @param	inRightSpace	�E��
 * @param	inStartY		�\���J�nY�ʒu
 * @param	buff			�o�b�t�@
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
static void WriteStrData(	GF_BGL_BMPWIN *inWin,
							const u32 inBmpWidth,
							const u32 inRightSpace,
							const u32 inStartY,
							const STRBUF *buff)
{
	u32 len;
	len = FontProc_GetPrintStrWidth(FONT_SYSTEM,buff,0);
	GF_STR_PrintColor(	inWin, FONT_SYSTEM, buff,
						inBmpWidth-(len+inRightSpace), inStartY,
						MSG_ALLPUT, TR_MSGCOLOR, NULL);
}

//--------------------------------------------------------------------------------------------
/**
 * �v���C���ԕ`��
 *
 * @param	win				BmpWin
 * @param	inTrCardData	�g���[�i�[�J�[�h�f�[�^
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
void TRCBmp_WritePlayTime(GF_BGL_BMPWIN	*win, const TR_CARD_DATA *inTrCardData, STRBUF *str)
{
	int hour;
	
	GF_ASSERT(inTrCardData->PlayTime!=NULL&&"ERROR:PlayTimeData is NULL!!");

	hour = PLAYTIME_GetHour(inTrCardData->PlayTime);

	if (hour>HOUR_DISP_MAX){
		hour = HOUR_DISP_MAX;
	}

	// ----------------------------------------------------------------------------
	// localize_spec_mark(LANG_ALL) imatake 2006/12/14
	// �P�ʗނ� gmm �̃e�L�X�g�Ɉڍs

	GF_BGL_BmpWinFill( &win[TRC_BMPWIN_PLAY_TIME], 0, TIME_OFS, 0, TIME_WIDTH, 2*8 );

	{
		u32 xofs;
		MSGDATA_MANAGER *man = MSGMAN_Create(MSGMAN_TYPE_NORMAL, ARC_MSG, NARC_msg_trainerscard_dat, HEAPID_TR_CARD);
		STRBUF *msg_buf = STRBUF_Create(TR_STRING_LEN, HEAPID_TR_CARD);
		STRBUF *tmp_buf = STRBUF_Create(TR_STRING_LEN, HEAPID_TR_CARD);
		WORDSET *wordset = WORDSET_CreateEx(WORDMAX_TIME, WORDSET_DEFAULT_BUFLEN, HEAPID_TR_CARD);

		WORDSET_RegisterNumber(wordset, BUFID_HOUR,   PLAYTIME_GetHour(inTrCardData->PlayTime),   TIME_H_DIGIT, NUMBER_DISPTYPE_SPACE, NUMBER_CODETYPE_DEFAULT);
		WORDSET_RegisterNumber(wordset, BUFID_MINUTE, PLAYTIME_GetMinute(inTrCardData->PlayTime), TIME_M_DIGIT, NUMBER_DISPTYPE_ZERO,  NUMBER_CODETYPE_DEFAULT);
		MSGMAN_GetString(man, MSG_TCARD_17, tmp_buf);
		WORDSET_ExpandStr(wordset, msg_buf, tmp_buf);
		xofs = BMP_WIDTH_TYPE2 - FontProc_GetPrintStrWidth(FONT_SYSTEM, msg_buf, 0);
		GF_STR_PrintColor(&win[TRC_BMPWIN_PLAY_TIME], FONT_SYSTEM, msg_buf, xofs, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);

		MSGMAN_Delete( man );
		STRBUF_Delete( msg_buf );
		STRBUF_Delete( tmp_buf );
		WORDSET_Delete( wordset );
	}

	// ----------------------------------------------------------------------------
}

//--------------------------------------------------------------------------------------------
/**
 * �b�\��
 *
 * @param	win				BmpWin
 * @param	inDisp			�\���t���O
 * @param	inSecBuf		������i�R�����j
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
void TRCBmp_WriteSec(GF_BGL_BMPWIN	*win, const BOOL inDisp, STRBUF *inSecBuf)
{
	// ----------------------------------------------------------------------------
	// localize_spec_mark(LANG_ALL) imatake 2006/12/14
	// �P�ʗނ� gmm �̃e�L�X�g�Ɉڍs
	if (inDisp){
		GF_STR_PrintColor(win, FONT_SYSTEM, inSecBuf, COLON_OFS, 0, MSG_ALLPUT, TR_MSGCOLOR, NULL);
	}else{
		GF_BGL_BmpWinFill( win, 0, COLON_OFS, 0, COLON_WIDTH, WIN_S_TIME_SY*8 );
		GF_BGL_BmpWinOn( win );
	}
	// ----------------------------------------------------------------------------
}

