#ifndef QUEUE_H
#define QUEUE_H
template <typename T>

class Node{
public:
	T data;
    Node* next;
	Node(T data){
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