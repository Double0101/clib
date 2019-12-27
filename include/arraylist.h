//
// Created by Double on 2019-03-29.
//

#ifndef __CLIB_ARRAYLIST_H__
#define __CLIB_ARRAYLIST_H__

#define VALID_FLAG 0xff
#define GENUINE(x) ((char*)x + 1)

struct arraylist
{
    unsigned int capacity;
    unsigned int e_size;
    char** data;
    int compare(void*, void*);
    void destruct(void*);
};

struct arraylist* new_arraylist(unsigned int, unsigned int);
void resize_arraylist(struct arraylist*, unsigned int);
void clear_arraylist(struct arraylist*);
void release_arraylist(struct arraylist*);
void arraylist_delete(struct arraylist*, unsigned int);
void arraylist_insert(struct arraylist*, unsigned int, void*);
void arraylist_pop(struct arraylist*, unsigned int, void*);
unsigned int arraylist_contains(struct arraylist*, void*);

#endif //CLIB_ARRAYLIST_H
