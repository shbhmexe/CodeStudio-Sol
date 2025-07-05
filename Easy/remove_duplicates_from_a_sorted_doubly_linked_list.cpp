#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete(nodeToDelete);
        } else {
            curr = curr->next;
        }
    }
    return head;
}


// Node * removeDuplicates(Node *head)
// {
//     // Write your code here

//     if (head == NULL) {
//         return NULL;
//     }

//     Node* curr = head;

//     while (curr != NULL) {
//         if ((curr->next != NULL) && curr->data == curr->next->data) {
//             Node* nextNode = curr->next->next;
//             Node* nodeToDelete = curr->next;
//             delete(nodeToDelete);
//             curr->next = nextNode;
//         }
//         else {
//             curr = curr->next;
//         }
//     }
//     return head;
// } 