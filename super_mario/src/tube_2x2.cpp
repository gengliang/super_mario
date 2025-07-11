#include "tube_2x2.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createTube_2x2()
{
	tube_2x2* pTube_2x2 = (struct tube_2x2*)malloc(sizeof(tube_2x2));
	tube_2x2Init(pTube_2x2);
	return (struct sprite*)pTube_2x2;
}

void tube_2x2Draw(struct tube_2x2* t)
{
	putTransparentImage(t->super.x, t->super.y, t->imgTube_2x2_mask, t->imgTube_2x2);
}

void tube_2x2Update(struct tube_2x2* t)
{

}

void tube_2x2Destroy(struct tube_2x2* t)
{
	delete t->imgTube_2x2;
	delete t->imgTube_2x2_mask;
}

void tube_2x2Init(struct tube_2x2* t)
{
	spriteInit((sprite*)t);
	t->super.draw = (void (*)(struct sprite*))tube_2x2Draw;
	t->super.update = (void (*)(struct sprite*))tube_2x2Update;
	t->super.destroy = (void (*)(struct sprite*))tube_2x2Destroy;
	t->super.width = 2 * GRID_WIDTH;
	t->super.height = 2 * GRID_HEIGHT;
	t->super.isCollisionable = true;
	t->super.spriteType = sprite_type_tube_2x2;

	t->imgTube_2x2 = new IMAGE;
	loadimage(t->imgTube_2x2, "img/tube_2x2.png");

	t->imgTube_2x2_mask = new IMAGE;
	loadimage(t->imgTube_2x2_mask, "img/tube_2x2_mask.png");
}
