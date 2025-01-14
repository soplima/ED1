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


bool pop_back(LinkedList* list){

    if (list->head == NULL){
        return false;
    }

    if (list -> head == list -> tail){
        delete list -> head;
        list -> head == NULL;
        list -> tail == NULL;
        return true;
    }

    Node* atual = list->head;
    while (atual->next != list ->tail){
        atual = atual ->next;
    }

    delete list ->tail;
    list -> tail = atual;
    list -> tail ->next = NULL;

    return true;
}
