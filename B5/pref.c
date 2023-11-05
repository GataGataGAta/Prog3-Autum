#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pref.h"

#define NAMELEN 15

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

pref_t *pref_new_scan()
{
    pref_t *b = NULL;
    b = (pref_t *)malloc(sizeof(pref_t));

    if (scanf("%s", b->name) == EOF || scanf("%lf", &b->area) == EOF || scanf("%d", &b->population) == EOF)
    {
        return NULL;
    }
    return b;
}