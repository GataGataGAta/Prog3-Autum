#include <stdio.h>
#include <math.h>
#include "newton.h"

double newton(double a, double b, double c, double x0, double eps, int max_repeat)
{
    double x1, f_x0, df_x0;
    int i;

    for (i = 0; i < max_repeat; i++)
    {
        f_x0 = a * x0 * x0 + b * x0 + c;
        df_x0 = 2 * a * x0 + b;

        if (fabs(df_x0) < eps)
        {
            fprintf(stderr, "導関数が小さすぎます。\n");
            return x0;
        }

        x1 = x0 - f_x0 / df_x0;

        fprintf(stderr, "  %d  %23.10f  %23.10f  %23.10f\n", i, x0, f_x0, x1);

        if (fabs(x1 - x0) < eps)
        {
            return x1;
        }

        x0 = x1;
    }

    fprintf(stderr, "最大反復回数に達しました。最後の近似値: %23.10f\n", x1);
    return x1;
}
