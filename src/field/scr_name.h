//============================================================================================
/**
 * @file	scr_name.h
 * @bfief	�X�N���v�g�R�}���h�F���O�֘A
 * @author	Satoshi Nohara
 * @date	06.06.23
 */
//============================================================================================
#ifndef SCR_NAME_H
#define SCR_NAME_H


//============================================================================================
//
//	�v���O�����ł̂ݎQ�Ƃ����`
//
//============================================================================================
//__ASM_NO_DEF_����`����Ă���ꍇ�A�A�Z���u���\�[�X�Ȃ̂ňȉ��͖����ɂ���
#ifndef	__ASM_NO_DEF_
extern BOOL EvCmdStatusName(VM_MACHINE * core );
extern BOOL EvCmdPlayerName(VM_MACHINE * core );
extern BOOL EvCmdRivalName(VM_MACHINE * core ); 
extern BOOL EvCmdSupportName(VM_MACHINE * core );
extern BOOL EvCmdPokemonName(VM_MACHINE * core );
extern BOOL EvCmdTypeName(VM_MACHINE * core );
extern BOOL EvCmdItemName(VM_MACHINE * core );
extern BOOL EvCmdPocketName(VM_MACHINE * core );
extern BOOL EvCmdItemWazaName(VM_MACHINE * core );
extern BOOL EvCmdWazaName(VM_MACHINE * core );
extern BOOL EvCmdNumberName(VM_MACHINE * core );
extern BOOL EvCmdNumberNameEx(VM_MACHINE * core );
extern BOOL EvCmdNumberNameEx32(VM_MACHINE * core );
extern BOOL EvCmdNickName(VM_MACHINE * core );
extern BOOL EvCmdNickNamePC(VM_MACHINE * core );
extern BOOL EvCmdPoketchName(VM_MACHINE * core );
extern BOOL EvCmdTrTypeName(VM_MACHINE * core );
extern BOOL EvCmdMyTrTypeName(VM_MACHINE * core );
extern BOOL EvCmdPokemonNameExtra(VM_MACHINE * core );
extern STRBUF * PokeNameGetAlloc( u16 id, u32 heap );
extern BOOL EvCmdFirstPokemonName(VM_MACHINE * core );
extern BOOL EvCmdRivalPokemonName(VM_MACHINE * core );
extern BOOL EvCmdSupportPokemonName(VM_MACHINE * core );
extern BOOL EvCmdGoodsName(VM_MACHINE * core );
extern BOOL EvCmdTrapName(VM_MACHINE * core );
extern BOOL EvCmdTamaName(VM_MACHINE * core );
extern BOOL EvCmdZoneName(VM_MACHINE * core );
extern BOOL EvCmdNutsName(VM_MACHINE * core);
extern BOOL EvCmdSeikakuName(VM_MACHINE * core);
extern BOOL EvCmdAcceName(VM_MACHINE * core );
extern BOOL EvCmdMonumantName(VM_MACHINE * core ) ;
extern BOOL EvCmdTemotiWazaName( VM_MACHINE * core );
extern BOOL EvCmdRibbonName(VM_MACHINE * core);
extern BOOL EvCmdSealName(VM_MACHINE * core );
extern BOOL EvCmdTrainerName(VM_MACHINE * core );

// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/10/13
// �����t���E�����`�̃A�C�e���������������Ă���X�N���v�g���߂�ǉ�
extern BOOL EvCmdItemNameIndefinate(VM_MACHINE * core );
extern BOOL EvCmdItemNamePlural(VM_MACHINE * core );
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/11/28
// �s�芥���t���̒n���O�b�Y�������������Ă���X�N���v�g���߂�ǉ�
extern BOOL EvCmdGoodsNameIndefinate(VM_MACHINE * core );
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/11/29
// �s�芥���t���̒n���O�b�Y�������������Ă���X�N���v�g���߂�ǉ�
extern BOOL EvCmdTrapNameIndefinate(VM_MACHINE * core );
extern BOOL EvCmdTamaNameIndefinate(VM_MACHINE * core );
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/12/11
// �s�芥���t���̃|�P�������E�A�N�Z�T���[�������������Ă���X�N���v�g���߂�ǉ�
extern BOOL EvCmdPokemonNameExtraIndefinate(VM_MACHINE * core );
extern BOOL EvCmdSupportPokemonNameIndefinate(VM_MACHINE * core );
extern BOOL EvCmdAcceNameIndefinate(VM_MACHINE * core );
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/12/19
// �s�芥���t���̃g���[�i�[�^�C�v�������������Ă���X�N���v�g���߂�ǉ�
extern BOOL EvCmdTrTypeNameIndefinate(VM_MACHINE * core );
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2007/01/26
// �����`�̃V�[���������������Ă���X�N���v�g���߂�ǉ�
extern BOOL EvCmdSealNamePlural(VM_MACHINE * core );
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// localize_spec_mark(LANG_ALL) imatake 2006/11/24
// �ϐ��ɑ�����ꂽ��������L���s�^���C�Y����X�N���v�g���߂�ǉ�
extern BOOL EvCmdCapitalizeName(VM_MACHINE * core);
// ----------------------------------------------------------------------------

extern BOOL EvCmdTobariDepartFloorNo(VM_MACHINE * core); // plat_us_match

#endif	/* __ASM_NO_DEF_ */


#endif	/* SCR_NAME_H */


