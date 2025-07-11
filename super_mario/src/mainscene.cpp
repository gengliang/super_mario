#include "mainscene.h"
#include "vector.h"
#include "map.h"
#include "define.h"
#include "sprite.h"
#include "overlap.h"
#include "collision.h"
#include "direction.h"
#include <stdio.h>

void getSprites(struct vector *vecSprites, int m, int n, struct mainScene *ms)
{   
    for (int i = 0; i < ms->pMap->size; i++)
    {
        //  地图中每一层
        vector* pLayer = (vector*)ms->pMap->get(ms->pMap, i);
        if (pLayer == NULL)
            continue;
        //  层中每一列
        for (int j = m - 4; j <= n; j++)
        {
            if (j < 0)
                continue;
            vector* pCol = (vector*)pLayer->get(pLayer, j);
            if (pCol == NULL)
                continue;
            //  列中每一个列元素
            for (int k = 0; k < pCol->size; k++)
            {
                struct vector* pColRow = (struct vector*)pCol->get(pCol, k);
                if (pColRow == NULL)
                    continue;
                //  列元素中每一个物体对象
                for (int l = 0; l < pColRow->size; l++)
                {
                    struct sprite* s = (struct sprite*)pColRow->get(pColRow, l);
                    if (s == NULL)
                        continue;
                    //  追加进入vector
                    vecSprites->append(vecSprites, s);
                }
            }
        }
    }
	
	struct sprite* pMario = (struct sprite*)&ms->m;
    vecSprites->append(vecSprites, pMario);
}

void mainSceneDraw(struct mainScene* ms)
{
    int m, n;
    m = ms->viewX / GRID_WIDTH;
    n = (ms->viewX + VIEW_WIDTH) / GRID_WIDTH;

    cleardevice();
    //  draw
    struct vector vecSprites;
    vectorInit(&vecSprites);
    getSprites(&vecSprites, m, n, ms);
    for (int i = 0; i < vecSprites.size; i++)
    {
        sprite* s = (sprite*)vecSprites.get(&vecSprites, i);
        //  调用物体对象的draw方法
        s->draw(s);
    }
}

void spritesMoving(struct mainScene *ms, int m, int n)
{
    struct vector vecSprites;
    vectorInit(&vecSprites);
    getSprites(&vecSprites, m, n, ms);

    //  检查m到n内的物体的碰撞并尝试移动
    for (int i = 0; i < vecSprites.size; i++)
    {
        sprite* one = (sprite*)vecSprites.get(&vecSprites, i);

        int vx, vy;
        vx = one->vx;
        vy = one->vy;

        while (1)
        {
            //  get collision dirs
            if (one->isCollisionable == true)
                one->collisionDirs = getCollisionDirs(one, &vecSprites);

            //  v to zero
            //  left
            if ((one->collisionDirs & direction_left) && vx < 0)
            {
                vx = 0;
            }
            //  right
            if ((one->collisionDirs & direction_right) && vx > 0)
            {
                vx = 0;
            }
            //  top
            if ((one->collisionDirs & direction_top) && vy < 0)
            {
                vy = 0;
            }
            //  bottom
            if ((one->collisionDirs & direction_bottom) && vy > 0)
            {
                vy = 0;
            }

            //  one v to zero
            //  left
            if ((one->collisionDirs & direction_left) && one->vx < 0)
            {
                one->vx = 0;
            }
            //  right
            if ((one->collisionDirs & direction_right) && one->vx > 0)
            {
                one->vx = 0;
            }
            //  top
            if ((one->collisionDirs & direction_top) && one->vy < 0)
            {
                one->vy = 0;
            }
            //  bottom
            if ((one->collisionDirs & direction_bottom) && one->vy > 0)
            {
                one->vy = 0;
            }

            //  move
            if (vx > 0)
            {
                one->globalX += 1;
                vx -= 1;
            }
            else if (vx < 0)
            {
                one->globalX -= 1;
                vx += 1;
            }
            if (vy > 0)
            {
                one->globalY += 1;
                vy -= 1;
            }
            else if (vy < 0)
            {
                one->globalY -= 1;
                vy += 1;
            }

            if (vx == 0 && vy == 0)
                break;
        }
    }
}

void spritesTrigger(struct mainScene* ms, int m, int n)
{
    struct vector vecSprites;
    vectorInit(&vecSprites);
    getSprites(&vecSprites, m, n, ms);

    //  检查m到n内的物体的碰撞并触发
    for (int i = 0; i < vecSprites.size; i++)
    {
        struct sprite* one = (struct sprite*)vecSprites.get(&vecSprites, i);
        if (one->trigger == NULL)
            continue;
        
        struct vector vecCollisionSprites;
        vectorInit(&vecCollisionSprites);
        int dir = getCollisionSprites(one, &vecSprites, &vecCollisionSprites);
        if (dir == NULL)
            continue;
        for (int j = 0; j < vecCollisionSprites.size; j++)
        {
            struct collisionSprite *pCs = (struct collisionSprite *)vecCollisionSprites.get(&vecCollisionSprites, j);
            one->trigger(one, pCs->s, pCs->dir, ms);
        }
        destroyCollisionSprites(&vecCollisionSprites);
    }
}


void mainSceneUpdate(struct mainScene* ms)
{   
    //  移动viewX
    //  当马里奥与viewX的距离大于VIEW_MARIO_MAX_MARGIN时，需要移动viewX
    if (ms->m.super.globalX - ms->viewX > VIEW_MARIO_MAX_MARGIN)
    {
        ms->viewX = ms->m.super.globalX - VIEW_MARIO_MAX_MARGIN;
    }
    
    //  m to n
    int m, n;
    m = ms->viewX / GRID_WIDTH;
    n = (ms->viewX + VIEW_WIDTH) / GRID_WIDTH;

    //  update
    struct vector vecSprites;
    vectorInit(&vecSprites);
    getSprites(&vecSprites, m, n, ms);
    for (int i = 0; i < vecSprites.size; i++)
    {
        sprite* s = (sprite*)vecSprites.get(&vecSprites, i);
        //  调用物体对象的update方法
        s->update(s);
        //  更新物体对象的x，y
        s->x = s->globalX - ms->viewX;
        s->y = s->globalY;
    }

    spritesMoving(ms, m, n);
	spritesTrigger(ms, m, n);
}

void mainSceneControl(struct mainScene* ms, ExMessage* msg)
{
    ms->m.control(&ms->m, msg);
}

bool mainSceneIsQuit(struct mainScene* ms)
{
    return false;
}

void mainSceneInit(struct mainScene* ms)
{
    ms->super.draw = (void (*)(struct scene*))mainSceneDraw;
    ms->super.update = (void (*)(struct scene*))mainSceneUpdate;
    ms->super.control = (void (*)(struct scene*, ExMessage*))mainSceneControl;
    ms->super.isQuit = (bool (*)(struct scene*))mainSceneIsQuit;

    //  viewX
    ms->viewX = 0;
    ms->pMap = createMap("map.txt", &ms->width, &ms->height, &ms->layers);

    //  mario
    marioInit(&ms->m);
}

void mainSceneDestroy(struct mainScene* ms)
{
    destroyMap(ms->pMap);
}