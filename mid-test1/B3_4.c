#include <stdio.h>

void diverm(int x, int y, int *q, int *r);

int main(void)
{
    int a, b, q, r;
    a = 15;
    b = 3;
    diverm(a, b, &q, &r);
    printf("%d / %d = %d ... %d", a, b, q, r);

}

void diverm(int x, int y, int *q, int *r)
{
    *q = x / y;
    *r = x % y;
}