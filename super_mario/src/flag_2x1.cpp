#include "flag_2x1.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createFlag_2x1()
{
	flag_2x1* pFlag_2x1 = (struct flag_2x1*)malloc(sizeof(flag_2x1));
	flag_2x1Init(pFlag_2x1);
	return (struct sprite*)pFlag_2x1;
}

void flag_2x1Draw(struct flag_2x1* f)
{
	putTransparentImage(f->super.x, f->super.y, f->imgFlag_2x1_mask, f->imgFlag_2x1);
}

void flag_2x1Update(struct flag_2x1* f)
{

}

void flag_2x1Destroy(struct flag_2x1* f)
{
	delete f->imgFlag_2x1;
	delete f->imgFlag_2x1_mask;
}

void flag_2x1Init(struct flag_2x1* f)
{
	spriteInit((sprite*)f);
	f->super.draw = (void (*)(struct sprite*))flag_2x1Draw;
	f->super.update = (void (*)(struct sprite*))flag_2x1Update;
	f->super.destroy = (void (*)(struct sprite*))flag_2x1Destroy;
	f->super.width = 2 * GRID_WIDTH;
	f->super.height = 1 * GRID_HEIGHT;
	f->super.spriteType = sprite_type_flag_2x1;

	f->imgFlag_2x1 = new IMAGE;
	loadimage(f->imgFlag_2x1, "img/flag_2x1.png");

	f->imgFlag_2x1_mask = new IMAGE;
	loadimage(f->imgFlag_2x1_mask, "img/flag_2x1_mask.png");
}
