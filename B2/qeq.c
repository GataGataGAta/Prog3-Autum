#include <stdio.h>
#include <math.h>

void qeq(double a, double b, double c);

int main(void)
{
    double a, b, c;
    for (;;)
    {
        a = 0.0;
        b = 0.0;
        c = 0.0;
        fprintf(stderr, "ax^2 + bx + cの係数を入力してください(a=0.0で終了します):");
        scanf("%lf %lf %lf", &a, &b, &c);
        if (a == 0.0)
        {
            break;
        }
        qeq(a, b, c);

    }
}

void qeq(double a, double b, double c)
{
    for (;;)
    {
        double x1 = 0;
        double x2 = 0;
        double D = 0;

        D = b * b - 4 * a * c;
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

        if (D < 0)
        {
            printf("\n");
            break;
        }
        if (x1 == x2)
        {
            printf("%0.5f\n", x1);
            break;
        }
        else
        {
            if(x1 < x2)
            {
                printf("%0.5f %0.5f\n", x1, x2);
                break;
            }
            else
            {
                printf("%0.5f %0.5f\n", x2, x1);
                break;
            }
        }
    }
}