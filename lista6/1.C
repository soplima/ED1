struct Node {
 int key;
 Node* next;
};

struct LinkedList {
 Node* head; // primeiro Node
 Node* tail; // último Node
};

#include <cstddef>

bool is_empty(Node* head, Node* tail)
{
    return (head && tail == NULL);
}