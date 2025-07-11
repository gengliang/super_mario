#pragma once

#include "sprite.h"
#include <easyx.h>

struct hill_5x3 {
	struct sprite super;
	IMAGE* imgHill_5x3;
	IMAGE* imgHill_5x3_mask;
};

void hill_5x3Init(struct hill_5x3 *);
struct sprite* createHill_5x3();