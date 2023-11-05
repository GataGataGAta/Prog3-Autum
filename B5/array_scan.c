#include <stdio.h>
#include <stdlib.h>

int* new_array_scan(int *pn)
{
    int *a = NULL; 
    int n, i;
    fprintf(stderr, "nを入力してください: ");
    scanf("%d", &n);
    a = (int *) malloc(sizeof(int)*n); /* 動的割当て; 書き方は覚える */
    if (a == NULL)
    { /* malloc が失敗すると NULL が返るので, エラー処理 */
        fprintf(stderr, "a のmalloc が失敗\n");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
       
        scanf("%d", &a[i]);
    } /* 値のセット */

    *pn = n;

    return a;
}