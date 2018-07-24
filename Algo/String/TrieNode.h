#ifndef TRIENODE_H
#define TRIENODE_H
#include<map>
using namespace std;

class Node{
public:
	map<char,Node*>* children;
	bool endofWord;

	Node(){
		children = new map<char,Node*>();
		endofWord = false;
	}

	~Node(){
		delete children;
	}
};

#endif