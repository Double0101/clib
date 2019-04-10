//
// Created by Double on 2019-04-11.
//

#ifndef CLIB_PRIORITYQUEUE_H
#define CLIB_PRIORITYQUEUE_H

struct qnode
{
    void *weight;
    void *element;
    void *next;
    void *pre;
};

struct priorityqueue
{
    struct qnode* first;
    struct qnode* last;
    int size;
    int (*compare)(void* data1, void* data2);
};

struct prioriryqueue* new_priorityqueue(int compare(void* data1, void* data2));

#endif //CLIB_PRIORITYQUEUE_H
