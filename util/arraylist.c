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
    return list;
}

void
resize(struct arraylist* list, int new_capacity)
{
    void **data = malloc(new_capacity * sizeof(void*));
    memcpy(data, list -> data, (list -> capacity) * sizeof(void*));
    list -> data = data;
    free(list -> data);
}

