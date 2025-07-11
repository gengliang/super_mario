#pragma once

#include "sprite.h"
#include <easyx.h>

struct tube_2x2 {
	struct sprite super;
	IMAGE* imgTube_2x2;
	IMAGE* imgTube_2x2_mask;
};

void tube_2x2Init(struct tube_2x2 *);
struct sprite* createTube_2x2();