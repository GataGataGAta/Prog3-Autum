#include <stdio.h>

void triple(int *p, int *q);

int main(void)
{
    int a, b;
    a = 1;
    b = 2;

    triple(&a, &b);

    printf("a = %d, b = %d\n", a, b);
}

void triple(int *p, int *q)
{
    *p = *p * 3;
    *q = *q * 3;
}