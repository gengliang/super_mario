#include "flagpole_1x9.h"
#include "image.h"
#include "define.h"
#include "spritetype.h"

struct sprite* createFlagpole_1x9()
{
	flagpole_1x9* pFagpole_1x9 = (struct flagpole_1x9*)malloc(sizeof(flagpole_1x9));
	flagpole_1x9Init(pFagpole_1x9);
	return (struct sprite*)pFagpole_1x9;
}

void flagpole_1x9Draw(struct flagpole_1x9* f)
{
	putTransparentImage(f->super.x, f->super.y, f->imgflagpole_1x9_mask, f->imgflagpole_1x9);
}

void flagpole_1x9Update(struct flagpole_1x9* f)
{

}

void flagpole_1x9Destroy(struct flagpole_1x9* f)
{
	delete f->imgflagpole_1x9;
	delete f->imgflagpole_1x9_mask;
}

void flagpole_1x9Init(struct flagpole_1x9* f)
{
	spriteInit((sprite*)f);
	f->super.draw = (void (*)(struct sprite*))flagpole_1x9Draw;
	f->super.update = (void (*)(struct sprite*))flagpole_1x9Update;
	f->super.destroy = (void (*)(struct sprite*))flagpole_1x9Destroy;
	f->super.width = GRID_WIDTH;
	f->super.height = 9 * GRID_HEIGHT;
	f->super.spriteType = sprite_type_flagpole_1x9;

	f->imgflagpole_1x9 = new IMAGE;
	loadimage(f->imgflagpole_1x9, "img/flagpole_1x9.png");

	f->imgflagpole_1x9_mask = new IMAGE;
	loadimage(f->imgflagpole_1x9_mask, "img/flagpole_1x9_mask.png");
}
