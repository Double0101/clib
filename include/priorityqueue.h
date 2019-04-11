//
// Created by Double on 2019-04-11.
//

#ifndef CLIB_PRIORITYQUEUE_H
#define CLIB_PRIORITYQUEUE_H

struct qnode
{
    void *weight;
    void *element;
    struct qnode* next;
    struct qnode* pre;
};

struct priorityqueue
{
    struct qnode* first;
    struct qnode* last;
    int size;
    int (*compare)(void* data1, void* data2);
};

struct priorityqueue* new_priorityqueue(int compare(void* data1, void* data2));
void* priority_extract_first(struct priorityqueue* queue);
void* priority_first(struct priorityqueue* queue);
void priority_insert(struct priorityqueue* queue, void* weight, void* element);

#endif //CLIB_PRIORITYQUEUE_H
