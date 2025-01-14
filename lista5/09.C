typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

int list_is_sorted(VectorList *list)
{
    for (int i = 0; i < list->size - 1; i++)
    {
        if (list->data[i] > list->data[i + 1])
        {
            return 0;
        }
    }
    return 1;
}