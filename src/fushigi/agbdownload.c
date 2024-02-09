//===================================================================
/**
 * @file	agbdownload.c
 * @bfief	AGB�J�Z�b�g����̂ӂ����f�[�^�_�E�����[�h
 * @author	Satoshi Mitsuhara
 * @date	06.06.09
 *
 * <pre>
 * �`�f�a�J�Z�b�g���̃������}�b�v
 *	0x08000000	�v���O�����{�f�[�^
 *	     |
 *	0x08100000	�]���f�[�^�̃T�C�Y(�S�o�C�g)
 *	0x08100010	�r�[�R�����
 *	0x08100100	�ӂ����Ȃ�������̃f�[�^�J�n
 *	     |
 *	0x081xxxxx	�I��
 * </pre>
 *
 * $Id: agbdownload.c,v 1.3 2006/07/15 08:47:20 mitsuhara Exp $
 */
//===================================================================

#include "agbdownload.h"
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2007/01/15
// �d�q�����F�؂ɑΉ�
#include "common.h"
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2007/01/18
// NitroCrypto ���C�u���������[�J���ɒu�������̂ɒu������
#include "nitrocrypto/crypto.h"
#include "nitrocrypto/crypto/sign.h"
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// �A�N�Z�X�\�J�[�g���b�W�̃Q�[���R�[�h
static u32 AgbCartridgeTable[] = {
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2007/01/10
// �ӂ����Ȃ��������AGB�J�[�g���b�W�̃C�j�V�����R�[�h���e����Ή���
#if (PM_LANG == LANG_JAPAN)
  'B5BJ', 'B5CJ', 'B5DJ', 'B5EJ', 'B5FJ',
  'B5GJ', 'B5HJ', 'B5IJ', 'B5JJ', 'B5KJ',
  'B5LJ', 'B5MJ', 'B5PJ', 'B5QJ', 'B5RJ',
  'B5SJ', 'B5TJ', 'B5UJ', 'B5VJ', 'B5WJ',
#elif (PM_LANG == LANG_ENGLISH)
  'B5BE', 'B5CE', 'B5DE', 'B5EE', 'B5FE',
  'B5GE', 'B5HE', 'B5IE', 'B5JE', 'B5KE',
  'B5LE', 'B5ME', 'B5PE', 'B5QE', 'B5RE',
  'B5SE', 'B5TE', 'B5UE', 'B5VE', 'B5WE',
#elif (PM_LANG == LANG_FRANCE)
  'B5BF', 'B5CF', 'B5D0', 'B5EF', 'B5FF',
  'B5GF', 'B5HF', 'B5IF', 'B5JF', 'B5KF',
  'B5LF', 'B5MF', 'B5PF', 'B5QF', 'B5RF',
  'B5SF', 'B5TF', 'B5UF', 'B5VF', 'B5WF',
#elif (PM_LANG == LANG_ITALY)
  'B5BI', 'B5CI', 'B5DI', 'B5EI', 'B5FI',
  'B5GI', 'B5HI', 'B5II', 'B5JI', 'B5KI',
  'B5LI', 'B5MI', 'B5PI', 'B5QI', 'B5RI',
  'B5SI', 'B5TI', 'B5UI', 'B5VI', 'B5WI',
#elif (PM_LANG == LANG_GERMANY)
  'B5BG', 'B5CG', 'B5DG', 'B5EG', 'B5FG',
  'B5GG', 'B5HG', 'B5IG', 'B5JG', 'B5KG',
  'B5LG', 'B5MG', 'B5PG', 'B5QG', 'B5RG',
  'B5SG', 'B5TG', 'B5UG', 'B5VG', 'B5WG',
#elif (PM_LANG == LANG_SPAIN)
  'B5BS', 'B5CS', 'B5DS', 'B5ES', 'B5FS',
  'B5GS', 'B5HS', 'B5IS', 'B5JS', 'B5KS',
  'B5LS', 'B5MS', 'B5PS', 'B5QS', 'B5RS',
  'B5SS', 'B5TS', 'B5US', 'B5VS', 'B5WS',
#endif
// ----------------------------------------------------------------------------
  0,
};

// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2007/01/15
// �d�q�����F�؂ɑΉ�

static const u8 PublicKey[] = {
	0xc8,0x7e,0x66,0x71,0x46,0x0b,0xe6,0x6f,0x17,0x8a,0x5c,0x7d,0xea,0xe1,0x93,0xfd,
	0xee,0xfa,0x99,0x84,0xfe,0x35,0x02,0xb9,0x7f,0x4f,0xf1,0x19,0x74,0xa2,0x0f,0x65,
	0x8a,0x9c,0x44,0x81,0x0c,0x1f,0x94,0xe4,0xc0,0xb6,0xd7,0x20,0xee,0x11,0x9a,0x8d,
	0x27,0x33,0x9b,0x7b,0x02,0xe9,0x33,0x11,0xdc,0xcf,0x72,0xd9,0xa8,0x78,0x12,0x8c,
	0x3b,0x60,0xd5,0x24,0xb8,0xd9,0xfc,0x8d,0x15,0xba,0x0b,0x90,0xa3,0xbd,0x3a,0xe4,
	0x01,0x18,0xba,0xf9,0x65,0xa5,0x15,0x37,0xdc,0x7a,0x48,0x5c,0x3a,0x55,0x35,0x43,
	0xe2,0xc6,0x66,0xba,0x21,0xea,0x67,0x2e,0xa8,0x29,0x03,0xd7,0x1f,0x0f,0xc6,0xde,
	0x1b,0xe2,0xa1,0xca,0x21,0x51,0xfe,0xb9,0x68,0x17,0x3c,0xeb,0x04,0x54,0xe0,0xbd
};

static u32 _heapID;

void SetAgbCartridgeHeapID(u32 heapID) {
	_heapID = heapID;
}

extern void *alloc(u32 size);

void *alloc(u32 size) {
	return sys_AllocMemory(_heapID, size);
}

// ----------------------------------------------------------------------------


//------------------------------------------------------------------
/**
 * @brief	�ӂ����f�[�^���܂ރJ�Z�b�g����������
 * @param	NONE
 * @return	TRUE: �ӂ����J�Z�b�g   FALSE: �Ȃ�
 */
//------------------------------------------------------------------
static BOOL CheckAgbCartridgeInitialCode(void)
{
  int i;
  u32 init_code = CTRDG_GetAgbGameCode();
  // AgbCartridgeTable��u32�Ƃ��Ĉ����Ă��ă��g���G���f�B�A���ɂȂ��Ă��܂�����
  // ���̂��܂��킹��init_code���Ђ�����Ԃ�
  init_code = (((init_code >>  0) & 255) << 24 |
	       ((init_code >>  8) & 255) << 16 |
	       ((init_code >> 16) & 255) <<  8 |
	       ((init_code >> 24) & 255) <<  0);

  for(i = 0; i < AgbCartridgeTable[i]; i++){
    if(AgbCartridgeTable[i] == init_code){
      // MatchComment: ignore this localization change
	  // ----------------------------------------------------------------------------
	  // localize_spec_mark(LANG_ALL) imatake 2007/01/15
	  // �d�q�����F�؂ɑΉ�
      
	  u8 signed_data[AGB_SIGNEDDATA_SIZE];
	  u8 signature[AGB_SIGNATURE_SIZE];
      
	  CTRDG_Enable(TRUE);
	  CTRDG_CpuCopy8(AGB_SIGNEDDATA_PTR, signed_data, AGB_SIGNEDDATA_SIZE);
	  CTRDG_CpuCopy8(AGB_SIGNATURE_PTR,  signature,   AGB_SIGNATURE_SIZE);
	  CTRDG_Enable(FALSE);
      
	  CRYPTO_SetAllocator(alloc, sys_FreeMemoryEz);
	  if (CRYPTO_VerifySignature(signed_data, AGB_SIGNEDDATA_SIZE, signature, PublicKey)) {
	    OS_TPrintf("�ӂ����Ȃ�������̂̏����F�؂ɐ������܂����B\n");
	    return TRUE;
	  } else {
	    OS_TPrintf("�ӂ����Ȃ�������̂̏����F�؂Ɏ��s���܂����B\n");
	  }
      
	  // ----------------------------------------------------------------------------
    }
  }
  return FALSE;
}


//------------------------------------------------------------------
/**
 * @brief	�`�f�a�J�Z�b�g�̃A�N�Z�X�����������Ă��邩����
 * @param	NONE
 * @return	TRUE: �A�N�Z�X�\   FALSE: �Ȃ�
 */
//------------------------------------------------------------------
static BOOL IsExistAgbCartridge(void)
{
  // �`�f�a�J�[�g���b�W������(OS_Init�ŏ�������Ă���͂��H)
  CTRDG_Init();
  // �`�f�a�J�[�g���b�W�����݂��Ȃ����FALSE
  if(CTRDG_IsAgbCartridge() == FALSE)
    return FALSE;
  // �C�V���ȊO�̃J�Z�b�g�Ȃ��FALSE
  if(CTRDG_GetAgbMakerCode() != AGB_MAKER_CODE)
    return FALSE;
  // �w�肳�ꂽ�C�j�V�����R�[�h�ȊO��FALSE
  if(CheckAgbCartridgeInitialCode() == FALSE)
    return FALSE;
  return TRUE;
}


//------------------------------------------------------------------
/**
 * @brief	�`�f�a�J�[�g���b�W���ɂ���f�[�^�̃T�C�Y��Ԃ�
 * @param	NONE
 * @return	�T�C�Y(0�Ȃ�΃J�[�g���b�W���h�����Ă��Ȃ�
 */
//------------------------------------------------------------------
int GetAgbCartridgeDataSize(void)
{
  u32 size;

  // �J�Z�b�g�̏������`�F�b�N
  if(IsExistAgbCartridge() == FALSE)
    return 0;

  CTRDG_Enable(TRUE);
  CTRDG_Read32((const u32 *)AGBMISSIONDATASIZE, &size);
  CTRDG_Enable(FALSE);
  
  return size;
}


//------------------------------------------------------------------
/**
 * @brief	�`�f�a�J�[�g���b�W���ɂ���r�[�R���f�[�^���R�s�[
 * @param	NONE
 * @return	TRUE: �R�s�[����  : FALSE: ���s
 */
//------------------------------------------------------------------
BOOL GetAgbCartridgeBeaconData(void *dist, int size)
{
  BOOL flag;

  // �J�Z�b�g�̏������`�F�b�N
  if(IsExistAgbCartridge() == FALSE)
    return FALSE;

  // �Q�[���f�[�^���w��̈�ɃR�s�[����
  if(size == 0)
    return FALSE;

  CTRDG_Enable(TRUE);
  flag = (BOOL)CTRDG_CpuCopy16((const void *)AGBBEACONDATAPTR, dist, size);
  CTRDG_Enable(FALSE);

  // �Ō�ɃJ�[�g���b�W����������s��
  if(CTRDG_IsExisting() == FALSE)
    return FALSE;

  return flag;
}


//------------------------------------------------------------------
/**
 * @brief	�`�f�a�J�[�g���b�W����f�[�^��ǂݏo��
 * @param	NONE
 * @return	TRUE: ����   FALSE: ���s
 */
//------------------------------------------------------------------
BOOL ReadAgbCartridgeData(void *dist, int size)
{
  BOOL flag;

  // �J�Z�b�g�̏������`�F�b�N
  if(IsExistAgbCartridge() == FALSE)
    return FALSE;

  // �Q�[���f�[�^���w��̈�ɃR�s�[����
  if(size == 0)
    size = GetAgbCartridgeDataSize();
  CTRDG_Enable(TRUE);
  flag = (BOOL)CTRDG_CpuCopy16((const void *)AGBMISSIONDATAPTR, dist, size);
  CTRDG_Enable(FALSE);

  OS_TPrintf("AGB�J�Z�b�g�ɓ����Ă�f�[�^�̃T�C�Y��%d [%08X\n", size, dist);

  
  // �Ō�ɃJ�[�g���b�W����������s��
  if(CTRDG_IsExisting() == FALSE)
    return FALSE;

  return flag;
}

/*  */
