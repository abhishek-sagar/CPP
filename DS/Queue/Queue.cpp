#include<iostream>
#include "queue.h"
using namespace std;
template <typename T>

class Queue{
public:
	Node<T>* front = NULL;
    Node<T>* rear = NULL;
	void Enqueue(T data){
		Node<T>* newNode = new Node<T>(data);
		if(front == NULL){
			front = newNode;
			rear = newNode;
		}else{
			rear->next = newNode;
			rear = newNode;
		}
		return;
	}

	void Dequeue(){
		if(front == NULL){
			return;
		}else{
			Node<T>* temp = front;
			front = front->next;
			temp->next = NULL;
			delete temp;
			return;
		}
	}

	T Front(){
		if(front != NULL){
			return (front->data);
		}
	}

	bool Isempty(){
		if(front == NULL){
			return true;
		}else return false;
	}

	void PrintQ(){
		Node<T>* temp = front;
		while(temp != NULL){
			cout<<temp->data<<"->";
		    temp = temp->next;
		}
		cout<<endl;
	}
};

template <typename T>
Node<T>* ReverseQ(Node<T>* front , Node<T>** rear){
	if(front == (*rear) || front == NULL){
		return front;
	}else{
		Node<T>* temp = ReverseQ(front->next , rear);
        front->next->next = front;
        front->next = NULL;
        (*rear) = front;
        return temp;        
	}
}

int main(){
     Queue<int> Q;
     for(int i=0;i<10;i++){
     	Q.Enqueue(i);
     }
     Q.PrintQ();
     Q.Dequeue();
     cout<<"now front : "<<(Q.front->data)<<endl;
     cout<<"empty or not : "<<Q.Isempty()<<endl;

     // Q.front = ReverseQ(Q.front , & Q.rear);
     // Q.PrintQ();
     // Q.Enqueue(11);
     // Q.PrintQ(); 

     return 0;
}
