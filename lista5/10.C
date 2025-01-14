typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

void list_reverse(VectorList *list)
{
    for (int i = 0; i < list->size / 2; i++)
    {
        int temp = list->data[i];
        list->data[i] = list->data[list->size - 1 - i];
        list->data[list->size - 1 - i] = temp;
    }
}

//  0  1  2  3  4
// (1, 2, 3, 4, 5)
// (5, 2, 3, 4, 1)
// (5, 4, 3, 2, 1)