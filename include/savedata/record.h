//============================================================================================
/**
 * @file	record.h
 * @brief
 * @date	2006.03.28
 * @author	tamada/iwasawa
 */
//============================================================================================

#ifndef	__RECORD_H__
#define	__RECORD_H__

#ifndef	__ASM_NO_DEF_

#include "savedata/savedata_def.h"
#include "score_def.h"
#include "savedata/zukanwork.h"

//============================================================================================
//
//	RECORD�𑀍삷��̂ɕK�v�Ȓ�`
//
//============================================================================================
//----------------------------------------------------------
/**
 * @brief	RECORD�ւ̕s���S�^��`
 */
//----------------------------------------------------------
typedef struct RECORD RECORD;

//----------------------------------------------------------
//----------------------------------------------------------
//���R�[�h�f�[�^�̎擾
extern RECORD * SaveData_GetRecord(SAVEDATA * sv);

extern void RECORD_Init(RECORD * rec);
extern int RECORD_GetWorkSize(void);

//----------------------------------------------------------
//----------------------------------------------------------
//�l���Z�b�g����
extern u32 RECORD_Set(RECORD * rec, int id, u32 value);
//���݂̒l�Ɣ�r�A�傫����Βl���Z�b�g����
extern u32 RECORD_SetIfLarge(RECORD * rec, int id, u32 value);
//�l���C���N�������g����
extern u32 RECORD_Inc(RECORD * rec, int id);
//�l���擾����
extern u32 RECORD_Get(RECORD * rec, int id);
//�l�𑫂�
extern u32 RECORD_Add(RECORD * rec, int id, u32 add_value);

#ifdef PM_DEBUG
//�X�R�A�̃Z�b�g
extern void RECORD_Score_DebugSet(RECORD * rec, const u32 inScore);
#endif

//----------------------------------------------------------
//----------------------------------------------------------
//�X�R�A�̉��Z����
extern void RECORD_Score_Add(RECORD * rec, int id);
//�X�R�A���擾����
extern u32 RECORD_Score_Get(RECORD * rec);
//�}�ӃX�R�A���Z
extern void RECORD_Score_AddZukanScore(RECORD * rec, const ZUKAN_WORK * zw, u16 const inMonsno);

#endif	//__ASM_NO_DEF_


//============================================================================================
//
//	RECORD�e���ڂ̒�`
//
//============================================================================================
//----------------------------------------------------------
//----------------------------------------------------------
#define	REC_FIRST		0

//�Í�������O���ׁA�����J�E���^��擪�Ɏ����Ă���
#define RECID_WALK_COUNT				(REC_FIRST+0)	///<����

/**
 *	@brief	�X�R�A�擾�w��ID(4byte)
 *
 *	�l�̉��Z�ɂ͕K��RECORD_Score_Add()�֐�
 *	�l�̎Q�Ƃɂ͕K��RECORD_Score_Get()�֐����g�p���邱��
 *
 *	RECORD_Add()/RECORD_Get()�ɒ��ڎw�肵�Ēl���X�V/�Q�Ƃ��邱�Ƃ͋֎~�ł�
*/
#define RECID_SCORE						(REC_FIRST+1)	///<�X�R�A

#define	LARGE_REC_START		1

//�ȉ��́A4�o�C�g�̃J�E���^������
#define RECID_REPORT_COUNT				(LARGE_REC_START+1)	///<���|�[�g��
#define RECID_CLEAR_TIME				(LARGE_REC_START+2)	///<�N���A�^�C��
#define RECID_NUTS_PLANT				(LARGE_REC_START+3)	///<�؂̎���A������
#define RECID_RIDE_CYCLE				(LARGE_REC_START+4)	///<���]�Ԃɏ������
#define RECID_BATTLE_COUNT				(LARGE_REC_START+5)	///<�S�퓬��
#define RECID_BTL_ENCOUNT				(LARGE_REC_START+6)	///<�G���J�E���g�퓬��
#define RECID_BTL_TRAINER				(LARGE_REC_START+7)	///<�g���[�i�[�퓬��

#define	RECID_CAPTURE_POKE				(LARGE_REC_START+8)	///<���08:�ߊl�����|�P�����̐�
#define RECID_FISHING_SUCCESS			(LARGE_REC_START+9)	///<�ނ肠�����|�P�����̉�
#define	RECID_TAMAGO_HATCHING			(LARGE_REC_START+10)	///<���12:�^�}�S��z������
#define	RECID_POKE_EVOLUTION			(LARGE_REC_START+11)	///<�i���������|�P�����̈���
#define RECID_RECOVERY_PC				(LARGE_REC_START+12)	///<�|�P�Z���ŋx�񂾉�
#define RECID_SLOT_FEAVER				(LARGE_REC_START+13)	///<�X���b�g�ő哖���肳������
#define RECID_BTOWER_CHALLENGE			(LARGE_REC_START+14)	///<�o�g���^���[�ɒ��񂾉�
#define RECID_ENTER_MARSHLAND			(LARGE_REC_START+15)	///<�����ɓ�������
#define RECID_WAZA_IAIGIRI				(LARGE_REC_START+16)	///<�������؂���g������
#define RECID_WAZA_IWAKUDAKI			(LARGE_REC_START+17)	///<���킭�������g������

#define RECID_COMM_TRADE				(LARGE_REC_START+18)	///<���C�����X�ʐM������������
#define RECID_COMM_BATTLE				(LARGE_REC_START+19)	///<���C�����X�ʐM�ΐ��������
#define RECID_COMM_BTL_WIN				(LARGE_REC_START+20)	///<���C�����X�ʐM�ΐ�̏�����
#define RECID_COMM_BTL_LOSE				(LARGE_REC_START+21)	///<���C�����X�ʐM�ΐ�̔s�k��
#define RECID_COMM_BTL_DRAW				(LARGE_REC_START+22)	///<���C�����X�ʐM�ΐ�̈���������

#define RECID_WIFI_TRADE				(LARGE_REC_START+23)	///<WiFi�ʐM������������
#define RECID_WIFI_BATTLE				(LARGE_REC_START+24)	///<WiFi�ʐM�ΐ��������
#define RECID_WIFI_BTL_WIN				(LARGE_REC_START+25)	///<WiFi�ʐM�ΐ�̏�����
#define RECID_WIFI_BTL_LOSE				(LARGE_REC_START+26)	///<WiFi�ʐM�ΐ�̔s�k��
#define RECID_WIFI_BTL_DRAW				(LARGE_REC_START+27)	///<WiFi�ʐM�ΐ�̈���������

#define RECID_BTOWER_WIN				(LARGE_REC_START+28)	///<�o�g���^���[�ł̑�������(���g���C���[�h�ȊO�S��)
#define RECID_NMIXER_PLAY				(LARGE_REC_START+29)	///<�܂��܂��������s������
#define RECID_NMUSU_PLAY				(LARGE_REC_START+30)	///<�ނ��ނ��������s������
#define RECID_PORUTO_COMM				(LARGE_REC_START+31)	///<�|���g�����C�����X�ʐM�ō������
#define RECID_PORUTO_EAT				(LARGE_REC_START+32)	///<�|�P�����ɐH�ׂ������|���g�̌�

#define RECID_SHOPPING_CNT				(LARGE_REC_START+33)	///<��������������
#define RECID_SHOPPING_MONEY			(LARGE_REC_START+34)	///<���������������v���z
#define RECID_POKETCH_CHANGE			(LARGE_REC_START+35)	///<�|�P�b�`�̋@�\��؂�ւ�����
#define RECID_ZUKAN_OPEN				(LARGE_REC_START+36)	///<�|�P�����}�ӂ��J������
#define RECID_WATCH_TV					(LARGE_REC_START+37)	///<�e���r��������
#define RECID_DANSA_JUMP				(LARGE_REC_START+38)	///<�i�����э~�肽��
#define RECID_SODATEYA_CNT				(LARGE_REC_START+39)	///<��ĉ��Ƀ|�P������a������

#define	RECID_KILL_POKE					(LARGE_REC_START+40)	///<���07:�|�����|�P�����̐�
#define	RECID_DAYMAX_EXP				(LARGE_REC_START+41)	///<���24:1���ɉ҂����o���l
#define	RECID_DAYCNT_EXP				(LARGE_REC_START+42)	///<���24:1���ɉ҂����o���l

//4byte:�v���`�i����ǉ�
#define RECID_GTS_PUT					(LARGE_REC_START+43)	///<GTS�Ƀ|�P������a������
#define RECID_MAIL_WRITE				(LARGE_REC_START+44)	///<���[������������
#define RECID_LOBBY_CHAT				(LARGE_REC_START+45)	///<WIFI�L��Řb����������
#define RECID_UG_BALL					(LARGE_REC_START+46)	///<�n���ʘH�ŋ��𖄂߂���
#define RECID_TV_COUNT					(LARGE_REC_START+47)	///<�e���r��������
#define RECID_NICKNAME					(LARGE_REC_START+48)///<�|�P�����Ƀj�b�N�l�[����t������
#define RECID_PREMIUM_BALL				(LARGE_REC_START+49)	///<��������v���~�A�{�[���̐�
#define RECID_FUREAI_ITEM		(LARGE_REC_START+50)///<�ӂꂠ���L��Ń|�P�����ɉ������������
#define RECID_COOKING_SINGLE			(LARGE_REC_START+51)	///<��l�Ń|�t�B�����������
#define RECID_COOKING_FRIENDS			(LARGE_REC_START+52)	///<�F�B�ƃ|�t�B�����������
#define RECID_DRESS_COUNT			(LARGE_REC_START+53)///<�|�P�����̃h���X�A�b�v�ʐ^���������
#define RECID_KAIRIKI_COUNT			(LARGE_REC_START+54)	///<��`�Z�����肫�Ŋ����������
#define RECID_MARSH_COUNT			(LARGE_REC_START+55)	///<���ɂ͂܂�����
#define RECID_LEADERHOUSE_BATTLE	(LARGE_REC_START+56)	///<���[�_�[�n�E�X�Ő������
#define RECID_FRONTIER_COUNT		(LARGE_REC_START+57)	///<�t�����e�B�A�{�݂ɒ��킵����
#define RECID_FRONTIER_BRAIN		(LARGE_REC_START+58)	///<�t�����e�B�A�u���[���ɉ������
#define RECID_FACTORY_WIN			(LARGE_REC_START+59)	///<�t�@�N�g���[�ŏ�������
#define RECID_CASTLE_WIN			(LARGE_REC_START+60)	///<�L���b�X���ŏ�������
#define RECID_STAGE_WIN				(LARGE_REC_START+61)	///<�X�e�[�W�ŏ�������
#define RECID_ROULETTE				(LARGE_REC_START+62)	///<���[���b�g�ŏ�������
#define RECID_FACTORY_POKE_CHANGE	(LARGE_REC_START+63)///<�t�@�N�g���[�Ń|�P����������������
#define RECID_CASTLE_POINT			(LARGE_REC_START+64)	///<�҂����L���b�X���|�C���g
#define RECID_STAGE_RANK10_WIN	(LARGE_REC_START+65)///<�X�e�[�W�Ń����N10�̃|�P�����ɏ�������
#define RECID_ROULETTE_BP			(LARGE_REC_START+66)	///<���[���b�g�̖ڂł������BP
#define RECID_WIN_BP				(LARGE_REC_START+67)	///<���������BP
#define RECID_USE_BP				(LARGE_REC_START+68)	///<�g����BP
#define RECID_CHANGE_HOSHINOKAKERA	(LARGE_REC_START+69)	///<�^�^�����S���Ō��������ق��̂�����̐�

#define	LARGE_REC_NUM	(70+LARGE_REC_START)
#define	LARGE_REC_MAX	(LARGE_REC_NUM)	

//�ȉ��́A2�o�C�g�����J�E���^�������Ȃ�
#define	SMALL_REC_START		LARGE_REC_MAX

#define RECID_MAKE_TRAND_CNT			(SMALL_REC_START+0)	///<���s���������
#define RECID_INTERVIEW_CNT				(SMALL_REC_START+1)	///<�C���^�r���[�ɓ�������
#define RECID_DENDOU_CNT				(SMALL_REC_START+2)	///<�a�����肵����
#define RECID_RECOVERY_HOME				(SMALL_REC_START+3)	///<�����̉Ƃŋx�񂾉�
#define RECID_MOVE_MYBASE				(SMALL_REC_START+4)	///<�閧��n���ړ�������

#define RECID_WAZA_HANERU				(SMALL_REC_START+5)	///<�u�͂˂�v���g������
#define RECID_WAZA_WARUAGAKI			(SMALL_REC_START+6)	///<�u��邠�����v���g������
#define RECID_WAZA_ZIBAKU				(SMALL_REC_START+7)	///<�u���΂��v���g������
#define RECID_WAZA_DAIBAKUHATU			(SMALL_REC_START+8)	///<�u�����΂��͂v���g������

#define	RECID_RENSHOU_SINGLE			(SMALL_REC_START+9)	///<�^���[:�V���O���o�g���A����
#define	RECID_RENSHOU_SINGLE_CNT		(SMALL_REC_START+10)///<�^���[:�V���O���o�g���A����
#define	RECID_RENSHOU_DOUBLE			(SMALL_REC_START+11)	///<�^���[:�_�u���o�g���A����
#define	RECID_RENSHOU_DOUBLE_CNT		(SMALL_REC_START+12)	///<�^���[:�_�u���o�g���A����
#define	RECID_RENSHOU_MULTI				(SMALL_REC_START+13)	///<�^���[:�}���`�o�g���A����
#define	RECID_RENSHOU_MULTI_CNT			(SMALL_REC_START+14)	///<�^���[:�}���`�o�g���A����
#define	RECID_RENSHOU_COMM_MULTI		(SMALL_REC_START+15)	///<�^���[:�}���`�o�g���i�ʐM�j�A����
#define	RECID_RENSHOU_COMM_MULTI_CNT	(SMALL_REC_START+16)	///<�^���[:�}���`�o�g���i�ʐM�j�A����
#define	RECID_RENSHOU_WIFI				(SMALL_REC_START+17)	///<�^���[:Wi-Fi�o�g���A����
#define	RECID_RENSHOU_WIFI_CNT			(SMALL_REC_START+18)	///<�^���[:Wi-Fi�o�g���A����

#define RECID_CONTEST_ENTRY				(SMALL_REC_START+19)	///<�R���e�X�g�ɎQ��������
#define RECID_CONTEST_COMM_ENTRY		(SMALL_REC_START+20)	///<�R���e�X�g(�ʐM)�ɎQ��������
#define RECID_CONTEST_GPX				(SMALL_REC_START+21)	///<�R���e�X�g�ŗD��������
#define RECID_CONTEST_COMM_GPX			(SMALL_REC_START+22)	///<�R���e�X�g(�ʐM)�ŗD��������
#define RECID_CONTEST_RIBBON_GET		(SMALL_REC_START+23)	///<��������{���̌�(�R���e�X�g����)

#define	RECID_WAZA_MUKOU				(SMALL_REC_START+24)	///<���14:�����ʂ킴���o������
#define	RECID_TEMOTI_KIZETU				(SMALL_REC_START+25)	///<���15:�C�₳�����莝���̈���
#define	RECID_TEMOTI_MAKIZOE			(SMALL_REC_START+26)	///<���16:�����Ƀ_���[�W��^������
#define	RECID_NIGERU_SIPPAI				(SMALL_REC_START+27)	///<���17:���������Ȃ�����
#define	RECID_NIGERARETA				(SMALL_REC_START+28)	///<���18�F������ꂽ�|�P�����̐�
#define	RECID_FISHING_FAILURE			(SMALL_REC_START+29)	///<���22:�葹�Ȃ�����
#define	RECID_DAYMAX_PORUTO				(SMALL_REC_START+30)	///<���23:1���Ƀ|���g��H�ׂ�������
#define	RECID_DAYCNT_PORUTO				(SMALL_REC_START+31)	///<���23:1���Ƀ|���g��H�ׂ�������
#define	RECID_DAYMAX_KILL				(SMALL_REC_START+32)	///<���25:1���ɓ|�����|�P�����̐�
#define	RECID_DAYCNT_KILL				(SMALL_REC_START+33)	///<���25:1���ɓ|�����|�P�����̐�
#define	RECID_DAYMAX_CAPTURE			(SMALL_REC_START+34)	///<���26:1���ɕߊl�����|�P�����̐�
#define	RECID_DAYCNT_CAPTURE			(SMALL_REC_START+35)	///<���26:1���ɕߊl�����|�P�����̐�
#define	RECID_DAYMAX_TRAINER_BATTLE		(SMALL_REC_START+36)	///<���27:1���Ƀg���[�i�[�킵����
#define	RECID_DAYCNT_TRAINER_BATTLE		(SMALL_REC_START+37)	///<���27:1���Ƀg���[�i�[�킵����
#define	RECID_DAYMAX_EVOLUTION			(SMALL_REC_START+38)	///<���28:1���Ƀ|�P�����i����������
#define	RECID_DAYCNT_EVOLUTION			(SMALL_REC_START+39)	///<���28:1���Ƀ|�P�����i����������

#define RECID_COMM_SURETIGAI			(SMALL_REC_START+40)	///<����Ⴂ�ʐM��������
#define RECID_NMIXER_TEAMWORK			(SMALL_REC_START+41) ///<�܂��܂������`�[�����[�N�ō����_

//2byte:�v���`�i����ǉ�
#define RECID_WIFICLUB_TRADE	(SMALL_REC_START+42)	///<WIFI�N���u�Ń|�P��������������
#define RECID_MYSIGN_WRITE		(SMALL_REC_START+43)	///<�g���[�i�[�J�[�h�ɃT�C������������
#define RECID_FOSSIL_RESTORE	(SMALL_REC_START+44)	///<�|�P�����̉��΂𕜌�������
#define RECID_FOOTMARK_LOOK		(SMALL_REC_START+45)	///<�t�g�}�L���m�ɑ��Ղ����Ă��������
#define RECID_MITSU_ENC			(SMALL_REC_START+46)	///<�Â����Ŗ쐶�̃|�P�����Əo�������
#define RECID_LOBBY_GAME_COUNT	(SMALL_REC_START+47)	///<WIFI�L��̃Q�[���ɎQ��������
#define RECID_GURUGURU_COUNT	(SMALL_REC_START+48)	///<���邮������Ō��������^�}�S�̐�



#define	SMALL_REC_NUM	(49+28)	//28�ӏ����]��
#define	SMALL_REC_MAX	(SMALL_REC_NUM+LARGE_REC_MAX)


#endif	/* __RECORD_H__ */
