#include <stdio.h>

int main(void)
{
    int a, b;
    double x, y;
    b = 12;
    x = 1.0;
    y = 1.0;
    int *p;
    double *q, *r;

    printf(" a のの番地は%pです。\n", &a);
    printf(" b のの番地は%pです。\n", &b);
    printf(" x のの番地は%pです。\n", &x);
    printf(" y のの番地は%pです。\n", &y);

    p = &b;
    *p = *p + 4;

    q = &x;
    *q = *q * 2.0;

    r = &y;
    *r = *r * 4.0;

    for (;;)
    {
        printf("番地を入力 : ");
        scanf("%p %p", &q, &r);
        if (p == 0)
        {
            break;
        }
        printf("%p 番地の内容は %f\n", q, *q);
        printf("%p 番地の内容は %f\n", r, *r);
    }
    return 0;
}