#pragma once

#include "sprite.h"
#include <easyx.h>

struct cloud_4x2 {
	struct sprite super;
	IMAGE* imgCloud_4x2;
	IMAGE* imgCloud_4x2_mask;
};

void cloud_4x2Init(struct cloud_4x2 *);
struct sprite* createCloud_4x2();