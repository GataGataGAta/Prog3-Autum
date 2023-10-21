#include <stdio.h>
#include "image1.h"

void bmp_collapse(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

int main(void)
{
    bmp_header_t hd;
    pixel_t img[MAX_Y][MAX_X];

    bmp_read("in.bmp", &hd, img);
    hd.biHeight = hd.biHeight / 2;
    bmp_collapse(&hd, img);           /* 処理の呼び出し */
    bmp_write("out.bmp", &hd, img); /* out.bmp への書き出し */

    return 0;
}

/* 画像処理の関数の本体 */
void bmp_collapse(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j, g, k;
    for (i = 0; i < hd->biHeight; i++)
    {
        for (j = 0; j < hd->biWidth ; j++)
        {
            // int red = 0;
            // int green = 0;
            // int blue = 0;
            // int count;

            // count = 0;
            img[i][j].r = (img[i * 2][j].r + img[i * 2 + 1][j].r) / 2;
            img[i][j].g = (img[i * 2][j].g + img[i * 2 + 1][j].g) / 2;
            img[i][j].b = (img[i * 2][j].b + img[i * 2 + 1][j].b) / 2;
         

            
        }
    }
}

/************** ここまで *************************************************/

