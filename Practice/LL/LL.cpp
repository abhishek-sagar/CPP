#include<iostream>
#include "Node.h"
using namespace std;

Node* takeinput(){
   Node* head = NULL;
   Node* tail = NULL;

   int data;
   cout<<"enter data : ";
   cin>>data;
   while(data!=-1){
   	  Node* newNode = new Node(data);
   	  if(head == NULL){
   	  	head = newNode;
   	  	tail = newNode;
   	  }else{
   	  	tail->next = newNode;
   	  	tail = newNode;
   	  }
   	  cout<<"enter data : ";
      cin>>data;
   }
   return head;
}

void print(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
	return;
}



int main(){
	Node* head = takeinput();
	print(head);
	return 0;
}