#pragma once

#include "sprite.h"
#include <easyx.h>

struct tube_2x3 {
	struct sprite super;
	IMAGE* imgTube_2x3;
	IMAGE* imgTube_2x3_mask;
};

void tube_2x3Init(struct tube_2x3 *);
struct sprite* createTube_2x3();