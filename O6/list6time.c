#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

static unsigned long myrand_r;

#define R_INIT 53402397UL
#define A 65539UL
#define B 125654UL
#define MASK 0x7fffffffUL

void myrand_init(void)
{
    myrand_r = R_INIT;
}

int myrand(void)
{
    myrand_r = (myrand_r * A + B) & MASK;
    return (int)myrand_r;
}

int main()
{
    int n = 0;
    list_node_t *p = create_node(0);
    printf("乱数を何個生成しますか?:");
    scanf("%d", &n);
    int i;
    myrand_init();
    clock_t clk_start, clk_end;
    clk_start = clock();
    for (i = 0; i < n; i++)
    {
        list_insert_delete_dup(p, myrand());
    }
    clk_end = clock();
    printf("一つ目の乱数の検索 = %g [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC / n);
    myrand_init();
    for (i = 0; i < n; i++)
    {
        list_insert(p, myrand());
    }
    myrand_init();
    clk_start = clock();
    for (i = 0; i < n; i++)
    {
        list_insert_delete_dup2(p, myrand());
    }
    clk_end = clock();
    printf("二つ目の乱数の検索 = %g [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC / n);
}
