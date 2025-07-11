#include "hill_3x2.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createHill_3x2()
{
	hill_3x2* pHill_3x2 = (struct hill_3x2*)malloc(sizeof(hill_3x2));
	hill_3x2Init(pHill_3x2);
	return (struct sprite*)pHill_3x2;
}

void hill_3x2Draw(struct hill_3x2* h)
{
	putTransparentImage(h->super.x, h->super.y, h->imgHill_3x2_mask, h->imgHill_3x2);
}

void hill_3x2Update(struct hill_3x2* h)
{

}

void hill_3x2Destroy(struct hill_3x2* h)
{
	delete h->imgHill_3x2;
	delete h->imgHill_3x2_mask;
}

void hill_3x2Init(struct hill_3x2* h)
{
	spriteInit((sprite*)h);
	h->super.draw = (void (*)(struct sprite*))hill_3x2Draw;
	h->super.update = (void (*)(struct sprite*))hill_3x2Update;
	h->super.destroy = (void (*)(struct sprite*))hill_3x2Destroy;
	h->super.width = 3 * GRID_WIDTH;
	h->super.height = 2 * GRID_HEIGHT;
	h->super.spriteType = sprite_type_hill_3x2;

	h->imgHill_3x2 = new IMAGE;
	loadimage(h->imgHill_3x2, "img/hill_3x2.png");

	h->imgHill_3x2_mask = new IMAGE;
	loadimage(h->imgHill_3x2_mask, "img/hill_3x2_mask.png");
}
