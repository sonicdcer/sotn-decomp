typedef enum ItemSlots {
    /* 0 */ LEFT_HAND_SLOT,
    /* 1 */ RIGHT_HAND_SLOT,
    /* 2 */ HEAD_SLOT,
    /* 3 */ ARMOR_SLOT,
    /* 4 */ CAPE_SLOT,
    /* 5 */ ACCESSORY_1_SLOT,
    /* 6 */ ACCESSORY_2_SLOT,
} ItemSlots;

typedef enum ItemTypes {
    /* 0 */ HAND_TYPE,
    /* 1 */ HEAD_TYPE,
    /* 2 */ ARMOR_TYPE,
    /* 3 */ CAPE_TYPE,
    /* 4 */ ACCESSORY_TYPE,
} ItemTypes;

typedef enum EquipmentItems {
    /* Hand Items */
    /* 0x000 */ ITEM_EMPTY_HAND,
    /* 0x001 */ ITEM_MONSTER_VIAL_1,
    /* 0x002 */ ITEM_MONSTER_VIAL_2,
    /* 0x003 */ ITEM_MONSTER_VIAL_3,
    /* 0x004 */ ITEM_SHIELD_ROD,
    /* 0x005 */ ITEM_LEATHER_SHIELD,
    /* 0x006 */ ITEM_KNIGHT_SHIELD,
    /* 0x007 */ ITEM_IRON_SHIELD,
    /* 0x008 */ ITEM_AXELORD_SHIELD,
    /* 0x009 */ ITEM_HERALD_SHIELD,
    /* 0x00A */ ITEM_DARK_SHIELD,
    /* 0x00B */ ITEM_GODDESS_SHIELD,
    /* 0x00C */ ITEM_SHAMAN_SHIELD,
    /* 0x00D */ ITEM_MEDUSA_SHIELD,
    /* 0x00E */ ITEM_SKULL_SHIELD,
    /* 0x00F */ ITEM_FIRE_SHIELD,
    /* 0x010 */ ITEM_ALUCARD_SHIELD,
    /* 0x011 */ ITEM_SWORD_OF_DAWN,
    /* 0x012 */ ITEM_BASILARD,
    /* 0x013 */ ITEM_SHORT_SWORD,
    /* 0x014 */ ITEM_COMBAT_KNIFE,
    /* 0x015 */ ITEM_NUNCHAKU,
    /* 0x016 */ ITEM_WERE_BANE,
    /* 0x017 */ ITEM_RAPIER,
    /* 0x018 */ ITEM_KARMA_COIN,
    /* 0x019 */ ITEM_MAGIC_MISSILE,
    /* 0x01A */ ITEM_RED_RUST,
    /* 0x01B */ ITEM_TAKEMITSU,
    /* 0x01C */ ITEM_SHOTEL,
    /* 0x01D */ ITEM_ORANGE,
    /* 0x01E */ ITEM_APPLE,
    /* 0x01F */ ITEM_BANANA,
    /* 0x020 */ ITEM_GRAPES,
    /* 0x021 */ ITEM_STRAWBERRY,
    /* 0x022 */ ITEM_PINEAPPLE,
    /* 0x023 */ ITEM_PEANUTS,
    /* 0x024 */ ITEM_TOADSTOOL,
    /* 0x025 */ ITEM_SHIITAKE,
    /* 0x026 */ ITEM_CHEESECAKE,
    /* 0x027 */ ITEM_SHORTCAKE,
    /* 0x028 */ ITEM_TART,
    /* 0x029 */ ITEM_PARFAIT,
    /* 0x02A */ ITEM_PUDDING,
    /* 0x02B */ ITEM_ICE_CREAM,
    /* 0x02C */ ITEM_FRANKFURTER,
    /* 0x02D */ ITEM_HAMBURGER,
    /* 0x02E */ ITEM_PIZZA,
    /* 0x02F */ ITEM_CHEESE,
    /* 0x030 */ ITEM_HAM_AND_EGGS,
    /* 0x031 */ ITEM_OMELETTE,
    /* 0x032 */ ITEM_MORNING_SET,
    /* 0x033 */ ITEM_LUNCH_A,
    /* 0x034 */ ITEM_LUNCH_B,
    /* 0x035 */ ITEM_CURRY_RICE,
    /* 0x036 */ ITEM_GYROS_PLATE,
    /* 0x037 */ ITEM_SPAGHETTI,
    /* 0x038 */ ITEM_GRAPE_JUICE,
    /* 0x039 */ ITEM_BARLEY_TEA,
    /* 0x03A */ ITEM_GREEN_TEA,
    /* 0x03B */ ITEM_NATOU,
    /* 0x03C */ ITEM_RAMEN,
    /* 0x03D */ ITEM_MISO_SOUP,
    /* 0x03E */ ITEM_SUSHI,
    /* 0x03F */ ITEM_PORK_BUN,
    /* 0x040 */ ITEM_RED_BEAN_BUN,
    /* 0x041 */ ITEM_CHINESE_BUN,
    /* 0x042 */ ITEM_DIM_SUM_SET,
    /* 0x043 */ ITEM_POT_ROAST,
    /* 0x044 */ ITEM_SIRLION,
    /* 0x045 */ ITEM_TURKEY,
    /* 0x046 */ ITEM_MEAL_TICKET,
    /* 0x047 */ ITEM_NEUTRON_BOMB,
    /* 0x048 */ ITEM_POWER_OF_SIRE,
    /* 0x049 */ ITEM_PENTAGRAM,
    /* 0x04A */ ITEM_BAT_PENTAGRAM,
    /* 0x04B */ ITEM_SHURIKEN,
    /* 0x04C */ ITEM_CROSS_SHURIKEN,
    /* 0x04D */ ITEM_BUFFALO_STAR,
    /* 0x04E */ ITEM_FLAME_STAR,
    /* 0x04F */ ITEM_TNT,
    /* 0x050 */ ITEM_BWAKA_KNIFE,
    /* 0x051 */ ITEM_BOOMERANG,
    /* 0x052 */ ITEM_JAVELIN,
    /* 0x053 */ ITEM_TYRFING,
    /* 0x054 */ ITEM_NAMAKURA,
    /* 0x055 */ ITEM_KNUCKLE_DUSTER,
    /* 0x056 */ ITEM_GLADIUS,
    /* 0x057 */ ITEM_SCIMITAR,
    /* 0x058 */ ITEM_CUTLASS,
    /* 0x059 */ ITEM_SABER,
    /* 0x05A */ ITEM_FALCHION,
    /* 0x05B */ ITEM_BROADSWORD,
    /* 0x05C */ ITEM_BEKATOWA,
    /* 0x05D */ ITEM_DAMASCUS_SWORD,
    /* 0x05E */ ITEM_HUNTER_SWORD,
    /* 0x05F */ ITEM_ESTOC,
    /* 0x060 */ ITEM_BASTARD_SWORD,
    /* 0x061 */ ITEM_JEWEL_KNUCKLES,
    /* 0x062 */ ITEM_CLAYMORE,
    /* 0x063 */ ITEM_TALWAR,
    /* 0x064 */ ITEM_KATANA,
    /* 0x065 */ ITEM_FLAMBERGE,
    /* 0x066 */ ITEM_IRON_FIST,
    /* 0x067 */ ITEM_ZWEIHANDER,
    /* 0x068 */ ITEM_SWORD_OF_HADOR,
    /* 0x069 */ ITEM_LUMINUS,
    /* 0x06A */ ITEM_HARPER,
    /* 0x06B */ ITEM_OBSIDIAN_SWORD,
    /* 0x06C */ ITEM_GRAM,
    /* 0x06D */ ITEM_JEWEL_SWORD,
    /* 0x06E */ ITEM_MORMEGIL,
    /* 0x06F */ ITEM_FIREBRAND,
    /* 0x070 */ ITEM_THUNDERBRAND,
    /* 0x071 */ ITEM_ICEBRAND,
    /* 0x072 */ ITEM_STONE_SWORD,
    /* 0x073 */ ITEM_HOLY_SWORD,
    /* 0x074 */ ITEM_TERMINUS_EST,
    /* 0x075 */ ITEM_MARSIL,
    /* 0x076 */ ITEM_DARK_BLADE,
    /* 0x077 */ ITEM_HEAVEN_SWORD,
    /* 0x078 */ ITEM_FIST_OF_TULKAS,
    /* 0x079 */ ITEM_GURTHANG,
    /* 0x07A */ ITEM_MOURNEBLADE,
    /* 0x07B */ ITEM_ALUCARD_SWORD,
    /* 0x07C */ ITEM_MABLUNG_SWORD,
    /* 0x07D */ ITEM_BADELAIRE,
    /* 0x07E */ ITEM_SWORD_FAMILIAR,
    /* 0x07F */ ITEM_GREAT_SWORD,
    /* 0x080 */ ITEM_MACE,
    /* 0x081 */ ITEM_MORNINGSTAR,
    /* 0x082 */ ITEM_HOLY_ROD,
    /* 0x083 */ ITEM_STAR_FLAIL,
    /* 0x084 */ ITEM_MOON_ROD,
    /* 0x085 */ ITEM_CHAKRAM,
    /* 0x086 */ ITEM_FIRE_BOOMERANG,
    /* 0x087 */ ITEM_IRON_BALL,
    /* 0x088 */ ITEM_HOLBEIN_DAGGER,
    /* 0x089 */ ITEM_BLUE_KNUCKLES,
    /* 0x08A */ ITEM_DYNAMITE,
    /* 0x08B */ ITEM_OSAFUNE_KATANA,
    /* 0x08C */ ITEM_MASAMUNE,
    /* 0x08D */ ITEM_MURAMASA,
    /* 0x08E */ ITEM_HEART_REFRESH,
    /* 0x08F */ ITEM_RUNESWORD,
    /* 0x090 */ ITEM_ANTIVENOM,
    /* 0x091 */ ITEM_UNCURSE,
    /* 0x092 */ ITEM_LIFE_APPLE,
    /* 0x093 */ ITEM_HAMMER,
    /* 0x094 */ ITEM_STR_POTION,
    /* 0x095 */ ITEM_LUCK_POTION,
    /* 0x096 */ ITEM_SMART_POTION,
    /* 0x097 */ ITEM_ATTACK_POTION,
    /* 0x098 */ ITEM_SHIELD_POTION,
    /* 0x099 */ ITEM_RESIST_FIRE,
    /* 0x09A */ ITEM_RESIST_THUNDER,
    /* 0x09B */ ITEM_RESIST_ICE,
    /* 0x09C */ ITEM_RESIST_STONE,
    /* 0x09D */ ITEM_RESIST_HOLY,
    /* 0x09E */ ITEM_RESIST_DARK,
    /* 0x09F */ ITEM_POTION,
    /* 0x0A0 */ ITEM_HIGH_POTION,
    /* 0x0A1 */ ITEM_ELIXIR,
    /* 0x0A2 */ ITEM_MANNA_PRISM,
    /* 0x0A3 */ ITEM_VORPAL_BLADE,
    /* 0x0A4 */ ITEM_CRISSAEGRIM,
    /* 0x0A5 */ ITEM_YASUTSUNA,
    /* 0x0A6 */ ITEM_LIBRARY_CARD,
    /* 0x0A7 */ ITEM_ALUCART_SHIELD,
    /* 0x0A8 */ ITEM_ALUCART_SWORD,

    /* Armor Items */
    /* 0x0A9 */ ITEM_NO_ARMOR,
    /* 0x0AA */ ITEM_CLOTH_TUNIC,
    /* 0x0AB */ ITEM_HIDE_CUIRASS,
    /* 0x0AC */ ITEM_BRONZE_CUIRASS,
    /* 0x0AD */ ITEM_IRON_CUIRASS,
    /* 0x0AE */ ITEM_STEEL_CUIRASS,
    /* 0x0AF */ ITEM_SILVER_PLATE,
    /* 0x0B0 */ ITEM_GOLD_PLATE,
    /* 0x0B1 */ ITEM_PLATINUM_MAIL,
    /* 0x0B2 */ ITEM_DIAMOND_PLATE,
    /* 0x0B3 */ ITEM_FIRE_MAIL,
    /* 0x0B4 */ ITEM_LIGHTNING_MAIL,
    /* 0x0B5 */ ITEM_ICE_MAIL,
    /* 0x0B6 */ ITEM_MIRROR_CUIRASS,
    /* 0x0B7 */ ITEM_SPIKE_BREAKER,
    /* 0x0B8 */ ITEM_ALUCARD_MAIL,
    /* 0x0B9 */ ITEM_DARK_ARMOR,
    /* 0x0BA */ ITEM_HEALING_MAIL,
    /* 0x0BB */ ITEM_HOLY_MAIL,
    /* 0x0BC */ ITEM_WALK_ARMOR,
    /* 0x0BD */ ITEM_BRILLIANT_MAIL,
    /* 0x0BE */ ITEM_MOJO_MAIL,
    /* 0x0BF */ ITEM_FURY_PLATE,
    /* 0x0C0 */ ITEM_DRACULA_TUNIC,
    /* 0x0C1 */ ITEM_GODS_GARB,
    /* 0x0C2 */ ITEM_AXE_LORD_ARMOR,

    /* Head Items */
    /* 0x0C3 */ ITEM_EMPTY_HEAD,
    /* 0x0C4 */ ITEM_SUNGLASSES,
    /* 0x0C5 */ ITEM_BALLROOM_MASK,
    /* 0x0C6 */ ITEM_BANDANNA,
    /* 0x0C7 */ ITEM_FELT_HAT,
    /* 0x0C8 */ ITEM_VELVET_HAT,
    /* 0x0C9 */ ITEM_GOGGLES,
    /* 0x0CA */ ITEM_LEATHER_HAT,
    /* 0x0CB */ ITEM_HOLY_GLASSES,
    /* 0x0CC */ ITEM_STEEL_HELM,
    /* 0x0CD */ ITEM_STONE_MASK,
    /* 0x0CE */ ITEM_CIRCLET,
    /* 0x0CF */ ITEM_GOLD_CIRCLET,
    /* 0x0D0 */ ITEM_RUBY_CIRCLET,
    /* 0x0D1 */ ITEM_OPAL_CIRCLET,
    /* 0x0D2 */ ITEM_TOPAZ_CIRCLET,
    /* 0x0D3 */ ITEM_BERYL_CIRCLET,
    /* 0x0D4 */ ITEM_CAT_EYE_CIRCLET,
    /* 0x0D5 */ ITEM_CORAL_CIRCLET,
    /* 0x0D6 */ ITEM_DRAGON_HELM,
    /* 0x0D7 */ ITEM_SILVER_CROWN,
    /* 0x0D8 */ ITEM_WIZARD_HAT,

    /* Cape Items */
    /* 0x0D9 */ ITEM_NO_CAPE,
    /* 0x0DA */ ITEM_CLOTH_CAPE,
    /* 0x0DB */ ITEM_REVERSE_CLOAK,
    /* 0x0DC */ ITEM_ELVEN_CLOAK,
    /* 0x0DD */ ITEM_CRYSTAL_CLOAK,
    /* 0x0DE */ ITEM_ROYAL_CLOAK,
    /* 0x0DF */ ITEM_BLOOD_CLOAK,
    /* 0x0E0 */ ITEM_JOSEPHS_CLOAK,
    /* 0x0E1 */ ITEM_TWILIGHT_CLOAK,

    /* Accessory Items */
    /* 0x0E2 */ ITEM_NO_ACCESSORY,
    /* 0x0E3 */ ITEM_MOONSTONE,
    /* 0x0E4 */ ITEM_SUNSTONE,
    /* 0x0E5 */ ITEM_BLOODSTONE,
    /* 0x0E6 */ ITEM_STAUROLITE,
    /* 0x0E7 */ ITEM_RING_OF_PALES,
    /* 0x0E8 */ ITEM_ZIRCON,
    /* 0x0E9 */ ITEM_AQUAMARINE,
    /* 0x0EA */ ITEM_TURQUOISE,
    /* 0x0EB */ ITEM_ONYX,
    /* 0x0EC */ ITEM_GARNET,
    /* 0x0ED */ ITEM_OPAL,
    /* 0x0EE */ ITEM_DIAMOND,
    /* 0x0EF */ ITEM_LAPIS_LAZULI,
    /* 0x0F0 */ ITEM_RING_OF_ARES,
    /* 0x0F1 */ ITEM_GOLD_RING,
    /* 0x0F2 */ ITEM_SILVER_RING,
    /* 0x0F3 */ ITEM_RING_OF_VARDA,
    /* 0x0F4 */ ITEM_RING_OF_ARCANA,
    /* 0x0F5 */ ITEM_MYSTIC_PENDANT,
    /* 0x0F6 */ ITEM_HEART_BROACH,
    /* 0x0F7 */ ITEM_NECKLACE_OF_J,
    /* 0x0F8 */ ITEM_GAUNTLET,
    /* 0x0F9 */ ITEM_ANKH_OF_LIFE,
    /* 0x0FA */ ITEM_RING_OF_FEANOR,
    /* 0x0FB */ ITEM_MEDAL,
    /* 0x0FC */ ITEM_TALISMAN,
    /* 0x0FD */ ITEM_DUPLICATOR,
    /* 0x0FE */ ITEM_KINGS_STONE,
    /* 0x0FF */ ITEM_COVENANT_STONE,
    /* 0x100 */ ITEM_NAUGLAMIR,
    /* 0x101 */ ITEM_SECRET_BOOTS,
    /* 0x102 */ ITEM_ALUCART_MAIL
} EquipmentItems;

#define ITEM_HEAD_START ITEM_EMPTY_HEAD
#define ITEM_ARMOR_START ITEM_NO_ARMOR
#define ITEM_CAPE_START ITEM_NO_CAPE
#define ITEM_ACCESSORY_START ITEM_NO_ACCESSORY

#define ITEM_WEARABLE_FLAG ITEM_NO_ARMOR

#define HAND(x) (x)
#define WEARABLE(x) (x - ITEM_WEARABLE_FLAG)

#define HAND_COUNT(x) (x)
#define HEAD_COUNT(x) (x - ITEM_HEAD_START)
#define ARMOR_COUNT(x) (x - ITEM_ARMOR_START)
#define CAPE_COUNT(x) (x - ITEM_CAPE_START)
#define ACCESSORY_COUNT(x) (x - ITEM_ACCESSORY_START)