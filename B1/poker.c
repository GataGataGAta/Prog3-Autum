#include <stdio.h>

#define numbers 5
#define cards 13

int main(void)
{
    int n[numbers];
    int c[cards];
    int i, j;
    //int count1, count2;
    for (i = 0; i < cards; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < numbers; i++)
    {
        n[i] = 0;
    }
    
    i = 0;
    for (;;)
    {
        fprintf(stderr, "整数を入力してください:");
        if (scanf("%d", &n[i]) == EOF)
        {
            break;
        }
        c[n[i]]++;
        i++;
    }
    printf("\n");
    for(i = 0; i < cards; i++)
    {
        printf("%d %d\n", i, c[i]);
    }

    for (i = 0; i < cards; i++)
    {
        
    }

    return 0;
}