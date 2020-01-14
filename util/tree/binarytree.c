#include <stdlib.h>

#include "binarytree.h"

struct binarytree*
new_binarytree(int (*compare)(void*, void*))
{
    struct binarytree* tree = (struct binarytree*) malloc(sizeof(struct binarytree));
    tree->compare = compare;
    tree->size = 0;
    tree->root = NULL;
    return tree;
}


