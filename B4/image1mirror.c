#include <stdio.h>
#include "image1.h"

/* 画像全体をモノクロにする関数 */
void bmp_mirror(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

int main(void)
{
    bmp_header_t hd;
    pixel_t img[MAX_Y][MAX_X];

    bmp_read("in.bmp", &hd, img);   /* in.bmp から読み込む */
    bmp_mirror(&hd, img);             /* 処理の呼び出し */
    bmp_write("out.bmp", &hd, img); /* out.bmp への書き出し */

    return 0;
}

/* 画像処理の関数の本体 */
void bmp_mirror(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j;
    pixel_t tmp;
    for (i = 0; i <= hd->biWidth; i++)
    { /* biHeight は画像の高さ */
    
        for (j = 0; j < hd->biHeight / 2; j++)
        { /* biWidth  は画像の幅 */
            tmp.r = img[hd->biHeight - j - 1][i].r;
            img[hd->biHeight - j - 1][i].r = img[j][i].r;
            img[j][i].r = tmp.r;

            tmp.g = img[hd->biHeight - j - 1][i].g;
            img[hd->biHeight - j - 1][i].g = img[j][i].g;
            img[j][i].g = tmp.g;

            tmp.b = img[hd->biHeight - j - 1][i].b;
            img[hd->biHeight - j - 1][i].b = img[j][i].b;
            img[j][i].b = tmp.b;

            
        }
    }

    
    /************** ここまで *************************************************/
}
