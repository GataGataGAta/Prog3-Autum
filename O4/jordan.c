#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrix.h"

int main (void)
{
  int n;
  double A[N][N];
  double b[N]; 
  double A_copy[N][N];
  double b_copy[N];
  double y[N];

  fprintf(stderr, "n = ");
  scanf("%d", &n);
  assert(n<=N);

  fprintf(stderr, "A = \n");
  matrix_scan(n, A);
  fprintf(stderr, "b = \n");
  vector_scan(n, b);
  printf("\n与えられた A と b\n");
  matrix_vector_print(n, A,b);

  matrix_copy(n, A, A_copy);
  vector_copy(n, b, b_copy);

  gauss_jordan(n, A,b);
  
  printf("\n解 x \n");
  vector_print(n, b);

  matrix_vector_prod(n, A_copy,b,y);
  printf("\nA x (与えられた b に等しければ OK)\n");
  vector_print(n, y);

  return 0;
}