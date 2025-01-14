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

//Escreva uma função para inserir o valor “key” na lista, em ordem crescente de id.
//Exemplo:
//LinkedList* list1 = new LinkedList;
//list1->insert_sorted(10); // head -> [10]
//list1->insert_sorted(5); // head -> [5] -> [10]
//list1->insert_sorted(7); // head -> [5] -> [7] -> [10]
//list1->insert_sorted(2); // head -> [2] -> [5] -> [7] -> [10]
//list1->insert_sorted(15); // head -> [2] -> [5] -> [7] -> [10] -> [15]

bool insert_sorted(LinkedList* list, int key) {
    Node* newNode = new Node{key, NULL};

    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
        return 1;
    } 
    Node* atual = list->head;

    while(atual->next != NULL && atual->next->key < key){
        atual = atual->next;
    }
        newNode->next = atual->next;
        atual->next = newNode;

        if(newNode->next == NULL){
            list->tail = newNode;
        }
    return 1;
}