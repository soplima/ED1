#include <stdio.h>

typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

void list_print_reverse(VectorList *list)
{
    for (int i = list->size - 1; i >= 0; i--)
    {
        printf("%d", list->data[i]);
    }
}
