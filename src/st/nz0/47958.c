#include "nz0.h"

// DECOMP_ME_WIP EntityBloodSkeleton https://decomp.me/scratch/O9yG0
// INCLUDE_ASM("asm/us/st/nz0/nonmatchings/47958", EntityBloodSkeleton);
extern u16 D_80180C40;
extern u8 D_80182610;
extern s16 D_80182624[];
extern u8 D_80182638;
extern u8 D_80182654;
extern u8 D_80182670;
extern s32 D_80182694;
extern s32 D_801826AC;
typedef struct test {
    char pad[0xb14];
    s32 unkb14;
} test;

extern test* D_8003C808;

u8 func_801C070C(void*, s32);

// INCLUDE_ASM("asm/us/st/nz0/nonmatchings/47958", EntityBloodSkeleton);
void EntityBloodSkeleton(Entity* self) {
    int new_var3;
    const char* animation;
    test* temp;
    int new_var4;
    if ((self->flags & 0x100) && (self->step < 3)) {
        func_801C29B0(0x6CB);
        self->unk3C = 0;
        func_801BD52C(3);
    }
    switch (self->step) {
    case 0:
        InitializeEntity(&D_80180C40);
        new_var3 = ((unsigned char)Random()) % 2;
        self->facing = new_var3;
        self->animCurFrame = 1;
        self->flags &= 0x1FFFFFFF;
        self->palette += self->subId;
        break;

    case 1:
        if (func_801BCCFC(&D_80182694) % 2) {
            self->unk2E = 0;
            self->step++;
        }
        break;

    case 2:
        if (self->animFrameDuration == 0) {
            if (self->facing != 0) {
                self->posX.i.hi += D_80182624[self->animFrameIdx];
            } else {
                self->posX.i.hi -= D_80182624[self->animFrameIdx];
            }
        }
        if (((AnimateEntity(&D_80182610, self) == 0) &&
             (func_801BCC28() < 0x30)) &&
            ((Random() % 4) == 0)) {
            self->facing = (func_801BCC5C() % 2) == 0;
        }
        if (func_801C070C(&D_801826AC, self->facing) != 2) {
            self->facing ^= 1;
        }
        break;

    case 3:
        if (AnimateEntity(&D_80182638, self) == 0) {
            self->unk80.modeS16.unk0 = 0xF0;
            self->flags &= ~0x100;
            if (self->subId != 0) {
                self->unk80.modeS16.unk0 = 4;
            }
            func_801BD52C(4);
        }
        break;

    case 4:
        switch (self->unk2E) {
        case 0:
            if ((--self->unk80.modeS16.unk0) == 0) {
                self->unk1E = 0;
                self->unk19 |= 4;
                func_801C29B0(0x6CC);
                self->unk2E++;
                return;
            }
            break;

        case 1:
            if ((g_blinkTimer % 3) == 0) {
                self->unk80.modeS16.unk0++;
                if ((self->unk80.modeS16.unk0 % 2) != 0) {
                    self->unk1E = 0x10;
                } else {
                    self->unk1E = -0x10;
                }
            }
            if (self->unk80.modeS16.unk0 >= 9) {
                self->unk19 = 0;
                self->unk1E = 0;
                self->unk2E++;
            }
            break;

        case 2:
            if (self->subId == 0) {
                animation = &D_80182654;
            } else {
                animation = &D_80182670;
            }
            if (AnimateEntity(animation, self) == 0) {
                self->hitPoints = 0;
        do
        {
          self->unk3C = 3;
        }
        while (0);
        new_var4 = 0x1FFFFFFF;
        self->flags = D_8003C808->unkb14 & new_var4;
        func_801BD52C(2);
            }
        }

        break;
    }
}

s32 func_801C7CF0(Entity* e) {
    s16 diff;

    diff = PLAYER.posX.i.hi - e->posX.i.hi;
    diff = ABS(diff);

    if (diff >= 25) {
        diff = 0;
    } else {
        diff = PLAYER.posY.i.hi - e->posY.i.hi;
        diff = ABS(diff);
        diff = diff < 33;
    }

    return diff;
}

// sealed door that displays "Magically Sealed" prompt
INCLUDE_ASM("asm/us/st/nz0/nonmatchings/47958", EntityMagicallySealedDoor);

INCLUDE_ASM("asm/us/st/nz0/nonmatchings/47958", func_801C8ADC);

INCLUDE_ASM("asm/us/st/nz0/nonmatchings/47958", EntityStageNamePopup);

INCLUDE_ASM("asm/us/st/nz0/nonmatchings/47958", func_801C9930);

INCLUDE_ASM("asm/us/st/nz0/nonmatchings/47958", func_801C9D18);

POLY_GT4* func_801C9E68(POLY_GT4* poly) {
    while (poly != NULL) {
        if (poly->p3 != 0) {
            poly = (POLY_GT4*)poly->tag;
        } else {
            return poly;
        }
    }
    return NULL;
}

Primitive* func_801C9E98(Primitive* prim, u8 index) {
    if (prim) {
        s32 index_ = index;
    loop_2:
        if (prim->p3 == 0) {
            Primitive* var_v0 = NULL;
            Primitive* firstPrim = prim;
            s32 i = 1;
            if (i < index_) {
                do {
                    prim = prim->next;
                    if (!prim)
                        return NULL;
                } while (prim->p3 == 0 && ++i < index);
            }
            var_v0 = firstPrim;
            if (i == index_)
                return var_v0;
        }
        prim = prim->next;
        if (prim) {
            goto loop_2;
        }
    }
    return NULL;
}

POLY_GT4* func_801C9F14(POLY_GT4* startPoly, s32 count) {
    POLY_GT4* poly;
    s8 unk;
    s32 i;

    if (startPoly->p3) {
        startPoly->p3 = 0;
    } else {
        startPoly->p3 = 1;
    }

    poly = startPoly;
    for (i = 0; i < count; i++) {
        if (poly->p3) {
            poly->pad3 &= ~8;
            unk = 0;
        } else {
            poly->pad3 |= 8;
            unk = 1;
        }

        poly = (POLY_GT4*)poly->tag;
        if (poly == NULL)
            return NULL;
        poly->p3 = unk;
    }

    return poly;
}

void func_801C9F9C(POLY_GT4* poly) {
    poly->p1 = 0;
    poly->p2 = 0;
    poly->p3 = 0;
    ((POLY_GT4*)poly->tag)->x1 = 0;
    ((POLY_GT4*)poly->tag)->y1 = 0;
    ((POLY_GT4*)poly->tag)->y0 = 0;
    ((POLY_GT4*)poly->tag)->x0 = 0;
    ((POLY_GT4*)poly->tag)->clut = 0;
    *(u16*)&((POLY_GT4*)poly->tag)->u0 = 0;
    *(u16*)&((POLY_GT4*)poly->tag)->b1 = 0;
    *(u16*)&((POLY_GT4*)poly->tag)->r1 = 0;
    *(u16*)&((POLY_GT4*)poly->tag)->u1 = 0;
    ((POLY_GT4*)poly->tag)->tpage = 0;
    *(u16*)&((POLY_GT4*)poly->tag)->r2 = 0;
    *(u16*)&((POLY_GT4*)poly->tag)->b2 = 0;
    ((POLY_GT4*)poly->tag)->u2 = 0;
    ((POLY_GT4*)poly->tag)->v2 = 0;
    ((POLY_GT4*)poly->tag)->r3 = 0;
    ((POLY_GT4*)poly->tag)->b3 = 0;
    ((POLY_GT4*)poly->tag)->x2 = 0;
    ((POLY_GT4*)poly->tag)->y2 = 0;
}

void func_801CA07C(POLY_GT4* poly) {
    func_801C9F9C(poly);
    poly->p3 = 8;
    ((POLY_GT4*)poly->tag)->p3 = 1;
    ((POLY_GT4*)poly->tag)->code = 2;
    ((POLY_GT4*)poly->tag)->pad3 = 0xA;
}

void func_801CA0D0(POLY_GT4* poly) {
    poly->p3 = 0;
    poly->pad3 = 8;
    ((POLY_GT4*)poly->tag)->p3 = 0;
    ((POLY_GT4*)poly->tag)->code = 4;
    ((POLY_GT4*)poly->tag)->pad3 = 8;
}

//! FAKE
s32 func_801CA0FC(s32 arg0, u8 arg1) {
    s32 var_v0;
    s32 ret = 0;
    s32 j = arg0 + 4;
    u8* var_v1;
    s32 i;

    for (i = 0; i < 4; i++, j += 12) {
        var_v1 = (u8*)j;
        do {
            var_v0 = *var_v1 - arg1;

            if (var_v0 < 0) {
                var_v0 = 0;
            } else {
                ret |= 1;
            }

            *var_v1 = var_v0;
            var_v1++;
        } while ((s32)var_v1 < (s32)j + 3);
    }

    return ret;
}

// particle effect that spawns life up item
// Unique
INCLUDE_ASM("asm/us/st/nz0/nonmatchings/47958", EntityLifeUpSpawn);