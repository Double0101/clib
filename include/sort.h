#ifndef __CLIB_SORT_H__
#define __CLIB_SORT_H__

void bubble_sort_arraylist(struct arraylist* list, int start, int end, int compare(void* data1, void* data2));
void bubble_sort_linkedlist(struct linkedlist* list, int start, int end, int compare(void* data1, void* data2));
void quick_sort_arraylist(struct arraylist* list, int start, int end, int compare(void* data1, void* data2));
void quick_sort_linkedlist(struct linkedlist* list, int start, int end, int compare(void* data1, void* data2));
void insertion_sort_arraylist(struct arraylist* list, int start, int end, int compare(void* data1, void* data2));
void insertion_sort_linkedlist(struct linkedlist* list, int start, int end, int compare(void* data1, void* data2));
void merge_sort_arraylist(struct arraylist* list, int start, int end, int compare(void* data1, void* data2));
void merge_sort_linkedlist(struct linkedlist* list, int start, int end, int compare(void* data1, void* data2));
void arraylist_heap_sort(struct arraylist* list, int compare(void* data1, void* data2));

#endif