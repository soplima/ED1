struct Node{
    int key;
    Node *next;
};

struct LinkedList
{
    Node *head; // primeiro Node
    Node *tail; // último Node
};

#include <cstddef>

Node *find(Node *head, int elem){
    Node *atual = head;
    while (atual != NULL)
    {
        if (atual->key == elem)
        {
            return atual;
        }
        atual = atual->next;
    }
    return NULL;
}