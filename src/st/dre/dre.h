#include "stage.h"

void ReplaceBreakableWithItemDrop(Entity_*arg0);
void DestroyEntity(Entity_*entity);
void func_80198F18(s16);
void func_80199014(s16);
void func_801991CC(s16);
void func_801992C8(s16);
void func_801A046C(u16);
s32 func_8019AC78(u8, s16);
void PreventEntityFromRespawning(Entity_*entity);
void FallEntity(void);
void func_8019B858(void);
void CreateEntityFromCurrentEntity(u16 objectId, Entity_*entity);
Entity_*AllocEntity(Entity_*, Entity_*);
void func_8019A78C(void);
Entity_*func_8019AC18(Entity_*, Entity_*);
void func_8019E5E0(Entity_*entity);
void EntityEquipItemDrop(Entity_*);

extern u16 D_80180464[];
extern u16 D_80180494[];
extern u16 D_801804A0[];
extern u16 D_80180500[];
extern u8 D_80180580[];
extern u8 D_80180588[];
extern u16 D_80180590[];
extern u16 D_80180660[];
extern s32 D_80180664;
extern const u8 D_80180794[];
extern u16 D_8018097C[];
extern s16 D_80180D80[];
extern LayoutObject* D_801A32C4;
extern LayoutObject* D_801A32C8;
extern u16 D_801804AC[];
extern u16 D_80180470[];
extern s8 c_HeartPrizes[];
extern s32 D_801811B0[];
extern u32 D_8018125C[];
extern s16 D_801812E4[];
extern u32 D_801812F4[];
extern u8 D_80181338;
extern PfnEntityUpdate D_801803C4[];
extern u16 D_801804E8[];
extern u16 D_8018050C[];
extern u16 D_80180528[];
extern s32 D_80180664;
extern s32 D_80180668;
extern s16 D_801807F0[];
extern u16 D_801811A4[];
extern u32 D_8018130C[];
extern u8 D_80181324[];
extern u16 D_80181328[];
extern s16 D_801A3EDE;
extern u16 D_801A3EE0;
extern s16 D_801A3EE2;
extern s16 D_801A3EE4;
extern s16 D_801A3EE6;
extern s16 D_801A3EEA;
extern s8 D_801A3EEE;
extern s8 D_801A3EEF;
extern s16 D_801A3F14;
extern s16 D_801A3F16;
extern s32 D_801A3F18;
extern u16 D_801A3F8C[];