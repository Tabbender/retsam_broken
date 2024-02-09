//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
/**
 *
 *	@file		wifi_p2pmatchroom_map.dat
 *	@brief		wifi	�}�b�`���O���[��	�}�b�v�f�[�^
 *	@author		tomoya takahashi
 *	@data		2007.03.30
 *
 */
//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

#define __WIFI_P2PMATCHROOM_MAP_H_GLOBAL
#include "wifi_p2pmatchroom_map.h"

//-----------------------------------------------------------------------------
/**
 *					�R�[�f�B���O�K��
 *		���֐���
 *				�P�����ڂ͑啶������ȍ~�͏������ɂ���
 *		���ϐ���
 *				�E�ϐ�����
 *						const�ɂ� c_ ��t����
 *						static�ɂ� s_ ��t����
 *						�|�C���^�ɂ� p_ ��t����
 *						�S�č��킳��� csp_ �ƂȂ�
 *				�E�O���[�o���ϐ�
 *						�P�����ڂ͑啶��
 *				�E�֐����ϐ�
 *						�������Ɓh�Q�h�Ɛ������g�p���� �֐��̈���������Ɠ���
*/
//-----------------------------------------------------------------------------

#define MCR_MAP_NUM	(4)

// �}�b�v�O���b�h��
#define MCR_MAP00_GRID_X	(16)
#define MCR_MAP00_GRID_Y	(11)
#define MCR_MAP00_ARRYNUM	( MCR_MAP00_GRID_X*MCR_MAP00_GRID_Y )

#define MCR_MAP01_GRID_X	(16)
#define MCR_MAP01_GRID_Y	(11)
#define MCR_MAP01_ARRYNUM	( MCR_MAP01_GRID_X*MCR_MAP01_GRID_Y )

#define MCR_MAP02_GRID_X	(22)
#define MCR_MAP02_GRID_Y	(11)
#define MCR_MAP02_ARRYNUM	( MCR_MAP02_GRID_X*MCR_MAP02_GRID_Y )

#define MCR_MAP03_GRID_X	(28)
#define MCR_MAP03_GRID_Y	(11)
#define MCR_MAP03_ARRYNUM	( MCR_MAP03_GRID_X*MCR_MAP03_GRID_Y )


//-----------------------------------------------------------------------------
/**
 *		�}�b�v�f�[�^
 */
//-----------------------------------------------------------------------------

// �}�b�v�f�[�^
static const WF2DMAP_MAP McrMap00Data[MCR_MAP00_ARRYNUM] = {
	// 1�s
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, 
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 2�s
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, 
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_PC,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 3�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, WCR_MAPDATA_OBJ00, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, WCR_MAPDATA_OBJ04, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 4�s
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK,
	// 5�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, WCR_MAPDATA_OBJ01, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, WCR_MAPDATA_OBJ05, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 6�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 7�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, WCR_MAPDATA_OBJ02, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, WCR_MAPDATA_OBJ06, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 8�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 9�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, WCR_MAPDATA_OBJ03, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, WCR_MAPDATA_OBJ07, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 10�s
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK,
	// 11�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_EXIT,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
};

static const WF2DMAP_MAP McrMap01Data[MCR_MAP01_ARRYNUM] = {
	// 1�s
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, 
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 2�s
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, 
	WCR_MAPDATA_PC, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_PC, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 3�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ00, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ04, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ00, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ04, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 4�s
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, 
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, 
	WCR_MAPDATA_MAP01, MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK,
	// 5�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ01, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ05, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ01, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ05, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 6�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, 
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, 
	WCR_MAPDATA_MAP01, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 7�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ02, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ06, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ02, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ06, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 8�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, 
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, 
	WCR_MAPDATA_MAP01, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 9�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ03, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ07, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ03, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ07, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 10�s
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, 
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, 
	WCR_MAPDATA_MAP01, MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK,
	// 11�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_EXIT,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
};

static const WF2DMAP_MAP McrMap02Data[MCR_MAP02_ARRYNUM] = {
	// 1�s
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, 
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 2�s
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, 
	WCR_MAPDATA_PC, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_PC, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_PC, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 3�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ00, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ04, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ00, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ04, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ00, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ04, MCR_MAPPM_NONE,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 4�s
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, 
	WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK,
	// 5�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ01, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ05, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ01, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ05, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ01, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ05, MCR_MAPPM_NONE,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 6�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, 
	WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, MCR_MAPPM_NONE,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 7�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ02, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ06, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ02, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ06, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ02, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ06, MCR_MAPPM_NONE,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 8�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, 
	WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, MCR_MAPPM_NONE,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 9�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ03, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ07, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ03, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ07, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ03, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ07, MCR_MAPPM_NONE,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 10�s
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, 
	WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK,
	// 11�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_EXIT, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
};

static const WF2DMAP_MAP McrMap03Data[MCR_MAP03_ARRYNUM] = {
	// 1�s
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, 
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 2�s
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, 
	WCR_MAPDATA_PC, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_PC, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_PC, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_PC, WCR_MAPDATA_BLOCK,
	WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 3�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ00, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ04, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ00, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ04, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ00, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ04, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ00, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ04, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 4�s
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, 
	WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03,
	WCR_MAPDATA_MAP03, MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK,
	// 5�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ01, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ05, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ01, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ05, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ01, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ05, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ01, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ05, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 6�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, 
	WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03,
	WCR_MAPDATA_MAP03, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 7�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ02, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ06, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ02, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ06, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ02, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ06, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ02, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ06, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 8�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, 
	WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03,
	WCR_MAPDATA_MAP03, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 9�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ03, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ07, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ03, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ07, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ03, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_OBJ07, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ03, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	WCR_MAPDATA_OBJ07, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
	// 10�s
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, 
	WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, WCR_MAPDATA_MAP02, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00, WCR_MAPDATA_MAP00,
	WCR_MAPDATA_MAP00, MCR_MAPPM_NONE, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01,
	WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, WCR_MAPDATA_MAP01, MCR_MAPPM_NONE,
	WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03, WCR_MAPDATA_MAP03,
	WCR_MAPDATA_MAP03, MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK,
	// 11�s
	WCR_MAPDATA_BLOCK, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, 
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, WCR_MAPDATA_EXIT, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE, MCR_MAPPM_NONE,
	MCR_MAPPM_NONE, MCR_MAPPM_NONE, WCR_MAPDATA_BLOCK, WCR_MAPDATA_BLOCK,
};




//----------------------------------------------------------------------------
/**
 *	@brief	�}�b�v�̃O���b�h�T�C�Y���擾����
 *
 *	@param	no		�}�b�v�i���o�[
 *
 *	@return	�O���b�h�T�C�Y
 */
//-----------------------------------------------------------------------------
WF2DMAP_POS WcrMapGridSizGet( u32 no )
{
	static const WF2DMAP_POS WcrMapSiz[ MCR_MAP_NUM ] = {
		{ MCR_MAP00_GRID_X, MCR_MAP00_GRID_Y },
		{ MCR_MAP01_GRID_X, MCR_MAP01_GRID_Y },
		{ MCR_MAP02_GRID_X, MCR_MAP02_GRID_Y },
		{ MCR_MAP03_GRID_X, MCR_MAP03_GRID_Y },
	};
	return WcrMapSiz[no];
}

//----------------------------------------------------------------------------
/**
 *	@brief	�}�b�v�̃f�[�^���擾
 *
 *	@param	no		�}�b�v�i���o�[
 *
 *	@return	�}�b�v�f�[�^�擾
 */
//-----------------------------------------------------------------------------
const WF2DMAP_MAP* WcrMapDataGet( u32 no )
{
	static const WF2DMAP_MAP* pWcrMapData[ MCR_MAP_NUM ] = {
		McrMap00Data,
		McrMap01Data,
		McrMap02Data,
		McrMap03Data,
	};

	return pWcrMapData[ no ];
}