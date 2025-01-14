typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

int list_get_available(VectorList *list)
{
    return list->capacity - list->size;
}