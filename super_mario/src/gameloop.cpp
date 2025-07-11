#include <easyx.h>
#include "gameloop.h"
#include "scene.h"

void gameLoop(struct scene* s, int fps)
{
    timeBeginPeriod(1);
    //  开始时间、结束时间、频率F
    LARGE_INTEGER startCount, endCount, F;
    //  获取频率F
    QueryPerformanceFrequency(&F);

    BeginBatchDraw();
    while (1)
    {
        //  获取起始计数
        QueryPerformanceCounter(&startCount);

        //  清空窗体
        cleardevice();

        //  1. 更新数据
        s->update(s);

        //  2. 绘制画面
        s->draw(s);

        //  3.  是否结束
        if (s->isQuit(s))
            break;

        //  获取结束计数
        QueryPerformanceCounter(&endCount);

        //  计算时差
        long long elapse = (endCount.QuadPart - startCount.QuadPart)
            * 1000000 / F.QuadPart;

        //  注意这里的单位是微秒
        while (elapse < 1000000 / fps)
        {
            Sleep(1);

            //  4. 处理消息
            ExMessage msg;
            bool isOk = peekmessage(&msg, EX_KEY);
            if (isOk == true)
            {
                s->control(s, &msg);
            }

            //  重新获取结束时间
            QueryPerformanceCounter(&endCount);
            //  更新时差
            elapse = (endCount.QuadPart - startCount.QuadPart)
                * 1000000 / F.QuadPart;
        }

        //  绘制画面
        FlushBatchDraw();
    }
    EndBatchDraw();
    timeEndPeriod(1);
}