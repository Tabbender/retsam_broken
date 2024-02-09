//==============================================================================
/**
 * @file	west_sp.h
 * @brief	サポート関数用ヘッダ
 * @author	goto
 * @date	2005.07.14(木)
 *
 * ここに色々な解説等を書いてもよい
 *
 */
//==============================================================================

#ifndef	_WEST_SP_H_
#define _WEST_SP_H_

#include "wazaeffect/we_mana.h"
#include "we_sys.h"

#if 0

	■ 注意 ■
	
	*.s で扱うためのdefine登録は、[ west_sp_def.h ] 内に記述してください。
	実際に呼び出す関数は、[ west_sp.c ] のテーブル内に記述してください。
	
	サポート用の関数は、多くの人が操作する可能性があるので
	west_sp.c 内にコーディングせず、ユーザー個人で用意したファイルを
	includeするようにしてください	

#endif


// ----------------------------------------
//
//	サポート関数呼び出し関数
//
// -----------------------------------------
extern pWeFunc WazaEffectSupportFuncGet(u32 id);


// -----------------------------------------
//
//	セルアクター用 サポート関数呼び出し
//
// -----------------------------------------
extern pWeClactFunc WazaEffectSupportFuncGet_CATS(u32 id);


// -----------------------------------------
//
//	OLDACT用 サポート関数呼び出し
//
// -----------------------------------------
extern pWeOldActFunc WazaEffectSupportFuncGet_OLDACT(u32 id);

#endif	