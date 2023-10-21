#include <stdio.h>
#include "image1.h"
#define Size 16

void bmp_mosaic(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]);

int main(void)
{
   bmp_header_t hd;
   pixel_t img[MAX_Y][MAX_X];

   bmp_read("in.bmp", &hd, img);    /* in.bmp から読み込む */
   bmp_mosaic(&hd, img);            
   bmp_write("out.bmp", &hd, img);  /* out.bmp への書き出し */

   return 0;
}

void bmp_mosaic(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]) 
{
   int i, j, k, p;
   for (i = 0; i < hd->biHeight; i += Size) 
   {
   	   for (j = 0; j < hd->biWidth / 2; j += Size) 
	   {
           int r = 0;
		   int g = 0;
	       int b = 0;
		   int pixelCount = 0;

		   for (k = 0; k < Size; k++) 
		   {
		      for (p = 0; p < Size; p++) 
			  {
			     r += img[i + k][j + p].r;
				 g += img[i + k][j + p].g;
				 b += img[i + k][j + p].b;
				 pixelCount++;
			   }
		   }

		   r /= pixelCount;
		   g /= pixelCount;
		   b /= pixelCount;

		   for (k = 0; k < Size; k++) 
		   {
		      for (p = 0; p < Size; p++) 
			  {
				 img[i + k][j + p].r = r;
				 img[i + k][j + p].g = g;
			 	 img[i + k][j + p].b = b;
		      }
		   }
       }
   }
}