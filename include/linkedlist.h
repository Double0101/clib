#ifndef __CLIB_LINKEDLIST_H__
#define __CLIB_LINKEDLIST_H__

struct node
{
    void *data;
    struct node *next;
    struct node *pre;
};

struct linkedlist
{
    int size;
    struct node *head;
    struct node *tail;
};

struct linkedlist* new_linkedlist();
void linked_list_free(struct linkedlist* list);
struct node* new_node(void* data);
void linked_node_free(struct node* n);
void add_first(struct linkedlist* list, void* data);
void add_last(struct linkedlist* list, void* data);
struct node* contains(struct linkedlist* list, struct node* n);
struct node* get(struct linkedlist* list, int index);
int index(struct linkedlist* list, struct node* n);
void remove_node(struct linkedlist* list, int index);
struct node* remove_and_get(struct linkedlist* list, int index);
void insert_data_into(struct linkedlist* list, void* data, int index);
void insert_into(struct linkedlist* list, struct node* n, int index);
#endif