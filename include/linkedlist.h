#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct
{
    void *data;
    node *next;
    node *pre;
} node;

typedef struct
{
    node *head;
    node *tail;
} linkedlist;

#endif