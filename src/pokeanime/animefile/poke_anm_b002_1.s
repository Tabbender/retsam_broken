//==============================================================================
/**
 * @file	poke_anm_b_002_1.s
 * @brief	�|�P�����A�j�� ���h��
 * @author	saito
 * @date	
 *
 */
//==============================================================================

	.text
	
	.include	"past.h"
	.include	"past_def.h"
	
	.global		PAST_ANIME_B_002_1
	
// =============================================================================
//
//
//	�w��	���h��N�C�b�N
//
//
// =============================================================================
PAST_ANIME_B002_1:
	//10��̃��[�v��1.5���i0x18000�j��������
	CALL_MF_CURVE_DIVTIME	APPLY_SET,0,CURVE_SIN,TARGET_DX,6,0x18000,0,10
	HOLD_CMD
	END_ANM