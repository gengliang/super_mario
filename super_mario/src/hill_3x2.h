#pragma once

#include "sprite.h"
#include <easyx.h>

struct hill_3x2 {
	struct sprite super;
	IMAGE* imgHill_3x2;
	IMAGE* imgHill_3x2_mask;
};

void hill_3x2Init(struct hill_3x2 *);
struct sprite* createHill_3x2();