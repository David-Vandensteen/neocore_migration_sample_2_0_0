// DATlib v2 structures and patterns - complete test file
#include <stdio.h>

// DATlib v2 structures that were completely redesigned
typedef struct paletteInfo_v2 {
    WORD palCount;          // Changed to 'count' in v3
    WORD data[0];
} paletteInfo_v2;

typedef struct scrollerInfo_v2 {
    WORD colSize;           // Changed to stripSize (different unit!)
    WORD sprHeight;
    WORD mapWidth;
    WORD mapHeight;
    WORD map[0];           // Completely removed in v3
} scrollerInfo_v2;

typedef struct scroller_v2 {
    WORD baseSprite;
    WORD basePalette;
    WORD colNumber[21];    // Removed in v3
    WORD topBk, botBk;     // Removed in v3
    WORD scrlPosX, scrlPosY;
    scrollerInfo_v2 *info;
} scroller_v2;

typedef struct pictureInfo_v2 {
    WORD colSize;           // Changed to stripSize
    WORD unused__height;   // Removed in v3
    WORD tileWidth;
    WORD tileHeight;
    WORD *maps[4];         // Changed to ushort* in v3
} pictureInfo_v2;

typedef struct sprFrame_v2 {
    WORD tileWidth;
    WORD tileHeight;
    WORD colSize;          // Changed to stripSize in v3
    WORD *maps[4];
} sprFrame_v2;

typedef struct animation_v2 {  // COMPLETELY REMOVED in v3
    WORD stepsCount;
    WORD repeats;
    void *data;
    struct animation_v2 *link;
} animation_v2;

typedef struct spriteInfo_v2 {
    WORD palCount;         // Removed in v3
    WORD frameCount;
    WORD maxWidth;
    animation_v2 *anims;   // Changed to animStep** in v3
} spriteInfo_v2;

typedef struct aSprite_v2 {
    WORD baseSprite;
    WORD basePalette;
    short posX, posY;
    short currentStepNum;    // Renamed to stepNum in v3
    short maxStep;           // Removed in v3
    sprFrame_v2 *frames;     // Removed in v3
    sprFrame_v2 *currentFrame;
    animation_v2 *anims;     // Changed in v3
    animation_v2 *currentAnimation;  // Removed in v3
    void *steps;
    void *currentStep;
    DWORD counter;          // Changed to uint in v3
    WORD repeats;
    WORD currentFlip;
    WORD tileWidth;
    WORD animID;
    WORD flags;
} aSprite_v2;

// Old function signatures with WORD/BYTE parameters
void pictureInit_v2(void *p, pictureInfo_v2 *pi, WORD baseSprite, BYTE basePalette, short posX, short posY, WORD flip);
void scrollerInit_v2(scroller_v2 *s, scrollerInfo_v2 *si, WORD baseSprite, BYTE basePalette, short posX, short posY);
void aSpriteInit_v2(aSprite_v2 *as, spriteInfo_v2 *si, WORD baseSprite, BYTE basePalette, short posX, short posY, WORD anim, WORD flip);
void spritePoolInit_v2(void *sp, WORD baseSprite, WORD size);  // Missing clearSprites parameter

// Usage examples with old patterns
void test_datlib_v2_patterns(void) {
    // Using old paletteInfo structure
    paletteInfo_v2 *palette;
    printf("Palette count: %d\n", palette->palCount);  // Should be 'count' in v3

    // Using old scroller structure
    scroller_v2 scroller;
    scroller.colNumber[0] = 10;    // Removed in v3
    scroller.topBk = 5;            // Removed in v3
    scroller.botBk = 15;           // Removed in v3

    // Using old picture structure
    pictureInfo_v2 *pic_info;
    WORD old_height = pic_info->unused__height;  // Removed field
    WORD old_col_size = pic_info->colSize;       // Changed to stripSize

    // Using old animation structure (completely removed)
    animation_v2 *anim;
    WORD step_count = anim->stepsCount;
    animation_v2 *next_anim = anim->link;

    // Using old sprite structure members
    aSprite_v2 sprite;
    sprite.currentStepNum = 5;           // Renamed to stepNum
    sprite.maxStep = 10;                 // Removed in v3
    animation_v2 *current_anim = sprite.currentAnimation;  // Removed

    // Old function calls with WORD/BYTE
    pictureInit_v2(NULL, pic_info, (WORD)100, (BYTE)2, 0, 0, (WORD)0);
    aSpriteInit_v2(&sprite, NULL, (WORD)50, (BYTE)1, 10, 20, (WORD)0, (WORD)0);  // Missing flags param
    spritePoolInit_v2(NULL, (WORD)200, (WORD)50);  // Missing clearSprites param
}

// Constants that were removed
#define ASPRITE_FRAMES_ADDR 8  // Removed in v3

// Old job meter colors (values changed in v3)
#define JOB_BLACK_OLD       0x0000    // Changed to 0x8000 in v3
#define JOB_LIGHTRED_OLD    0x7f66    // Changed to 0xcf88 in v3
#define JOB_DARKRED_OLD     0xc900    // Changed to 0x8800 in v3
#define JOB_GARKGREEN_OLD   0xa090    // Typo fixed to JOB_DARKGREEN in v3

void test_old_constants(void) {
    // Using old job meter colors
    WORD old_black = JOB_BLACK_OLD;
    WORD old_red = JOB_LIGHTRED_OLD;
    WORD old_green = JOB_GARKGREEN_OLD;  // Typo in name

    // Using removed constant
    WORD frames_addr = ASPRITE_FRAMES_ADDR;
}
