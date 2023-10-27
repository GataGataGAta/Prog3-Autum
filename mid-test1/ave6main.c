#include <stdio.h>
#include "ave6.h"

int main(void)
{
    double a, b;
    double ave_p;
    double ave_x;

    for (;;)
    {
        fprintf(stderr, "a, bの値を入力:");
        if (scanf("%lf %lf", &a, &b) == EOF)
        {
            break;
        }
        average(a, b, &ave_p, &ave_x);
        printf("%.3f, %.3f\n", ave_p, ave_x);
    }
}
