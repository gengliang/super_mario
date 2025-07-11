#include "tube_2x4.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createTube_2x4()
{
	tube_2x4* pTube_2x4 = (struct tube_2x4*)malloc(sizeof(tube_2x4));
	tube_2x4Init(pTube_2x4);
	return (struct sprite*)pTube_2x4;
}

void tube_2x4Draw(struct tube_2x4* t)
{
	putTransparentImage(t->super.x, t->super.y, t->imgTube_2x4_mask, t->imgTube_2x4);
}

void tube_2x4Update(struct tube_2x4* t)
{

}

void tube_2x4Destroy(struct tube_2x4* t)
{
	delete t->imgTube_2x4;
	delete t->imgTube_2x4_mask;
}

void tube_2x4Init(struct tube_2x4* t)
{
	spriteInit((sprite*)t);
	t->super.draw = (void (*)(struct sprite*))tube_2x4Draw;
	t->super.update = (void (*)(struct sprite*))tube_2x4Update;
	t->super.destroy = (void (*)(struct sprite*))tube_2x4Destroy;
	t->super.width = 2 * GRID_WIDTH;
	t->super.height = 4 * GRID_HEIGHT;
	t->super.isCollisionable = true;
	t->super.spriteType = sprite_type_tube_2x4;

	t->imgTube_2x4 = new IMAGE;
	loadimage(t->imgTube_2x4, "img/tube_2x4.png");

	t->imgTube_2x4_mask = new IMAGE;
	loadimage(t->imgTube_2x4_mask, "img/tube_2x4_mask.png");
}
