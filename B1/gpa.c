#include <stdio.h>
#include <math.h>

int main(void)
{
   int a; 
   int b = 0;
   int c = 0;
   int d = 0;
   int e = 0;
   int f = 0;
   int g = 0;
   int h = 0;
   int i = 0;
   double ave;

   for (;;) {  /* 無限ループ */
      fprintf(stderr, "点数を入力してください:");
      if (scanf("%d", &a)==EOF) { break; }  /* 入力がなければループ脱出 */ /* 入力がなければループ脱出 */

      if(a >= 90)
      {
        printf("4.0\n");
        b++;
      }

      else if(a >= 85)
      {
        printf("3.5\n");
        c++;
      }

      else if(a >= 80)
      {
        printf("3.0\n");
        d++;
      }

      else if(a >= 75)
      {
        printf("2.5\n");
        e++;
      }

      else if(a >= 70)
      {
        printf("2.0\n");
        f++;
      }

      else if(a >= 65)
      {
        printf("1.5\n");
        g++;
      }

      else if(a >= 60)
      {
        printf("1.0\n");
        h++;
      }

      else
      {
        printf("0.0\n");
        i++;
      }
   }
    ave = (b * 4.0 + c * 3.5 + d * 3.0 + e * 2.5 + f * 2.0 + g * 1.5 + h * 1.0 + i * 0.0) / 26;
    printf("%0.3f", ave);

   return 0;
}