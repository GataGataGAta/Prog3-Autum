#include <stdio.h>
#include <math.h>
#include "bisection.h"

double f(double a, double b, double c, double x)
{
    return a * x * x + b * x + c;
}

double bisection(double x1, double x2, double a, double b, double c, double eps)
{
    int i = 0;
    double xmid, f1, f2, fmid;

    fprintf(stderr, "   i                  x1                 x2             xmid                  f1                  f2               fmid\n");

    while (1)
    {
        xmid = (x1 + x2) / 2;
        f1 = f(a, b, c, x1);
        f2 = f(a, b, c, x2);
        fmid = f(a, b, c, xmid);

        fprintf(stderr, "%3d  %0.8f  %0.8f  %0.8f %0.8f %0.8f %0.8f\n", i, x1, x2, xmid, f1, f2, fmid);

        if (fabs(f1) < eps)
        {
            fprintf(stderr, "%f\n", x1);
            return x1;
        }
        else if (fabs(f2) < eps)
        {
            fprintf(stderr, "%f\n", x2);
            return x2;
        }
        else if (fabs(x1 - x2) < eps)
        {
            fprintf(stderr, "%f\n", x1);
            return x1;
        }

        if (f1 * fmid < 0)
        {
            x2 = xmid;
        }
        else
        {
            x1 = xmid;
        }
        i++;
    }
}
