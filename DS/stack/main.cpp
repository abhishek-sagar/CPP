#include <iostream>
#include <stack>
#include "Node.h"
using namespace std;

class Stack{
   Node* top = NULL;
   public:
   	 void push(int data){
   	 	Node* newnode = new Node(data);
   	 	if(top == NULL){
   	 		top = newnode;
   	 		return;
   	 	}
   	 	else{
   	 		newnode->next = top;
   	 		top = newnode;
   	 		return;
   	 	}
   	 }

   	 int pop(){
   	 	int output;
   	 	if(top == NULL){
   	 		return -1;
   	 	}
   	 	else{
   	 		Node* temp = top;
   	 		top = top->next;
   	 		output = temp->data;
   	 		temp->next = NULL;
   	 		delete temp;
   	 		return output;
   	 	}
   	 }

   	 int Top(){
   	 	if(top!=NULL){
   	 		return (top->data);
   	 	}
   	 	else return -1;
   	 }

   	 bool empty(){
   	 	if(top==NULL){
   	 		return true;
   	 	}
   	 	else return false;
   	 }

   	 void print(){
   	 	if(top == NULL){
   	 		return;
   	 	}
   	 	else{
   	 	  Node* temp = top;
   	      while(temp!=NULL){
             cout<<temp->data<<endl;
             temp = temp->next;  
   	 	  }
   	    }
   	    return;
   	 }

   	 int size(){
   	 	int out=0;
   	 	if(top == NULL){
   	 		return 0;
   	 	}
   	 	Node* temp = top;
   	 	while(temp!=NULL){
   	 		temp = temp->next;
   	 		out++;
   	 	}
   	 	return out;
   	 }
};

int main(){
 //     stack<int> s;      Use STL like this.For more info go to cplusplus.com
      Stack s;
      s.push(2);
      s.push(3);
      s.push(4);
      s.push(4);
      s.push(25);
      s.push(6);
      int n = s.size();
      for(int i=0;i<n;i++){
      	cout<<s.Top()<<endl;
         s.pop();
      }
      if(s.empty()){
      	cout<<"yes"<<endl;
      }
      else{
      	cout<<"Stack is not empty"<<endl;
      }
}