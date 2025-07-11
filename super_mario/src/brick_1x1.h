#pragma once

#include "sprite.h"
#include <easyx.h>

enum brickStatus {
	brick_status_static,
	brick_status_damping
};

struct brick_1x1 {
	struct sprite super;
	IMAGE* imgBrick_1x1;
	enum brickStatus status; 
	int t;
};

void brick_1x1Init(struct brick_1x1 *);
struct sprite* createBrick_1x1();