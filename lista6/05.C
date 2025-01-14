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

void print_last(LinkedList* list){

    if(list->head == NULL){
        return;
    }

    Node* atual = list -> head;

    while(atual != NULL){
    atual = atual -> next;
    }
    atual -> key;
}