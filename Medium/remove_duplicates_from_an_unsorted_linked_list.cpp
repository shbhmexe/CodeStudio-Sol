#include <iostream>
#include <unordered_map>
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
    if (head == NULL || head->next == NULL) {
        return head;
    }

    unordered_map<int, bool> visited;

    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (visited[curr->data]) {
            prev->next = curr->next;
            delete(curr); 
            curr = prev->next;
        } else {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}



// Node *removeDuplicates(Node *head)
// {
//     // Write your code here
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     unordered_map<int, bool> visited;

//     Node* curr = head;
//     Node* prev = head;

//     while (curr != NULL) {

//         if (visited[curr->data] == true) {
//             prev->next = curr->next;
//             curr = prev->next;
//         }
//         else {
//             visited[curr->data] = true;
//             prev = curr;
//             curr = curr->next;
//         }
//     }
//     return head;
// }