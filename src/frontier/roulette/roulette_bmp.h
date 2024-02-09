//==============================================================================================
/**
 * @file	roulette_bmp.h
 * @brief	�u�o�g�����[���b�g�vBMP
 * @author	Satoshi Nohara
 * @date	08.09.05
 */
//==============================================================================================
#ifndef _ROULETTE_BMP_H_
#define _ROULETTE_BMP_H_

#include "roulette_sys.h"
#include "system/window.h"


//==============================================================================================
//
//	�����N�A�b�v�@�f�[�^
//
//==============================================================================================
//�r�b�g�}�b�vID
enum{
	RANK_BMPWIN_TALK = 0,
	RANK_BMPWIN_YESNO,
	ROULETTE_BMPWIN_MAX,			//BMP�E�B���h�E�̐�
};


//==============================================================================================
//
//	extern�錾
//
//==============================================================================================

//--------------------------------------------------------------
/**
 * @brief	�r�b�g�}�b�v�ǉ�
 *
 * @param	ini		BGL�f�[�^
 * @param	win		�r�b�g�}�b�v�E�B���h�E
 *
 * @return	none
 */
//--------------------------------------------------------------
extern void RouletteAddBmpWin( GF_BGL_INI* bgl, GF_BGL_BMPWIN* win );

//--------------------------------------------------------------
/**
 * @brief	�r�b�g�}�b�v�E�B���h�E�j��	
 *
 * @param	win		�r�b�g�}�b�v�E�B���h�E
 *
 * @return	none
 */
//--------------------------------------------------------------
extern void RouletteExitBmpWin( GF_BGL_BMPWIN* win );

//--------------------------------------------------------------
/**
 * @brief	�r�b�g�}�b�v�E�B���h�E�I�t
 *
 * @param	win		�r�b�g�}�b�v�E�B���h�E
 *
 * @return	none
 */
//--------------------------------------------------------------
extern void RouletteOffBmpWin( GF_BGL_BMPWIN* win );

//--------------------------------------------------------------
/**
 * @brief	���j���[�E�B���h�E�\��
 *
 * @param	ini		BGL�f�[�^
 * @param	win		�r�b�g�}�b�v�E�B���h�E
 *
 * @return	none
 */
//--------------------------------------------------------------
extern void RouletteWriteMenuWin( GF_BGL_INI* bgl, GF_BGL_BMPWIN* win );

//--------------------------------------------------------------------------------------------
/**
 * ��b�E�B���h�E�\��
 *
 * @param	win		BMP�f�[�^
 * @param	wintype	�E�B���h�E�^�C�v
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
extern void RouletteTalkWinPut( GF_BGL_BMPWIN * win, WINTYPE wintype );


#endif //_ROULETTE_BMP_H_

