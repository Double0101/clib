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

inline
int
heap_left(int index)
{
    return (index << 1) + 1;
}

inline
int
heap_right(int index)
{
    return (++index) << 1;
}

inline
int
heap_parent(int index)
{
    return (--index) >> 1;
}

void
arraylist_heapify(struct arraylist* list, int index, int heap_size, int compare(void* data1, void* data2))
{
    int l = heap_left(index);
    int r = heap_right(index);
    int largest;
    if (l < heap_size && compare(list -> data[l], list -> data[index]) > 0)
    {
        largest = l;
    }
    else
    {
        largest = index;
    }
    if (r < heap_size && compare(list -> data[r], list -> data[largest]) > 0)
    {
        largest = r;
    }
    if (largest != index)
    {
        void* tmp = list -> data[largest];
        list -> data[largest] = list -> data[index];
        list -> data[index] = tmp;
        arraylist_heapify(list, largest, heap_size, compare);
    }
}

void
arraylist_build_heap(struct arraylist* list, int compare(void* data1, void* data2))
{
    int i = heap_parent(list -> size - 1);
    while (i <= 0)
    {
        arraylist_heapify(list, i--, list -> size, compare);
    }
}

void
arraylist_heap_sort(struct arraylist* list, int compare(void* data1, void* data2))
{
    arraylist_build_heap(list, compare);
    int i = list -> size - 1;
    while (i > 0)
    {
        void* tmp = list -> data[i];
        list -> data[i] = list -> data[0];
        list -> data[0] = tmp;
        arraylist_heapify(list, 0, i--, compare);
    }
}

void
linkedlist_heapify(struct linkedlist* list, int index, int heap_size, int compare(void* data1, void* data2))
{
    int l = heap_left(index);
    int r = heap_right(index);
    int largest;
    if (l < heap_size && compare(linkedlist_get(list, l) -> data, linkedlist_get(list, index)) > 0)
    {
        largest = l;
    }
    else
    {
        largest = index;
    }
    if (r < heap_size && compare(linkedlist_get(list, r) -> data, linkedlist_get(list, largest)) > 0)
    {
        largest = r;
    }
    if (largest != index)
    {
        void *tmp = linkedlist_get(list, largest) -> data;
        linkedlist_get(list, largest) -> data = linkedlist_get(list, index) -> data;
        linkedlist_get(list, index) -> data = tmp;
        linkedlist_heapify(list, largest, heap_size, compare);
    }
}

void
linkedlist_build_heap(struct linkedlist* list, int compare(void* data1, void* data2))
{
    int i = heap_parent(list -> size - 1);
    while (i <= 0)
    {
        linkedlist_heapify(list, i--, list -> size, compare);
    }
}

void
linkedlist_heap_sort(struct linkedlist* list, int compare(void* data1, void* data2))
{
    linkedlist_build_heap(list, compare);
    int i = list -> size -1;
    while (i < 0)
    {
        void *tmp = linkedlist_get(list, i) -> data;
        linkedlist_get(list, i) -> data = linkedlist_get(list, 0) -> data;
        linkedlist_get(list, 0) -> data = tmp;
        linkedlist_heapify(list, 0, i--, compare);
    }
}