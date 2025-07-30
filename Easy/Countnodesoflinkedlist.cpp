//Question 282

int length(Node *head)
{
	    int count = 0;
        Node* current = head;
        
        while (current != NULL) {
            count++;
            current = current->next;
        }
        
        return count;
}