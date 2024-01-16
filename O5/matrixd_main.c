#include <stdio.h>
#include "matrixd.h"

int main(void)
{
   int n;
   double *A = NULL;
   double *B = NULL;
   double *Y = NULL;

   fprintf(stderr, "n = ");
   scanf("%d", &n);

   A = matrixd_new(n);
   B = matrixd_new(n);
   Y = matrixd_new(n);

   fprintf(stderr, "A\n");
   matrixd_scan(n, A);
   fprintf(stderr, "B\n");
   matrixd_scan(n, B);

   matrixd_sum(n, A, B, Y);

   printf("A\n");
   matrixd_print(n, A);
   printf("B\n");
   matrixd_print(n, B);
   printf("Y\n");
   matrixd_print(n, Y);

   matrixd_delete(Y);
   matrixd_delete(B);
   matrixd_delete(A);
   Y = NULL;
   B = NULL;
   A = NULL;

   return 0;
}