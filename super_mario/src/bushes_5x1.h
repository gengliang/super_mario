#pragma once

#include "sprite.h"
#include <easyx.h>

struct bushes_5x1 {
	struct sprite super;
	IMAGE* imgBushes_5x1;
	IMAGE* imgBushes_5x1_mask;
};

void bushes_5x1Init(struct bushes_5x1 *);
struct sprite* createBushes_5x1();