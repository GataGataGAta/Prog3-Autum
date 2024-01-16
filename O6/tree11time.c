#include <stdio.h>
#include <time.h>
#include "tree.h"

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
    tree_node_t *p = NULL; 
    printf("乱数を何個生成しますか?: ");
    scanf("%d", &n);

    myrand_init();
    clock_t clk_start, clk_end;

    for (int i = 0; i < n; i++)
    {
        p = tree_insert_uniq(p, myrand());
    }

    clk_start = clock();
    for (int i = 0; i < n; i++)
    {
        tree_find(p, myrand());
    }
    clk_end = clock();

    printf("実行時間 = %g [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC / n);

    tree_delete(p);

    return 0;
}
