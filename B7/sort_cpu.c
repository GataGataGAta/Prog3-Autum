#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* 時間計測に必要 */
#include <assert.h>

#define MIN_N 1024 /* 完成後にもっと大きくする */
#define MAX_N 65536 /* 完成後にもっと大きくする */
#define N_TEST 8

void sort(int n, double *a);

void array_set_rand(int n, double *a)
{
    /* a[0]〜a[n-1] に乱数のデータをセットする */
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = rand();
    }
}

void array_set_sorted(int n, double *a)
{
    /* a[0]〜a[n-1] に正順のデータをセットする */
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

void array_set_reverse(int n, double *a)
{
    /* a[0]〜a[n-1] に逆順のデータをセットする */
    int i;
    for (i = n; i > 0; i--)
    {
        a[n - i] = i;
    }
}

void array_copy(int n, double *a, double *r)
{
    /* r[0]〜r[n-1] から a[0]〜a[n-1] にデータコピーする */
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = r[i];
    }
}

void sort_check(int n, double *a)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] <= a[i + 1])
        {
            ; /* OK */
        }
        else
        {
            /* データが (a[i] と a[i+1] が) 昇順に並んでいない */
            fprintf(stderr, "sort error (a[%d]=%0.10f, a[%d]=%0.10f)\n", i, a[i], i + 1, a[i + 1]);
            exit(1);
        }
    }
}

void sort_cpu(double *r)
{
    int n;
    int i;
    double *a;
    int t0, t1;

    /* 初期データがちゃんと生成されているかの確認用 */
    for (i = 0; i < N_TEST; i++)
    {
        printf("%18.5f\n", r[i]);
    }

    /** ここを埋めて関数を完成させよ **/
    /*サイズ MAX_N の double 型配列の動的領域を割り当て, その先頭要素へのポインタを a に代入する;
    n = MIN_N から始め, n が MAX_N を超えない範囲で, n を毎回 2 倍に増やしながら繰り返す {
    n の値を出力する (例: "n = 8" 等);
    array_copy を呼び出し, r[0]〜r[n-1] を a[0]〜a[n-1] にコピーする;
    sort 関数で a[0]〜a[n-1] をソートする; … (1)
    sort_check(n, a) を呼び出す (正しくソートが行われていることを確認する);
    (1) にかかった CPU 時間を出力する;
    }
    a の指す動的領域を解放する; */
    
    a = (double *)malloc(sizeof(double) * MAX_N);
    if (a == NULL)
    {
        fprintf(stderr, "malloc に失敗 (MAX_N = %d\n", MAX_N);
        exit(1);
    }
    for (int i = MIN_N; i <= MAX_N; i *= 2)
    {
        printf("nの値: %d\n", i);
        array_copy(i, a, r);
        clock_t clk_start, clk_end;
        clk_start = clock();
        sort(i, a);
        clk_end = clock();
        printf("cpu = %11.6f [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);
        sort_check(i, a);
    }
    free(a);
    a = NULL;
}

int main(void)
{
    double *r;
    int i;

    r = (double *)malloc(sizeof(double) * MAX_N);
    if (r == NULL)
    {
        fprintf(stderr, "malloc に失敗 (MAX_N = %d\n", MAX_N);
        exit(1);
    }

    printf("乱数\n");
    array_set_rand(MAX_N, r);
    sort_cpu(r);

    printf("正順\n");
    array_set_sorted(MAX_N, r);
    sort_cpu(r);

    printf("逆順\n");
    array_set_reverse(MAX_N, r);
    sort_cpu(r);

    free(r);
    r = NULL;

    return 0;
}