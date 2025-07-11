#pragma once

#include "scene.h"
#include "mario.h"

#define VIEW_MARIO_MAX_MARGIN (6 * GRID_WIDTH)

struct mainScene {
    struct scene super;
    struct vector* pMap;
    int viewX;
    int width;
    int height;
    int layers;
    mario m;
};

void mainSceneInit(struct mainScene* s);
void mainSceneDestroy(struct mainScene* s);
