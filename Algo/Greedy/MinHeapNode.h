#ifndef MINHEAPNODE_H
#define MINHEAPNODE_H

class MinHeapNode{
public:
	char c;
	int freq;
	MinHeapNode* left;
	MinHeapNode* right;

	MinHeapNode(char c,int freq){
		this->c = c;
		this->freq = freq;
		this->left = NULL;
		this->right = NULL;
	}
};

#endif