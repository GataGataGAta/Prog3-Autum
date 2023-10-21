#include <stdio.h>
#include "image2.h"

void bmp_collapse(bmp_data_t *hd);

int main(void)
{
   bmp_data_t hd;

    bmp_read("in.bmp", &hd);   /* in.bmp から読み込む */
    hd.header.biHeight = hd.header.biHeight / 2;
    bmp_collapse(&hd);           /* 処理の呼び出し */
    bmp_write("out.bmp", &hd); /* out.bmp への書き出し */

    return 0;
}

/* 画像処理の関数の本体 */
void bmp_collapse(bmp_data_t *hd)
{
    int i, j, g, k;
    for (i = 0; i < hd->header.biHeight; i++)
    {
        for (j = 0; j < hd->header.biWidth ; j++)
        {
            hd->img[i][j].r = (hd->img[i * 2][j].r + hd->img[i * 2 + 1][j].r) / 2;
            hd->img[i][j].g = (hd->img[i * 2][j].g + hd->img[i * 2 + 1][j].g) / 2;
            hd->img[i][j].b = (hd->img[i * 2][j].b + hd->img[i * 2 + 1][j].b) / 2;
        }
    }
}

/************** ここまで *************************************************/

