//==============================================================================================
/**
 * @file	snd_perap.h
 * @brief	�T�E���h �y���b�v�֐�
 * @author	Satoshi Nohara
 * @date	2006.04.15
 */
//==============================================================================================
#ifndef __SND_PERAP_H__
#define __SND_PERAP_H__


#include "common.h"
#include "system/snd_tool.h"
#include "savedata/savedata.h"				//
#include "savedata/perapvoice.h"			//


//==============================================================================================
//
//	extern�錾
//
//==============================================================================================

//--------------------------------------------------------------
/**
 * @brief	�T�E���h���C������Ă΂��
 *			�؃��b�v�̘^�������f�[�^�̍Đ��I�����Ď����ă`�����l���J��������
 *
 * @param	none
 *
 * @retval	"��������=TRUE�A�������Ȃ�=FALSE"
 */
//--------------------------------------------------------------
extern BOOL Snd_MainPerapCheck( void );

//--------------------------------------------------------------
/**
 * @brief	�y���b�v�̘^�������f�[�^���Đ��\���`�F�b�N
 *
 * @param	no		�|�P�����i���o�[
 *
 * @retval	"�Đ��\=TRUE�A�Đ��s��=FALSE"
 */
//--------------------------------------------------------------
extern BOOL Snd_PerapVoiceCheck( const PERAPVOICE* perap );

//--------------------------------------------------------------
/**
 * @brief	�y���b�v�̘^�������f�[�^���Đ����Ă��邩�`�F�b�N
 *
 * @param	no		�|�P�����i���o�[
 *
 * @retval	"�Đ���=TRUE�A�Đ����Ă��Ȃ�=FALSE"
 */
//--------------------------------------------------------------
extern BOOL Snd_PerapVoicePlayingCheck( const PERAPVOICE* perap );

//--------------------------------------------------------------
/**
 * @brief	�y���b�v�̘^�������f�[�^���Đ�
 *
 * @param	perap	PERAPVOICE�^�̃|�C���^
 * @param	sex		����
 * @param	vol		�{�����[��
 * @param	pan		�p��
 *
 * @retval	"�Đ�����=TRUE�A���s=FALSE"
 */
//--------------------------------------------------------------
extern BOOL Snd_PerapVoicePlaySub( const PERAPVOICE* perap, u32 sex, int vol, int pan );

//--------------------------------------------------------------
/**
 * @brief	�y���b�v�̘^�������f�[�^���~
 *
 * @param	none
 *
 * @retval	none
 */
//--------------------------------------------------------------
extern void Snd_PerapVoiceStop( void );

//--------------------------------------------------------------
/**
 * @brief	�y���b�v�f�[�^�^���J�n(�T�E���h�V�X�e���̗̈�Ɉꎞ�ۑ�����)
 *
 * @param	none
 *
 * @retval	"MIC_RESULT_SUCCESS		����������Ɋ���"
 * @retval	"����ȊO				���炩�̌����Ŏ��s"
 */
//--------------------------------------------------------------
extern MICResult Snd_PerapVoiceRecStart( void );

//--------------------------------------------------------------
/**
 * @brief	�y���b�v�f�[�^�^����~
 *
 * @param	none
 *
 * @retval	"MIC_RESULT_SUCCESS		����������Ɋ���"
 * @retval	"����ȊO				���炩�̌����Ŏ��s"
 */
//--------------------------------------------------------------
extern MICResult Snd_PerapVoiceRecStop( void );

//--------------------------------------------------------------
/**
 * @brief	�^�������f�[�^���Z�[�u�f�[�^�ɃZ�b�g
 *
 * @param	none
 *
 * @retval	none
 */
//--------------------------------------------------------------
extern void Snd_PerapVoiceDataSave( PERAPVOICE* perap );


//==============================================================================================
//
//	�T�E���h�V�X�e�����ŁA
//
//	���؃��b�v�i���o�[���`�F�b�N
//	���f�t�H���g�̖�����炷�t���O���`�F�b�N
//
//	�^�������f�[�^���Đ����邩�ɑΉ������֘A
//
//==============================================================================================

//--------------------------------------------------------------
/**
 * @brief	�؃��b�v�̃f�t�H���g�̖������Đ�����t���O����
 *
 * @param	no		�t���O����
 *
 * @retval	none
 */
//--------------------------------------------------------------
extern void Snd_PerapVoiceDefaultFlagSet( u8 no );


//==============================================================================================
//
//	�ʐM�m�ۂ����؃��b�v�f�[�^�̃|�C���^���󂯎��A�Đ�����֘A
//
//==============================================================================================

//--------------------------------------------------------------
/**
 * @brief	�T�E���h�V�X�e���̂؃��b�v�|�C���^�ɃZ�b�g
 *
 * @param	perap	PERAPVOICE�^�̃|�C���^
 *
 * @retval	none
 */
//--------------------------------------------------------------
extern void Snd_PerapVoicePtrSet( PERAPVOICE* perap );

//--------------------------------------------------------------
/**
 * @brief	�y���b�v�̘^�������f�[�^���Đ�
 *
 * @param	perap	�؃��b�v�f�[�^�̃|�C���^
 * @param	sex		����
 * @param	vol		�{�����[��
 * @param	pan		�p��
 *
 * @retval	"�Đ�����=TRUE�A���s=FALSE"
 */
//--------------------------------------------------------------
extern BOOL Snd_PerapVoicePlay( PERAPVOICE* perap, u32 sex, int vol, int pan );

//--------------------------------------------------------------
/**
 * @brief	�y���b�v�̘^�������f�[�^���Đ�(�E�F�C�g�w�肠��)
 *
 * @param	perap	�؃��b�v�f�[�^�̃|�C���^
 * @param	sex		����
 * @param	vol		�{�����[��
 * @param	pan		�p��
 * @param	wait	�E�F�C�g
 *
 * @retval	"�Đ�����=TRUE�A���s=FALSE"
 */
//--------------------------------------------------------------
extern BOOL Snd_PerapVoiceWaitPlay( PERAPVOICE* perap, u32 sex, int vol, int pan, u8 wait );


//==============================================================================================
//
//	�Z�u������ׂ�v
//
//==============================================================================================

//--------------------------------------------------------------
/**
 * @brief	�Z�̃p�����[�^���擾
 *
 * @param	id		�ǂ̂؃��b�v��炷��(�ʐMID)
 *
 * @retval	"�p�����[�^ 0�`2"
 */
//--------------------------------------------------------------
//extern int Snd_PerapVoiceWazaParamGet( u32 id );
extern	int Snd_PerapVoiceWazaParamGet( PERAPVOICE* perap );


//--------------------------------------------------------------
/**
 * @brief	�^���f�[�^�A�f�t�H���g�f�[�^�ǂ�����Đ����邩�`�F�b�N
 *
 * @param	type		�Đ��p�^�[��
 *
 * @retval	"TRUE=�^�������f�[�^���Đ�����AFALSE=�f�t�H���g�̖������Đ�����"
 */
//--------------------------------------------------------------
extern BOOL Snd_PerapVoicePMVoiceTypeCheck( int type );


#endif

