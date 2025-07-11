#include "cloud_4x2.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createCloud_4x2()
{
	cloud_4x2* pCloud_4x2 = (struct cloud_4x2*)malloc(sizeof(cloud_4x2));
	cloud_4x2Init(pCloud_4x2);
	return (struct sprite*)pCloud_4x2;
}

void cloud_4x2Draw(struct cloud_4x2* c)
{
	putTransparentImage(c->super.x, c->super.y, c->imgCloud_4x2_mask, c->imgCloud_4x2);
}

void cloud_4x2Update(struct cloud_4x2* c)
{

}

void cloud_4x2Destroy(struct cloud_4x2* c)
{
	delete c->imgCloud_4x2;
	delete c->imgCloud_4x2_mask;
}

void cloud_4x2Init(struct cloud_4x2* c)
{
	spriteInit((sprite*)c);
	c->super.draw = (void (*)(struct sprite*))cloud_4x2Draw;
	c->super.update = (void (*)(struct sprite*))cloud_4x2Update;
	c->super.destroy = (void (*)(struct sprite*))cloud_4x2Destroy;
	c->super.width = 4 * GRID_WIDTH;
	c->super.height = 2 * GRID_HEIGHT;
	c->super.spriteType = sprite_type_cloud_4x2;

	c->imgCloud_4x2 = new IMAGE;
	loadimage(c->imgCloud_4x2, "img/cloud_4x2.png");

	c->imgCloud_4x2_mask = new IMAGE;
	loadimage(c->imgCloud_4x2_mask, "img/cloud_4x2_mask.png");
}
