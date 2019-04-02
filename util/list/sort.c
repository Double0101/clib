//
// Created by Double on 2019-04-02.
//

#include <stdlib.h>
#include <assert.h>

#include "arraylist.h"
#include "linkedlist.h"

#include "../../include/sort.h"

void
bubble_sort_arraylist(struct arraylist* list, int start, int end, int compare(void* data1, void* data2))
{
    for (int i = 0; i < list -> size - 1; ++i)
    {
        for (int j = 0; j < list -> size - 1 - i; ++j)
        {
            if (compare(list -> data[j], list -> data[j + 1]) > 0)
            {
                void *tmp = list -> data[j];
                list -> data[j] = list -> data[j + 1];
                list -> data[j + 1] = tmp;
            }
        }
    }
}

int
arraylist_partition(struct arraylist* list, int start, int end, int compare(void* data1, void* data2))
{
    void* x = list -> data[end];
    int i = start - 1;
    int j;
    for (j = start; j < end; ++j)
    {
        if (compare(list -> data[j], x) <= 0)
        {
            void *tmp = list -> data[++i];
            list -> data[j] = list -> data[i];
            list -> data[i] = tmp;
        }
    }
    list -> data[end] = list -> data[++i];
    list -> data[i] = x;
    return i;
}

void
quick_sort_arraylist(struct arraylist* list, int start, int end, int compare(void* data1, void* data2))
{
    if (end > start)
    {
        int p = arraylist_partition(list, start, end, compare);
        quick_sort_arraylist(list, start, p - 1, compare);
        quick_sort_arraylist(list, p + 1, end, compare);
    }

}
