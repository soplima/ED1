typedef struct
{
    int size;
    int capacity;
    int *data;
} VectorList;

int list_equal(VectorList *list1, VectorList *list2)
{
    if (list1->size != list2->size)
    {
        return 0;
    }
    for (int i = 0; i < list1->size; i++)
    {
        if (list1->data[i] != list2->data[i])
        {
            return 0;
        }
    }
    return 1;
}