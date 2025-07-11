#pragma once

#include "sprite.h"
#include <easyx.h>

struct bushes_4x1 {
	struct sprite super;
	IMAGE* imgBushes_4x1;
	IMAGE* imgBushes_4x1_mask;
};

void bushes_4x1Init(struct bushes_4x1 *);
struct sprite* createBushes_4x1();