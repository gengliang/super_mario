#include "sprite.h"
#include <stdlib.h>
#include "direction.h"
#include "spritetype.h"

void spriteInit(struct sprite* s)
{
    s->draw = NULL;
    s->update = NULL;
    s->destroy = NULL;
    s->trigger = NULL;

    s->x = 0;
    s->y = 0;

    s->vx = 0;
    s->vy = 0;

    s->globalX = 0;
    s->globalY = 0;
    s->zOrder = 0;

    s->width = 0;
    s->height = 0;

    s->isCollisionable = false;
    s->collisionDirs = direction_none;

    s->spriteType = sprite_type_unknown;
}