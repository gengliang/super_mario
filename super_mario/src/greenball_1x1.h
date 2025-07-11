#pragma once

#include "sprite.h"
#include <easyx.h>

struct greenball_1x1 {
	struct sprite super;
	IMAGE* imgGreenball_1x1;
	IMAGE* imgGreenball_1x1_mask;
};

void greenball_1x1Init(struct greenball_1x1*);
struct sprite* createGreenball_1x1();