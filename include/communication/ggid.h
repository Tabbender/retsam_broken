#ifndef __GGID_H__
#define __GGID_H__

// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2007/01/10
// src/communication/wh.h, src/fushigi/beacondownload.h ��GGID��`�𕪗�
// # ���O�� _ �Ŏn�܂�܂܂Ȃ̂͋C�ɂȂ邯��ǁc�c
// ----------------------------------------------------------------------------

// �g�p���� GGID
#define _DP_GGID       (0x333)   // ���C����GGID

#define _MYSTERY_GGID  (0x333)

// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/10/31
// �C�O�Ń|�P���������W���[�ƒʐM�ł���悤��GGID��ύX�i5���ꋤ�ʁj
// localize_spec_mark(LANG_ALL) imatake 2006/12/14
// LANG_JAPAN �� LANG_JAPANESE �ɂȂ��Ă����̂��C���c�c
#if (PM_LANG == LANG_JAPAN)
#define	_RANGER_GGID   (0x00000178)
#else
#define	_RANGER_GGID   (0x00400131)
#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/10/31
// �C�O��PBR�ƒʐM�ł���悤��GGID��ύX
// ���p�ȊO�͖��肾���A����ȊO�ł��p��ł�GGID���Ƃ肠�����Ԃ�
// localize_spec_mark(LANG_ALL) imatake 2006/12/14
// LANG_JAPAN �� LANG_JAPANESE �ɂȂ��Ă����̂��C���c�c
#if (PM_LANG == LANG_JAPAN)
#define	_WII_GGID      (0x346)   //
#else
#define	_WII_GGID      (0x00400286)
#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2007/01/10
// �ӂ����Ȃ�������̃r�[�R����GGID���e����Ή�
#if (PM_LANG == LANG_JAPAN)
#define _BCON_DOWNLOAD_GGID (0x345)
#elif (PM_LANG == LANG_ENGLISH)
#define _BCON_DOWNLOAD_GGID (0x00400318)
#elif (PM_LANG == LANG_FRANCE)
#define _BCON_DOWNLOAD_GGID (0x008000CD)
#elif (PM_LANG == LANG_ITALY)
#define _BCON_DOWNLOAD_GGID (0x008000CF)
#elif (PM_LANG == LANG_GERMANY)
#define _BCON_DOWNLOAD_GGID (0x008000CE)
#elif (PM_LANG == LANG_SPAIN)
#define _BCON_DOWNLOAD_GGID (0x008000D0)
#endif
// ----------------------------------------------------------------------------

#endif
