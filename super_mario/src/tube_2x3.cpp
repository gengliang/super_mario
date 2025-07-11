#include "tube_2x3.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createTube_2x3()
{
	tube_2x3* pTube_2x3 = (struct tube_2x3*)malloc(sizeof(tube_2x3));
	tube_2x3Init(pTube_2x3);
	return (struct sprite *)pTube_2x3;
}

void tube_2x3Draw(struct tube_2x3* t)
{
	putTransparentImage(t->super.x, t->super.y, t->imgTube_2x3_mask, t->imgTube_2x3);
}

void tube_2x3Update(struct tube_2x3* t)
{

}

void tube_2x3Destroy(struct tube_2x3* t)
{
	delete t->imgTube_2x3;
	delete t->imgTube_2x3_mask;
}

void tube_2x3Init(struct tube_2x3* t)
{
	spriteInit((sprite*)t);
	t->super.draw = (void (*)(struct sprite*))tube_2x3Draw;
	t->super.update = (void (*)(struct sprite*))tube_2x3Update;
	t->super.destroy = (void (*)(struct sprite*))tube_2x3Destroy;
	t->super.width = 2 * GRID_WIDTH;
	t->super.height = 3 * GRID_HEIGHT;
	t->super.isCollisionable = true;
	t->super.spriteType = sprite_type_tube_2x3;

	t->imgTube_2x3 = new IMAGE;
	loadimage(t->imgTube_2x3, "img/tube_2x3.png");

	t->imgTube_2x3_mask = new IMAGE;
	loadimage(t->imgTube_2x3_mask, "img/tube_2x3_mask.png");
}
