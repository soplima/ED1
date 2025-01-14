struct LinkedList
{
    Node *head; // primeiro Node
    Node *tail; // último Node
};

struct Node
{
    int key;
    Node *next;
};

#include <cstddef>

bool is_sorted(LinkedList *list)
{
    Node *atual = list->head;
    while (atual != NULL)
    {
        if (atual->key > atual->next->key)
        {
            return 0;
        }
        atual = atual->next;
    }
    return 1;
}