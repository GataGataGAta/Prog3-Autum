#include <stdio.h>
#include "image1.h"

void bmp_mosaic(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

int main(void)
{
    bmp_header_t hd;
    pixel_t img[MAX_Y][MAX_X];

    bmp_read("in.bmp", &hd, img);   /* in.bmp から読み込む */
    bmp_mosaic(&hd, img);           /* 処理の呼び出し */
    bmp_write("out.bmp", &hd, img); /* out.bmp への書き出し */

    return 0;
}

/* 画像処理の関数の本体 */
void bmp_mosaic(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j, g, k;

    for (i = 0; i < hd->biHeight; i+=16)
    {
        for (j = 0; j < hd->biWidth / 2; j+=16)
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            int count;

            count = 0;
            for (k = 0; k < 16; k++)
            {
                for (g = 0; g < 16; g++)
                {
                    red += img[i + k][j + g].r;
                    green += img[i + k][j + g].g;
                    blue += img[i + k][j + g].b;
                    count++;
                }
            }
            red /= count;
            green /= count;
            blue /= count;

            for (k = 0; k < 16; k++)
            {
                for (g = 0; g < 16; g++)
                {
                    img[i + k][j + g].r = red;
                    img[i + k][j + g].g = green;
                    img[i + k][j + g].b = blue;
                }
            }
        }
    }
}

/************** ここまで *************************************************/
