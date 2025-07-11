#pragma once

#include "sprite.h"
#include <easyx.h>

struct castle_5x5 {
	struct sprite super;
	IMAGE* imgCastle_5x5;
	IMAGE* imgCastle_5x5_mask;
};

void castle_5x5Init(struct castle_5x5 *);
struct sprite* createCastle_5x5();