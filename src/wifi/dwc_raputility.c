//=============================================================================
/**
 * @file	dwc_raputility.c
 * @bfief	DWC���b�p�[�B�o�g���I�[�o�[���C�Q�w�ɕ���  06.03.25
 * @author	kazuki yoshihara  -> k.ohno
 * @date	06/03/25
 */
//=============================================================================

#include "common.h"
#include "wifi/dwc_rap.h"
#include "communication/communication.h"

// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/11/10
// �|�P�����̌��ꂲ�Ƃ�Wi-Fi�ݒ��ʂ�؂芷��
#if (PM_LANG == LANG_JAPAN)
#define WIFI_SETTING_LANGUAGE	DWC_LANGUAGE_JAPANESE
#define WIFI_SETTING_UTILITY	DWC_UTILITY_TOP_MENU_FOR_JPN
#elif (PM_LANG == LANG_ENGLISH)
#define WIFI_SETTING_LANGUAGE	DWC_LANGUAGE_ENGLISH
//#define WIFI_SETTING_UTILITY	DWC_UTILITY_TOP_MENU_FOR_USA
#define WIFI_SETTING_UTILITY	DWC_UTILITY_TOP_MENU_COMMON
#elif (PM_LANG == LANG_FRANCE)
#define WIFI_SETTING_LANGUAGE	DWC_LANGUAGE_FRENCH
#define WIFI_SETTING_UTILITY	DWC_UTILITY_TOP_MENU_FOR_EUR
#elif (PM_LANG == LANG_GERMANY)
#define WIFI_SETTING_LANGUAGE	DWC_LANGUAGE_GERMAN
#define WIFI_SETTING_UTILITY	DWC_UTILITY_TOP_MENU_FOR_EUR
#elif (PM_LANG == LANG_ITALY)
#define WIFI_SETTING_LANGUAGE	DWC_LANGUAGE_ITALIAN
#define WIFI_SETTING_UTILITY	DWC_UTILITY_TOP_MENU_FOR_EUR
#elif (PM_LANG == LANG_SPAIN)
#define WIFI_SETTING_LANGUAGE	DWC_LANGUAGE_SPANISH
#define WIFI_SETTING_UTILITY	DWC_UTILITY_TOP_MENU_FOR_EUR
#endif
// ----------------------------------------------------------------------------

//==============================================================================
/**
 * WiFi�ڑ����[�e�B���e�B���Ăяo��
 * @param   none
 * @retval  none
 */
//==============================================================================
void mydwc_callUtility( int HeapID )
{
	OSIntrMode old;
	void *work;

	CommVRAMDInitialize(); // 
	// �A���[���V�X�e�������������Ă����Ȃ���DWC_StartUtility�ďo�����Panic����������
	OS_InitTick();
	OS_InitAlarm();


	// ���荞�ݏ�������U�֎~��
	old = OS_DisableInterrupts();

    DWC_SetAuthServer( GF_DWC_CONNECTINET_AUTH_TYPE );

	// WiFi�ݒ胁�j���[�Ăяo���i�I���܂ŋA���Ă��Ȃ�)
	work = sys_AllocMemory( HeapID, DWC_UTILITY_WORK_SIZE );
	// ----------------------------------------------------------------------------
	// localize_spec_mark(LANG_ALL) imatake 2006/11/10
	// �|�P�����̌��ꂲ�Ƃ�Wi-Fi�ݒ��ʂ�؂芷��
	(void)DWC_StartUtility( work, WIFI_SETTING_LANGUAGE, WIFI_SETTING_UTILITY );
	// ----------------------------------------------------------------------------
	sys_FreeMemoryEz( work );

	// �֎~�������荞�ݏ����𕜋A
	OS_RestoreInterrupts( old );

	//�}�X�^�[���荞�ݏ�����L����
	OS_EnableIrq( ); 


}