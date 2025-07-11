#include "block_1x1.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createBlock_1x1()
{
	block_1x1* pBlock_1x1 = (struct block_1x1*)malloc(sizeof(block_1x1));
	block_1x1Init(pBlock_1x1);
	return (struct sprite*)pBlock_1x1;
}

void block_1x1Draw(struct block_1x1* b)
{
	putimage(b->super.x, b->super.y, b->imgBlock_1x1);
}

void block_1x1Update(struct block_1x1* b)
{
	
}

void block_1x1Destroy(struct block_1x1* b)
{
	delete b->imgBlock_1x1;
}

void block_1x1Init(struct block_1x1 *b)
{
	spriteInit((sprite*)b);
	b->super.draw = (void (*)(struct sprite *))block_1x1Draw;
	b->super.update = (void (*)(struct sprite*))block_1x1Update;
	b->super.destroy = (void (*)(struct sprite *))block_1x1Destroy;
	b->super.width = GRID_WIDTH;
	b->super.height = GRID_HEIGHT;
	b->super.isCollisionable = true;
	b->super.spriteType = sprite_type_block_1x1;

	b->imgBlock_1x1 = new IMAGE;
	loadimage(b->imgBlock_1x1, "img/block_1x1.png");
}
