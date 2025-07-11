#include "cloud_5x2.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createCloud_5x2()
{
	cloud_5x2* pCloud_5x2 = (struct cloud_5x2*)malloc(sizeof(cloud_5x2));
	cloud_5x2Init(pCloud_5x2);
	return (struct sprite*)pCloud_5x2;
}

void cloud_5x2Draw(struct cloud_5x2* c)
{
	putTransparentImage(c->super.x, c->super.y, c->imgCloud_5x2_mask, c->imgCloud_5x2);
}

void cloud_5x2Update(struct cloud_5x2* c)
{

}

void cloud_5x2Destroy(struct cloud_5x2* c)
{
	delete c->imgCloud_5x2;
	delete c->imgCloud_5x2_mask;
}

void cloud_5x2Init(struct cloud_5x2* c)
{
	spriteInit((sprite*)c);
	c->super.draw = (void (*)(struct sprite*))cloud_5x2Draw;
	c->super.update = (void (*)(struct sprite*))cloud_5x2Update;
	c->super.destroy = (void (*)(struct sprite*))cloud_5x2Destroy;
	c->super.width = 5 * GRID_WIDTH;
	c->super.height = 2 * GRID_HEIGHT;
	c->super.spriteType = sprite_type_cloud_5x2;

	c->imgCloud_5x2 = new IMAGE;
	loadimage(c->imgCloud_5x2, "img/cloud_5x2.png");

	c->imgCloud_5x2_mask = new IMAGE;
	loadimage(c->imgCloud_5x2_mask, "img/cloud_5x2_mask.png");
}
