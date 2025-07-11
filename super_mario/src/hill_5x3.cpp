#include "hill_5x3.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createHill_5x3()
{
	hill_5x3* pHill_5x3 = (struct hill_5x3*)malloc(sizeof(hill_5x3));
	hill_5x3Init(pHill_5x3);
	return (struct sprite*)pHill_5x3;
}

void hill_5x3Draw(struct hill_5x3* h)
{
	putTransparentImage(h->super.x, h->super.y, h->imgHill_5x3_mask, h->imgHill_5x3);
}

void hill_5x3Update(struct hill_5x3* h)
{

}

void hill_5x3Destroy(struct hill_5x3* h)
{
	delete h->imgHill_5x3;
	delete h->imgHill_5x3_mask;
}

void hill_5x3Init(struct hill_5x3* h)
{
	spriteInit((sprite*)h);
	h->super.draw = (void (*)(struct sprite*))hill_5x3Draw;
	h->super.update = (void (*)(struct sprite*))hill_5x3Update;
	h->super.destroy = (void (*)(struct sprite*))hill_5x3Destroy;
	h->super.width = 5 * GRID_WIDTH;
	h->super.height = 3 * GRID_HEIGHT;
	h->super.spriteType = sprite_type_hill_5x3;

	h->imgHill_5x3 = new IMAGE;
	loadimage(h->imgHill_5x3, "img/hill_5x3.png");

	h->imgHill_5x3_mask = new IMAGE;
	loadimage(h->imgHill_5x3_mask, "img/hill_5x3_mask.png");
}
