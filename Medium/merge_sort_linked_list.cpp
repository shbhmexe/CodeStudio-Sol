
#include <bits/stdc++.h>
using namespace std;

// Linked List Node Definition
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to find middle of linked list
Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if (left != nullptr) temp->next = left;
    if (right != nullptr) temp->next = right;

    Node* result = dummy->next;
    delete dummy;
    return result;
}

// Merge Sort on Linked List
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

// Utility to print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Example Usage
int main() {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}



// node* findMid(node* head) {
//     node* slow = head;
//     node* fast = head->next;

//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }

// node* merge(node* left, node* right) {
//     if (left == NULL) {
//         return right;
//     }

//     if (right == NULL) {
//         return left;
//     }

//     node* ans = new node(-1);
//     node* temp = ans;

//     while (left != NULL && right != NULL) {
//         if (left->data < right->data) {
//             temp->next = left;
//             temp = left;
//             left = left->next;
//         }
//         else {
//             temp->next = right;
//             temp = right;
//             right = right->next;
//         }
//     }

//     while (left != NULL) {
//         temp->next = left;
//         temp = left;
//         left = left->next;
//     }

//     while (right != NULL) {
//         temp->next = right;
//         temp = right;
//         right = right->next;
//     }

//     ans = ans->next;
//     return ans;
// }

// node* mergeSort(node *head) {
//     // Write your code here.

//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     // step 1 : find mid of the linked list
//     node* mid = findMid(head);

//     // step 2 : dividing lists into two halves
//     node* left = head;
//     node* right = mid->next;
//     mid->next = NULL;

//     // step 3 : sorting lists recursively
//     left = mergeSort(left);
//     right = mergeSort(right);

//     // step 4 : merging lists
//     node* result = merge(left, right);

//     //  step 5 : return list 
//     return result;
// }