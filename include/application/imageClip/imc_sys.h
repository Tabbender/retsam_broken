//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
/**
 *
 *	@file		imc_sys.h
 *	@brief		�C���[�W�N���b�v���C���V�X�e��
 *	@author		tomoya takahashi
 *	@data		2005.09.21
 *
 */
//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifndef __IMC_SYS_H__
#define __IMC_SYS_H__

#include "include/system/procsys.h"
#include "include/savedata/imageclip_data.h"
#include "include/savedata/config.h"
#include "include/contest/contest.h"
#include "include/savedata/record.h"

#undef GLOBAL
#ifdef	__IMC_SYS_H_GLOBAL
#define	GLOBAL	/* */
#else
#define	GLOBAL	extern
#endif


//-----------------------------------------------------------------------------
/**
 *	�y�����z
 *		�C���[�W�N���b�v�v���b�N��2����܂��B
 *		�P�F�ʏ�̍쐬�v���b�N			[JAMP_NORMAL]
 *		�Q�F�R���e�X�g�p�v���b�N		[JAMP_CONTEST]
 *		�ł��B
 */
//-----------------------------------------------------------------------------




//-----------------------------------------------------------------------------
/**
 *					�ʏ�
 * [JAMP_NORMAL]
 */
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/**
 *					�萔�錾
*/
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/**
 *					�\���̐錾
*/
//-----------------------------------------------------------------------------
//-------------------------------------
//	�C���[�W�N���b�v�O���f�[�^
//=====================================
typedef struct {
	// �ҏW����|�P�����f�[�^
	POKEMON_PARAM* p_poke_para;

	// �C���[�W�N���b�v�Z�[�u�̈�
	IMC_TELEVISION_SAVEDATA* p_imc_one_data;

	// �C���[�W�N���b�v�A�C�e���Z�[�u�̈�
	const IMC_ITEM_SAVEDATA* cp_imc_item;

	// �R���t�B�O
	const CONFIG* cp_config;

	// ���R�[�h�f�[�^
	RECORD* p_record;	

	// �g���[�i�[�f�[�^
	const MYSTATUS* cp_tr;

	// �Z�[�u�L���i�[��
	BOOL* p_save_flg;

	// �ŏ��̐����e�L�X�g���o�����`�F�b�N
	BOOL reference;
} IMC_PROC_WORK;


//-----------------------------------------------------------------------------
/**
 *					�v���g�^�C�v�錾
*/
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------
/**
 *
 *	@brief	�C���[�W�N���b�v�v���b�N����
 *
 *	@param	proc		�v���b�N�f�[�^	
 *	@param	seq			�V�[�P���X
 *
 *	@return	������
 *
 *	typedef enum {
 *		PROC_RES_CONTINUE = 0,		///<����p����
 *		PROC_RES_FINISH,			///<����I��
 *	}PROC_RESULT;
 *
 *
 */
//-----------------------------------------------------------------------------
GLOBAL PROC_RESULT IMC_ProcInit( PROC* proc, int* seq );

//----------------------------------------------------------------------------
/**
 *
 *	@brief	�C���[�W�N���b�v�v���b�N���C��
 *
 *	@param	proc		�v���b�N�f�[�^	
 *	@param	seq			�V�[�P���X
 *
 *	@return	������
 *
 *	typedef enum {
 *		PROC_RES_CONTINUE = 0,		///<����p����
 *		PROC_RES_FINISH,			///<����I��
 *	}PROC_RESULT;
 *
 *
 */
//-----------------------------------------------------------------------------
GLOBAL PROC_RESULT IMC_ProcMain( PROC* proc, int* seq );

//----------------------------------------------------------------------------
/**
 *
 *	@brief	�C���[�W�N���b�v�v���b�N�I��
 *
 *	@param	proc		�v���b�N�f�[�^	
 *	@param	seq			�V�[�P���X
 *
 *	@return	������
 *
 *	typedef enum {
 *		PROC_RES_CONTINUE = 0,		///<����p����
 *		PROC_RES_FINISH,			///<����I��
 *	}PROC_RESULT;
 *
 *
 */
//-----------------------------------------------------------------------------
GLOBAL PROC_RESULT IMC_ProcEnd( PROC* proc, int* seq );




//-----------------------------------------------------------------------------
/**
 *					�R���e�X�g�p
 * [JAMP_CONTEST]
 */
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/**
 *					�萔�錾
*/
//-----------------------------------------------------------------------------
//-------------------------------------
//	�����萔
//=====================================
#define IMC_COUNT_MAX	(60)

//-----------------------------------------------------------------------------
/**
 *					�\���̐錾
*/
//-----------------------------------------------------------------------------
//-------------------------------------
//	�C���[�W�N���b�v�O���f�[�^
//=====================================
typedef struct {
	// �ҏW����|�P�����f�[�^
	POKEMON_PARAM* p_poke_para;

	// �C���[�W�N���b�v�Z�[�u�̈�
	IMC_CONTEST_SAVEDATA* p_imc_one_data;

	int theme;			// �e�[�}
	int rank;			// �����N
	int mode;			// ���[�h
	int type;			// ����

	// �C���[�W�N���b�v�A�C�e���Z�[�u�̈�
	const IMC_ITEM_SAVEDATA* cp_imc_item;

	// �ʐM�p�f�[�^
	CON_IMC_LOCAL* p_comm_data;	

	// �R���t�B�O
	const CONFIG* cp_config;	

	// �g���[�i�[�f�[�^
	const MYSTATUS* cp_tr;

} IMC_CONTEST_PROC_WORK;


//-----------------------------------------------------------------------------
/**
 *					�v���g�^�C�v�錾
*/
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------
/**
 *
 *	@brief	�C���[�W�N���b�v�v���b�N����
 *
 *	@param	proc		�v���b�N�f�[�^	
 *	@param	seq			�V�[�P���X
 *
 *	@return	������
 *
 *	typedef enum {
 *		PROC_RES_CONTINUE = 0,		///<����p����
 *		PROC_RES_FINISH,			///<����I��
 *	}PROC_RESULT;
 *
 *
 */
//-----------------------------------------------------------------------------
GLOBAL PROC_RESULT IMC_ProcContestInit( PROC* proc, int* seq );

//----------------------------------------------------------------------------
/**
 *
 *	@brief	�C���[�W�N���b�v�v���b�N���C��
 *
 *	@param	proc		�v���b�N�f�[�^	
 *	@param	seq			�V�[�P���X
 *
 *	@return	������
 *
 *	typedef enum {
 *		PROC_RES_CONTINUE = 0,		///<����p����
 *		PROC_RES_FINISH,			///<����I��
 *	}PROC_RESULT;
 *
 *
 */
//-----------------------------------------------------------------------------
GLOBAL PROC_RESULT IMC_ProcContestMain( PROC* proc, int* seq );

//----------------------------------------------------------------------------
/**
 *
 *	@brief	�C���[�W�N���b�v�v���b�N�I��
 *
 *	@param	proc		�v���b�N�f�[�^	
 *	@param	seq			�V�[�P���X
 *
 *	@return	������
 *
 *	typedef enum {
 *		PROC_RES_CONTINUE = 0,		///<����p����
 *		PROC_RES_FINISH,			///<����I��
 *	}PROC_RESULT;
 *
 *
 */
//-----------------------------------------------------------------------------
GLOBAL PROC_RESULT IMC_ProcContestEnd( PROC* proc, int* seq );



#undef	GLOBAL
#endif		// __IMC_SYS_H__
