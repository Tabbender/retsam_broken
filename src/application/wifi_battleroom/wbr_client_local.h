//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
/**
 *
 *	@file		wbr_client_local.h
 *	@brief		�N���C�A���g�V�X�e���֘A�\�[�X����w�b�_
 *	@author		tomoya takahashi
 *	@data		2007.02.22
 *
 */
//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifndef __WBR_CLIENT_LOCAL_H__
#define __WBR_CLIENT_LOCAL_H__

#include "wbr_common.h"
#include "field/field.h"

#undef GLOBAL
#ifdef	__WBR_CLIENT_LOCAL_H_GLOBAL
#define	GLOBAL	/* */
#else
#define	GLOBAL	extern
#endif

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
///	�N���C�A���g�ʐM��{�f�[�^
//	�T�u�Ղ�����ɂ��n�����
//=====================================
typedef struct {
	u16 netid;
	u16	next_seq;	// �������邩(WALK�v���b�N�݂̂ɗL��)
	u16 link_netid;	// ����������Ώۂ̃v���C���[

	u32 heapID;
	const WBR_MYSTATUS* cp_mystatus;
	FIELDSYS_WORK* p_fsys;

	// �v���b�N�f�[�^���[�N
	void* p_procw;

	// ��M�f�[�^���[�N
	WBR_COMM_COMMON	comm_data[ WBR_COMM_NUM ];

} WBR_CLIENT_COMMON;

//-----------------------------------------------------------------------------
/**
 *					�v���g�^�C�v�錾
*/
//-----------------------------------------------------------------------------
#undef	GLOBAL
#endif		// __WBR_CLIENT_LOCAL_H__
