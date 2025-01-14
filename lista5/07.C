typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

int list_find(VectorList *list, int elem)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i] == elem)
        {
            return i;
        }
    }
    return -1;
}
