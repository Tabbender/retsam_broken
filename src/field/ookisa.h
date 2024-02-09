//============================================================================================
/**
 * @file	ookisa.h
 * @bfief	������������חp�֐�
 * @author	Tomomichi Ohta
 * @date	06.03.23
 */
//============================================================================================
#ifndef OOKISA_H
#define OOKISA_H

//�ŏ��̋L�^�̊�ƂȂ�̒l
#define OOKISA_KURABE_DEFAULT_RECORD	(0x8200)

//--------------------------------------------------------------------------------------------
/**
 *�@�����������ׂ�
 *
 * @param	fsys		FIELDSYS_WORK�\���̂ւ̃|�C���^
 * @param	num			�I�񂾎莝���ԍ�
 *
 * @return	"0:�X�V�����A1:�����A2=�L�^�X�V"
 */
//--------------------------------------------------------------------------------------------
extern u8 OokisaRecordChk( FIELDSYS_WORK* fsys,u16 num);

//--------------------------------------------------------------------------------------------
/**
 *�@���������̃��R�[�h(�̒l)���X�V
 *
 * @param	fsys		FIELDSYS_WORK�\���̂ւ̃|�C���^
 * @param	num			�I�񂾎莝���ԍ�
 *
 * @return	0
 */
//--------------------------------------------------------------------------------------------
extern void OokisaRecordSet(FIELDSYS_WORK* fsys,u16 num);

//--------------------------------------------------------------------------------------------
/**
 *�@���R�[�h�𐔎��ɕϊ����āA�����o�b�t�@�փZ�b�g
 *
 * @param	fsys		FIELDSYS_WORK�\���̂ւ̃|�C���^
 * @param	buf_no1		�����o�b�t�@�P
 * @param	buf_no2		�����o�b�t�@�Q
 * @param	monsno		�|�P�����i���o�[
 *
 * @return	0
 */
//--------------------------------------------------------------------------------------------
extern void OokisaRecordBufSet(FIELDSYS_WORK* fsys,u8 buf_no1,u8 buf_no2,u16 monsno);

//--------------------------------------------------------------------------------------------
/**
 *�@�莝���|�P���������𐔎��ɕϊ����āA�����o�b�t�@�փZ�b�g
 *
 * @param	fsys		FIELDSYS_WORK�\���̂ւ̃|�C���^
 * @param	buf_no1		�����o�b�t�@�P
 * @param	buf_no2		�����o�b�t�@�Q
 * @param	num			�莝���ԍ�
 *
 * @return	0
 */
//--------------------------------------------------------------------------------------------
extern void OokisaTemotiBufSet(FIELDSYS_WORK* fsys,u8 buf_no1,u8 buf_no2,u16 num);


//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

#endif	/* OOKISA_H */
