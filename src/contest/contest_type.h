//==============================================================================
/**
 * @file	contest_type.h
 * @brief	�R���e�X�g��������Ŏg�p����悤�Ȓ�`�Ȃ�
 * @author	matsuda
 * @date	2006.04.11(��)
 */
//==============================================================================
#ifndef __CONTEST_TYPE_H__
#define __CONTEST_TYPE_H__


//==============================================================================
//	�萔��`
//==============================================================================
///�ԕ��͗l�A�N�^�[�̐�
#define CON_FLOWER_MAX				(6)


//==============================================================================
//	�\���̒�`
//==============================================================================
//--------------------------------------------------------------
/**
 * �ԕ��͗l�A�N�^�[����\����
 */
//--------------------------------------------------------------
typedef struct{
	CATS_ACT_PTR cap[CON_FLOWER_MAX];			///<�ԕ��͗l�A�N�^�[�̃|�C���^
	TCB_PTR tcb;					///<�ԕ��͗l����^�X�N
}FLOWER_WORK;


#endif	//__CONTEST_TYPE_H__
