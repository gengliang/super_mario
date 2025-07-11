#pragma once

#include "sprite.h"
#include <easyx.h>

struct cloud_3x2 {
	struct sprite super;
	IMAGE* imgCloud_3x2;
	IMAGE* imgCloud_3x2_mask;
};

void cloud_3x2Init(struct cloud_3x2 *);
struct sprite* createCloud_3x2();