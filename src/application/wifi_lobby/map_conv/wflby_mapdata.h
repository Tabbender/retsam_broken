#ifndef __WFLBY_MAP_H__
#define __WFLBY_MAP_H__



// �}�b�v�̑傫��
#define WFLBY_MAPSIZE_X		(35)
#define WFLBY_MAPSIZE_Y		(42)



// �}�b�v�I�u�W�F�N�gID
#define WFLBY_MAPOBJID_NONE		(0)
#define WFLBY_MAPOBJID_FLOOR		(1)
#define WFLBY_MAPOBJID_BLOCK		(2)
#define WFLBY_MAPOBJID_PLAYER_IN		(3)
#define WFLBY_MAPOBJID_NPC_00		(4)
#define WFLBY_MAPOBJID_NPC_01		(5)
#define WFLBY_MAPOBJID_NPC_02		(6)
#define WFLBY_MAPOBJID_NPC_03		(7)
#define WFLBY_MAPOBJID_NPC_04		(8)
#define WFLBY_MAPOBJID_NPC_05		(9)
#define WFLBY_MAPOBJID_NPC_06		(10)
#define WFLBY_MAPOBJID_NPC_07		(11)
#define WFLBY_MAPOBJID_NPC_08		(12)
#define WFLBY_MAPOBJID_NPC_09		(13)
#define WFLBY_MAPOBJID_NPC_10		(14)
#define WFLBY_MAPOBJID_NPC_11		(15)
#define WFLBY_MAPOBJID_NPC_12		(16)
#define WFLBY_MAPOBJID_NPC_13		(17)
#define WFLBY_MAPOBJID_NPC_14		(18)
#define WFLBY_MAPOBJID_NPC_15		(19)
#define WFLBY_MAPOBJID_NPC_16		(20)
#define WFLBY_MAPOBJID_NPC_17		(21)
#define WFLBY_MAPOBJID_NPC_18		(22)
#define WFLBY_MAPOBJID_NPC_19		(23)
#define WFLBY_MAPOBJID_DOUZOU00		(24)
#define WFLBY_MAPOBJID_DOUZOU0100		(25)
#define WFLBY_MAPOBJID_DOUZOU0101		(26)
#define WFLBY_MAPOBJID_DOUZOU0102		(27)
#define WFLBY_MAPOBJID_DOUZOU0103		(28)
#define WFLBY_MAPOBJID_DOUZOUBL0100		(29)
#define WFLBY_MAPOBJID_DOUZOUBL0101		(30)
#define WFLBY_MAPOBJID_DOUZOUBL0102		(31)
#define WFLBY_MAPOBJID_DOUZOUBL0103		(32)
#define WFLBY_MAPOBJID_TREE00		(33)
#define WFLBY_MAPOBJID_FOOT_00_00		(34)
#define WFLBY_MAPOBJID_FOOT_00_01		(35)
#define WFLBY_MAPOBJID_FOOT_00_02		(36)
#define WFLBY_MAPOBJID_FOOT_00_03		(37)
#define WFLBY_MAPOBJID_FOOT_00_04		(38)
#define WFLBY_MAPOBJID_FOOT_00_05		(39)
#define WFLBY_MAPOBJID_FOOT_00_06		(40)
#define WFLBY_MAPOBJID_FOOT_00_07		(41)
#define WFLBY_MAPOBJID_FOOT_01_00		(42)
#define WFLBY_MAPOBJID_FOOT_01_01		(43)
#define WFLBY_MAPOBJID_FOOT_01_02		(44)
#define WFLBY_MAPOBJID_FOOT_01_03		(45)
#define WFLBY_MAPOBJID_FOOT_01_04		(46)
#define WFLBY_MAPOBJID_FOOT_01_05		(47)
#define WFLBY_MAPOBJID_FOOT_01_06		(48)
#define WFLBY_MAPOBJID_FOOT_01_07		(49)
#define WFLBY_MAPOBJID_WLDTIMER_00		(50)
#define WFLBY_MAPOBJID_WLDTIMER_01		(51)
#define WFLBY_MAPOBJID_WLDTIMER_02		(52)
#define WFLBY_MAPOBJID_WLDTIMER_03		(53)
#define WFLBY_MAPOBJID_TOPIC_00		(54)
#define WFLBY_MAPOBJID_TOPIC_01		(55)
#define WFLBY_MAPOBJID_TOPIC_02		(56)
#define WFLBY_MAPOBJID_TOPIC_03		(57)
#define WFLBY_MAPOBJID_BALLSLOW_IN		(58)
#define WFLBY_MAPOBJID_BALANCE_IN		(59)
#define WFLBY_MAPOBJID_BALLOON_IN		(60)
#define WFLBY_MAPOBJID_FLOAT00_IN		(61)
#define WFLBY_MAPOBJID_FLOAT01_IN		(62)
#define WFLBY_MAPOBJID_FLOAT02_IN		(63)
#define WFLBY_MAPOBJID_NPC_SW_IN		(64)
#define WFLBY_MAPOBJID_NPC_SW_TOPIC		(65)
#define WFLBY_MAPOBJID_NPC_SW_TOPIC2		(66)
#define WFLBY_MAPOBJID_NPC_SW_IN_TALK		(67)
#define WFLBY_MAPOBJID_NPC_SW_TOPIC_TALK		(68)
#define WFLBY_MAPOBJID_NPC_SW_TOPIC2_TALK		(69)
#define WFLBY_MAPOBJID_MG00		(70)
#define WFLBY_MAPOBJID_MG01		(71)
#define WFLBY_MAPOBJID_MG02		(72)
#define WFLBY_MAPOBJID_KANBAN00		(73)
#define WFLBY_MAPOBJID_KANBAN01		(74)
#define WFLBY_MAPOBJID_KANBAN02		(75)
#define WFLBY_MAPOBJID_TABLE		(76)
#define WFLBY_MAPOBJID_LAMP00		(77)
#define WFLBY_MAPOBJID_LAMP01		(78)
#define WFLBY_MAPOBJID_NPCMG00MAT00		(79)
#define WFLBY_MAPOBJID_NPCMG00MAT01		(80)
#define WFLBY_MAPOBJID_NPCMG00MAT02		(81)
#define WFLBY_MAPOBJID_NPCMG00MAT03		(82)
#define WFLBY_MAPOBJID_NPCMG01MAT00		(83)
#define WFLBY_MAPOBJID_NPCMG01MAT01		(84)
#define WFLBY_MAPOBJID_NPCMG01MAT02		(85)
#define WFLBY_MAPOBJID_NPCMG01MAT03		(86)
#define WFLBY_MAPOBJID_NPCMG02MAT00		(87)
#define WFLBY_MAPOBJID_NPCMG02MAT01		(88)
#define WFLBY_MAPOBJID_NPCMG02MAT02		(89)
#define WFLBY_MAPOBJID_NPCMG02MAT03		(90)
#define WFLBY_MAPOBJID_ROOF_MAT		(91)
#define WFLBY_MAPOBJID_DOUZOU00FIRE00		(92)
#define WFLBY_MAPOBJID_DOUZOU00FIRE01		(93)
#define WFLBY_MAPOBJID_KANBAN00_1		(94)
#define WFLBY_MAPOBJID_KANBAN01_1		(95)
#define WFLBY_MAPOBJID_KANBAN02_1		(96)
#define WFLBY_MAPOBJID_ANKETO_MAN		(97)
#define WFLBY_MAPOBJID_ANKETO_BOARD		(98)
#define WFLBY_MAPOBJID_ANKETO_BOARD_POS		(99)



// �C�x���gID
#define WFLBY_MAPEVID_NONE		(0)
#define WFLBY_MAPEVID_EV_PLAYER_OUT		(1)
#define WFLBY_MAPEVID_EV_DZ_00		(2)
#define WFLBY_MAPEVID_EV_DZ_01		(3)
#define WFLBY_MAPEVID_EV_DZ_02		(4)
#define WFLBY_MAPEVID_EV_DZ_03		(5)
#define WFLBY_MAPEVID_EV_FOOT_00_00		(6)
#define WFLBY_MAPEVID_EV_FOOT_00_01		(7)
#define WFLBY_MAPEVID_EV_FOOT_00_02		(8)
#define WFLBY_MAPEVID_EV_FOOT_00_03		(9)
#define WFLBY_MAPEVID_EV_FOOT_00_04		(10)
#define WFLBY_MAPEVID_EV_FOOT_00_05		(11)
#define WFLBY_MAPEVID_EV_FOOT_00_06		(12)
#define WFLBY_MAPEVID_EV_FOOT_00_07		(13)
#define WFLBY_MAPEVID_EV_FOOT_01_00		(14)
#define WFLBY_MAPEVID_EV_FOOT_01_01		(15)
#define WFLBY_MAPEVID_EV_FOOT_01_02		(16)
#define WFLBY_MAPEVID_EV_FOOT_01_03		(17)
#define WFLBY_MAPEVID_EV_FOOT_01_04		(18)
#define WFLBY_MAPEVID_EV_FOOT_01_05		(19)
#define WFLBY_MAPEVID_EV_FOOT_01_06		(20)
#define WFLBY_MAPEVID_EV_FOOT_01_07		(21)
#define WFLBY_MAPEVID_EV_WLDTIMER_00		(22)
#define WFLBY_MAPEVID_EV_WLDTIMER_01		(23)
#define WFLBY_MAPEVID_EV_WLDTIMER_02		(24)
#define WFLBY_MAPEVID_EV_WLDTIMER_03		(25)
#define WFLBY_MAPEVID_EV_TOPIC_00		(26)
#define WFLBY_MAPEVID_EV_TOPIC_01		(27)
#define WFLBY_MAPEVID_EV_TOPIC_02		(28)
#define WFLBY_MAPEVID_EV_TOPIC_03		(29)
#define WFLBY_MAPEVID_EV_BALLSLOW		(30)
#define WFLBY_MAPEVID_EV_BALANCE		(31)
#define WFLBY_MAPEVID_EV_BALLOON		(32)
#define WFLBY_MAPEVID_EV_FLOAT00		(33)
#define WFLBY_MAPEVID_EV_FLOAT01		(34)
#define WFLBY_MAPEVID_EV_FLOAT02		(35)
#define WFLBY_MAPEVID_EV_SW_IN		(36)
#define WFLBY_MAPEVID_EV_SW_TOPIC		(37)
#define WFLBY_MAPEVID_EV_SW_TOPIC2		(38)
#define WFLBY_MAPEVID_EV_KANBAN00		(39)
#define WFLBY_MAPEVID_EV_KANBAN01		(40)
#define WFLBY_MAPEVID_EV_KANBAN02		(41)
#define WFLBY_MAPEVID_EV_ROOF_MAT		(42)
#define WFLBY_MAPEVID_EV_ANKETO_MAN		(43)
#define WFLBY_MAPEVID_EV_ANKETO_BOARD		(44)



#endif //__WFLBY_MAP_H__