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


bool push_back(LinkedList *list, int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        Node *newNode = new Node{vet[i], NULL};

        if (list->head == NULL)
        {
            list->head = newNode;
            list->tail = newNode;
        }
        else
        {
            list->tail->next = newNode;
            list->tail = newNode;
        }
    }
    return true;
}