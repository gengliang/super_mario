#pragma once

#include "sprite.h"
#include <easyx.h>

struct bushes_3x1 {
	struct sprite super;
	IMAGE* imgBushes_3x1;
	IMAGE* imgBushes_3x1_mask;
};

void bushes_3x1Init(struct bushes_3x1 *);
struct sprite* createBushes_3x1();