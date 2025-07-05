//Appoach 1: Iterative Approach

// #include <bits/stdc++.h>

// // this is iterative approach

// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
// {
//     // Write your code here
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     LinkedListNode<int> *prev = NULL;
//     LinkedListNode<int> *curr = head;
//     LinkedListNode<int> *forward = NULL;

//     while (curr != NULL) {
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     return prev;
// }

// approach 2: Recursive Approach

// #include <bits/stdc++.h>

// // this is recursive approach

// void reverse(LinkedListNode<int>* &head, LinkedListNode<int> *prev, LinkedListNode<int> *curr) {
//     // base case
//     if (curr == NULL) {
//         head = prev;
//         return;
//     }
//     LinkedListNode<int> *forward = curr->next;

//     reverse(head, curr, forward);
//     curr->next = prev;

// }


// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
// {
//     // Write your code here
//     LinkedListNode<int> *prev = NULL;
//     LinkedListNode<int> *curr = head;
//     reverse(head, prev, curr);
//     return head;
// }

// approach 3: Recursive Approach

// #include <bits/stdc++.h>

// // this is recursive approach

// LinkedListNode<int> *reverse(LinkedListNode<int>* &head) {
//     // base case
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     LinkedListNode<int> *newHead = reverse(head->next);

//     head->next->next = head;
//     head->next = NULL;

//     return newHead;

// }


// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
// {
//     // Write your code here
//     return reverse(head);
// }h