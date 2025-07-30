// Question 286
Node *insert(Node *head, int n, int pos, int val)
{

    // Write your code here

    Node *newnode = new Node(val);

    // if the position is first then

    if (pos == 0)
    {

        newnode->next = head;

        head = newnode;

        return head;
    }

    Node *curr = head;

    int i = 1;

    while (i < pos)
    {

        curr = curr->next;

        i++;
    }

    newnode->next = curr->next;

    curr->next = newnode;

    return head;
}