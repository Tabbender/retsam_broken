//============================================================================================
/**
 * @file	board.h
 * @brief	�Ŕ���
 * @author	Hiroyuki Nakamura
 * @date	2005.10.25
 */
//============================================================================================
#ifndef BOARD_H
#define BOARD_H
#undef GLOBAL
#ifdef BOARD_H_GLOBAL
#define GLOBAL	/*	*/
#else
#define GLOBAL	extern
#endif


//============================================================================================
//	�萔��`
//============================================================================================
#define	BOARD_REQ_WAIT	( 0 )	///< �Ŕ��N�G�X�g�F�ҋ@
#define	BOARD_REQ_ADD	( 1 )	///< �Ŕ��N�G�X�g�F�ŔE�B���h�E�쐬
#define	BOARD_REQ_DOWN	( 2 )	///< �Ŕ��N�G�X�g�F�ŔE�B���h�E��������
#define	BOARD_REQ_UP	( 3 )	///< �Ŕ��N�G�X�g�F�ŔE�B���h�E���グ��
#define	BOARD_REQ_DEL	( 4 )	///< �Ŕ��N�G�X�g�F�ŔE�B���h�E�j��


#ifndef	__ASM_NO_DEF_	// ������ȍ~�́A�A�Z���u���ł͖���

typedef	struct _BOARD_WORK BOARD_WORK;


//============================================================================================
//	�v���g�^�C�v�錾
//============================================================================================

//--------------------------------------------------------------------------------------------
/**
 * �Ŕ��[�N�m��
 *
 * @param	heap	�q�[�vID
 *
 * @return	�m�ۂ������[�N
 */
//--------------------------------------------------------------------------------------------
GLOBAL void * BoardWorkAlloc( u32 heap );

//--------------------------------------------------------------------------------------------
/**
 * �Ŕ��[�N���
 *
 * @param	wk		���[�N
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
GLOBAL void BoardWorkDelete( BOARD_WORK * wk );

//--------------------------------------------------------------------------------------------
/**
 * �Ŕf�[�^�Z�b�g
 *
 * @param	wk		���[�N
 * @param	type	�Ŕ^�C�v
 * @param	map		�}�b�vID�i�O���t�B�b�NID�j
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
GLOBAL void BoardDataSet( BOARD_WORK * wk, u16 type, u16 map );

//--------------------------------------------------------------------------------------------
/**
 * �Ŕ��N�G�X�g���s
 *
 * @param	wk		���[�N
 * @param	req		���N�G�X�g
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
GLOBAL void BoardSetRequest( BOARD_WORK * wk, u8 req );

//--------------------------------------------------------------------------------------------
/**
 * �f�[�^�擾�FBMP�E�B���h�E�f�[�^
 *
 * @param	wk		���[�N
 *
 * @return	BMP�E�B���h�E�f�[�^
 */
//--------------------------------------------------------------------------------------------
GLOBAL GF_BGL_BMPWIN * BoardWinGet( BOARD_WORK * wk );

//--------------------------------------------------------------------------------------------
/**
 * �f�[�^�擾�F�Ŕ^�C�v
 *
 * @param	wk		���[�N
 *
 * @return	�Ŕ^�C�v
 */
//--------------------------------------------------------------------------------------------
GLOBAL u8 BoardTypeGet( BOARD_WORK * wk );

//--------------------------------------------------------------------------------------------
/**
 * �Ŕ����I���`�F�b�N
 *
 * @param	wk		���[�N
 *
 * @retval	"TRUE = �I��"
 * @retval	"FALSE = ���쒆"
 */
//--------------------------------------------------------------------------------------------
GLOBAL BOOL BoardReqEndCheck( BOARD_WORK * wk );

//--------------------------------------------------------------------------------------------
/**
 * �Ŕ��C������
 *
 * @param	repw	�t�B�[���h���[�N
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
GLOBAL void BoardMain( FIELDSYS_WORK * repw );

//--------------------------------------------------------------------------------------------
/**
 * ���N�G�X�g�𑦎��s
 *
 * @param	repw	�t�B�[���h���[�N
 * @param	req		���N�G�X�g
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
GLOBAL void BoardSetDirect( FIELDSYS_WORK * repw, u8 req );


#endif	__ASM_NO_DEF_

#undef GLOBAL
#endif	/* BOARD_H */