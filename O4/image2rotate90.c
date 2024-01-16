#include <stdio.h>
#include "image2.h"

#define INPUT_FILENAME "in.bmp"
#define OUTPUT_FILENAME "out.bmp"

void bmp_rotate90(const bmp_data_t *a, bmp_data_t *b)
{
    for (int i = 0; i < a->header.biHeight; i++)
    {
        for (int j = 0; j < a->header.biWidth; j++)
        {
            b->img[j][a->header.biHeight - 1 - i] = a->img[i][j];
        }
    }
}

int main(void)
{
    bmp_data_t hd, kaiten;
    bmp_read(INPUT_FILENAME, &hd);

    kaiten.header = hd.header;
    kaiten.header.biHeight = hd.header.biWidth;
    kaiten.header.biWidth = hd.header.biHeight;

    bmp_rotate90(&hd, &kaiten);
    bmp_write(OUTPUT_FILENAME, &kaiten);

    return 0;
}

