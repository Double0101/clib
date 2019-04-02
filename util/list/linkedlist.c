#include <stdlib.h>
#include <assert.h>

#include "../../include/linkedlist.h"

void add_first_node(struct linkedlist* list, struct node* n);
void add_last_node(struct linkedlist* list, struct node* n);



struct linkedlist*
new_linkedlist()
{
    struct linkedlist *list = malloc(sizeof(*list));
    list -> head = list -> tail = NULL;
    list -> size = 0;
    return list;
}

struct node*
linked_new_node(void* data)
{
    struct node *newnode;
    newnode = malloc(sizeof(*newnode));
    newnode -> data = data;
    return newnode;
}

void 
linked_add_first(struct linkedlist* list, void* data)
{
    struct node *newnode = linked_new_node(data);
    add_first_node(list, newnode);
}

void
linked_add_last(struct linkedlist* list, void* data)
{
    struct node *newnode = linked_new_node(data);
    add_last_node(list, newnode);
}

struct node*
linkedlist_contains(struct linkedlist* list, struct node* n)
{
    assert(n);
    struct node* nn = list -> head;
    while (nn) {
        if (n == nn) return nn;
        nn = nn -> next;
    }
    return NULL;
}

struct node*
linkedlist_get(struct linkedlist* list, int index)
{
    if (index < list -> size) 
    {
        struct node* n = list -> head;
        int i = 0;
        while (i != index) {
            n = n -> next;
            ++i;
        }
        return n;
    }
    return NULL;
}

void 
linked_node_free(struct node* n)
{
    free(n -> data);
    free(n);
}

void
clear_linked_list(struct linkedlist* list)
{
    int i = list -> size;
    while (i-- != 0)
    {
        linked_remove_node(list, 0);
    }
}

int
linked_index(struct linkedlist* list, struct node* n)
{
    int idx = 0;
    struct node* nn = list -> head;
    while (nn != n && nn != NULL)
    {
        nn = nn -> next;
        ++idx;
    }
    if (nn) return idx;
    return -1;
}

void
linked_remove_node(struct linkedlist* list, int index)
{
    struct node* n = linked_remove_and_get(list, index);
    linked_node_free(n);
}

struct node*
linked_remove_and_get(struct linkedlist* list, int index)
{
    struct node* n = linkedlist_get(list, index);
    if (!n) return NULL;
    if (n -> pre && n -> next)
    {
        n -> pre -> next = n -> next;
        n -> next -> pre = n -> pre;
    }
    else if (n -> pre && !n -> next)
    {
        n -> pre -> next = n -> next;
        list -> tail = n -> pre;
    }
    else if (!n -> pre && n -> next)
    {
        list -> head = n -> next;
        n -> next -> pre = n -> pre;
    }
    else
    {
        list -> head = list -> tail = NULL;
    }
    --(list -> size);
    n -> next = n -> pre = NULL;
    return n;
}

void
linked_insert_data_into(struct linkedlist* list, void* data, int index)
{
    struct node* nn = linked_new_node(data);
    linked_insert_into(list, nn, index);
}

void
linked_insert_into(struct linkedlist* list, struct node* n, int index)
{
    assert(index >= 0 && index <= list -> size && n);
    if (index == 0)
    {
        add_first_node(list, n);
    }
    else if (index == list -> size)
    {
        add_last_node(list, n);
    }
    else
    {
        struct node* nn = linkedlist_get(list, index - 1);
        nn -> next -> pre = n;
        n -> next = nn;
        nn -> next = n;
        n -> pre = nn;
    }
    ++(list -> size);
}

void 
add_first_node(struct linkedlist* list, struct node* n)
{
    assert(n);
    n -> next = list -> head;
    list -> head = n;
    ++(list -> size);
    if (list -> head -> next) 
    {
        list -> head -> next -> pre = list -> head;
    } 
    else
    {
        list -> tail = list -> head;
    }
}

void 
add_last_node(struct linkedlist* list, struct node* n)
{
    assert(n);
    n -> pre = list -> tail;
    list -> tail = n;
    ++(list -> size);
    if (list -> tail -> pre) 
    {
        list -> tail -> pre -> next = list -> tail;
    } 
    else
    {
        list -> head = list -> tail;
    }
}