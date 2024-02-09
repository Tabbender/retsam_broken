//============================================================================================
/**
 * @file	vm.h
 * @brief	仮想インタープリタマシン　メイン部分(スクリプトコマンド実行に使用される)
 * @author	Sousuke Tamada
 * @date	01.11.07
 *
 * 03.04.15	Satoshi Nohara
 * 05.04.25 Hiroyuki Nakamura
 *
 * エメラルドのファイルがベース ( R/S -> FR/LG -> EME -> D/P )
 */
//============================================================================================
#ifndef __VM_H
#define __VM_H

#undef GLOBAL
#ifdef __VM_H_GLOBAL
#define GLOBAL /*	*/
#else
#define GLOBAL extern
#endif


//#define OLD_MSG_SYS				//メッセージシステム(script.c,scrcmd.c,vm.h)

#include "field_common.h"			//FIELDSYS_WORK

#ifndef OLD_MSG_SYS
#include "system/msgdata.h"			//MSGDATA_MANAGER
#endif

//============================================================================================
//	定義
//============================================================================================
typedef	u8	VM_CODE;				// スクリプト、イベントデータの型宣言

//-------------------------------------------------------------------------
// 仮想マシン構造体宣言
//-------------------------------------------------------------------------

#define VM_STACK_MAX	( 20 )	// 仮想マシンのスタックの深さ
#define	VM_REG_MAX		( 4 )	// 仮想マシンのレジスタの数
//#define	VM_WORK_MAX		( 16 )	// 仮想マシンのワークの数

typedef struct VM_MACHINE_ST VM_MACHINE;
typedef BOOL ( * VM_CMD)(VM_MACHINE *);
typedef BOOL (*VM_WAIT_FUNC)(VM_MACHINE *);

struct VM_MACHINE_ST{
	u8	SP;									// スタックポインタ
	u8	status;								// 動作状態
	u8	cmp_flag;							// 計算結果フラグ
	VM_WAIT_FUNC routine;					// ウェイト関数
	const VM_CODE * PC;						// 現在のスクリプトアドレス
	const VM_CODE * array[VM_STACK_MAX];	// スタック
	const VM_CMD * command_table;			// スクリプトコマンドテーブル開始位置
	u32 cmd_max;							// コマンド上限値
	u32 reg[VM_REG_MAX];					// 汎用レジスタ
	void * event_work;						// コマンドなどで参照するワークのポインタ

#ifdef OLD_MSG_SYS
	u16 * pMsg;								// ロードしたメッセージ
#else
	MSGDATA_MANAGER* msgman;				// メッセージマネージャー
#endif
	VM_CODE * pScript;						// ロードしたスクリプト

	FIELDSYS_WORK* fsys;					//

	//script.c EV_SCRIPT_WORKへ移動
	//u16 scr_work[VM_WORK_MAX];			// ワーク(ANSWORK,TMPWORKなどの代わり)
	//
	//↓のように使えた
	//core->scr_work[SCRIPT_WK_ANSWER] = 0;
	//
	//TMPWORKに値をセットして、
	//共通スクリプトに渡したい時があるので、
	//VMごとにワークを持たないようにした(050901)
};

// u8サイズのデータを取得するためのマクロ
#define VMGetU8(core)	(*((core)->PC++))


//============================================================================================
//	グローバル変数
//============================================================================================

//============================================================================================
//	関数プロトタイプ
//============================================================================================

//********************************************************************************************
//	仮想マシン制御用
//********************************************************************************************

//--------------------------------------------------------------------------------------------
/**
 * 仮想マシン初期化
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 * @param	cmd_tbl		命令テーブル開始アドレス
 * @param	cmd_max		命令テーブルの大きさ
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
extern void VM_Init( VM_MACHINE * core, const VM_CMD * cmd_tbl, u32 cmd_max);

//--------------------------------------------------------------------------------------------
/**
 * 仮想マシンにコードを設定
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 * @param	start		実行コードの開始アドレス
 *
 * @return	常にTRUE
 */
//--------------------------------------------------------------------------------------------
GLOBAL u8 VM_Start( VM_MACHINE * core, const VM_CODE * start );

//--------------------------------------------------------------------------------------------
/**
 * 仮想マシンをウェイト状態に設定
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 * @param	func		ウェイト関数
 *
 * @return	none
 *
 * @li	TRUEが返ってくるまでウェイト関数を毎回呼びだす
 */
//--------------------------------------------------------------------------------------------
GLOBAL void VM_SetWait( VM_MACHINE * core, VM_WAIT_FUNC func );

//--------------------------------------------------------------------------------------------
/**
 * 仮想マシン実行終了
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
GLOBAL void VM_End( VM_MACHINE * core );

//--------------------------------------------------------------------------------------------
/**
 * コマンドなどで参照するワークをセット
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 * @param	work		ワークのポインタ
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
GLOBAL void VM_SetWork( VM_MACHINE * core, void * work );

//--------------------------------------------------------------------------------------------
/**
 * 仮想マシン制御メイン
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 *
 * @retval	"TRUE = 実行中"
 * @retval	"FALSE = 停止中・実行終了"
 */
//--------------------------------------------------------------------------------------------
GLOBAL u8 VM_Control( VM_MACHINE * core );


//********************************************************************************************
//	スタック操作
//********************************************************************************************

//--------------------------------------------------------------------------------------------
/**
 * 仮想マシンスタックプッシュ
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 * @param	val
 *
 * @retval	"0 = 正常"
 * @retval	"1 = エラー"
 */
//--------------------------------------------------------------------------------------------
GLOBAL u8 VMStackPush( VM_MACHINE * core, const VM_CODE * val );

//--------------------------------------------------------------------------------------------
/**
 * 仮想マシンスタックポップ
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 *
 * @return
 */
//--------------------------------------------------------------------------------------------
GLOBAL const VM_CODE * VMStackPop( VM_MACHINE * core );


//********************************************************************************************
//	分岐命令
//********************************************************************************************

//--------------------------------------------------------------------------------------------
/**
 * 仮想マシンジャンプ命令
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 * @param	adrs		ジャンプ先アドレス
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
GLOBAL void VMJump( VM_MACHINE * core, VM_CODE * adrs );

//--------------------------------------------------------------------------------------------
/**
 * 仮想マシンコール命令
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 * @param	adrs		呼び出すアドレス
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
GLOBAL void VMCall( VM_MACHINE * core, VM_CODE * adrs );

//--------------------------------------------------------------------------------------------
/**
 * 仮想マシンリターン命令
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 *
 * @return	none
 */
//--------------------------------------------------------------------------------------------
GLOBAL void VMRet( VM_MACHINE * core );


//********************************************************************************************
//	データ取得		VMGetU8 はマクロ定義
//********************************************************************************************

//--------------------------------------------------------------------------------------------
/**
 * PCのアドレスから16bit(2byte)データ取得
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 *
 * @return	取得データ
 */
//--------------------------------------------------------------------------------------------
GLOBAL u16 VMGetU16( VM_MACHINE * core );

//--------------------------------------------------------------------------------------------
/**
 * PCのアドレスから32bit(4byte)データ取得
 *
 * @param	core		仮想マシン制御構造体へのポインタ
 *
 * @return	取得データ
 */
//--------------------------------------------------------------------------------------------
GLOBAL u32 VMGetU32( VM_MACHINE * core );


#undef GLOBAL
#endif	/* __VM_H */
