#include "secretbox_1x1.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createSecretbox_1x1()
{
    secretbox_1x1* pSecretbox_1x1 = (struct secretbox_1x1*)malloc(sizeof(secretbox_1x1));
    secretbox_1x1Init(pSecretbox_1x1);
    return (struct sprite*)pSecretbox_1x1;
}

void secretbox_1x1Draw(struct secretbox_1x1 *s)
{
    putimage(s->super.x, s->super.y, s->imgSecretbox_1x1);
}

void secretbox_1x1Update(struct secretbox_1x1 *s)
{

}

void secretbox_1x1Destroy(struct secretbox_1x1 *s)
{
    delete s->imgSecretbox_1x1;
}

void secretbox_1x1Init(struct secretbox_1x1 *s)
{
    spriteInit((sprite*)s);
    s->super.draw = (void (*)(struct sprite*))secretbox_1x1Draw;
    s->super.update = (void (*)(struct sprite*))secretbox_1x1Update;
    s->super.destroy = (void (*)(struct sprite*))secretbox_1x1Destroy;
    s->super.width = GRID_WIDTH;
    s->super.height = GRID_HEIGHT;
    s->super.isCollisionable = true;
    s->super.spriteType = sprite_type_secretbox_1x1;

    s->imgSecretbox_1x1 = new IMAGE;
    loadimage(s->imgSecretbox_1x1, "img/secretbox_1x1.png");
}
