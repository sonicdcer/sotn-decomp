#include "ric.h"

// decompiling func_8015FB84 first is recommended to discover struct
INCLUDE_ASM("asm/us/ric/nonmatchings/21250", func_8015D250);

INCLUDE_ASM("asm/us/ric/nonmatchings/21250", func_8015D3CC);

INCLUDE_ASM("asm/us/ric/nonmatchings/21250", func_8015D678);

void func_8015D9B4() { SetPlayerStep(22); }

void func_8015D9D4(void) {
    func_8015C9CC();
    SetPlayerStep(0x17);
    func_8015C920(&D_80155750);
    g_CurrentEntity->accelerationY = 0;
    func_8015CA84(0x58000);
    func_8015CC28();
    func_801606BC(g_CurrentEntity, 0x19, 0);
    g_api.PlaySfx(0x707);
    g_Player.D_80072F18 = 4;
}

void func_8015DA60(void) {
    g_Player.unk44 = 0;
    SetPlayerStep(0x1A);
    func_8015C920(&D_8015577C);
    g_CurrentEntity->accelerationY = -0x20000;
    func_8015CA84(0x58000);
    func_8015CC28();
    func_801606BC(g_CurrentEntity, 0x19, 0);
    g_api.PlaySfx(0x6FA);
    g_Player.D_80072F18 = 4;
    func_801606BC(g_CurrentEntity, 0x1F, 0);
}

void func_8015DB04(void) {
    SetPlayerStep(0x18);
    func_8015C920(&D_801557D8);
    g_CurrentEntity->accelerationY = 0;
    func_8015CA84(0x58000);
    g_Player.unk46 = 5;
    g_Player.D_80072F18 = 4;
    func_801606BC(g_CurrentEntity, 0x1A, 0);
    func_8015CC28();
    g_api.PlaySfx(0x6FB);
    g_api.PlaySfx(0x707);
}

INCLUDE_ASM("asm/us/ric/nonmatchings/21250", func_8015DBB0);