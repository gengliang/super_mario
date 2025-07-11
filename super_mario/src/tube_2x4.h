#pragma once

#include "sprite.h"
#include <easyx.h>

struct tube_2x4 {
	struct sprite super;
	IMAGE* imgTube_2x4;
	IMAGE* imgTube_2x4_mask;
};

void tube_2x4Init(struct tube_2x4 *);
struct sprite* createTube_2x4();