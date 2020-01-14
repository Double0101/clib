//
// Created by Double on 2019-04-11.
//
#include <stdlib.h>
#include "priorityqueue.h"

struct priorityqueue*
new_priorityqueue(int compare(void* data1, void* data2))
{
    struct priorityqueue *queue;
    queue = malloc(sizeof(*queue));
    queue -> size = 0;
    queue -> first = NULL;
    queue -> last = NULL;
    queue -> compare = compare;
    return queue;
}

struct qnode*
new_qnode(void* weight, void* element)
{
    struct qnode* node;
    node = malloc(sizeof(*node));
    node -> element = element;
    node -> weight = weight;
    return node;
}

void
free_qnode(struct qnode* node)
{
    node -> weight = NULL;
    node -> element = NULL;
    node -> pre = node -> next = NULL;
    free(node);
}

void
priority_heapify(struct priorityqueue* queue, int index, struct qnode* node)
{
    int l = (index << 1) + 1;
    int r = (index + 1) << 1;
    if (index >= queue -> size) return;
    struct qnode *largest = node;
    struct qnode *l_node = node;
    if (l < queue -> size)
    {
        while (index++ < l) l_node = l_node -> next;
    }
    else
    {
        l_node = NULL;
    }
    struct qnode * r_node = l_node;
    if (r < queue -> size)
    {
        while (index++ < r) r_node = r_node -> next;
    }
    else
    {
        r_node = NULL;
    }
    if (l_node)
    {
        if (queue -> compare(l_node, largest) > 0)
        {
            largest = l_node;
            index = l;
        }
        if (r_node && queue -> compare(r_node, largest) > 0)
        {
            largest = r_node;
            index = r;
        }
    }
    if (largest != node)
    {
        void *e_tmp = largest -> element;
        largest -> element = node -> element;
        node -> element = e_tmp;

        void *w_tmp = largest -> weight;
        largest -> weight = node -> weight;
        node -> weight = w_tmp;
        priority_heapify(queue, index, largest);
    }
}

void*
priority_extract_itfirst(struct priorityqueue* queue)
{
    if (queue -> size <= 0) return NULL;
    struct qnode *node = queue -> first;
    struct qnode *last = queue -> last;

    queue -> last = last -> pre;
    if (queue -> last)
        queue -> last -> next = NULL;
    last -> pre = NULL;

    if (node != last)
    {
        queue -> first = last;
        queue -> first -> next = node -> next;
        queue -> first -> next -> pre = queue -> first;
    }
    else
    {
        queue -> first = NULL;
        queue -> last = NULL;
    }
    --queue -> size;
    priority_heapify(queue, 0, queue -> first);

    void *element = node -> element;
    free_qnode(node);
    return element;
}

void*
priority_first(struct priorityqueue* queue)
{
    return queue -> first -> element;
}

void
priority_insert(struct priorityqueue* queue, void* weight, void* element)
{
    struct qnode* node = new_qnode(weight, element);
    ++queue -> size;
    if (queue -> first)
    {
        queue -> last -> next = node;
        node -> pre = queue -> last;
    }
    else
    {
        queue -> first = node;
    }
    queue -> last = node;
    int index = queue -> size - 1;
    while (index > 0)
    {
        int pindex = (index - 1) >> 1;
        int i = index;
        struct qnode *parent = node;
        while (i-- > pindex)
        {
            parent = parent -> pre;
        }
        if (queue -> compare(node, parent) > 0)
        {
            void *e_tmp = node -> element;
            node -> element = parent -> element;
            parent -> element = e_tmp;

            void *w_tmp = node -> weight;
            node -> weight = parent -> weight;
            parent -> weight = w_tmp;
            node = parent;
            index = pindex;
        }
        else return;
    }
}