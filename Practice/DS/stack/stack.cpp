#include<iostream>
#include "Node.h"
using namespace std;

class Stack{
	Node* top;
public:
	Stack(){
		top = NULL;
	}

	bool empty(){
		if(top == NULL){
			return true;
		}else return false;
	}

	void push(int data){
		Node* newNode = new Node(data);
		if(top == NULL){
			top = newNode;
		}else{
			newNode->next = top;
			top = newNode;
		}
		return;
	}

	void print(){
		Node* temp = top;
		while(temp!=NULL){
			cout<<temp->data<<",";
		    temp = temp->next;
		}
		cout<<endl;
		return;
	}

	void pop(){
		if(top == NULL){
			return;
		}
		Node* temp = top;
		top = top->next;
		temp->next = NULL;
		delete temp;
		return;
	}

	int Top(){
		if(top!=NULL){
			return top->data;
		}
		else return -1;
	}
};



int main(){
    Stack s;
    s.push(2);
    s.push(4);
    s.push(4);
    s.push(1);
    s.push(9);
    s.print();
    while(!s.empty()){
    	cout<<s.Top()<<",";
    	s.pop();
    }
    cout<<endl;

    return 0;
}