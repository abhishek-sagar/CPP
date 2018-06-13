#include<iostream>
#include<math.h>
#include "AVLNode.h"
#include<queue>
using namespace std;

class AVLTree{
public:
	AVLNode* root = NULL;

	int height(AVLNode* root){
		if(root == NULL){
			return 0;
		}else return (root->height);
	}

	int balance(AVLNode* root){
		if(root == NULL){
			return 0;
		}else{
			return (height(root->left) - height(root->right));
		}
	}
    
    AVLNode* rotateright(AVLNode* y){
    	AVLNode* x = y->left;
    	AVLNode* z = x->right;

    	x->right = y;
    	y->left = z;

    	y->height = max(height(y->left),height(y->right))+1;
    	x->height = max(height(x->left),height(x->right))+1;
    	return x;
    }

    AVLNode* rotateleft(AVLNode* x){
    	AVLNode* y = x->right;
    	AVLNode* z = y->left;

    	y->left = x;
    	x->right = z;

    	x->height = max(height(x->left),height(x->right))+1;
    	y->height = max(height(y->left),height(y->right))+1;
    	return y;
    }

    AVLNode* InsertEleToAVL(AVLNode* root, int data){
        if(root == NULL){
        	AVLNode* newNode = new AVLNode(data);
        	return newNode;
        }else if(root->data < data){
            root->right = InsertEleToAVL(root->right,data);
        }else if(root->data > data){
        	root->left = InsertEleToAVL(root->left,data);
        }else{
           return root;
        }
        	root->height = 1 + max(height(root->left),height(root->right));
            int diff = balance(root);
            if(diff > 1 && root->left->data > data){ //Left Left case.
                return rotateright(root);
            }if(diff > 1 && root->left->data < data){ // left right case.
                root->left = rotateleft(root->left);
                return rotateright(root);
            }if(diff < -1 && root->right->data < data){ // Right right
                return rotateleft(root);
            }if(diff < -1 && root->right->data > data){ // Right left 
                root->right = rotateright(root->right);
                return rotateleft(root);
            }
            return root;
    }

	void InsertElement(int data){
         root = InsertEleToAVL(root,data);
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
    AVLTree a;
    a.InsertElement(2);
    a.InsertElement(1);
    a.InsertElement(3);
    a.InsertElement(-1);
    levelorder(a.root);
    cout<<endl;
    a.InsertElement(-2);
    levelorder(a.root);
    cout<<endl;
    a.InsertElement(0);
    a.InsertElement(4);
    levelorder(a.root);
    cout<<endl;
    return 0;
}