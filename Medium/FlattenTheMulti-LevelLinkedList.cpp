//Question 300
#include <bits/stdc++.h> 
Node<int> *flattenMultiLinkedList(Node<int> *head) {
    if(!head) return NULL;
    Node<int>* dummy = new Node<int> (-1);
    Node<int>* current = dummy;
    Node<int>* temp = head;
    queue<Node<int>*> q;


    while(temp){

        current->next = new Node<int>(temp->data);
        current = current->next;

        if(temp->child){
            q.push(temp->child);
        }
        
        if(temp->next){
            temp = temp->next;
        }else if(!q.empty()){
            temp=q.front();
            q.pop();
        }else{
            temp=NULL;
        }
        
    }
    
    return dummy->next;
}