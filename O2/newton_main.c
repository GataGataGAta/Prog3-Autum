#include <stdio.h>
#include "newton.h"
#define MAX_REPEAT 10

int main(void)
{
  int i;
  for (i = 0; i < MAX_REPEAT; i++)
  {
    double a, b, c, x0, eps;
    int max_repeat;
    fprintf(stderr, "a, b, c, x0, eps, max_repeat を入力 : ");
    if (scanf("%lf %lf %lf %lf %lf %d", &a, &b, &c, &x0, &eps, &max_repeat) == EOF)
    {
      break;
    }
    double x = newton(a, b, c, x0, eps, max_repeat);
    printf("%23.20f\n", x);
  }
  return 0;
}