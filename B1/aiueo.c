#include <stdio.h>
#include <string.h>  /* strcmp 等の文字列関数使用時に必要 */

#define W_LEN 31  /* 文字列 w の最大文字数 */
#define W_FMT "%31s"  /* 文字列 w を読み込むフォーマット */

int main(void)
{
   int i;
   char w[W_LEN+1];

   for (;;) {

     fprintf(stderr, "英単語を入力して下さい (qq で終了): ");
     scanf(W_FMT, w);
     if (strcmp(w,"qq")==0) { break; }  /* 終了判定 */

     for (i=0; w[i]!='\0'; i++) 
     {  
        if (w[i]=='a' || w[i] == 'i'|| w[i] == 'u' || w[i] == 'e' || w[i] == 'o') 
        {
         w[i] = w[i];
        }
      
         else
         {
            w[i] = '*';
         }
     }
     printf("%s\n", w);

   }


   return 0;
}