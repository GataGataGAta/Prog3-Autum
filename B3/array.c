#include <stdio.h>

int main(void)
{
    int x[ ] = {0,10,20,30,40};
    /* x[0]=0, x[1]=10, x[2]=20, x[3]=30, x[4]=40 と初期化される */
    int k;
    k = sizeof x / sizeof x[0];
    int *p;

    for(int i = 0; i < k; i++)
    {
        printf("x[%d]のアドレスは%pです。\n", i, &x[i]);
    }

    printf("\n");
    printf("xのアドレスは%pです。\n", &x);

    printf("\n");
    for(int j = 0; j < k; j++)
    {
        printf("x+%dのアドレスは%pです。\n", j, &x+j);
    }

    printf("\n");
    for(int n = 0; n < k; n++)
    {
        printf("x[%d]の値は%dです。\n", n, x[n]);
    }

    p = &x[2];
    printf("\n");
    printf("p + 2の値は%pです。\n", &p + 2);
    printf("p[2]の値は%dです。\n", p[2]);

    return 0;

}