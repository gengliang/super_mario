#pragma once

#include "sprite.h"
#include <easyx.h>

struct flag_2x1 {
	struct sprite super;
	IMAGE* imgFlag_2x1;
	IMAGE* imgFlag_2x1_mask;
};

void flag_2x1Init(struct flag_2x1 *);
struct sprite* createFlag_2x1();