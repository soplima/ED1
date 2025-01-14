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

LinkedList* concat(LinkedList* list1, LinkedList* list2) {
    LinkedList* newList = new LinkedList{NULL, NULL};

    if (list1->head == NULL && list2->head == NULL) {
        return newList; 
    }

    Node* newNode = NULL;
    Node* atual3 = NULL;

    if (list1->head != NULL) {
        Node* atual1 = list1->head;
        newNode = new Node{atual1->key, NULL};
        newList->head = newNode;
        atual3 = newNode;

        while (atual1->next != NULL) {
            atual1 = atual1->next;
            newNode = new Node{atual1->key, NULL};
            atual3->next = newNode;
            atual3 = newNode;
        }
        newList->tail = atual3;
    }
    if (list2->head != NULL) {
        Node* atual2 = list2->head;
        if (newList->head == NULL) {
            newNode = new Node{atual2->key, NULL};
            newList->head = newNode;
            atual3 = newNode;
        } else {
            newNode = new Node{atual2->key, NULL};
            atual3->next = newNode;
            atual3 = newNode;
        }

        while (atual2->next != NULL) {
            atual2 = atual2->next;
            newNode = new Node{atual2->key, NULL};
            atual3->next = newNode;
            atual3 = newNode;
        }
        newList->tail = atual3;
    }

    return newList;
}