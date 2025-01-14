struct Node
{
    int key;
    Node *next;
};

struct LinkedList
{
    Node *head;
    Node *tail;
};
#include <cstddef>

bool pop_front(LinkedList *list)
{
    if (list->head == NULL)
    {
        return 0;
    }
    Node *atual = list->head;
    Node *temp = atual;
    atual = atual->next;
    delete temp;

    if (atual == NULL)
    {
        list->tail = NULL;
    }
    return 1;
}
