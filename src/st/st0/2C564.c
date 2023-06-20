#include "st0.h"

// INCLUDE_ASM("asm/us/st/st0/nonmatchings/2C564", EntityDracula);

extern u16 D_801805E0[];
extern u8 D_80180914;
extern u8 D_80180924;
extern u8 D_80180934;
extern u8 D_80180944;
extern u8 D_80180954;
extern u8 D_801809A4;
extern u8 D_80180A0C;
extern u8 D_80180A20;
extern u8 D_80180A2C;
extern s32 D_80180A58[];
extern s32 D_80180A5A[];
extern s32 D_801C2578;
extern s32 D_801C257C;
// extern ? (*g_api_func_80102CD8)(?);
extern u16 g_pads_1_pressed;
extern u16 D_80180A48[];

void EntityDracula(Entity* self) {
    Entity* temp_2;
    Entity* temp_4;
    Entity* newEntity;
    Primitive* prim;
    s16 firstPrimIndex;
    s16 temp_18;
    s16 temp_19;
    s16 temp_20;
    s16 temp_21;
    s16 temp_v1_8;
    s32 var_a0_2;
    s32 var_a0_3;
    s16 var_v0;
    s16 var_v1;
    s32 var_a1;
    s32 var_v0_2;
    u16 temp_a0;
    s32 temp_s2;
    u16 temp;
    u16 temp_12;
    u16 temp_13;
    u16 temp_15;
    u16 temp_16;
    u16 temp_3;
    u16 temp_5;
    u16 temp_7;
    u16 temp_8;
    u16 temp_9;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;
    u16 temp_v1_4;
    u16 temp_v1_5;
    u16 temp_v1_6;
    u16 temp_v1_7;
    s32 i;
    u8 temp_11;
    u8 temp_14;
    u8 temp_17;
    u8 temp_22;
    u8 temp_23;
    u8 temp_24;
    u8* var_a0;
    if ((self->flags & 0x100) && (self->step < 8)) {
        self->unk3C = 0;
        self[1].unk3C = 0;
        func_801B5794(8);
    }
    if (self->unk48 == 1) {
        g_api.PlaySfx(0x85B);
    }
    if (self->unk48 == 2) {
        g_api.PlaySfx(0x85C);
    }
    if (self->unk48 == 3) {
        g_api.PlaySfx(0x85D);
    }
    switch (self->step) {
    case 0:
        InitializeEntity(&D_801805E0);
        self->animCurFrame = 0x4F;
        self->ext.stub[0x25] = 1;
        self->unk3C = 0;
        self->facing = 1;
        CreateEntityFromCurrentEntity(0x1D, &self[1]);
        self[1].zPriority = self->zPriority + 1;
        firstPrimIndex = g_api.func_800EDB58(4, 0x80);
        if (firstPrimIndex == (-1)) {
            self->step = 0;
            return;
        }
        prim = &g_PrimBuf[firstPrimIndex];
        self->firstPolygonIndex = firstPrimIndex;
        self->ext.dracula.unkAC = prim;
        self->flags |= 0x800000;
        while (prim != 0) {
            prim->blendMode = 8;
            prim = prim->next;
        }

        func_801B5794(2);
        return;

    case 2:
        func_801B5794(3);
        return;

    case 3:
        switch (self->step_s) {
        case 0:
            if (D_801C257C & 0x10) {
                func_801B57B4(1);
            }
            break;

        case 1:
            if ((AnimateEntity(&D_80180A0C, self) == 0) &&
                (D_801C257C & 0x20)) {
                func_801B57B4(2);
            }
            break;

        case 2:
            if (AnimateEntity(&D_80180A20, self) == 0) {
                D_801C257C |= 0x100;
            }
            if (D_801C257C & 0x40) {
                D_8003C744 = 1;
                func_801B57B4(3);
            }
            if ((*((s32*)(&self->animFrameIdx))) == 2) {
                temp_2 = AllocEntity(D_8007D858, &D_8007D858[32]);
                if (temp_2 != 0) {
                    CreateEntityFromEntity(0x1F, self, temp_2);
                    temp_2->facing = self->facing;
                    temp_2->posX.i.hi -= 8;
                    temp_2->posY.i.hi -= 24;
                    return;
                }
            }
            break;

        case 3:
            if (AnimateEntity(&D_80180A2C, self) == 0) {
                g_api.func_800FD4C0(0, 2);
                func_801B5794(4);
            }
            break;
        }

        break;

    case 4:
        switch (self->step_s) {
        case 0:
            self->unk3C = 0;
            self->ext.dracula.unk9C = 0;
            self->step_s++;

        case 1:
            self->ext.dracula.unk9C =
                func_801ABBBC(self->ext.dracula.unk9C, self);
            if (((u8)self->ext.stub[0x24]) != 0) {
                g_api.PlaySfx(0x850);
                self->animCurFrame = 0;
                self->ext.stub[0x24] = 0;
            }
            if (self->ext.dracula.unk9C != 0xFF) {
                return;
            }
            self->step_s++;
            return;

        case 2:
            func_801B5794(5);
            return;
        }

        break;

    case 5:
        switch (self->step_s) {
        case 0:
            self->ext.dracula.unk8C = 0x80;
            self->step_s++;

        case 1:
            if ((--self->ext.dracula.unk8C) == 0) {
                temp_a0 = D_80180A48[Random() & 7];
                self->posY.i.hi = 0x82;
                self->ext.dracula.unk9C = 0;
                self->posX.i.hi = temp_a0;
                self->step_s++;
            }
            break;

        case 2:
            self->ext.dracula.unk9C =
                func_801ABBBC(self->ext.dracula.unk9C, self);
            if (((u8)self->ext.stub[0x24]) != 0) {
                g_api.PlaySfx(0x84F);
                self->animCurFrame = 1;
                self->facing = (func_801B4C78() & 1) ^ 1;
                self->ext.stub[0x24] = 0;
            }
            if (self->ext.dracula.unk9C != 0xFF) {
                return;
            }
            self->step_s++;
            break;

        case 3:
            self->facing = (func_801B4C78() & 1) ^ 1;
            self->ext.stub[0x26] = (((u8)self->ext.stub[0x26]) + 1) & 3;
            self->unk3C = 3;
            if (((u8)self->ext.stub[0x26]) == 0) {
                func_801B5794(6);
                return;
            }
            func_801B5794(7);
        }

        break;

    case 7:
        switch (self->step_s) {
        case 0:
            if (AnimateEntity(&D_80180914, self) == 0) {
                self[1].animFrameDuration = 0;
                self[1].animFrameIdx = 0;
                func_801B57B4(1);
                g_api.PlaySfx(0x853);
                return;
            }
            break;

        case 1:
            if (AnimateEntity(&D_801809A4, &self[1]) == 0) {
                self[1].animCurFrame = 0;
                func_801B57B4(2);
            }
            break;

        case 2:
            for (i = 0; i < 3; i++) {
                temp_4 = AllocEntity(D_8007A958, &D_8007A958[32]);
                if (temp_4 != 0) {
                    CreateEntityFromEntity(0x1B, self, temp_4);
                    temp_4->facing = self->facing;
                    temp_4->zPriority = self->zPriority + 1;
                    temp_4->subId = i;
                    if (self->facing != 0) {
                        temp_4->posX.i.hi -= 24;
                    } else {
                        temp_4->posX.i.hi += 24;
                    }
                    temp_4->posY.i.hi += 44;
                }
            }

            self->step_s++;

        case 3:
            if (AnimateEntity(&D_80180924, self) == 0) {
                func_801B5794(4);
            }
        }

        break;

    case 6:
        switch (self->step_s) {
        case 0:
            if (AnimateEntity(&D_80180934, self) == 0) {
                func_801B57B4(1);
                self->ext.dracula.unk8C = 2;
                g_api.PlaySfx(0x660);
                g_api.PlaySfx(0x855);
                return;
            }
            break;

        case 1:

        case 2:
            if ((--self->ext.dracula.unk8C) == 0) {
                newEntity = AllocEntity(D_8007A958, &D_8007A958[32]);
                if (newEntity != 0) {
                    CreateEntityFromEntity(0x1C, self, newEntity);
                    temp_s2 = self->step_s - 1;
                    newEntity->facing = self->facing;
                    if (self->facing != 0) {
                        newEntity->posX.i.hi += D_80180A58[temp_s2];
                    } else {
                        newEntity->posX.i.hi -= D_80180A58[temp_s2];
                    }
                    newEntity->posY.i.hi += D_80180A5A[temp_s2];
                    newEntity->zPriority = self->zPriority + 1;
                    newEntity->subId = temp_s2;
                }
                self->ext.dracula.unk8C = 0x20;
                self->step_s++;
            }
            break;

        case 3:
            if ((--self->ext.dracula.unk8C) == 0) {
                self->step_s++;
            }
            break;

        case 4:
            if (AnimateEntity(&D_80180944, self) == 0) {
                func_801B5794(4);
            }
            break;
        }

        break;

    case 8:
        switch (self->step_s) {
        case 0:
            prim = self->ext.dracula.unkAC;
            self->unk3C = 0;
            g_isDraculaFirstFormDefeated = 1;
            while (prim != 0) {
                prim->blendMode = 8;
                prim = prim->next;
            }

            g_api.PlaySfx(0x858);
            self->step_s++;

        case 1:
            if (AnimateEntity(&D_80180954, self) == 0) {
                self->ext.dracula.unk8C = 0x28;
                self->unk5A = 0x59;
                self->step_s++;
            }
            if ((*((s32*)(&self->animFrameIdx))) == 5) {
                g_api.func_80102CD8(2);
            }
            break;

        case 2:
            if ((--self->ext.dracula.unk8C) == 0) {
                g_api.PlaySfx(0x857);
                self->step_s++;
            }
            break;

        case 3:
            prim = self->ext.dracula.unkAC;
            self->ext.generic.unk94 = 0x40;
            self->ext.dracula.unk98 = 0;
            self->unk6C = 0x80;
            self->unk19 |= 8;
            prim->type = 3;
            prim->x0 = (prim->x2 = self->posX.i.hi);
            temp = self->posX.i.hi;
            prim->y1 = 0;
            prim->y0 = 0;
            prim->y3 = 0x100;
            prim->y2 = 0x100;
            prim->x3 = temp;
            prim->x1 = temp;
            temp_11 = self->ext.generic.unk94;
            prim->b0 = temp_11;
            prim->g0 = temp_11;
            prim->r0 = temp_11;
            prim->priority = 0xC0;
            prim->blendMode = 0x31;
            *((s32*)(&prim->r1)) = *((s32*)(&prim->r0));
            *((s32*)(&prim->r2)) = *((s32*)(&prim->r0));
            *((s32*)(&prim->r3)) = *((s32*)(&prim->r0));
            prim = prim->next;
            prim->type = 3;
            temp_12 = self->posX.i.hi;
            prim->x2 = temp_12;
            prim->x0 = temp_12;
            temp_13 = self->posX.i.hi;
            prim->b0 = 0;
            prim->g0 = 0;
            prim->r0 = 0;
            prim->y1 = 0;
            prim->y0 = 0;
            prim->y3 = 0x100;
            prim->y2 = 0x100;
            prim->x3 = (s16)temp_13;
            prim->x1 = (s16)temp_13;
            *((s32*)(&prim->r2)) = *((s32*)(&prim->r0));
            temp_14 = self->ext.generic.unk94;
            prim->b1 = temp_14;
            prim->g1 = temp_14;
            prim->r1 = temp_14;
            prim->priority = 0xC0;
            prim->blendMode = 0x31;
            *((s32*)(&prim->r3)) = *((s32*)(&prim->r1));
            prim = prim->next;
            prim->type = 3;
            temp_15 = (u16)self->posX.i.hi;
            prim->x2 = (s16)temp_15;
            prim->x0 = (s16)temp_15;
            temp_16 = (u16)self->posX.i.hi;
            prim->y1 = 0;
            prim->y0 = 0;
            prim->y3 = 0x100;
            prim->y2 = 0x100;
            prim->x3 = (s16)temp_16;
            prim->x1 = (s16)temp_16;
            temp_17 = self->ext.generic.unk94;
            prim->b0 = temp_17;
            prim->g0 = temp_17;
            prim->r0 = temp_17;
            prim->b1 = 0;
            prim->g1 = 0;
            prim->r1 = 0;
            prim->priority = 0xC0;
            prim->blendMode = 0x31;
            *((s32*)(&prim->r2)) = *((s32*)(&prim->r0));
            *((s32*)(&prim->r3)) = *((s32*)(&prim->r1));
            self->ext.dracula.unk8C = 0x20;
            self->step_s++;

        case 4:
            prim = self->ext.dracula.unkAC->next;
            prim->x0 = (prim->x2 = prim->x2 - 2);
            prim = prim->next;
            temp_19 = prim->x3 + 2;
            prim->x3 = temp_19;
            prim->x1 = temp_19;
            if (self->posX.i.hi != (temp_19 - 0x30)) {
                return;
            }
            self->step_s++;
            break;

        case 5: {

            var_a1 = 0;
        }
            temp_20 = self->ext.dracula.unk98 + 4;
            var_a0_2 = self->posX.i.hi - temp_20;
            self->ext.dracula.unk98 = temp_20;
            if (var_a0_2 < 0) {
                var_a1 = 1;
                var_a0_2 = 0;
            }
            prim = self->ext.dracula.unkAC;
            temp_v1_6 = var_a0_2;
            prim->x2 = temp_v1_6;
            prim->x0 = temp_v1_6;
            prim = prim->next;
            temp_21 = temp_v1_6 - 0x30;
            prim->x2 = temp_21;
            prim->x0 = temp_21;
            prim->x1 = (prim->x3 = temp_v1_6);
            var_a0_3 = self->posX.i.hi + self->ext.dracula.unk98;
            if (var_a0_3 > 0x100) {
                var_a1 += 1;
                var_a0_3 = 0x100;
            }
            temp_v1_8 = var_a0_3 + 0x30;
            prim = self->ext.dracula.unkAC;
            prim->x3 = var_a0_3;
            prim->x1 = var_a0_3;
            prim = prim->next;
            prim = prim->next;
            i = (prim->x2 = var_a0_3);
            prim->x0 = i;
            prim->x1 = (prim->x3 = temp_v1_8);
            if (self->unk6C != 0) {
                self->unk6C += 0xF8;
            }
            if (self->ext.generic.unk94 < 0xF0) {
                self->ext.generic.unk94 += 8;
            }
            prim = self->ext.dracula.unkAC;
            prim->r0 = (prim->g0 = (prim->b0 = self->ext.generic.unk94));
            *((s32*)(&prim->r1)) = *((s32*)(&prim->r0));
            *((s32*)(&prim->r2)) = *((s32*)(&prim->r0));
            *((s32*)(&prim->r3)) = *((s32*)(&prim->r0));
            prim = prim->next;
            prim->r0 = (prim->g0 = (prim->b0 = 0));
            *((s32*)(&prim->r2)) = *((s32*)(&prim->r0));
            prim->r1 = (prim->g1 = (prim->b1 = self->ext.generic.unk94));
            *((s32*)(&prim->r3)) = *((s32*)(&prim->r1));
            prim = prim->next;
            prim->r0 = (prim->g0 = (prim->b0 = self->ext.generic.unk94));
            prim->r1 = (prim->g1 = (prim->b1 = 0));
            *((s32*)(&prim->r2)) = *((s32*)(&prim->r0));
            *((s32*)(&prim->r3)) = *((s32*)(&prim->r1));
            if (var_a1 == 2) {
                self->step_s++;
            }

            break;

        case 6:
            prim = self->ext.dracula.unkAC->next;
            while (prim != 0) {
                prim->blendMode = 8;
                prim = prim->next;
            }

            CreateEntityFromCurrentEntity(0x2B, &self[2]);
            self[2].facing = self->facing;
            CreateEntityFromCurrentEntity(0x20, &self[5]);
            self[5].facing = self->facing;
            self[5].posY.i.hi += 2;
            self->step_s++;
            return;

        case 7:
            var_v0_2 = func_801BD88C(self->ext.dracula.unkAC, 7);
            if (var_v0_2 == 0) {
                self->step_s++;
            }
            break;

        case 8:
            if (D_801C2578 == 0) {
                DestroyEntity(self);
                return;
            }
        }

        break;

    case 255:
        if (g_pads[1].pressed & 0x0080) {
            if (self->subId == 0) {
                self->animCurFrame++;
                self->subId |= 1;
            } else {
                break;
            }
        } else {
            self->subId = 0;
        }
        if (g_pads[1].pressed & 0x0020) {
            if (self->step_s == 0) {
                self->animCurFrame--;
                self->step_s |= 1;
                break;
            }
        } else {
            self->step_s = 0;
        }
        break;
    }
}