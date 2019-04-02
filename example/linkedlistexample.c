#include "arraylist.h"
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

int a(void* a, void* b)
{
    return *((int*) a) - *((int*) b);
}

int main()
{
    struct arraylist* list = new_arraylist(10);
    int *array = (int*) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        array[i] = 10 - i;
        arraylist_add(list, &array[i]);
        printf("%d\n", *(int*)(list -> data[i]));
    }
    quick_sort_arraylist(list, 0, 9, a);
    return 0;
}