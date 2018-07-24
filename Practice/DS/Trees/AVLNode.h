#ifndef AVLNODE_H
#define AVLNODE_H

class AVLNode{
public:
	int data;
	AVLNode* left;
	AVLNode* right;
	int height;

	AVLNode(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->height = 0;
	}
};

#endif