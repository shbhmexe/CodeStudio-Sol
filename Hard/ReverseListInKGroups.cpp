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

Node* kReverse(Node* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }

    // Count total nodes
    Node* temp = head;
    int len = 0;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    if (len < k) {
        return head;
    }

    // Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }

    // Recursively reverse the remaining list
    if (nextNode != NULL) {
        head->next = kReverse(nextNode, k);
    }

    return prev;
}

// Optional Helper to Print Linked List
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Example Main Function
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    cout << "Original List: ";
    printList(head);

    head = kReverse(head, k);

    cout << "List after Reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}


// Node* kReverse(Node* head, int k) {
//     // Write your code here.

//     Node* temp = head;
//     int len=0;
//     while(temp != NULL){
//         temp = temp->next;
//         len++;
//     }
//     // Base Case
//     if(len<k || len==0){
//       return head;
//     }

//     // step 1 : reverse in k group
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* nextNode = NULL;
//     int count = 0;

//     while (curr != NULL && count < k) {
//         nextNode = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = nextNode;
//         count++;

//     }

//     // step 2 : recursion
//     if (nextNode != NULL) {
//         head->next = kReverse(nextNode, k);
//     }

//     // step 3 : return head of reverse list
//     return prev;
// }