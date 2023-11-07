#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

static tree_node_t *create_node(int val);

static tree_node_t *create_node(int val)
/* 値 val を保持する新しい節点を作成し, その節点へのポインタを返す */
{
    tree_node_t *new_node;
    new_node = (tree_node_t *)malloc(sizeof(tree_node_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "節点の割当てに失敗しました\n");
        exit(1);
    }
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

tree_node_t *tree_insert_uniq(tree_node_t *n, int val)
/* n を根とする二分木に val (の節点) を挿入する */
{
    /* val と同じ値を持つ節点が存在すれば挿入しないようにせよ. */

    if (n == NULL)
    {
        n = create_node(val);
    }
    else if (val < n->data)
    {
        n->left = tree_insert_uniq(n->left, val);
    }
    else if (val == n->data)
    {
        return n;
    }
    else
    {
        n->right = tree_insert_uniq(n->right, val);
    }
    return n;
}

void tree_print(tree_node_t *n)
{
    if (n != NULL)
    {
        tree_print(n->left);    // 左の子ノードを再帰的に表示
        printf(" %d", n->data); // 現在のノードの値を表示
        tree_print(n->right);   // 右の子ノードを再帰的に表示
    }
}

tree_node_t *tree_find(tree_node_t *n, int val)
/* *n を根とする二分木中に値が val の節点を探す
   見つかればその節点のポインタを, なければ NULL を返す */
{
}

void tree_delete(tree_node_t *n)
/* 二分木のデータを解放する */
{
    if (n != NULL)
    {
        tree_delete(n->left);
        tree_delete(n->right);
        free(n);
    }
}