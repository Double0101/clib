#include <stdlib.h>
#include <stdio.h>

#include "include/linkedlist.h"

void add_first_node(linkedlist* list, node* n);
void add_last_node(linkedlist* list, node* n);

node*
new_node(void* data)
{
    node *newnode;
    newnode = malloc(sizeof(*newnode));
    newnode -> data = data;
    return newnode;
}

void 
add_first(linkedlist* list, void* data) 
{
    node *newnode = new_node(data);
    add_first_node(list, newnode);
}

void
add_last(linkedlist* list, void* data)
{
    node *newnode = new_node(data);
    add_last_node(list, newnode);
}

void 
add_first_node(linkedlist* list, node* n)
{
    assert(n);
    n -> next = list -> head;
    list -> head = n;
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
add_last_node(linkedlist* list, node* n)
{
    assert(n);
    n -> pre = list -> tail;
    list -> tail = n;
    if (list -> tail -> pre) 
    {
        list -> tail -> pre -> next = list -> tail;
    } 
    else
    {
        list -> head = list -> tail;
    }
}