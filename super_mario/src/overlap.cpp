#include "overlap.h"
#include <easyx.h>

bool overlapDetection(struct sprite* one, struct sprite* other)
{
    if (one == other)
        return false;

    RECT rectOne;
    rectOne.left = one->globalX;
    rectOne.top = one->globalY;
    rectOne.right = one->globalX + one->width - 1;
    rectOne.bottom = one->globalY + one->height - 1;

    RECT rectOther;
    rectOther.left = other->globalX;
    rectOther.top = other->globalY;
    rectOther.right = other->globalX + other->width - 1;
    rectOther.bottom = other->globalY + other->height - 1;

    if (rectOne.left > rectOther.right || rectOne.right < rectOther.left ||
        rectOne.top > rectOther.bottom || rectOne.bottom < rectOther.top)
    {
        return false;
    }
    return true;
}
