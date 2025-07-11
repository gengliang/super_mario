#pragma once

#include "sprite.h"
#include <easyx.h>

struct block_1x1 {
	struct sprite super;
	IMAGE* imgBlock_1x1;
};

void block_1x1Init(struct block_1x1 *);
struct sprite* createBlock_1x1();