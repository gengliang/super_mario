#pragma once

#include "sprite.h"
#include <easyx.h>

struct cloud_5x2 {
	struct sprite super;
	IMAGE* imgCloud_5x2;
	IMAGE* imgCloud_5x2_mask;
};

void cloud_5x2Init(struct cloud_5x2 *);
struct sprite* createCloud_5x2();