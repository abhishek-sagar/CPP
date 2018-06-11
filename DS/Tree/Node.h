#ifndef NODE_H
#define NODE_H
template<typename T>

class Node{
public:
  T data;
  Node<T>* left;
  Node<T>* right;
  Node(T data){
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
