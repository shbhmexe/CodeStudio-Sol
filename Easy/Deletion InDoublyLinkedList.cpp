// Question 290
#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node *prev;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
                this->prev = NULL;
            }
        };

*****************************************************************/

void deleteNode(Node *(&head), int pos)
{

    // Write your code here.

    if (pos == 0)

    {

        head = head->next;

        return;
    }

    int i = 1;

    Node *curr = head;

    while (i <= pos && curr)

    {

        curr = curr->next;

        i++;
    }

    if (curr->next == NULL)

    {

        curr->prev->next = NULL;
    }

    else

    {

        curr->data = curr->next->data;

        curr->next = curr->next->next;

        curr->next->prev = curr;
    }
}