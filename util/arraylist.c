//
// Created by Double on 2019-03-29.
//

#include <stdlib.h>
#include <assert.h>

#include "../include/arraylist.h"

struct arraylist*
new_arraylist(int capacity)
{
    struct arraylist *list;
    list = malloc(sizeof(*list));
    list -> capacity = capacity;
    list -> size = 0;
    list -> data = malloc(capacity * sizeof(void*));
    int i;
    for (i = 0; i < capacity; ++i) {
        (list -> data)[i] = NULL;
    }
    return list;
}

void
resize_arraylist(struct arraylist* list, int new_capacity)
{
    void **data = malloc(new_capacity * sizeof(void*));
    memcpy(data, list -> data, (list -> capacity) * sizeof(void*));
    list -> data = data;
    free(list -> data);
}

void
clear_arraylist(struct arraylist* list)
{
    int i;
    for (i = 0; i < list -> capacity; ++i)
    {
        free((list -> data)[i]);
        (list -> data)[i] = NULL;
    }
    free(list -> data);
    list -> data = NULL;
    list -> capacity = list -> size = 0;
    free(list);
    list = NULL;
}

void*
arraylist_replace(struct arraylist* list, int index, void* data)
{
    void *tmp = (list -> data)[index];
    (list -> data)[index] = data;
    return tmp;
}

void
arraylist_insert(struct arraylist* list, int index, void* data)
{
    void *tmp = arraylist_replace(list, index, data);
    if (tmp) free(tmp);
}

