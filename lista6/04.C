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

Node* get(int pos, LinkedList *list){
    Node* atual = list -> head;
    
    int i = 0;
    while (atual != NULL && pos > 0){
        atual = atual -> next;
        i++;
        pos --;
    }
    return atual;
}
