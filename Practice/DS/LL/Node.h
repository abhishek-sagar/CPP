#ifndef NODE_H
#define NODE_H

class Node{
public:
	int data;
	Node* next;

	Node(int d){
		this->data = d;
		this->next = NULL;
	}
};

#endif