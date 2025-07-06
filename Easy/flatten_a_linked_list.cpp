#include <bits/stdc++.h>
using namespace std;

// Definition for linked list node
class Node {
public:
    int data;
    Node *next;
    Node *child;

    Node() : data(0), next(nullptr), child(nullptr) {}
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

// Merge two sorted child-linked lists
Node* merge(Node* left, Node* right) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            temp->child = left;
            left = left->child;
        } else {
            temp->child = right;
            right = right->child;
        }
        temp = temp->child;
    }

    if (left != nullptr) temp->child = left;
    if (right != nullptr) temp->child = right;

    return dummy->child;
}

// Recursively flatten multi-level linked list
Node* flattenLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    head->next = flattenLinkedList(head->next);

    head = merge(head, head->next);

    return head;
}

// Utility to print flattened linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

// Example Usage
int main() {
    // Creating sample multi-level linked list
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next->child = new Node(20);

    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);

    Node* flattened = flattenLinkedList(head);

    cout << "Flattened Linked List: ";
    printList(flattened);

    return 0;
}




// /*
//  * Definition for linked list.
//  * class Node {
//  *  public:
//  *		int data;
//  *		Node *next;
//  * 		Node *child;
//  *		Node() : data(0), next(nullptr), child(nullptr){};
//  *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
//  *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
//  * };
//  */

// Node* merge(Node* left, Node* right) {
//     Node* ans = new Node(-1);
// 	Node* temp = ans;

//     while (left != NULL && right != NULL) {
//         if (left->data < right->data) {
//             temp->child = left;
//             temp = left;
//             left = left->child;
//         }
//         else {
//             temp->child = right;
//             temp = right;
//             right = right->child;
//         }
// 		temp->next = NULL;
//     }

//     if (left != NULL) {
//         temp->child = left;
//         temp = left;
//         left = left->child;
//     }
// 	temp->next = NULL;

//     while (right != NULL) {
//         temp->child = right;
//         temp = right;
//         right = right->child;
//     }
// 	temp->next = NULL;

//     if (ans->child != NULL) {
// 		ans->child->next = NULL;
// 	}
//     return ans->child;
// }

// Node* flattenLinkedList(Node* head) 
// {
// 	// Write your code here
// 	if (head == NULL || head->next == NULL) {
// 		return head;
// 	}

// 	Node* mergedHead = flattenLinkedList(head->next);

// 	head = merge(head, mergedHead);

// 	return head;
// }