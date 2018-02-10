#ifndef NODE_H
#define NODE_H

class Node{
public:
	int data;
	Node* next;
	Node(int data){
       this->data = data;
       this->next = NULL;
	}
	~Node(){
		if(this->next!=NULL){
			delete next;
		}
	}
};

#endif