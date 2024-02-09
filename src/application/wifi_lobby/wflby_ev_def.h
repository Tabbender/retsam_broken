//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
/**
 *	GAME FREAK inc.
 *
 *	@file		wflby_ev_def.h
 *	@brief		常駐イベント		各キャラクタの常駐イベント
 *	@author		tomoya takahashi
 *	@data		2007.11.26
 *
 */
//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
#ifndef __WFLBY_EV_DEF_H__
#define __WFLBY_EV_DEF_H__

#include "wflby_room_def.h"

//-----------------------------------------------------------------------------
/**
 *					定数宣言
*/
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/**
 *					構造体宣言
*/
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/**
 *					プロトタイプ宣言
*/
//-----------------------------------------------------------------------------
// プレイヤー常駐イベント開始
extern void WFLBY_EV_DEF_StartPlayer( WFLBY_ROOMWK* p_rmwk );

// NPC常駐イベント開始
extern void WFLBY_EV_DEF_StartNpc( WFLBY_ROOMWK* p_rmwk );

#endif		// __WFLBY_EV_DEF_H__

