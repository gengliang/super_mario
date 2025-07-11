#pragma once

#include "sprite.h"
#include <easyx.h>

struct brickSecretbox_1x1 {
    struct sprite super;
    IMAGE* imgBrickSecretbox_1x1;
};

void brickSecretbox_1x1Init(struct brickSecretbox_1x1*);
struct sprite* createBrickSecretbox_1x1();