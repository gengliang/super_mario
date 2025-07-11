#include "bushes_3x1.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createBushes_3x1()
{
	bushes_3x1* pBushes_3x1 = (struct bushes_3x1*)malloc(sizeof(bushes_3x1));
	bushes_3x1Init(pBushes_3x1);
	return (struct sprite*)pBushes_3x1;
}

void bushes_3x1Draw(struct bushes_3x1* b)
{
	putTransparentImage(b->super.x, b->super.y, b->imgBushes_3x1_mask, b->imgBushes_3x1);
}

void bushes_3x1Update(struct bushes_3x1* b)
{

}

void bushes_3x1Destroy(struct bushes_3x1* b)
{
	delete b->imgBushes_3x1;
	delete b->imgBushes_3x1_mask;
}

void bushes_3x1Init(struct bushes_3x1* b)
{
	spriteInit((sprite*)b);
	b->super.draw = (void (*)(struct sprite*))bushes_3x1Draw;
	b->super.update = (void (*)(struct sprite*))bushes_3x1Update;
	b->super.destroy = (void (*)(struct sprite*))bushes_3x1Destroy;
	b->super.width = 3 * GRID_WIDTH;
	b->super.height = GRID_HEIGHT;
	b->super.spriteType = sprite_type_bushes_3x1;

	b->imgBushes_3x1 = new IMAGE;
	loadimage(b->imgBushes_3x1, "img/bushes_3x1.png");

	b->imgBushes_3x1_mask = new IMAGE;
	loadimage(b->imgBushes_3x1_mask, "img/bushes_3x1_mask.png");
}
