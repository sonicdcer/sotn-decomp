#include "stage.h"

void CreateEntityFromCurrentEntity(u16, Entity*);
void ReplaceBreakableWithItemDrop(Entity*);
s32 func_801C5D18(Entity* entity, s32 arg1, s32 arg2, s32 arg3);
void func_801C8C84(Entity* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   u8 arg5, s32 arg6);

extern u8 D_8003BE1C[]; // probably part of a struct
extern u8 D_8003BE1D[]; // probably part of a struct
extern u8 D_8003BE20[];
extern s32 D_8003C8B8;
extern u8* D_80180850;
extern u16 D_80180AC4[];
extern u16 D_80180AD0[];
extern u16 D_80180ADC[];
extern u16 D_80180AE8[];
extern u16 D_80180B00[];
extern u16 D_80180B18[];
extern u16* D_80180B90;
extern ObjInit2 D_80180BFC[];
extern s32 D_8018123C;
extern s32 D_80181240;
extern u16 D_8018139C[];
extern u16 D_8018139E[];
extern s32 D_801819D0;
extern s32 D_801819DC;
extern s32 D_801819E8[];
extern s32 D_801819EC[];
extern s16 D_801820C4[];
u8* D_80182438[];
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
extern s32 D_80183C30;
extern s32 D_80183C38;
extern u16* D_80183C44;
extern u16* D_80183C60;
extern LayoutObject* D_801D7110;
extern LayoutObject* D_801D7114;
extern s8 D_801D7118;
extern s8 D_801D711C;
extern s16 D_801D7D30;
extern s16 D_801D7D32;
extern s16 D_801D7D36;
extern s16 D_801D7D60;
extern s16 D_801D7D62;
extern s32 D_801D7D64;
extern s16 D_801D7D2A;
extern u16 D_801D7D2C;
extern s16 D_801D7D2E;
extern s8 D_801D7D3A;
extern s8 D_801D7D3B;
extern LayoutObject* g_pStObjLayout[];
extern PfnEntityUpdate PfnEntityUpdates[];