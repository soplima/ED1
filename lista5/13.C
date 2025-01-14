#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

VectorList *list_copy(VectorList *list)
{

    VectorList *list1 = (VectorList *)malloc(sizeof(VectorList));
    if (!list1)
    {
        return NULL;
    }

    list1->data = (int *)malloc(list->capacity * sizeof(int));
    if (!list1->data)
    {
        return NULL;
    }

    for (int i = 0; i < list->size; i++)
    {
        list1->data[i] = list->data[i];
    }
    return list1;
}