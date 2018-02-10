#include<iostream>
#include "../stack/Node.h"
using namespace std;

class Queue{
   Node* front = NULL;
   Node* rear = NULL;
public:
   void Enqueue(int data){
   	 Node* newNode = new Node(data);
   	 if(front == NULL){
   	 	front = newNode;
   	 	rear = newNode;
   	 }
   	 else{
   	 	rear->next = newNode;
   	 	rear = newNode;
   	 }
   	 return;
   }

   int Dequeue(){
   	  if(front == NULL){
   	  	return -1;
   	  }
   	  else{
   	    int out;
   	    Node* temp = front;
   	    front = front->next;
   	    out = temp->data;
   	    temp->next = NULL;
   	    delete temp;
   	    return out;
      }
   }

   int Front(){
   	  if(front == NULL){
   	  	return -1;
   	  }
   	  else return front->data;
   }

   bool IsEmpty(){
   	  if(front == NULL){
   	  	return true;
   	  }
   	  else return false;
   }

   void Print(){
   	  if(front!=NULL){
   	  	Node* temp = front;
   	  	while(temp!=NULL){
   	  		cout<<temp->data<<" ";
   	  		temp = temp->next;
   	  	}
   	  }
   	  cout<<endl;
   	  return;
   }
};

// Do variety of Questions from hackerrank;

int main(){
     Queue q;
     q.Enqueue(2);
     q.Enqueue(3);
     q.Enqueue(5);
     q.Enqueue(6);
     q.Enqueue(1);
     q.Enqueue(0);
     q.Enqueue(7);
     for(int i=0;i<7;i++){
     	cout<<q.Dequeue()<<" ";
     }
     cout<<endl;
     if(q.IsEmpty()){
     	cout << "Queue is Empty"<<endl;
     }
     return 0;
}