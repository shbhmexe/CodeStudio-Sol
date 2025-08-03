//Question 311
Node * deleteAllOccurrences(Node* head, int k) {

    // Write your code here

    Node*temp = head;

    while(temp!=NULL){

    if(temp->data == k){

      if(temp == head){

        head = temp->next;

      }

 

      Node*newNode = temp->next;

      Node*prevNode = temp->prev;

 

      if(newNode != NULL){

        newNode->prev = prevNode;

      }

      if(prevNode != NULL){

        prevNode->next = newNode;

      }

 

      free(temp);

      temp = newNode;

    } else {

      temp = temp->next;

    }

    }

    return head;

}

 
