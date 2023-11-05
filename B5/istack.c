#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "istack.h"

istack_t *istack_new(int size);  /* サイズ size のスタックを新たに作り, そのポインタを返す */
void istack_delete(istack_t *s);  /* スタックを破棄する */
int istack_empty(istack_t *s);  /* スタックが空のとき 1 を, そうでないとき 0 を返す */
int istack_full(istack_t *s);  /* スタックが満杯のとき 1 を, そうでないとき 0 を返す */
void istack_push(istack_t *s, int d);  /* データ d をスタック末尾に追加する */
void istack_pop(istack_t *s, int *d);  /* スタック末尾のデータを *d にセットし, スタックから削除する */