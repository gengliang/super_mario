#include "spritefactory.h"
#include "hash.h"

#include "block_1x1.h"
#include "brick_1x1.h"
#include "bricksecretbox_1x1.h"
#include "bushes_3x1.h"
#include "bushes_4x1.h"
#include "bushes_5x1.h"
#include "castle_5x5.h"
#include "cloud_3x2.h"
#include "cloud_4x2.h"
#include "cloud_5x2.h"
#include "flag_2x1.h"
#include "flagpole_1x9.h"
#include "floor_1x1.h"
#include "greenball_1x1.h"
#include "hill_3x2.h"
#include "hill_5x3.h"
#include "secretbox_1x1.h"
#include "tube_2x2.h"
#include "tube_2x3.h"
#include "tube_2x4.h"

struct sprite *spriteFactoryCreateSprite(struct spriteFactory* sf, const char* spriteName)
{
    unsigned int h;
    h = DJBHash(spriteName) % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    TYPE_CREATE_SPRITE_FUNC pFunc = sf->createSpriteFuncArr[h];
    if (pFunc == NULL)
        return NULL;
    struct sprite* pSprite = pFunc();
    return pSprite;
}

void hashCollision()
{
    MessageBox(NULL, "hash collision", "error", MB_OK);
}

void spriteFactoryInit(struct spriteFactory *sf)
{
    sf->createSprite = spriteFactoryCreateSprite;

    unsigned int h;
    //  block_1x1
    h = DJBHash("block_1x1") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createBlock_1x1;

    //  brick_1x1
    h = DJBHash("brick_1x1") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createBrick_1x1;

    //  brick_secretbox_1x1
    h = DJBHash("brick_secretbox_1x1") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createBrickSecretbox_1x1;

    //  bushes_3x1
    h = DJBHash("bushes_3x1") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createBushes_3x1;

    //  bushes_4x1
    h = DJBHash("bushes_4x1") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createBushes_4x1;

    //  bushes_5x1
    h = DJBHash("bushes_5x1") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createBushes_5x1;

    //  castle_5x5
    h = DJBHash("castle_5x5") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createCastle_5x5;

    //  cloud_3x2
    h = DJBHash("cloud_3x2") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createCloud_3x2;

    //  cloud_4x2
    h = DJBHash("cloud_4x2") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createCloud_4x2;

    //  cloud_5x2
    h = DJBHash("cloud_5x2") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createCloud_5x2;

    //  flag_2x2
    h = DJBHash("flag_2x1") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createFlag_2x1;

    //  flagpole_1x9
    h = DJBHash("flagpole_1x9") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createFlagpole_1x9;

    //  floor_1x1
    h = DJBHash("floor_1x1") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createFloor_1x1;

    //  greenball_1x1
    h = DJBHash("greenball_1x1") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createGreenball_1x1;

    //  hill_3x2
    h = DJBHash("hill_3x2") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createHill_3x2;

    //  hill_5x3
    h = DJBHash("hill_5x3") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createHill_5x3;

    //  secretbox_1x1
    h = DJBHash("secretbox_1x1") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createSecretbox_1x1;

    //  tube_2x2
    h = DJBHash("tube_2x2") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createTube_2x2;

    //  tube_2x3
    h = DJBHash("tube_2x3") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createTube_2x3;

    //  tube_2x4
    h = DJBHash("tube_2x4") % LENGTH_OF_CREATE_SPRITE_FUNC_ARR;
    if (sf->createSpriteFuncArr[h] != NULL)
    {
        hashCollision();
        return;
    }
    sf->createSpriteFuncArr[h] = createTube_2x4;

    //  append Sprites...
}
