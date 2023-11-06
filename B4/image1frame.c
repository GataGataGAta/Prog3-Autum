#include <stdio.h>
#include "image1.h"

/* 画像全体をモノクロにする関数 */
void bmp_frame(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

int main(void)
{
    bmp_header_t hd;
    pixel_t img[MAX_Y][MAX_X];

    bmp_read("in.bmp", &hd, img);   /* in.bmp から読み込む */
    bmp_frame(&hd, img);             /* 処理の呼び出し */
    bmp_write("out.bmp", &hd, img); /* out.bmp への書き出し */

    return 0;
}

/* 画像処理の関数の本体 */
void bmp_frame(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j;

    /**** 以下 (現状は画像を全体に暗くする処理になっている) を書き換えて完成させよ ****/
    for (i = 0; i < hd->biHeight; i++)
    { /* biHeight は画像の高さ */
        for (j = 0; j < hd->biWidth; j++)
        { /* biWidth  は画像の幅 */
            if((i <= 7 || (hd->biHeight - i) <= 7) || (j <= 7 || (hd->biWidth - j) <= 7))
            {
                img[i][j].r = 234;
                img[i][j].g = 145;
                img[i][j].b = 152;
            }
        }
    }

    
    /************** ここまで *************************************************/
}