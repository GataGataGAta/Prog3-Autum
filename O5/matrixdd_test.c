#include <stdio.h>
#include "matrixdd.h"

int main(void)
{
   int n;
   double **A = NULL;
   double **B = NULL;
   double **Y = NULL;

   fprintf(stderr, "n = ");
   scanf("%d", &n);

   A = matrixdd_new(n);
   B = matrixdd_new(n);
   Y = matrixdd_new(n);

   fprintf(stderr, "A\n");
   matrixdd_scan(n, A);
   fprintf(stderr, "B\n");
   matrixdd_scan(n, B);

   matrixdd_sum(n, A, B, Y);

   printf("A\n");
   matrixdd_print(n, A);
   printf("B\n");
   matrixdd_print(n, B);
   printf("Y\n");
   matrixdd_print(n, Y);

   matrixdd_delete(n, Y);
   matrixdd_delete(n, B);
   matrixdd_delete(n, A);
   Y = NULL;
   B = NULL;
   A = NULL;

   return 0;
}