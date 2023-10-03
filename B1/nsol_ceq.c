#include <stdio.h>

int main(void)
{
    double a, b, c, d;
    for (;;)
    {
        fprintf(stderr, "f(x) = ax^3 + bx^2+ cx + d (ただし a≠0)のa,b,c,dの値を入力してください:");
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

        if(a == 0)
        {
            fprintf(stderr, "aに0が入力されたので終了します\n");
            break;
        }

        double D = (-4 * a * c * c * c) - (27 * a * a * d * d) + (b * b * c * c) + (18 * a * b * c * d) - (4 * b * b * b * d); // 三次式の判別式です。        
        if(D > 0)
        {
            printf("実数解は3個\n");
        }

        if (D < 0)
        {
            printf("実数解は1個\n");
        }

        else
        {
            printf("実数解は2個\n");
        }
    }

    return 0;
}