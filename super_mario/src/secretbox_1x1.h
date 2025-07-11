#pragma once

#include "sprite.h"
#include <easyx.h>

struct secretbox_1x1 {
    struct sprite super;
    IMAGE* imgSecretbox_1x1;
};

void secretbox_1x1Init(struct secretbox_1x1 *);
struct sprite* createSecretbox_1x1();
