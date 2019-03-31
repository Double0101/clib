//
// Created by Double on 2019-03-29.
//

#ifndef __CLIB_ARRAYLIST_H__
#define __CLIB_ARRAYLIST_H__

struct arraylist
{
    int size;
    int capacity;
    void** data;
};

struct arraylist* new_arraylist(int capacity);
void resize_arraylist(struct arraylist* list, int new_capacity);
void clear_arraylist(struct arraylist* list);
void arraylist_add(struct arraylist* list, void* data);
void arraylist_delete(struct arraylist* list, int index);
void arraylist_insert(struct arraylist* list, int index, void* data);
int arraylist_contains(struct arraylist* list, void* data);
#endif //CLIB_ARRAYLIST_H
