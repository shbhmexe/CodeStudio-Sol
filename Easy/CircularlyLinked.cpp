#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool isCircular(Node *head) {
    if (head == NULL) {
        return true;
    }
    if (head->next == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detected
            break;
        }
    }

    // If loop exists and slow reached head again, it's circular
    if (slow == fast && slow == head) {
        return true;
    }

    return false;
}



// bool isCircular(Node *head) {
//     if (head == NULL) {
//         return true;
//     }
//     if (head->next == NULL) {
//         return false;
//     }

//     Node* slow = head;
//     Node* fast = head;

//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;

//         if (slow == fast) {
//             // Loop detected
//             break;
//         }
//     }

//     // If loop exists and slow reached head again, it's circular
//     if (slow == fast && slow == head) {
//         return true;
//     }

//     return false;
// }