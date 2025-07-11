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
        //  ��¼ͷβָ��
        DWORD *pHead = pDwImage;
        DWORD *pTail = pDwImage + width - 1;
        //  ��תһ��
        while (pHead < pTail)
        {
            //  ����
            DWORD temp;
            temp = *pHead;
            *pHead = *pTail;
            *pTail = temp;
            //  ͷβָ�����
            pHead++;
            pTail--;
        }
        //  ȥ��һ��
        pDwImage += width;
    }
}