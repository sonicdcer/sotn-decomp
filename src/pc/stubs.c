#include "pc.h"
#include "dra.h"
#include "memcard.h"

// game.h
GameApi g_api;
u32 g_GameStep;
Pad g_pads[PAD_COUNT];
Stages g_StageId;
s32 g_UseDisk;
u32 g_MenuStep;
DemoMode g_DemoMode;
s32 g_LoadOvlIdx;
s32 g_LoadFile;
u32 g_CdStep;
GameState g_GameState;
Entity g_Entities[TOTAL_ENTITY_COUNT];
unkGraphicsStruct g_unkGraphicsStruct;
Primitive g_PrimBuf[MAX_PRIM_COUNT];
Lba g_StagesLba[0x50];
FgLayer D_8003C708;
s16 D_8003C710;
s16 D_8003C712;
s32 D_8003C728;
s32 D_8003C730;
s32 g_IsUsingCd;
GpuUsage g_GpuUsage;
PlayerStatus g_Status;
u32 g_randomNext;
PlayerState g_Player;
u32 g_GameTimer;
GpuBuffer g_GpuBuffers[2];
s16 g_GpuBuffers_1_buf_draw_clip_y; // member of D_800542FC, TODO
                                    // overlap, hard to remove
GpuBuffer* g_CurrentBuffer;
u32 D_8003C9A4;
s32 D_8003C0F8;
s32 D_800973EC;
s32 D_8003C704;
s32 D_800973EC;
s32 D_8003C73C;
s32 D_8003C99C;
s32 g_PlayableCharacter;
s32 g_backbufferX;
s32 g_backbufferY;
u32 g_Timer;
s32 D_80097904;
s32 D_80097908;
s32 D_8009790C;
s32 D_80097910;
s32 g_LoadOvlIdx;
s32 D_8009791C;
s32 D_80097920;
s32 D_80097924;
s32 D_80097928;
s32 D_8006C3AC;
s32 D_800978C4;
s32 D_80097C98;
u32 D_800A04F8;
SVECTOR* D_800A3210[];
SVECTOR* D_800A33A0[];
SVECTOR* D_800A34C0[18][3];
SVECTOR* D_800A3598[];
SVECTOR* D_800A35D0[];
SVECTOR* D_800A3608[];
u8 D_800A3728;
MATRIX D_800A37B8;
s16 D_80136308[];
u16 g_Clut[];
s32 D_8006C384;
s32 D_8006C388;
MenuNavigation g_MenuNavigation;
GameSettings g_Settings;
s32 D_8006C384;
s32 D_8006C388;
s32 D_8006C38C;
s32 D_8006C390;
u16 D_8003C104[];
s32 D_8003C738;
u8 g_CastleFlags[0x300];
s32 D_8006C374;
s32 D_8006C378;
u16 D_8003C3C2[];
u32 D_80070BCC;
s32 g_Servant;
s32 g_ServantLoaded;
Event g_EvHwCardEnd;
Event g_EvHwCardErr;
Event g_EvHwCardTmo;
Event g_EvHwCardNew;
Event g_EvSwCardEnd;
Event g_EvSwCardErr;
Event g_EvSwCardTmo;
s32 D_80073074;
Event g_EvSwCardNew;
s32 D_8007307C;
s32 D_80073080;
s32 g_IsTimeAttackUnlocked;
Unkstruct_8003C908 D_8003C908;
s32 D_8003C100;
s32 D_800978B4;
u32 g_RoomCount;
char D_80097902[] = "dummy";
s32 D_8003C90C[2] = {0};
MemcardInfo g_MemcardInfo[2];
s32 g_MemcardBlockRead;
s32 g_MemcardStep;
s32 g_MemcardRetryCount;
s32 g_MemcardFd;
u8 g_SaveName[12];
Tilemap g_Tilemap;
u8 g_CastleMap[0x800];
u8 g_saveIcon0[0x180];
u8 g_saveIcon1[0x180];
u8 g_saveIcon2[0x180];
u8 g_saveIcon3[0x180];
u8 g_saveIcon4[0x180];
u8 g_saveIcon5[0x180];
u8 g_saveIcon6[0x180];
u8 g_saveIcon7[0x180];
u8 g_saveIcon8[0x180];
u8 g_saveIcon9[0x180];
u8 g_saveIcon10[0x180];
u8 g_saveIcon11[0x180];
u8 g_saveIcon12[0x180];
u8 g_saveIcon13[0x180];
u8 g_saveIcon14[0x180];
u8 g_saveIcon15[0x180];
u16 g_saveIconPal0[0x10][0x10];
s32 D_8003C0EC[4] = {};
Unkstruct_8006C3C4 D_8006C3C4[32] = {};
GfxLoad g_GfxLoad[0x10] = {};
s16 D_800705CC[0x100];
PlayerDraw g_PlayerDraw[0x10];
s32 D_8013AED0;
DR_ENV D_800974AC;
u32 D_8003C744 = 0;
u32 mocked_800C52F8[0x200] = {0};
PixPattern* D_800C52F8[] = {
    mocked_800C52F8, mocked_800C52F8, mocked_800C52F8, mocked_800C52F8,
    mocked_800C52F8, mocked_800C52F8, mocked_800C52F8, mocked_800C52F8,
    mocked_800C52F8, mocked_800C52F8, mocked_800C52F8, mocked_800C52F8,
    mocked_800C52F8, mocked_800C52F8, mocked_800C52F8, mocked_800C52F8,
    mocked_800C52F8, mocked_800C52F8, mocked_800C52F8, mocked_800C52F8,
    mocked_800C52F8, mocked_800C52F8, mocked_800C52F8, mocked_800C52F8,
    mocked_800C52F8, mocked_800C52F8, mocked_800C52F8, mocked_800C52F8,
    mocked_800C52F8, mocked_800C52F8, mocked_800C52F8, mocked_800C52F8,
};

// dra.h
GpuUsage g_GpuMaxUsage;
GpuBuffer* g_BackBuffer;
s32 g_DebugFreeze;
s32 g_DebugHitboxViewMode;
u32 D_801362B4;
u32 g_DebugCurPal;
s32 D_801362D4;
RoomTeleport D_800A245C[];
s32 D_8013640C;
s32 D_800974A4;
u32* g_CurrentOT;
s32 D_801362B8;
s32 D_801362BC;
s32 g_DebugPlayer;
Vram g_Vram;
s32 g_softResetTimer;
DebugMode g_DebugMode;
s32 g_DebugPalIdx;
DebugColorChannel g_DebugColorChannel;
u32 D_801362C8;
s32 g_DebugIsRecordingVideo;
s32 g_DebugWaitInfoTimer;
s32 g_DebugRecordVideoFid;
u8 D_8013B6A0[] = {0}; // VAB file
u8 D_8017D350[] = {0}; // VAB file
u8 D_8018B4E0[] = {0}; // VAB file
u8 D_801A9C80[] = {0}; // VAB file
u8 aPbav[] = {0};      // VAB file?
u8 aPbav_0[] = {0};    // VAB file?
u8 aPbav_1[] = {0};    // VAB file?
u8 aPbav_2[] = {0};    // VAB file?
u8 aPqes[] = {0};      // SEQ file
u8 aPqes_0[] = {0};    // SEQ file
u8 aPqes_1[] = {0};    // SEQ file
s32 D_801362D0[];
s32 D_800987B4;
u8 g_PadsRepeatTimer[BUTTON_COUNT * PAD_COUNT];
s32 D_80136410;
s32 D_80136414[];
s32 D_801375C0;
s32 D_801375C4;
s32 D_801375C8;
ItemTypes D_801375CC;
s32 D_801375D0;
s32 D_801375D4;
s32* D_801375D8;
s32 D_801375DC[0];
s32 D_801375E0[8];
s32 D_801375FC;
s32 D_80137608;
s32 g_IsCloakLiningUnlocked;
s32 g_IsCloakColorUnlocked;
s32 g_IsSelectingEquipment;
s32 g_EquipmentCursor;
s32 D_80137614;
s32 g_EquipOrderType;
MenuData g_MenuData = {0};
u8 D_801376B0;
s16 D_801376C4;
s16 D_801376C8;
MenuContext g_JosephsCloakContext;
s32 D_8013783C;
s32 D_801377FC[0x10];
s32 D_80137840;
s32 D_80137844[];
s32 D_80137848[];
s32 D_8013784C;
s16 g_RelicMenuFadeTimer;
s32 g_TimeAttackEntryTimes[];
s32 c_strTimeAttackEntry[];
s32 c_strTimeAttackGoals[];
s32 g_NewAttackRightHand;
s32 g_NewAttackLeftHand;
s32 g_NewDefenseEquip;
s32 g_NewPlayerStatsTotal[];
s32 D_80137948;
s8* D_8013794C; // Pointer to texture pattern
s32 D_80137950;
s32 D_80137954;
s32 D_80137958;
s32 g_ServantPrevious;
s32 D_80137960;
s32 D_80137964;
s32 D_80137968;
VECTOR D_801379E0;
VECTOR D_80137B20;
SVECTOR D_80137CA0;
SVECTOR D_80137D40;
SVECTOR D_80137E70[];
s32 D_80137EE0;
s32 D_80139824;
s32 D_80139828[];
s32 D_8013982C;
s32 D_80139830[];
s32 D_8013983C;
s32 D_80139840;
s32 D_80139844;
s32 D_80139848;
s32 D_8013984C;
s32 D_80139850;
s32 D_80139854;
u16 D_80137538[32];
GfxBank g_FakeGfxBank = {0};
GfxBank** g_GfxSharedBank[] = {
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
    &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank, &g_FakeGfxBank,
};
u8* g_DecSrcPtr = NULL;
u8* g_DecDstPtr = NULL;
s32 g_DecReadNibbleFlag = 0;
s32 g_DecWriteNibbleFlag = 0;
u8 g_GfxEquipIcon[32][16 * 16 / 2] = {0};
s16 g_PalEquipIcon[32] = {0};
UnkStructClut g_FakeUnkStruct = {0};
UnkStructClut* D_800A3BB8[] = {
    &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct,
    &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct,
    &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct,
    &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct,
    &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct,
    &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct,
    &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct,
    &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct, &g_FakeUnkStruct,
    &g_FakeUnkStruct, &g_FakeUnkStruct,
};
u16 D_80137478[0x20];
u16 D_801374B8[0x20];
u16 D_801374F8[0x20];
u16 D_80137538[0x20];
u8* D_80137590;
s32 D_80137594;
u32 g_DisplayHP[];
s32 D_80137970;
s32 D_80137974;
u32 D_80137978;
u32 D_8013797C;
s32 D_80137980;
s32 D_80137984;
u32 D_80137988;
u32 D_8013798C;
Unkstruct_80137990 D_80137990;
u32 D_800AC90C = 0x000F423F;
s32 D_8013B5E8;
s32 g_HealingMailTimer[1] = {0};
s32 D_8013B5E8;
s32 D_80137994;
s32 D_80139008;
s32 D_801397FC;

JosephsCloak g_JosephsCloak;
u8 g_Pix[4][128 * 128 / 2];
const char dummy[] = "dummy\xFF";
const char* c_strALUCARD[] = {"dummy"};
const char* c_strGOLD[] = {"dummy"};
const char* c_strButtonRightHand[] = {
    "x\xFF", "x\xFF", "x\xFF", "x\xFF", "x\xFF", "x\xFF", "x\xFF", "x\xFF"};
const char* D_800A83AC[] = {"x"};
const char* c_strSTR[] = {dummy, dummy, dummy, dummy};
const char* c_strCON = "xxx";
const char* c_strINT = "xxx";
const char* c_strLCK = "xxx";
const char* c_strEXP = "xxx";
const char* c_strNEXT = "xxxx";
const char* c_strLEVEL = "dummy";
const char* c_strTIME = "xxx";
const char* c_strROOMS = "dummy";
const char* c_strKILLS = "dummy";
const char* c_strHP = "xx";
const char* c_strMP = "xx";
const char* c_strHEART = "dummy";
const char* c_strSTATUS = "dummy";
const char* c_strButton = "dummy";
const char* c_strCloak = "dummy";
const char* c_strCloak2 = "dummy";
const char* c_strExterior = "dummy";
const char* c_strLining = "dummy";
const char* c_strButtonLeftHand = "dummy";
const char* c_strButtonJump = "dummy";
const char* c_strButtonSpecial = "dummy";
const char* c_strButtonWolf = "dummy";
const char* c_strButtonMist = "dummy";
const char* c_strButtonBat = "dummy";
const char* c_strNormal = "dummy";
const char* c_strReversal = "dummy";
const char* c_strSound = "dummy";
const char* c_strStereo = "dummy";
const char* c_strMono = "dummy";
const char* c_strWindow = "dummy";
const char* c_strTime = "dummy";
const char* c_strALUCART = "dummy";
const char* c_strSSword[] = {
    dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,
};
const char* g_WingSmashComboStr = "dummy";
const char* c_strEquip = "dummy";
const char* c_strSpells = "dummy";
const char* c_strRelics = "dummy";
const char* c_strSystem = "dummy";
const char* c_strFamiliars = "dummy";
const char* c_strFamiliar = "dummy";
const char* c_strSpecial2 = "dummy";
u8* c_strTimeAttackHiddenEntry = "dummy";
const char* c_strTimeAttackEntries[] = {
    dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,
    dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,
    dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,
    dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,
    dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,
    dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy, dummy,
};
ImgSrc* g_imgUnk8013C200_impl = {
    0,
    0,
    0,
    NULL,
};
ImgSrc* g_imgUnk8013C200 = &g_imgUnk8013C200_impl;
ImgSrc* g_imgUnk8013C270 = &g_imgUnk8013C200_impl;
s32 g_ExpNext[100] = {0};
s32 g_PrevEquippedWeapons[2];
s32 D_8013AEE4;
s32 D_800A3194[];
s32 D_80139060;
u32 D_8013799C;
s32 D_801379A0;
s32 D_801379A4;
s32 D_801379A8;
Unkstruct_80102CD8 D_801379AC;
s32 D_801379B0;
SVECTOR D_801379C8;
VECTOR D_801379D0;
MATRIX D_80137E00;
MATRIX D_80137E20;
s32 D_80137E40;
s32 D_80137E44;
s32 D_80137E48;
s32 D_80137E4C;
s32 g_MemCardRetryCount;
s32 D_80137E54;
s32 D_80137E58;
s32 D_80137E5C;
s32 D_80137E60;
s32 g_MemCardRStep;
s32 g_MemCardRStepSub;
s32 D_80137E6C;
s32 D_80137F6C;

// sound bss
s16 g_SoundCommandRingBufferReadPos;
s16 g_SoundCommandRingBufferWritePos;
s16 D_80139804;
s16 D_8013B664;
s16 D_80139A6C;
s16 g_CurrentXaSoundId;
s16 D_8013901C;
s16 g_SoundCommandRingBuffer[MAX_SND_COUNT];
s16 g_VolL;
s16 g_VolR;
s16 D_8013AE94;
u16 D_8013AEE0;
Unkstruct_800BF554 g_SfxData[];
u16 D_8013AE7C;
s16 D_801390A4;
s16 D_80139010;
s8 D_8013B690;
s16 D_8013B678[];
s16 D_8013B648[4];
s16 D_8013AEA0[4];
s32 D_8013B628[4];
u8 D_8013B5EC[4];
s16 D_8013B66C[4];
s8 g_UnkChannelSetting1[4];
s16 g_ChannelGroupVolume[4];
s16 g_UnkChannelSetting2[4];
s32 D_801390B4[];
s8 D_80139018[];
s16 D_80139814[];
s8 D_80139058[];
s16 D_801390AC[];
s32 D_8013B61C;
s32 D_8013980C;
s16 g_sfxRingBufferWritePos;
SfxRingBufferItem g_SfxRingBuffer[MAX_SND_COUNT];
u8 g_SoundInitialized;
s32 g_KeyOffChannels;
SpuVoiceAttr* D_80138FB4;
SpuVoiceAttr* D_801390C8;
SpuVoiceAttr* D_801390CC;
u8 D_801390A0;
volatile unsigned char g_CdSoundCommandStep;
s16 g_CdVolume;
s16 g_XaMusicVolume;
s16 D_80139A78;
s16 g_volumeL;
s16 g_volumeR;
u8 g_CdSoundCommand16;
u8 D_80139014;
struct Cmd14 D_8013B5F4[];
s32 D_8013AE90;
s32 D_8013AEF4;
u8 g_CdCommandResult[];
u8 D_8013B688[];
u8 g_CdMode[3];

// TODO
struct XaMusicConfig g_XaMusicConfigs[6] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3417, 0, 0, 80, 0, 1, 0, 0, 0},
    {8544, 5011, 0, 0, 80, 0, 0, 0, 0, 0},
    {21072, 8022, 10, 0, 64, 0, 1, 0, 0, 0},
    {41128, 3987, 10, 0, 64, 0, 0, 0, 0, 0},
    {51096, 7692, 20, 0, 84, 0, 1, 0, 0, 0}};

s8 D_801390C4;
u8 g_SeqPlayingId;
s16 g_SeqAccessNum;
volatile s16 g_CdSoundCommandQueuePos;
s16 g_SeqVolume1;
s16 g_SeqVolume2;
u8 g_ReverbDepth;
s32 g_SeqPointers[0xA];
s16 D_8013845C;
u8 D_8013B640[3];
s32 g_CurCdPos;
s16 g_CurrentXaConfigId;
s16 g_CdSoundCommandQueue[MAX_SND_COUNT];
s8 D_8013AEE8;
u8 D_801390D8;
char g_SeqTable[SS_SEQ_TABSIZ * SEQ_TABLE_S_MAX * SEQ_TABLE_T_MAX];
u8 D_801390A8;
s32 D_8013B694;
u8 g_MuteCd;
s32 D_80138F7C;
u8 D_8013B680;
s8 D_8013B618;
s16 D_80138F80;
s16 D_80139800;
s16 D_80138FBC;
s32 D_8013B69C;
s16 D_80139A74;
s16 g_SfxRingBufferReadPos;
s32 D_80138454;
s16 D_8013AED4[4];
s16 D_8013B650[4];
s32 g_CdCommandStatus;
const char* D_80138784[0x800];
s32 D_800C1ECC[];

// sound stubs
void func_801327B4(int arg0, int arg1, int vabId, int prog, int tone, int note,
                   int g_VolL, int g_VolR) {
    NOT_IMPLEMENTED;
}

void func_80133FCC(void) { NOT_IMPLEMENTED; }

void func_80135D8C() { NOT_IMPLEMENTED; }

s32 func_80136010(void) {
    NOT_IMPLEMENTED;
    return 0;
}

void func_8013572C(int sndId, int unk02, int unk04) { NOT_IMPLEMENTED; }

void func_801073C0(void) { NOT_IMPLEMENTED; }

s32 LoadFileSim(s32 fileId, SimFileType type) {
    NOT_IMPLEMENTED;
    return 0;
}

void func_800EA7CC(void) { NOT_IMPLEMENTED; }

void VSyncHandler(void) { NOT_IMPLEMENTED; }

void RenderEntities(void) { NOT_IMPLEMENTED; }

void RenderTilemap(void) { NOT_IMPLEMENTED; }

void UpdateCd(void) { NOT_IMPLEMENTED; }

int CdInit(void) {
    NOT_IMPLEMENTED;
    return 0;
}

void func_8010DFF0(s32 arg0, s32 arg1) { NOT_IMPLEMENTED; }

void func_800F2120(void) { NOT_IMPLEMENTED; }

s32 func_800F16D0(void) { NOT_IMPLEMENTED; }

void func_800E5D30(void* arg0, u16 arg1, u16 arg2, s32 arg3) {
    NOT_IMPLEMENTED;
}

void func_801083BC(void) { NOT_IMPLEMENTED; }

void DrawRichterHudSubweapon(void) { NOT_IMPLEMENTED; }

void func_8010A234(s32 arg0) { NOT_IMPLEMENTED; }

s32 func_800FB23C(MenuNavigation* nav, u8* order, u8* count, u32* selected) {
    NOT_IMPLEMENTED;
    return 0;
}

void AddToInventory(u16 itemId, s32 itemCategory) { NOT_IMPLEMENTED; }

Entity* GetFreeEntity(s16 start, s16 end);
Entity* CreateEntFactoryFromEntity(
    Entity* source, u32 factoryParams, s32 arg2_raw) {
    return GetFreeEntity(8, 16);
}

u16 g_FontCharData[0x60] = {1, 1, 1, 0, 0, 0};
u16* func_80106A28(u32 arg0, u16 kind) {
    NOT_IMPLEMENTED;
    return g_FontCharData;
}

// copied from 75F54.c
Entity* GetFreeEntity(s16 start, s16 end) {
    Entity* entity = &g_Entities[start];
    s16 i;

    for (i = start; i < end; i++, entity++) {
        if (entity->entityId == E_NONE) {
            return entity;
        }
    }
    return NULL;
}