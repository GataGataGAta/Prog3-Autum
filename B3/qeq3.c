#include <math.h>
#include <stdio.h>
#include "qeq3.h"

int qeq(double a, double b, double c, double *x1, double *x2)
{
    double D = 0;
    double *y;
    D = b * b - 4 * a * c;
    if(D < 0)
    {
        return 0;
    }
    if(D == 0)
    {
        *x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        return 1;
    }
    else
    {
        *x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        *x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        if(*x1 < *x2)
        {
            return 2;
        }
        else
        {
            *y = *x1;
            *x1 = *x2;
            *x2 = *y;
            return 2;
        }
        return 2;
    }

    
}