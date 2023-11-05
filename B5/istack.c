#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "istack.h"

istack_t *istack_new(int size)
{
    istack_t *s = NULL;
    s = (istack_t *)malloc(sizeof(istack_t));
    if (s == NULL)
    { 
        fprintf(stderr, "s のmalloc が失敗\n");
        exit(1);
    }
    s->size = size;
    s->sp = 0;
    s->data = (int *)malloc(sizeof(int) * size);
    if (s->data == NULL)
    { 
        fprintf(stderr, "s->data のmalloc が失敗\n");
        exit(1);
    }
    return s;
} /* サイズ size のスタックを新たに作り, そのポインタを返す */
void istack_delete(istack_t *s)
{
    free(s->data);
    free(s);
}
int istack_empty(istack_t *s)
{
    if (s->sp == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}      /* スタックが空のとき 1 を, そうでないとき 0 を返す */
int istack_full(istack_t *s)
{
    if (s->sp == s->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}       /* スタックが満杯のとき 1 を, そうでないとき 0 を返す */
void istack_push(istack_t *s, int d)
{
    if(s->sp < s->size)
    {
        s->data[s->sp] = d;
        s->sp++;
    }
    if(s->sp == s->size)
    {
        s->size = s->size * 2;
        s->data = (int *)realloc(s->data, sizeof(int) * s->size * 2);
    }
} /* データ d をスタック末尾に追加する */
void istack_pop(istack_t *s, int *d)
{
    if(s->sp > 0)
    {
        s->sp--;
        *d = s->data[s->sp];
    }
    if(s->sp == 0)
    {
        *d = 0;
    }

} /* スタック末尾のデータを *d にセットし, スタックから削除する */