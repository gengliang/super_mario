#pragma once

#include "sprite.h"
#include <stdlib.h>

#define LENGTH_OF_CREATE_SPRITE_FUNC_ARR 1024

typedef struct sprite* (*TYPE_CREATE_SPRITE_FUNC)();

struct spriteFactory {
    struct sprite* (*createSprite)(struct spriteFactory*, const char*);

    TYPE_CREATE_SPRITE_FUNC createSpriteFuncArr[LENGTH_OF_CREATE_SPRITE_FUNC_ARR] = { NULL };
};

void spriteFactoryInit(struct spriteFactory*);