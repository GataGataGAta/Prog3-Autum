#include <stdio.h>
#include "tree.h"

int main (void)
{
  tree_node_t *root = NULL;

  for (;;) {
    int data;
    fprintf(stderr, "input = ");
    if (scanf("%d", &data)==EOF) { break; }
    tree_node_t *p = tree_find(root,data);
    if (p==NULL) {
      root = tree_insert_uniq(root,data);
    }
    printf("[");
    tree_print(root);
    printf(" ]\n");
  }

  tree_delete(root); 
  return 0;
}