//==============================================================================================
/**
 * @file	backup.h
 * @brief	�o�b�N�A�b�v�x����ʋ��ʃw�b�_
 * @date	2006.07.07
 * @author	watanabe / tamada
 */
//==============================================================================================
#ifndef	__BACKUP_H__
#define	__BACKUP_H__

#include "system/procsys.h"


//---------------------------------------------------------------------------
/**
 * @brief	�Z�[�u���s�G���[�̎w��
 */
//---------------------------------------------------------------------------
enum {
	SAVEERROR_MSG_DISABLE_WRITE = 0,		///<�������ݎ��s�̎�
	SAVEERROR_MSG_DISABLE_READ,				///<�������ݑO�̃��[�h�`�F�b�N���s�̂Ƃ�
};

//---------------------------------------------------------------------------
/**
 * @brief	�Z�[�u���s��ʌĂяo��
 * @param	heapID			�g�p����q�[�v��ID
 * @param	error_msg_id	�\������G���[�̎�ގw��iSAVEERROR_MSG_�`���w�肷��j
 */
//---------------------------------------------------------------------------
extern void SaveErrorWarningCall( int heapID, int error_msg_id );

//---------------------------------------------------------------------------
/**
 * @brief	���[�h���s��ʌĂяo��
 * @param	heapID			�g�p����q�[�v��ID
 */
//---------------------------------------------------------------------------
extern void BackupErrorWarningCall( int heapID );

#if AFTERMASTER_070123_GBACARTRIDGE_BUG_FIX
extern void GbaCartridgeErrorWarningCall( int heapID );
#endif

#endif	//__BACKUP_H__