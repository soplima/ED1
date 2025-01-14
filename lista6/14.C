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

LinkedList *deep_copy(LinkedList *list)
{
    if (list->head == NULL)
    {
        return new LinkedList{NULL, NULL};
    }

    LinkedList *newList = new LinkedList{NULL, NULL};
    Node *atual = list->head;
    Node *newNode = new Node{atual->key, NULL};
    newList->head = newNode;
    newList->tail = newNode;

    Node *atual2 = newList->head;

    while (atual->next != NULL)
    {
        atual = atual->next;
        newNode = new Node{atual->key, NULL};
        atual2->next = newNode;
        atual2 = newNode;
    }

    newList->tail = atual2;
    return newList;
}