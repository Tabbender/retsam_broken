//==============================================================================
/**
 * @file	poke_anm_b007_3.s
 * @brief	�c���Ɉ�������
 * @author	
 * @date	
 *
 */
//==============================================================================

	.text
	
	.include	"past.h"
	.include	"past_def.h"
	
	.global		PAST_ANIME_B007_3
	
// =============================================================================
//
//
//	�w��	�c���Ɉ�������
//
//
// =============================================================================
PAST_ANIME_B007_3:
	//20��̃��[�v��180���i0x8000�j����
	CALL_MF_CURVE_DIVTIME APPLY_SET,0,CURVE_SIN,TARGET_RY,0x28,0x8000,0,20
	CALL_MF_CURVE_DIVTIME APPLY_SET,0,CURVE_SIN,TARGET_RX,0x28,0x8000,0,20
	//�E�F�C�g5�@10��̃��[�v��4��0x40000�j������
	CALL_MF_CURVE_DIVTIME APPLY_SYNTHE,5,CURVE_SIN,TARGET_RY,0x8,0x40000,0,10
	CALL_MF_CURVE_DIVTIME APPLY_SYNTHE,5,CURVE_SIN,TARGET_RX,0x8,0x40000,0,10
	HOLD_CMD
	
	END_ANM