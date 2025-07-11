#include "bushes_5x1.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createBushes_5x1()
{
	bushes_5x1* pBushes_5x1 = (struct bushes_5x1*)malloc(sizeof(bushes_5x1));
	bushes_5x1Init(pBushes_5x1);
	return (struct sprite*)pBushes_5x1;
}

void bushes_5x1Draw(struct bushes_5x1* b)
{
	putTransparentImage(b->super.x, b->super.y, b->imgBushes_5x1_mask, b->imgBushes_5x1);
}

void bushes_5x1Update(struct bushes_5x1* b)
{

}

void bushes_5x1Destroy(struct bushes_5x1* b)
{
	delete b->imgBushes_5x1;
	delete b->imgBushes_5x1_mask;
}

void bushes_5x1Init(struct bushes_5x1* b)
{
	spriteInit((sprite*)b);
	b->super.draw = (void (*)(struct sprite*))bushes_5x1Draw;
	b->super.update = (void (*)(struct sprite*))bushes_5x1Update;
	b->super.destroy = (void (*)(struct sprite*))bushes_5x1Destroy;
	b->super.width = 5 * GRID_WIDTH;
	b->super.height = GRID_HEIGHT;
	b->super.spriteType = sprite_type_bushes_5x1;

	b->imgBushes_5x1 = new IMAGE;
	loadimage(b->imgBushes_5x1, "img/bushes_5x1.png");

	b->imgBushes_5x1_mask = new IMAGE;
	loadimage(b->imgBushes_5x1_mask, "img/bushes_5x1_mask.png");
}
