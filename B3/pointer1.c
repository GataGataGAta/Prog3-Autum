#include <stdio.h>

int main(void)
{
    int a, b;
    double x, y;

    printf(" a のの番地は%pです。\n", &a);
    printf(" b のの番地は%pです。\n", &b);
    printf(" x のの番地は%pです。\n", &x);
    printf(" y のの番地は%pです。\n", &y);

    return 0;
}