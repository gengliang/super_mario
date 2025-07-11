#include "greenball_1x1.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createGreenball_1x1()
{
	greenball_1x1* pgreenball_1x1 = (struct greenball_1x1*)malloc(sizeof(greenball_1x1));
	greenball_1x1Init(pgreenball_1x1);
	return (struct sprite*)pgreenball_1x1;
}

void greenball_1x1Draw(struct greenball_1x1* g)
{
	putTransparentImage(g->super.x, g->super.y, g->imgGreenball_1x1_mask, g->imgGreenball_1x1);
}

void greenball_1x1Update(struct greenball_1x1* g)
{
	
}

void greenball_1x1Destroy(struct greenball_1x1* g)
{
	delete g->imgGreenball_1x1;
	delete g->imgGreenball_1x1_mask;
}

void greenball_1x1Init(struct greenball_1x1* g)
{
	spriteInit((sprite*)g);
	g->super.draw = (void (*)(struct sprite*))greenball_1x1Draw;
	g->super.update = (void (*)(struct sprite*))greenball_1x1Update;
	g->super.destroy = (void (*)(struct sprite*))greenball_1x1Destroy;
	g->super.width = GRID_WIDTH;
	g->super.height = GRID_HEIGHT;
	g->super.spriteType = sprite_type_greenball_1x1;

	g->imgGreenball_1x1 = new IMAGE;
	loadimage(g->imgGreenball_1x1, "img/greenball_1x1.png");
	g->imgGreenball_1x1_mask = new IMAGE;
	loadimage(g->imgGreenball_1x1_mask, "img/greenball_1x1_mask.png");
}
