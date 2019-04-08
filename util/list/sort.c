//
// Created by Double on 2019-04-02.
//

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "arraylist.h"
#include "linkedlist.h"

#include "../../include/sort.h"

const char _TAIL_[] = "tail";

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

void
bubble_sort_linkedlist(struct linkedlist* list, int start, int end, int compare(void* data1, void* data2))
{
    for (int i = 0; i < list -> size - 1; ++i)
    {
        for (int j = 0; j < list -> size - 1 - i; ++j)
        {
            if (compare(linkedlist_get(list, j) -> data, linkedlist_get(list, j + 1) -> data))
            {
                void *tmp = linkedlist_get(list, j) -> data;
                linkedlist_get(list, j) -> data = linkedlist_get(list, j + 1) -> data;
                linkedlist_get(list, j + 1) -> data = tmp;
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

int
linkedlist_partition(struct linkedlist* list, int start, int end, int compare(void* data1, void* data2))
{
    void* x = linkedlist_get(list, end) -> data;
    int i = start - 1;
    int j;
    for (j = start; j < end; ++j)
    {
        if (compare(linkedlist_get(list, j) -> data, x) <= 0)
        {
            void *tmp = linkedlist_get(list, ++i) -> data;
            linkedlist_get(list, j) -> data = linkedlist_get(list, i) -> data;
            linkedlist_get(list, i) -> data = tmp;
        }
    }
    linkedlist_get(list, end) -> data = linkedlist_get(list, ++i) -> data;
    linkedlist_get(list, i) -> data = x;
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

void
quick_sort_linkedlist(struct linkedlist* list, int start, int end, int compare(void* data1, void* data2))
{
    if (end > start)
    {
        int p = linkedlist_partition(list, start, end, compare);
        quick_sort_linkedlist(list, start, p - 1, compare);
        quick_sort_linkedlist(list, p + 1, end, compare);
    }
}

void
insertion_sort_arraylist(struct arraylist* list, int start, int end, int compare(void* data1, void* data2))
{
    int i;
    for (i = 1; i < list -> size; ++i)
    {
        void* element = list -> data[i];
        int j = i - 1;

        while (j >= 0 && compare(list -> data[j], element) > 0)
        {
            list -> data[j + 1] = list -> data[j];
            --j;
        }
        list -> data[j + 1] = element;
    }
}

void
insertion_sort_linkedlist(struct linkedlist* list, int start, int end, int compare(void* data1, void* data2))
{
    int i;
    for (i = 1; i < list -> size; ++i)
    {
        struct node* element = linkedlist_get(list, i);
        int j = i - 1;

        while (j >= 0 && compare(linkedlist_get(list, j) -> data, element -> data) > 0)
        {
            linkedlist_get(list, j + 1) -> data = linkedlist_get(list, j) -> data;
            --j;
        }
        linkedlist_get(list, j + 1) -> data = element -> data;
    }
}

void
arraylist_merge(struct arraylist* list, int start, int divide, int end, int compare(void* data1, void* data2))
{
    int n1 = divide - start + 1;
    int n2 = end - divide;
    void* l1[n1];
    void* l2[n2];

    int i, j;
    for (i = 0; i < n1; ++i)
        l1[i] = list -> data[start + i];
    for (j = 0; j < n2; ++j)
        l2[j] = list -> data[divide + j + 1];

    i = 0, j = 0;
    for (int k = 0; k < end - start + 1; ++k)
    {
        if (i < n1 && j < n2)
        {
            if (compare(l1[i], l2[j]) > 0)
            {
                list -> data[k] = l2[j++];
            }
            else
            {
                list -> data[k] = l1[i++];
            }
        }
        else
        {
            if (i == n1) list -> data[k] = l2[j++];
            else list -> data[k] = l1[i++];
        }
    }
}

void
linkedlist_merge(struct linkedlist* list, int start, int divide, int end, int compare(void* data1, void* data2))
{
    int n1 = divide - start + 1;
    int n2 = end - divide;
    void *l1[n1];
    void *l2[n2];

    int i, j;
    for (i = 0; i < n1; ++i)
        l1[i] = linkedlist_get(list, start + i);
    for (j = 0; j < n2; ++j)
        l2[j] = linkedlist_get(list, divide + j + 1);
    i = 0, j = 0;

    for (int k = 0; k < end - start + 1; ++k) {
        if (i < n1 && j < n2)
        {
            if (compare(l1[i], l2[j]) > 0)
            {
                linkedlist_get(list, k) -> data = l2[j++];
            }
            else
            {
                linkedlist_get(list, k) -> data = l1[i++];
            }
        }
        else
        {
            if (i == n1) linkedlist_get(list, k) -> data = l2[j++];
            else linkedlist_get(list, k) -> data = l1[i++];
        }
    }
}

void
merge_sort_arraylist(struct arraylist* list, int start, int end, int compare(void* data1, void* data2))
{
    if (end > start)
    {
        int div = (start + end) / 2;
        merge_sort_arraylist(list, start, div, compare);
        merge_sort_arraylist(list, div + 1, end, compare);
        arraylist_merge(list, start, div, end, compare);
    }
}


void
merge_sort_linkedlist(struct linkedlist* list, int start, int end, int compare(void* data1, void* data2))
{
    if (end > start)
    {
        int div = (start + end) / 2;
        merge_sort_linkedlist(list, start, div, compare);
        merge_sort_linkedlist(list, div + 1, end, compare);
        linkedlist_merge(list, start, div, end, compare);
    }
}