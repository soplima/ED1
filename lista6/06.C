struct Node
{
    int key;
    Node *next;
};

struct LinkedList
{
    Node *head; // primeiro Node
    Node *tail; // último Node
};

#include <cstddef>

bool equals(LinkedList *list1, LinkedList *list2)
{
    Node *atual1 = list1->head;
    Node *atual2 = list2->head;

    while (atual1 != NULL && atual2 != NULL)
    {
        if (atual1->key != atual2->key)
        {
            return false;
        }
        atual1 = atual1->next;
        atual2 = atual2->next;
    }
    return (atual1 == NULL && atual2 == NULL);
}
