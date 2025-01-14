
typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

void list_remove_last(VectorList *list, int n)
{
    if (n >= list->size)
    {
        list->size = 0;
    }
    else
    {
        list->size -= n;
    }
}