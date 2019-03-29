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
void resize(struct arraylist* list, int new_capacity);

#endif //CLIB_ARRAYLIST_H
