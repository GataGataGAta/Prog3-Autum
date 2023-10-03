#include <stdio.h>
#include "dist3.h"

#define Count 3

int main(void)
{

    double x1, y1, x2, y2, result;
    for (int i = 0; i < Count; i++)
    {
        fprintf(stderr, "実数を四つ入力してください>>>");
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
        result = dist(x1, y1, x2, y2);
        printf("%.4f\n", result);
    }

    return 0;
}