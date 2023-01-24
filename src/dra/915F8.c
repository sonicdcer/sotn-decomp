#include "common.h"
#include "dra.h"
#include "objects.h"
#include "sfx.h"

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_801315F8);

void func_80131EBC(const char* str, s16 id) { D_80138784[id] = str; }

void func_80131ED8(s32 value) { D_80138F20 = value; }

void func_80131EE8(void) {
    D_80139020 = 1;
    D_8013B694 = 0;
}

void func_80131F04(void) {
    D_80139020 = 0;
    D_8013B694++;
}

s32 func_80131F28(void) { return D_80138F7C; }

u16 func_80131F38(void) {
    if (D_80139810 == 0) {
        return 0;
    }
    return D_80139810 | 0x200;
}

bool func_80131F68(void) {
    if (D_8013B61C == 0) {
        return D_8013901C != 0;
    }
    return true;
}

s16 func_80131F94(void) { return D_8013B668; }

void func_80131FA4(s16 arg0) { func_80021F6C(arg0, arg0); }

void func_80131FCC(void) {
    if (D_8013B680 == 0) {
        D_80138F7C = 0;
    } else {
        s32 temp_v1 = D_8013B680;
        s32 temp_v0 = D_8013B680;
        if (temp_v0 >= 0 && temp_v1 < 3)
            D_80138F7C++;
    }
    D_8013B680 = 0;
}

u8 func_80132028(u_char com, u_char* param, u_char* result) {
    s32 ret = CdSync(1, D_80138F2C);

    D_801396F0 = ret;

    if (com == CdlGetlocL) {
        if (ret == 2) {
            goto block_9;
        } else {
            goto block_6;
        }
    } else if ((*D_80138F2C & 0x10) || (*D_80138F2C & 4)) {
    block_6:
        CdControl(CdlNop, 0, 0);
        D_8013B680 = 2;
        return D_8013B680;
    } else if (ret == 2) {
    block_9:
        if (CdControl(com, param, result)) {
            D_8013B680 = 0;
            return D_8013B680;
        }
        goto block_12;
    }
block_12:
    D_8013B680 = 1;

    return D_8013B680;
}

void func_80132134(void) {
    g_volumeL = 127;
    g_volumeR = 127;
    SsSetMVol(g_volumeL, g_volumeR);
}

void func_8013216C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_8013B620[i] = 0;
        D_8013B614[i] = 0;
        D_8013AE84[i] = 0;
        D_8013B66C[i] = 0;
        D_8013B5EC[i] = 0;
        D_8013B628[i] = 0;
        D_8013B648[i] = 0;
        D_8013AEA0[i] = 0;
    }
}

void func_801321FC(void) {
    s32 i;

    func_8013216C();
    D_8013B690 = 0;

    for (i = 0; i < 4; i++) {
        D_8013B650[i] = 0;
        D_8013AED4[i] = 0;
    }
    D_80139804 = 0;
    D_8013B664 = 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80132264);

void func_801324B4(s8 s_num, s16 arg1, s16 arg2) {
    short voll = D_800BD07C[arg1];
    short volr = D_800BD07C[arg2];

    SsSetSerialVol(s_num, voll, volr);
}

void func_80132500(u8 soundMode) {
    CdlATV audioVolume;

    switch (soundMode) {
    case MONO:
        if (D_801390A8 != 0) { // D_801390A8 fake symbol or part of another
            func_80021174();
            audioVolume.val2 = 128; // CD (R) --> SPU (R)
            audioVolume.val0 = 128; // CD (L) --> SPU (L)
            audioVolume.val3 = 128; // CD Right sound transferred to left
            audioVolume.val1 = 128; // CD Left sound transferred to right
            CdMix(&audioVolume);
            D_8013AE7C = 108;
            D_801390A8 = 0;
        }
        break;
    case STEREO:
        if (D_801390A8 != 1) {
            func_80021188();
            audioVolume.val2 = 224; // CD (R) --> SPU (R)
            audioVolume.val0 = 224; // CD (L) --> SPU (L)
            audioVolume.val3 = 0;
            audioVolume.val1 = 0;
            CdMix(&audioVolume);
            D_8013AE7C = 127;
            D_801390A8 = 1;
        }
        break;
    }
}

/**
 * Called by entrypoint_sotn, seems to be initializing
 * various parts of the sound system
 */
void func_801325D8(void) {
    D_8013AEEC = 1;
    SsInitHot();
    SsSetTickMode(1);
    func_80132500(1);
    SsSetReservedVoice(0x10);
    SsStart();
    func_800209B4(&D_80138460, 0x10, 1);
    func_80021E38(3);
    SpuClearReverbWorkArea(3);
    func_80021EEC();
    func_80132134();
    D_8013B668 = 0x78;
    SsSetSerialAttr(0, 0, 1);
    func_801324B4(0, D_8013B668, D_8013B668);
    D_80138F24[0] = -0x38; // !FAKE: D_80138F24 part of an array / struct
    func_80132028(0xE, D_80138F24, 0);
    func_80132264();
    func_80131FA4(0xA);
    func_8002ABF4(0);
    func_80029FBC(0);
    CdReadyCallback(NULL);
    func_80028D3C(0x1010, 0x10000);
}

s32 func_801326D8(void) {
    if (D_8013901C != 0)
        return 1;
    if (D_80139810 != 0)
        return 3;
    return (D_801390D8 != 0) * 2;
}

void func_8013271C(void) {
    while (!(func_801326D8() & 0xFF) == 0) {
        VSync(0);
        func_801361F8();
    }
}

void func_80132760(void) {
    SsSetMVol(0, 0);
    SsSetSerialAttr(0, 0, 0);
    func_801324B4(0, 0, 0);
    func_80132134();
    func_80132264();
}

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_801327B4);

// https://decomp.me/scratch/0X5YL
// Matches with gcc 2.6.0 + aspsx 2.3.4
#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80132A04);
#else
void func_801327B4(s16, s16, s16, s16, s16, s16, s16, s16);
extern s16 D_800BD19C[];
extern s16 D_800BD19E[];
extern s16 D_80138FB8; // vol_l
extern s16 D_80139004; // vol_r

void func_80132A04(s16 voice, s16 vabId, s16 prog, s16 tone, u16 note,
                   s16 volume, s16 distance) {
    s16 var_a0;
    s16 var_a1;
    volatile short pad;

    if (distance == 0) {
        D_80138FB8 = volume;
        D_80139004 = volume;
    } else {
        D_80139004 = (volume * D_800BD19C[distance * 2]) >> 7;
        D_80138FB8 = (volume * D_800BD19E[distance * 2]) >> 7;
    }

    if (voice < 0x18U) {
        SsUtKeyOnV(voice, vabId, prog, tone, note, 0, D_80138FB8, D_80139004);
        SsUtKeyOnV(voice + 1, vabId, prog, 1 + tone, note, 0, D_80138FB8,
                   D_80139004);
        return;
    }
    switch (voice) {
    case 0x1E:
        var_a0 = 0;
        var_a1 = 4;
        break;
    case 0x1F:
        var_a0 = 4;
        var_a1 = 8;
        break;
    case 0x20:
        var_a0 = 8;
        var_a1 = 0xC;
        break;
    case 0x21:
        var_a0 = 0xE;
        var_a1 = 0x12;
        break;
    default:
        return;
    }
    func_801327B4(var_a0, var_a1, vabId, prog, tone, note, D_80138FB8,
                  D_80139004);
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80132C2C);

extern s16 D_80139868[];

u16 func_80132E38(void) {
    s32 i;

    for (i = 0; i < 255; i++) {
        D_80139868[i] = D_80139868[i + 1];
    }
    D_801396F4--;

    return D_801396F4;
}

void func_80132E90(u32 arg0, s8* arg1) {
    u16 temp;
    u16 temp2;

    arg1[2] = (((arg0 % 75) / 10) * 0x10) + ((arg0 % 75) % 10);
    arg1[1] = ((((arg0 / 75) % 60) / 10) * 0x10) + (((arg0 / 75) % 60) % 10);
    temp = ((arg0 / 75) / 60) % 10;
    arg1[0] = (temp2 = (((arg0 / 75) / 60) / 10) * 0x10) + temp;
}

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80132F60);
void func_80132F60();

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80133290);
void func_80133290();

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80133488);
void func_80133488();

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80133604);
void func_80133604();

void func_80133780(s8 arg0) { SsSetSerialAttr(0, 1, arg0 == 1); }

void func_801337B4(void) {
    if (D_80139810 != 0) {
        func_80020F44(D_8013B658);
        SsSeqClose(D_8013B658);
        func_8013415C();
        D_80139810 = 0;
        D_801390C4 = 0;
    }
}

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80133810);

bool func_80133940(void) { return D_801396F4 == 0; }

bool func_80133950(void) { return D_8013980C == 0; }

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80133960);
void func_80133960();

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80133BDC);
void func_80133BDC();

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80133FCC);

extern Unkstruct_80138FB4* D_80138FB4;

void func_80134104(void) {
    D_80138FB4->unk4 = 0x4000;
    D_80138FB4->unk0 = 0xFFFFFF;
    D_80138FB4->unk36 = 0xE;
    func_8002A09C(D_80138FB4);
    D_80138F28 = 0xFFFFFF;
    func_801321FC();
}

void func_8013415C(void) {
    D_80138FB4->unk4 = 0x4000;
    D_80138FB4->unk0 = 0xFFFFFF;
    D_80138FB4->unk36 = 8;
    func_8002A09C(D_80138FB4);
    D_80138F28 = 0xFFFFFF;
    func_801321FC();
}

void func_801341B4(void) {
    s32 temp;

    switch (D_8013AE80) {
    case 0:
        D_801390A0 = 1;
        D_80139A78 = 0;
        D_8013AE80++;
        break;

    case 1:
        D_80139A78++;
        if (g_volumeL > 0) {
            temp = g_volumeR * D_80139A6C * D_80139A78;
            if (temp < 0) {
                temp += 0x1FF;
            }
            g_volumeL = g_volumeR - (temp >> 9);
            if (g_volumeL >> 0x10) {
                g_volumeL = 0;
            }
        } else {
            g_volumeL = 0;
        }
        SsSetMVol(g_volumeL, g_volumeL);
        if (g_volumeL == 0) {
            D_8013AE80++;
        }
        break;

    case 2:
        func_80131FA4(0);
        func_801337B4();
        func_80132C2C(3);
        D_800BD1C4 = 3;
        D_8013AE80++;
        break;

    case 3:
        D_800BD1C4--;
        if (D_800BD1C4 == 0) {
            func_8013415C();
        default:
            D_8013AE80 = 0;
            D_801390A0 = D_8013AE80;
            D_8013B61C = 0;
            func_80132E38();
        }
        break;
    }
}

void func_80134388(void) {
    s32 temp;

    switch (D_8013AE80) {
    case 0:
        D_8013AE80++;
        D_801390A0 = 1;
        D_80139A78 = 0;
        break;

    case 1:
        D_80139A78++;
        if (D_8013B668 > 0) {
            temp = D_80139820 * D_80139A6C * D_80139A78;
            if (temp < 0) {
                temp += 0x1FF;
            }
            D_8013B668 = D_80139820 - (temp >> 9);
            if (D_8013B668 >> 0x10) {
                D_8013B668 = 0;
            }
        } else {
            D_8013B668 = 0;
        }
        func_801324B4(0, D_8013B668, D_8013B668);
        if (D_8013B668 == 0) {
            D_8013AE80++;
        }
        break;

    case 2:
        func_80132C2C(2);

    default:
        D_8013AE80 = 0;
        D_801390A0 = D_8013AE80;
        D_8013B61C = 0;
        func_80132E38();
        break;
    }
}

extern Unkstruct_80138FB4* D_801390C8;

void func_80134508(void) {
    D_801390C8->unk0 = 0x300000;
    D_801390C8->unk4 = 0x4000;
    D_801390C8->unk36 = 0xE;
    func_8002A09C(D_801390C8);
    D_80138F28 |= 0x300000;
}

extern Unkstruct_80138FB4* D_801390CC;

void func_80134564(void) {
    D_801390CC->unk0 = 0xC00000;
    D_801390CC->unk4 = 0x4000;
    D_801390CC->unk36 = 0xE;
    func_8002A09C(D_801390CC);
    D_80138F28 |= 0xC00000;
}

extern Unkstruct_80138FB4* D_801390C8;

void func_801345C0(void) {
    D_801390C8->unk0 = 0x300000;
    D_801390C8->unk4 = 0x4000;
    D_801390C8->unk36 = 8;
    func_8002A09C(D_801390C8);
    D_80138F28 |= 0x300000;
}

extern Unkstruct_80138FB4* D_801390CC;

void func_8013461C(void) {
    D_801390CC->unk0 = 0xC00000;
    D_801390CC->unk4 = 0x4000;
    D_801390CC->unk36 = 8;
    func_8002A09C(D_801390CC);
    D_80138F28 |= 0xC00000;
}

s32 func_80134678(s16 arg0, u16 arg1) {
    s32 ret = -2;
    u16 temp;

    if (D_80139804 != 0) {
        ret = 0;
        temp = arg1 + 8;

        if (temp >= 0x11) {
            arg1 = 0;
            ret = -1;
        }

        D_8013AE94 = arg1;
        D_8013AEE0 = arg0;
        D_8013B3E8[D_80139A70] = 1;
        D_80139A70++;

        if (D_80139A70 == 0x100) {
            D_80139A70 = 0;
        }
    }
    return ret;
}

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80134714);

void PlaySfx(s16 sfxId) {
    u16 offset;

    if (D_8013AEEC != 0) {
        offset = (u32)(sfxId - 0x601);
        if (offset < 0x2E0) {
            D_801390DC[D_80139000].unk00 = sfxId - 0x600;
            D_801390DC[D_80139000].unk02 = 0xFFFF;
            D_801390DC[D_80139000].unk04 = 0;
            D_80139000++;
            if (D_80139000 == 0x100) {
                D_80139000 = 0;
            }
        } else {
            switch (sfxId) {
            case 0x10:
            case 0x11:
                D_8013980C = 1;
                break;

            case 0x80:
            case 0x81:
            case 0x82:
            case 0x83:
            case 0x84:
            case 0x90:
            case 0x91:
            case 0x92:
            case 0x93:
            case 0x94:
                D_8013B61C = 1;
                break;

            default:
                break;
            }

            D_8013B3E8[D_80139A70] = sfxId;
            D_80139A70++;
            if (D_80139A70 == 0x100) {
                D_80139A70 = 0;
            }
        }
    }
}

void func_8013493C(s16 arg0, s16 arg1) {
    D_8013AE84[arg1] = D_8013B678[arg0];
    D_8013B620[arg1] = D_801390AC[arg0];
    D_8013B614[arg1] = D_80139058[arg0];
    D_8013B66C[arg1] = D_80139814[arg0];
    D_8013B5EC[arg1] = D_80139018[arg0];
    D_8013B628[arg1] = D_801390B4[arg0];
}

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_801349F4);

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80134B48);

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80134C60);

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80134D14);

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80134E64);

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80134F50);
void func_80134F50();

#ifndef NON_EQUIVALENT
INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_801353A0);
#else
void func_801353A0(void) {
    if (D_801396F4 == 0)
        return;

    switch (D_80139868[0]) {
    case 2:
        func_80133604();
        break;
    case 3:
        func_80133488();
        break;
    case 4:
        func_80132F60();
        break;
    case 6:
        func_80133290();
        break;
    case 8:
        func_80134388();
        break;
    case 10:
        func_801341B4();
        break;
    case 12:
        func_80133960();
        break;
    case 14:
        func_80133BDC();
        break;
    case 16:
        D_8013B684 = 0;
    case 0:
        func_80132E38();
        break;
    }
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80135484);

void func_80135624(s16 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4) {
    if (arg2 != 0) {
        D_80138F28 |= (1 << ((arg1 + 6) * 2)) + (1 << (((arg1 + 6) * 2) + 1));
    }
    func_80132A04((arg1 * 2) + 12, D_800BF554[arg0 * 7], D_800BF555[arg0 * 7],
                  D_800BF559[arg0 * 7], D_800BF556[arg0 * 7], arg3, arg4);
    do { // !FAKE:
    } while (0);
    D_8013B650[arg1] = arg0;
    D_8013AED4[arg1] = D_800BF55A[arg0 * 7];
}

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_8013572C);

s16 func_80135C00(s16 arg0) {
    arg0++;

    if (arg0 == 0x100) {
        arg0 = 0;
    }

    return arg0;
}

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80135C2C);
void func_80135C2C();

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80135D8C);
void func_80135D8C();

INCLUDE_ASM("asm/dra/nonmatchings/915F8", func_80136010);

void func_801361F8(void) {
    if (D_8013AEEC != 0) {
        func_80136010();
        func_80135C2C();
        func_80135D8C();
        func_80134F50();
        func_80133FCC();
        func_801353A0();
        func_8002A024(0, D_80138F28);
        D_80138F28 = 0;
        func_80131FCC();

        if (D_80139020) {
            func_801324B4(0, 0, 0);
        } else {
            func_801324B4(0, D_8013B668, D_8013B668);
        }
    }
}

void nullsub_10(void) {}