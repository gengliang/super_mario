#include "flipimage.h"

void flipImage(IMAGE* pImage)
{   
    int width;
    int height;
    width = pImage->getwidth();
    height = pImage->getheight();

    DWORD *pDwImage = GetImageBuffer(pImage);
    for (int y = 0; y < height; y++)
    {
        //  记录头尾指针
        DWORD *pHead = pDwImage;
        DWORD *pTail = pDwImage + width - 1;
        //  翻转一行
        while (pHead < pTail)
        {
            //  交换
            DWORD temp;
            temp = *pHead;
            *pHead = *pTail;
            *pTail = temp;
            //  头尾指针更新
            pHead++;
            pTail--;
        }
        //  去下一行
        pDwImage += width;
    }
}