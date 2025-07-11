#include <time.h>
#include "define.h"
#include "gameloop.h"
#include "mainscene.h"
#include <stdio.h>
#include "vector.h"

int main()
{
    srand((unsigned int)time(NULL));

    initgraph(VIEW_WIDTH, VIEW_HEIGHT);
    setbkcolor(RGB(147, 144, 254));
    cleardevice();

    mainScene mainscene;
    mainSceneInit(&mainscene);
    gameLoop((scene*)&mainscene, 24);
    mainSceneDestroy(&mainscene);

    closegraph();
    return 0;
}