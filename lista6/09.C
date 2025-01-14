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

bool push_back(LinkedList* list, int elem)
{

    Node *newNode = new Node{elem, NULL};

    if (list -> head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {

        list->tail->next = newNode;
        list->tail = newNode;
    }

    return true;
}