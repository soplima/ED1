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

void remove(LinkedList* list, int key){
    Node* atual = list->head;
    Node* prev = NULL;

    while (atual != NULL && atual->key != key){
        prev = atual;
        atual = atual->next;
    }
    
    if(atual == NULL){
        return;
    }

    if(atual == list->tail){
        list->tail = prev;
    }

    if(prev != NULL){
        prev->next = atual->next;
    } else {
        list->head = atual->next;
    }
    
    delete atual;
}