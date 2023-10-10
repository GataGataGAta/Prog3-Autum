#include <stdio.h>

int main()
{
    int a, b;
    double x, y;
    a = 12;
    b = 34;
    x = 1.0;
    y = 2.0;

    printf(" a のの番地は%pです。\n", &a);
    printf(" b のの番地は%pです。\n", &b);
    printf(" x のの番地は%pです。\n", &x);
    printf(" y のの番地は%pです。\n", &y);

    printf("\n");
    printf(" a の値は%dです。\n", a);
    printf(" b の値は%dです。\n", b);
    printf(" x の値は%fです。\n", x);
    printf(" y の値は%fです。\n", y);

    a = 24;
    b = 56;
    x = 3.0;
    y = 4.0;
    
    printf("\n");
    printf(" a の値は%dです。\n", a);
    printf(" b の値は%dです。\n", b);
    printf(" x の値は%fです。\n", x);
    printf(" y の値は%fです。\n", y);

    return 0;
}