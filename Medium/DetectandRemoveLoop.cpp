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

bool detectAndRemoveLoop(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    // Detect Loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // No loop found
    if (slow != fast) {
        return false;
    }

    // Loop Found, now remove it
    slow = head;
    
    // If loop starts at head itself
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
        return true;
    }

    // Otherwise, find starting point of loop
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL; // Remove Loop

    return true;
}


// Node* removeLoop(Node *head) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     Node* slow = head;
//     Node* fast = head;

//     // Detect Loop
//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;

//         if (slow == fast) {
//             break;
//         }
//     }

//     // No loop found
//     if (slow != fast) {
//         return head;
//     }

//     // Loop Found, now remove it
//     slow = head;

//     // If loop starts at head itself
//     if (slow == fast) {
//         while (fast->next != slow) {
//             fast = fast->next;
//         }
//         fast->next = NULL;
//         return head;
//     }

//     // Otherwise, find starting point of loop
//     while (slow->next != fast->next) {
//         slow = slow->next;
//         fast = fast->next;
//     }

//     fast->next = NULL; // Remove Loop

//     return head;
// // }