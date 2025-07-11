#include "bricksecretbox_1x1.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createBrickSecretbox_1x1()
{
    brickSecretbox_1x1* pBrickSecretbox_1x1 = (struct brickSecretbox_1x1*)malloc(sizeof(brickSecretbox_1x1));
    brickSecretbox_1x1Init(pBrickSecretbox_1x1);
    return (struct sprite*)pBrickSecretbox_1x1;
}

void brickSecretbox_1x1Draw(struct brickSecretbox_1x1* b)
{
    putimage(b->super.x, b->super.y, b->imgBrickSecretbox_1x1);
}

void brickSecretbox_1x1Update(struct brickSecretbox_1x1* b)
{

}

void brickSecretbox_1x1Destroy(struct brickSecretbox_1x1* b)
{
    delete b->imgBrickSecretbox_1x1;
}

void brickSecretbox_1x1Init(struct brickSecretbox_1x1* b)
{
    spriteInit((sprite*)b);
    b->super.draw = (void (*)(struct sprite*))brickSecretbox_1x1Draw;
    b->super.update = (void (*)(struct sprite*))brickSecretbox_1x1Update;
    b->super.destroy = (void (*)(struct sprite*))brickSecretbox_1x1Destroy;
    b->super.width = GRID_WIDTH;
    b->super.height = GRID_HEIGHT;
    b->super.isCollisionable = true;
    b->super.spriteType = sprite_type_bricksecretbox_1x1;

    b->imgBrickSecretbox_1x1 = new IMAGE;
    loadimage(b->imgBrickSecretbox_1x1, "img/brick_1x1.png");
}