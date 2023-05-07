#include "stage.h"

extern void CreateEntityFromCurrentEntity(u16, Entity*);
extern void ReplaceBreakableWithItemDrop(Entity*);
extern s32 func_801C5D18(Entity*entity, s32 arg1, s32 arg2, s32 arg3);
extern void func_801C8C84(Entity*arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                          u8 arg5, s32 arg6);
extern void func_801CAD28(s32);
extern POLY_GT4* func_801D6DB8(POLY_GT4* poly);
void EntityEquipItemDrop(Entity*);

extern u8* D_80180850;
extern u16 D_80180AB8[];
extern u16 D_80180AC4[];
extern u16 D_80180AD0[];
extern u16 D_80180ADC[];
extern u16 D_80180AE8[];
extern u16 D_80180B00[];
extern u16 D_80180B18[];
extern u16 D_80180B48[];
extern u16 D_80180B54[];
extern u16 D_80180B6C[];
extern u16 D_80180B84[];
extern u16* D_80180B90;
extern u16 D_80180BA8[];
extern ObjInit2 D_80180BFC[];
extern u16 D_80181230[];
extern s32 g_TrapDoorFlag; // 0 = Closed, 1 = Open
extern s32 D_80181240;
extern u16 D_80181258[];
extern u16 D_80181264[];
extern u16 D_8018127C[];
extern u16 D_80181294[];
extern u16 D_801812A0[];
extern u16 D_801812B8[];
extern u16 D_801812E2[];
extern u16 D_8018131E[];
extern u16 D_8018133C[];
extern u8 D_80181344[];
extern const u8 D_80181390[];
extern u16 D_8018139C[];
extern u16 D_8018139E[];
extern s32 D_801819D0;
extern s32 D_801819DC;
extern s32 D_801819E8[];
extern s32 D_801819EC[];
extern s32 D_80181B40;
extern u8* D_80181B4C;
extern u16 D_80181C8C[];
extern u16 D_80181CC0[];
extern s16 D_801820C4[];
extern u8* D_80182438[];
extern u16 D_80182424[];
extern u8* D_80182488[];
extern u16 D_801824E8[];
extern s32 D_801824F4[];
extern u8* D_801825A0[];
extern u16 D_80182628[];
extern s32 D_80182650[];
extern u8 D_80182668[];
extern u16 D_8018266C[];
extern s32 D_80182638[];
extern u8 D_8018267C[];
extern ObjInit2 D_80182764[];
extern s32 c_GoldPrizes[];
extern u8 D_80183994[];
extern const u8 D_801839A0[];
extern u8 D_801839A8;
extern u8* D_801839B0;
extern u16* D_80183AF0;
extern s16 D_80183BA8[];
extern s32 D_80183C30;
extern s32 D_80183C38;
extern u16* D_80183C44;
extern u16* D_80183C60;
extern u8 D_80183C7C[];
extern u8 D_80183C84[];
extern u8 D_80183C98[];
extern s32 D_80183CAC;
extern s32 D_80183CBC;
extern LayoutObject* D_801D7110;
extern LayoutObject* D_801D7114;
extern s8 D_801D7118;
extern s8 D_801D711C;
extern s32 D_801D7D20;
extern s16 D_801D7D2A;
extern u16 D_801D7D2C;
extern s16 D_801D7D2E;
extern s16 D_801D7D30;
extern s16 D_801D7D32;
extern s16 D_801D7D36;
extern s8 D_801D7D3A;
extern s8 D_801D7D3B;
extern s32 D_801D7D54;
extern s32 D_801D7D58;
extern s16 D_801D7D60;
extern s16 D_801D7D62;
extern s32 D_801D7D64;
extern u16 D_801D7DD8[];
extern LayoutObject* g_pStObjLayout[];
extern PfnEntityUpdate PfnEntityUpdates[];
