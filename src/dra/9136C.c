#include "common.h"
#include "dra.h"
#include "objects.h"
#include "sfx.h"

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/9136C", func_8013136C);
#else
void func_8012C600(void); /* extern */
extern u16 D_8007412E;
extern s32 D_800741CC;
extern s32 D_800741D0;

void func_8013136C(Entity* entity) {
    if (!(D_80072F2C & 4)) {
        func_80106590(entity);
        return;
    }
    if (entity->step == 0) {
        entity->animationSet = 0xF;
        entity->unk5A = 0x7E;
        entity->palette = PLAYER.palette;
        entity->unk34 = 0x04060000;
        entity->unk19 = 4;
        entity->unk20 = -8;
        entity->step++;
    }
    entity->animationFrame = 0x50;
    entity->facing = PLAYER.facing;
    entity->posX.val = g_EntityArray[19].posX.val; // D_800741CC
    entity->posY.val = g_EntityArray[19].posY.val; // D_800741D0
    if (PLAYER.facing == 0) {
        entity->zPriority = PLAYER.zPriority - 5;
        entity->posX.i.hi += 8;
    } else {
        entity->zPriority = PLAYER.zPriority + 5;
        entity->posX.i.hi -= 8;
    }
    entity->posY.i.hi += 3;
    entity->unk1E = g_EntityArray[19].unk1E;
    switch (PLAYER.unk2E - 1) {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        break;

    case 0:
        if (D_800B0914 == 1) {
            entity->posY.i.hi -= 2;
            if (PLAYER.facing == 0) {
                entity->posX.i.hi -= 8;
            } else {
                entity->posX.i.hi += 8;
            }
        }
        break;

    case 2:
        switch (D_800B0914)
        {
        case 1:
            break;

        case 0:
            if (PLAYER.animationFrame == 33) {
                entity->animationFrame = 81;
                if (PLAYER.facing == 0) {
                    entity->posX.i.hi += 3;
                } else {
                    entity->posX.i.hi += 6;
                }
            }
            if (PLAYER.animationFrame == 34) {
                if (PLAYER.facing == 0) {
                    entity->posX.i.hi += 3;
                } else {
                    entity->posX.i.hi += 13;
                }
                entity->animationFrame = 82;
            }
        case 2:
            break;
        }
        break;

    }
    entity->palette = PLAYER.palette;
    func_8012C600();
}
#endif
const u32 rodataPadding_800E2024 = 0;
const u32 rodataPadding_800E2020 = 0;
