#ifndef __CLIB_LINKEDLIST_H__
#define __CLIB_LINKEDLIST_H__

struct node
{
    struct node *next;
    struct node *pre;
    void *data;
};

struct linkedlist
{
    int size;
    struct node *head;
    struct node *tail;
    void (*destruct)(void*);
    int (*compare)(void*, void*);
};

struct linkedlist* new_linkedlist();
void linked_list_free(struct linkedlist* list);
void linked_node_free(struct linkedlist* list, struct node* n);
void clear_linked_list(struct linkedlist* list);
void linked_add_first(struct linkedlist* list, void* data);
void linkedlist_add_last(struct linkedlist* list, void* data);
struct node* linkedlist_contains(struct linkedlist* list, struct node* n);
struct node* linkedlist_get(struct linkedlist* list, int index);
int linked_index(struct linkedlist* list, struct node* n);
void linked_remove_node(struct linkedlist* list, int index);
struct node* linked_remove_and_get(struct linkedlist* list, int index);
void linked_insert_data_into(struct linkedlist* list, void* data, int index);
void linked_insert_into(struct linkedlist* list, struct node* n, int index);
#endif