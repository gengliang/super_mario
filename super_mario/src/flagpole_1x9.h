#pragma once

#include "sprite.h"
#include <easyx.h>

struct flagpole_1x9 {
	struct sprite super;
	IMAGE* imgflagpole_1x9;
	IMAGE* imgflagpole_1x9_mask;
};

void flagpole_1x9Init(struct flagpole_1x9 *);
struct sprite* createFlagpole_1x9();