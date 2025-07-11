#pragma once

#include "sprite.h"
#include <easyx.h>

struct floor_1x1 {
	struct sprite super;
	IMAGE* imgFloor_1x1;
};

void floor_1x1Init(struct floor_1x1*);
struct sprite* createFloor_1x1();