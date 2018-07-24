#ifndef NODE_H
#define NODE_H

class Node{
public:
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
  ~Node(){
  	if(left!=NULL){
  		delete left;
  	}
  	if(right !=NULL){
  		delete right;
  	}
  }
};

#endif
