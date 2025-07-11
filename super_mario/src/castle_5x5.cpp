#include "castle_5x5.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createCastle_5x5()
{
	castle_5x5 *pCastle_5x5 = (struct castle_5x5*)malloc(sizeof(castle_5x5));
	castle_5x5Init(pCastle_5x5);
	return (struct sprite*)pCastle_5x5;
}

void castle_5x5Draw(struct castle_5x5* c)
{
	putTransparentImage(c->super.x, c->super.y, c->imgCastle_5x5_mask, c->imgCastle_5x5);
}

void castle_5x5Update(struct castle_5x5* c)
{

}

void castle_5x5Destroy(struct castle_5x5* c)
{
	delete c->imgCastle_5x5;
	delete c->imgCastle_5x5_mask;
}

void castle_5x5Init(struct castle_5x5* c)
{
	spriteInit((sprite*)c);
	c->super.draw = (void (*)(struct sprite*))castle_5x5Draw;
	c->super.update = (void (*)(struct sprite*))castle_5x5Update;
	c->super.destroy = (void (*)(struct sprite*))castle_5x5Destroy;
	c->super.width = 5 * GRID_WIDTH;
	c->super.height = 5 * GRID_HEIGHT;
	c->super.spriteType = sprite_type_castle_5x5;

	c->imgCastle_5x5 = new IMAGE;
	loadimage(c->imgCastle_5x5, "img/castle_5x5.png");

	c->imgCastle_5x5_mask = new IMAGE;
	loadimage(c->imgCastle_5x5_mask, "img/castle_5x5_mask.png");
}
