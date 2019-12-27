//
// Created by Double on 2019-03-29.
//

#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "../../include/arraylist.h"


struct arraylist*
new_arraylist(unsigned int capacity, unsigned int element_size,
        int compare(void*, void*), void destruct(void*))
{
    struct arraylist *list;

    list = malloc(sizeof(struct arraylist));
    list->capacity = capacity;
    list->e_size = element_size;
    list->data = calloc(capacity * element_size + capacity);
    list->compare = compare;
    list->destruct = destruct;

    return list;
}


void
resize_arraylist(struct arraylist* list, unsigned int new_capacity)
{
    list->data = realloc(list->data,
            new_capacity * (list->e_size) + new_capacity);
    if (list->data) {
        list->capacity = new_capacity;
    }
}


void
clear_arraylist(struct arraylist* list)
{
    unsigned int i;
    size_t ssize = list->e_size + 1;
    char *p = list->data;
    /* release elements */
    for (i = 0; i < list->capacity; ++i) {
        p += ssize;

        if (((*p) & VALID_FLAG) == VALID_FLAG)
            list->destruct(GENUINE(p));
    }
}


void
release_arraylist(struct arraylist* list)
{
    clear_arraylist(list);
    free(list->data);
    list->data = NULL;
    list->capacity = 0;
    free(list);
    list = NULL;
}


void
arraylist_delete(struct arraylist* list, unsigned int index)
{
    size_t ssize = list->e_size + 1;
    char *e = list->data;
    if (index >= list->capacity)
        return;

    e += (index * ssize);
    if (((*e) & VALID_FLAG) == VALID_FLAG)
        list->destruct(GENUINE(e));
    memset(e, 0, ssize);
}


void
arraylist_insert(struct arraylist* list, unsigned int index, void* data)
{
    char *e = list->data;
    size_t ssize = list->e_size + 1;
    if (index >= list->capacity)
        return;
    e += (index * ssize);
    *e = VALID_FLAG;
    memcpy(GENUINE(e), data, list->e_size);
}


void
arraylist_pop(struct arraylist* list, unsigned int index, void* data)
{
    size_t ssize = list->e_size + 1;
    char *d = list->data;
    if (index >= list->capacity)
        return;
    e += (index * ssize);
    if (((*e) & VALID_FLAG) != VALID_FLAG)
        return;

    memcpy(data, GENUINE(e), list->e_size);
    memset(d, 0, list->e_size + 1);
}


unsigned int
arraylist_contains(struct arraylist* list, void* data)
{
    char* element = list->data;
    int ssize = list->e_size;
    int i;
    for (i = 0; i < list->capacity; ++i)
    {
        element += ssize;
        if (((*element) & VALID_FLAG) != VALID_FLAG)
            continue;
        if (list->compare(data, GENUINE(element)) == 0)
            return i;
    }
    return -1;
}
