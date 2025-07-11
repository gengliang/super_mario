#include "bushes_4x1.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createBushes_4x1()
{
	bushes_4x1* pBushes_4x1 = (struct bushes_4x1*)malloc(sizeof(bushes_4x1));
	bushes_4x1Init(pBushes_4x1);
	return (struct sprite*)pBushes_4x1;
}

void bushes_4x1Draw(struct bushes_4x1* b)
{
	putTransparentImage(b->super.x, b->super.y, b->imgBushes_4x1_mask, b->imgBushes_4x1);
}

void bushes_4x1Update(struct bushes_4x1* b)
{
	
}

void bushes_4x1Destroy(struct bushes_4x1* b)
{
	delete b->imgBushes_4x1;
	delete b->imgBushes_4x1_mask;
}

void bushes_4x1Init(struct bushes_4x1 *b)
{
	spriteInit((sprite*)b);
	b->super.draw = (void (*)(struct sprite *))bushes_4x1Draw;
	b->super.update = (void (*)(struct sprite*))bushes_4x1Update;
	b->super.destroy = (void (*)(struct sprite *))bushes_4x1Destroy;
	b->super.width = 4 * GRID_WIDTH;
	b->super.height = GRID_HEIGHT;
	b->super.spriteType = sprite_type_bushes_4x1;

	b->imgBushes_4x1 = new IMAGE;
	loadimage(b->imgBushes_4x1, "img/bushes_4x1.png");

	b->imgBushes_4x1_mask = new IMAGE;
	loadimage(b->imgBushes_4x1_mask, "img/bushes_4x1_mask.png");
}
