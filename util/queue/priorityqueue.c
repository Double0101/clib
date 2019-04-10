//
// Created by Double on 2019-04-11.
//
#include <stdlib.h>
#include "../../include/priorityqueue.h"

struct prioriryqueue*
new_priorityqueue(int compare(void* data1, void* data2))
{
    struct priorityqueue *queue;
    queue = malloc(sizeof(*queue));
    queue -> size = 0;
    queue -> first = NULL;
    queue -> last = NULL;
    queue -> compare = compare;
}
