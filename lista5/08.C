
typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

void list_add(VectorList *list, int n, int *vet)
{
    int i = 0;
    while (list->size < list->capacity && n > 0)
    {
        list->data[list->size] = vet[i];
        list->size++;
        i++;
        n--;
    }
}
