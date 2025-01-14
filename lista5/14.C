#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

int list_concat(VectorList *list1, VectorList *list2)
{
    int i = 0;
    int count = 0;

    while (list1->capacity > list1->size && i < list2->size)
    {
        list1->data[list1->size] = list2->data[i];
        list1 -> size++;
        i++;
        count++;
    }
    return count;
}