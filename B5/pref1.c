#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 15

typedef struct
{
    char name[NAMELEN + 1]; /* 県名 */
    double area;            /* 面積 (km2)*/
    int population;         /* 人口 (人) */
} pref_t;

pref_t *pref_new(char *name, double area, int population)
{
    pref_t *a = NULL;

    /* 動的割当て */
    a = (pref_t *)malloc(sizeof(pref_t));

    /* 値の代入 */
    strcpy(a->name, name);
    a->area = area;
    a->population = population;

    return a;
}

void pref_print(pref_t *p)
{
    printf("%s   %.2f  %d\n", p->name, p->area, p->population);
}

pref_t *pref_new_scan() {
    char name[NAMELEN + 1];
    double area;
    int population;
    
    // %15s は、nameのサイズに合わせてバッファオーバーランを防ぐ
    int items_read = scanf("%15s %lf %d", name, &area, &population);
    
    // 3つの入力が読み込まれなかった場合、EOFまたはエラーが発生したと判断
    if (items_read != 3) {
        return NULL; // EOFまたはエラーを検出
    }
    
    return pref_new(name, area, population);
}