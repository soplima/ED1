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

int size(Node *head){
    int count = 0;
    Node* atual = head;

    while(atual != NULL){
        count++;
        atual = atual -> next;
    }
    return count;
}
