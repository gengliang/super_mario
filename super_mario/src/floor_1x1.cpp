#include "floor_1x1.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createFloor_1x1()
{
	floor_1x1* pFloor_1x1 = (struct floor_1x1*)malloc(sizeof(floor_1x1));
	floor_1x1Init(pFloor_1x1);
	return (struct sprite*)pFloor_1x1;
}

void floor_1x1Draw(struct floor_1x1* f)
{
	putimage(f->super.x, f->super.y, f->imgFloor_1x1);
}

void floor_1x1Update(struct floor_1x1* f)
{

}

void floor_1x1Destroy(struct floor_1x1* f)
{
	delete f->imgFloor_1x1;
}

void floor_1x1Init(struct floor_1x1* f)
{
	spriteInit((sprite*)f);
	f->super.draw = (void (*)(struct sprite*))floor_1x1Draw;
	f->super.update = (void (*)(struct sprite*))floor_1x1Update;
	f->super.destroy = (void (*)(struct sprite*))floor_1x1Destroy;
	f->super.width = GRID_WIDTH;
	f->super.height = GRID_HEIGHT;
	f->super.isCollisionable = true;
	f->super.spriteType = sprite_type_floor_1x1;

	f->imgFloor_1x1 = new IMAGE;
	loadimage(f->imgFloor_1x1, "img/floor_1x1.png");
}
