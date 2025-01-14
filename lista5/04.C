typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

void list_clear(VectorList *list)
{
    list->size = 0;
}