//Question 281
#include<bits/stdc++.h>

int searchInLinkedList(Node<int> *head, int k) {

    // Write your code here.

    Node<int>* temp=head;

    vector<int> arr;

 

    while (temp != NULL) {

        arr.push_back(temp->data);

        temp = temp->next;

    }

    int ans=0;

    int n = arr.size();

    for(int i=0;i<n;i++){

        if(arr[i]==k){

            ans=1;

        }

    }

    return ans;
}   

 