#include <stdio.h>
#include "qeq2.h"

int main(void)
{
    double a, b, c;
    for (;;)
    {
        fprintf(stderr, "ax^2 + bx + cの係数を入力してください(a=0.0で終了します):");
        scanf("%lf %lf %lf", &a, &b, &c);
        if (a == 0.0)
        {
            break;
        }
        qeq(a, b, c);

    }
}