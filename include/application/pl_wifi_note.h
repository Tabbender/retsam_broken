//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
/**
 *	GAME FREAK inc.
 *
 *	@file		pl_wifi_note.h
 *	@brief		�F�B�蒠
 *	@author		tomoya takahshi
 *	@data		2007.07.23
 *
 */
//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifndef __PL_WIFI_NOTE_H__
#define __PL_WIFI_NOTE_H__

#include "system/procsys.h"

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


//-----------------------------------------------------------------------------
/**
 *					�v���g�^�C�v�錾
*/
//-----------------------------------------------------------------------------

// �v���Z�X��`�f�[�^
extern PROC_RESULT WifiNoteProc_Init( PROC * proc, int * seq );
extern PROC_RESULT WifiNoteProc_Main( PROC * proc, int * seq );
extern PROC_RESULT WifiNoteProc_End( PROC * proc, int * seq );

#endif		// __PL_WIFI_NOTE_H__
