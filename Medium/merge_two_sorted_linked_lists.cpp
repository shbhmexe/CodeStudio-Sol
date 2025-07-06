#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
Node<T>* sorting(Node<T>* first, Node<T>* second) {
    // If first list contains only 1 element
    if (first->next == NULL) {
        first->next = second;
        return first;
    }

    // Create pointers to traverse lists
    Node<T>* curr1 = first;
    Node<T>* next1 = curr1->next;

    Node<T>* curr2 = second;
    Node<T>* next2 = curr2->next;

    while (curr2 != NULL && next1 != NULL) {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            // Insert curr2 between curr1 and next1
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // Move pointers
            curr1 = curr2;
            curr2 = next2;
        } else {
            // Advance first list pointers
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL) {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

template <typename T>
Node<T>* sortTwoLists(Node<T>* first, Node<T>* second) {
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data <= second->data)
        return sorting(first, second);
    else
        return sorting(second, first);
}



// Node<int>* sorting(Node<int>* first, Node<int>* second) {
//     // checking if first contains only 1 element
//     if (first->next == NULL) {
//         first->next = second;
//         return first;
//     }

//     // creating pointers
//     Node<int>* curr1 = first;
//     Node<int>* nextNode1 = curr1->next;

//     Node<int>* curr2 = second;
//     Node<int>* nextNode2 = curr2->next;

//     while (curr2 != NULL && nextNode1 != NULL) {
//         if ((curr2->data <= nextNode1->data) && (curr2->data >= curr1->data)) {

//             // adding node in between linked list
//             curr1->next = curr2;
//             nextNode2 = curr2->next;
//             curr2->next = nextNode1;

//             // moving pointers ahead
//             curr1 = curr2;
//             curr2 = nextNode2;
//         }
//         else {
//             curr1 = nextNode1;
//             nextNode1 = nextNode1->next;

//             // if next node is null then directly connect to another list
//             if (nextNode1 == NULL) {
//               curr1->next = curr2;
//               return first;
//             }
//         }
//     }
//     return first;
// }

// Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
// {
//     // Write your code here.
//     if (first == NULL) {
//         return second;
//     }

//     if (second == NULL) {
//         return first;
//     }

//     if (first->data <= second->data) {
//         return sorting(first, second);

//     }
//     else {
//         return sorting(second, first);
//     }

//     return first;
// }