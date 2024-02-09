/*---------------------------------------------------------------------------*
  Project:  NitroSDK - MB - include
  File:     mb_fake_child.h

  Copyright 2003-2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: mb_fake_child.h,v $
  Revision 1.10  2007/04/18 04:01:40  yosizaki
  add MB_FakeSetCompareGGIDCallback.

  Revision 1.9  2007/02/20 00:28:10  kitase_hirotake
  indent source

  Revision 1.8  2006/11/16 10:42:15  takano_makoto
  MB_FakeSetVerboseScanCallback関数を追加

  Revision 1.7  2006/03/13 06:34:02  yosizaki
  add MB_FAKESCAN_PARENT_BEACON.

  Revision 1.6  2006/01/18 02:11:29  kitase_hirotake
  do-indent

  Revision 1.5  2005/12/01 09:15:37  takano_makoto
  MB_FAKE_WORK_SIZEを追加

  Revision 1.4  2005/03/01 01:57:00  yosizaki
  copyright の年を修正.

  Revision 1.3  2005/02/28 05:26:24  yosizaki
  do-indent.

  Revision 1.2  2004/11/24 23:44:44  takano_makoto
  MB_FakeReadParentBssDesc, MB_FakeEndを追加

  Revision 1.1  2004/11/22 12:57:34  takano_makoto
  Initial update.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/


#ifndef NITRO_MB_MB_FAKE_CHILD_H_
#define NITRO_MB_MB_FAKE_CHILD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <nitro/types.h>
#include <nitro/mb/mb.h>

// 
// MB_FakeInit()の引数として必要なワークバッファのサイズです。
#define     MB_FAKE_WORK_SIZE       (0x5f20)

enum
{
    MB_FAKESCAN_PARENT_FOUND,
    MB_FAKESCAN_PARENT_LOST,
    MB_FAKESCAN_API_ERROR,
    MB_FAKESCAN_END_SCAN,
    MB_FAKESCAN_PARENT_BEACON
};

/*
 * スキャン親機の通知コールバック
 */
typedef struct
{
    u16     index;                     // 取得した親機の管理用インデクス
    u16     padding;
    MBGameInfo *gameInfo;              // 親機ゲーム情報
    WMBssDesc *bssDesc;                // 親機接続情報
}
MBFakeScanCallback;

/*
 * エラー通知コールバック
 */
typedef struct
{
    u16     apiid;                     // APIコード
    u16     errcode;                   // エラーコード
}
MBFakeScanErrorCallback;

typedef void (*MBFakeScanCallbackFunc) (u16 type, void *arg);
typedef BOOL (*MBFakeCompareGGIDCallbackFunc) (WMStartScanCallback *arg, u32 defaultGGID);

void    MB_FakeInit(void *buf, const MBUserInfo *user);
void    MB_FakeEnd(void);
u32     MB_FakeGetWorkSize(void);
void    MB_FakeSetCStateCallback(MBCommCStateCallbackFunc callback);
void    MB_FakeStartScanParent(MBFakeScanCallbackFunc callback, u32 ggid);
void    MB_FakeEndScan(void);
BOOL    MB_FakeEntryToParent(u16 index);
BOOL    MB_FakeGetParentGameInfo(u16 index, MBGameInfo *pGameInfo);
BOOL    MB_FakeGetParentBssDesc(u16 index, WMBssDesc *pBssDesc);
BOOL    MB_FakeReadParentBssDesc(u16 index, WMBssDesc *pBssDesc, u16 parent_max_size,
                                 u16 child_max_size, BOOL ks_flag, BOOL cs_flag);
void    MB_FakeSetVerboseScanCallback(WMCallbackFunc callback);
void    MB_FakeSetCompareGGIDCallback(MBFakeCompareGGIDCallbackFunc callback);


#ifdef __cplusplus
}
#endif


#endif // NITRO_MB_MB_FAKE_CHILD_H_
