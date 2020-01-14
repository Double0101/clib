
#ifndef __CLIB_BINARYTREE_H__
#define __CLIB_BINARYTREE_H__

struct binarytreenode
{
    void *data;
    struct binarytreenode *left;
    struct binarytreenode *right;
};

struct binarytree
{
    struct binarytreenode *root;
    int size;
    int (*compare)(void*, void*);
};

struct binarytree*
new_binarytree(int (*compare)(void*, void*));

#endif // __CLIB_BINARYTREE_H__
