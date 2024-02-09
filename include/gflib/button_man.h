//============================================================================================
/**
 * @file	button_man.h
 * @bfief	�{�^����ԊǗ��}�l�[�W��
 * @date	2005.11.08
 * @author	taya GAME FREAK inc.
 */
//============================================================================================
#ifndef __BUTTON_MAN_H__
#define __BUTTON_MAN_H__

#include "gflib/touchpanel.h"

//--------------------------------------------------------------
/**
 *  �{�^���C�x���g��ނ̒�`
 *
 *  �}�l�[�W���ɓo�^�����{�^���ɂ��āA�����̃C�x���g�����������
 *  �o�^�R�[���o�b�N�֐����Ăяo�����
 */
//--------------------------------------------------------------
enum {
	BMN_EVENT_TOUCH,		///< �G�ꂽ�u��
	BMN_EVENT_RELEASE,		///< �����ꂽ�u��
	BMN_EVENT_HOLD,			///< �G��Â��Ă���
	BMN_EVENT_SLIDEOUT,		///< ��ʃ^�b�`�����܂܃{�^���̈悩��O�ꂽ�u��
};


//--------------------------------------------------------------
/**
 * �R�[���o�b�N�֐��^��`�B
 * �������e�͈ȉ��̏��ł���B
 *
 * u32		�{�^��ID
 * u32		�C�x���g���
 * void*	�}�l�[�W���쐬���Ɉ����Ƃ��Đݒ肵���C�Ӄ|�C���^
 *
 */
//--------------------------------------------------------------
typedef		void (*pBmnCallBackFunc)(u32, u32, void*);


//--------------------------------------------------------------
/**
 * �{�^���Ǘ��}�l�[�W���̃��[�N�\���̐錾
 */
//--------------------------------------------------------------
typedef		struct _BUTTON_MAN		BUTTON_MAN;




//======================================================================================================
/**
 * �{�^���Ǘ��}�l�[�W���쐬
 *
 * @param   hit_tbl			[in]  �����蔻��e�[�u���ւ̃|�C���^
 * @param   btn_cnt			[in]  hit_tbl �̗v�f���i=���ꂪ�o�^����{�^���̐��Ƃ������Ɓj
 * @param   callback		[in]  �{�^���C�x���g�������ɌĂяo�����R�[���o�b�N�֐�
 * @param   callback_arg	[in]  callback �Ăяo�����Ɉ����Ƃ��ēn�����C�ӂ̃|�C���^
 * @param   heapID			[in]  �}�l�[�W���̈�쐬�p�q�[�vID
 *
 * @retval  BUTTON_MAN*		�}�l�[�W���|�C���^
 *
 *
 * btn_cnt �̐������A�����ł̓{�^���Ǘ��p���[�N�����������B
 * �R�[���o�b�N�ň����n�����{�^��ID�Ƃ����̂́A0 �` (btn_cnt-1�j�̐��l�ŁA
 * hit_tbl �̉����ڂɊY�����邩�������B
 *
 */
//======================================================================================================
extern BUTTON_MAN* BMN_Create( const TP_HIT_TBL *hit_tbl, u32 btn_cnt, pBmnCallBackFunc callback, void *callback_arg, u32 heapID );


//======================================================================================================
/**
 * �{�^���Ǘ��}�l�[�W�����C��
 *
 * �e�{�^����Ԃ̃`�F�b�N���X�V�A�C�x���g����������΃R�[���o�b�N�Ăяo�����s���B
 *
 * @param   bmn		�}�l�[�W���|�C���^
 */
//======================================================================================================
extern void BMN_Main( BUTTON_MAN *bmn );


//======================================================================================================
/**
 * �{�^���Ǘ��}�l�[�W������
 *
 * @param   bmn		�}�l�[�W���|�C���^
 */
//======================================================================================================
extern void BMN_Delete( BUTTON_MAN *bmn );


//======================================================================================================
/**
 * �{�^�����z�[���h��Ԃɂ��鎞�A���̃z�[���h���ԁi�t���[�����j��Ԃ�
 *
 * @param   bmn		�}�l�[�W�����[�N
 * @param   idx		�{�^���C���f�b�N�X
 *
 * @retval  u32		�z�[���h���Ȃ�z�[���h���ԁA�z�[���h���ȊO�Ȃ�O
 */
//======================================================================================================
extern u32 BMN_GetHoldFrameCount( BUTTON_MAN* bmn, u32 idx );


#endif