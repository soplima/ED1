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

LinkedList* merge_sorted_lists(LinkedList* list1, LinkedList* list2) {
    LinkedList* mergedList = new LinkedList{NULL, NULL};
    Node* current1 = list1->head;
    Node* current2 = list2->head;
    Node* newNode = NULL;
    Node* mergedCurrent = NULL;

    while (current1 != NULL && current2 != NULL) {
        if (current1->key <= current2->key) {
            newNode = new Node{current1->key, NULL};
            current1 = current1->next;
        } else {
            newNode = new Node{current2->key, NULL};
            current2 = current2->next;
        }

        if (mergedList->head == NULL) {
            mergedList->head = newNode;
            mergedCurrent = newNode;
        } else {
            mergedCurrent->next = newNode;
            mergedCurrent = newNode;
        }
    }

    while (current1 != NULL) {
        newNode = new Node{current1->key, NULL};
        if (mergedList->head == NULL) {
            mergedList->head = newNode;
            mergedCurrent = newNode;
        } else {
            mergedCurrent->next = newNode;
            mergedCurrent = newNode;
        }
        current1 = current1->next;
    }

    while (current2 != NULL) {
        newNode = new Node{current2->key, NULL};
        if (mergedList->head == NULL) {
            mergedList->head = newNode;
            mergedCurrent = newNode;
        } else {
            mergedCurrent->next = newNode;
            mergedCurrent = newNode;
        }
        current2 = current2->next;
    }

    mergedList->tail = mergedCurrent;
    return mergedList;
}