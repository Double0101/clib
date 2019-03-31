//
// Created by Double on 2019-03-29.
//

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../../include/arraylist.h"

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
    list -> capacity = new_capacity;
    free(list -> data);
}

void
clear_arraylist(struct arraylist* list)
{
    int i;
    for (i = 0; i < list -> size; ++i)
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

void
arraylist_add(struct arraylist* list, void* data)
{
    if (list -> size = list -> capacity)
    {
        resize_arraylist(list, 2 * list -> capacity);
    }

    (list -> data)[list -> size] = data;
    ++(list -> size);
}

void
arraylist_delete(struct arraylist* list, int index)
{
    free((list -> data)[index]);
    (list -> data)[index] = NULL;
    memmove((char*) (list -> data) + index * sizeof(void*),
            (char*) (list -> data) + (index + 1) * sizeof(void*),
            ((list -> size) - index - 1) * sizeof(void*));
    --(list -> size);
}

void
arraylist_insert(struct arraylist* list, int index, void* data)
{
    if (list -> size = list -> capacity)
    {
        resize_arraylist(list, 2 * list -> capacity);
    }
    memmove((char*) (list -> data) + (index + 1) * sizeof(void*),
           (char*) (list -> data) + index * sizeof(void*),
           ((list -> size) - index) * sizeof(void*));
    (list -> data)[index] = data;
    ++(list -> size);
}

void*
arraylist_remove_and_get(struct arraylist* list, int index, void* data)
{
    void *d = (list -> data)[index];
    (list -> data)[index] = NULL;
    memmove((char*) (list -> data) + index * sizeof(void*),
            (char*) (list -> data) + (index + 1) * sizeof(void*),
            ((list -> size) - index - 1) * sizeof(void*));
    --(list -> size);
    return d;
}

int
arraylist_contains(struct arraylist* list, void* data)
{
    void* element = *(list -> data);
    int i;
    int size = list -> size;
    for (i = 0; i < size; ++i, ++element)
    {
        if (data == element) return 1;
    }
    return 0;
}