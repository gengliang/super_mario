#pragma once

#include "sprite.h"
#include "vector.h"

struct collisionSprite {
	struct sprite* s;
	int dir;
};

int getCollisionDirs(struct sprite* ont, struct vector* vecSprites);
int getCollisionSprites(struct sprite* one, struct vector* vecSprites, struct vector* vecCollisionSprites);
void destroyCollisionSprites(struct vector* vecCollisionSprites);