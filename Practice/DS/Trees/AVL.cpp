#include <iostream>
#include "AVLNode.h"
#include <math.h>
#include<queue>
using namespace std;

class AVLTree{
public:
	AVLNode* root = NULL;

	int height(AVLNode* root){
		if(root == NULL){
			return -1;
		}else return (root->height);
	}

	AVLNode* rotateRight(AVLNode * y){
        AVLNode* x = y->left;
        AVLNode* z = x->right;

        x->right = y;
        y->left  = z;

        y->height = 1+max(height(y->left),height(y->right));
        x->height = 1+max(height(x->left),height(x->right));

        return x;
	}

	AVLNode* rotateLeft(AVLNode* y){
		AVLNode* x = y->right;
		AVLNode* z = x->left;

		x->left = y;
		y->right = z;

        y->height = 1+max(height(y->left),height(y->right));
        x->height = 1+max(height(x->left),height(x->right));

        return x;		
	}

    AVLNode* TakeInput(AVLNode* root,int data){
    	if(root == NULL){
    		AVLNode* newNode = new AVLNode(data);
    		return newNode;
    	}else if(root->data > data){
    		root->left = TakeInput(root->left,data);
    	}else if(root->data < data){
    		root->right = TakeInput(root->right,data);
    	}else{
    		return root;
    	}
    	root->height = 1+ max(height(root->left),height(root->right));
    	int diff =  height(root->left) - height(root->right);
    	if(diff > 1 && root->left->data > data){ // ll
            return rotateRight(root);
    	}else if(diff > 1 && root->left->data < data){
    		root->left = rotateLeft(root->left);
    		return rotateRight(root);
    	}else if(diff < -1 && root->right->data < data){
    		return rotateLeft(root);
    	}else if(diff < -1 && root->right->data > data){
    		root->right = rotateRight(root->right);
    		return rotateLeft(root);
    	}
    	return root;
    }

	void InsertNode(int data){
		root = TakeInput(root,data);
	    return;
	}

};

void levelorder(AVLNode* root){
    if(root!=NULL){
    AVLNode* temp = NULL;
    queue<AVLNode*> Q;
    Q.push(root);
    Q.push(temp);
    while(!Q.empty()){
        root = Q.front();
        Q.pop();
        if(root == NULL){
        	Q.push(temp);
        	cout<<endl;
        	if(Q.front() == NULL){
        		return;
        	}
        }else{
            cout<<root->data<<",";
            if(root->left!=NULL){
        	   Q.push(root->left);
            }
            if(root->right!=NULL){
        	   Q.push(root->right);
            }
        }
    }
    }
    return;
}


int main(){
	AVLTree T;

	T.InsertNode(10);
	T.InsertNode(20);
	T.InsertNode(30);
	T.InsertNode(40);
	T.InsertNode(50);
	levelorder(T.root);
	return 0;
}