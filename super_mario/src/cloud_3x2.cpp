#include "cloud_3x2.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createCloud_3x2()
{
	cloud_3x2* pCloud_3x2 = (struct cloud_3x2*)malloc(sizeof(cloud_3x2));
	cloud_3x2Init(pCloud_3x2);
	return (struct sprite*)pCloud_3x2;
}

void cloud_3x2Draw(struct cloud_3x2* c)
{
	putTransparentImage(c->super.x, c->super.y, c->imgCloud_3x2_mask, c->imgCloud_3x2);
}

void cloud_3x2Update(struct cloud_3x2* c)
{

}

void cloud_3x2Destroy(struct cloud_3x2* c)
{
	delete c->imgCloud_3x2;
	delete c->imgCloud_3x2_mask;
}

void cloud_3x2Init(struct cloud_3x2* c)
{
	spriteInit((sprite*)c);
	c->super.draw = (void (*)(struct sprite*))cloud_3x2Draw;
	c->super.update = (void (*)(struct sprite*))cloud_3x2Update;
	c->super.destroy = (void (*)(struct sprite*))cloud_3x2Destroy;
	c->super.width = 3 * GRID_WIDTH;
	c->super.height = 2 * GRID_HEIGHT;
	c->super.spriteType = sprite_type_cloud_3x2;

	c->imgCloud_3x2 = new IMAGE;
	loadimage(c->imgCloud_3x2, "img/cloud_3x2.png");

	c->imgCloud_3x2_mask = new IMAGE;
	loadimage(c->imgCloud_3x2_mask, "img/cloud_3x2_mask.png");
}
