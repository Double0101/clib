#ifndef __LIBS_LINKEDLIST_H__
#define __LIBS_LINKEDLIST_H__

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

node* new_node(void* data);
void add_first(linkedlist* list, void* data);
void add_last(linkedlist* list, void* data);
#endif