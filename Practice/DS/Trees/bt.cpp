#include<iostream>
#include "Node.h"
#include<stack>
#include<map>
#include <vector>
using namespace std;

Node* TakeInput(){
	int data;
	cout<<"enter data : ";
	cin>>data;
    if(data != -1){
       Node* root = new Node(data);
       root->left = TakeInput();
       root->right = TakeInput();
       return root;
    }else{
    	return NULL;
    }
}

void print(Node* root){
	if(root == NULL){
		return;
	}else{
		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}
	return;
}

void Inorder_I(Node* root){
   if(root == NULL){
   	return;
   }else{
   	stack<Node*> s;
   	while(true){
   		if(root != NULL){
            s.push(root);
            root = root->left;
   		}else{
   			if(s.empty()){
   				break;
   			}
   			root = s.top();
   			cout<<root->data<<",";
   			s.pop();
   			root = root->right;
   		}
   	}
   	cout<<endl;
   	return;
   }
}

void Postorder_I(Node* root){
	if(root == NULL){
		return;
	}else{
		stack<Node*> s;
		Node* prev = NULL;
		while(true){
			if(root != NULL){
				s.push(root);
				root = root->left;
			}else{
				if(s.empty()){
					break;
				}
				root = s.top();
				if(root->left == NULL && root->right == NULL){
					cout<<root->data<<",";
    			    prev = root;
    		        s.pop();
    		        root = s.top();
				}
				if(root->right != prev && root->right != NULL){
					root = root->right;
				}else{
					cout<<root->data<<",";
					prev = root;
					s.pop();
					root = NULL;
				}
			}
		}
		cout<<endl;
		return;
	}
}

void VerticalOrder(Node* root,map<int,vector<int>>& m,int hd){
    if(root == NULL){
    	return;
    }else{
    	m[hd].push_back(root->data);
    	VerticalOrder(root->left,m,hd-1);
    	VerticalOrder(root->right,m,hd+1);
    	return;
    }
}

void PrintVerticalOrder(Node* root){
	if(root == NULL){
		return;
	}else{
       map<int,vector<int>> m;
       int hd = 0;
       VerticalOrder(root,m,hd);
       map<int,vector<int>>::iterator it = m.begin();
       for(it;it!=m.end();it++){
       	  for(int i=0;i<it->second.size();i++){
       	  	cout<<(it->second).at(i)<<" ";
       	  }
       	  cout<<endl;
       }
	}
	return;
}

void PrintTopView(Node* root){
	if(root == NULL){
		return;
	}else{
       map<int,vector<int>> m;
       int hd = 0;
       VerticalOrder(root,m,hd);
       map<int,vector<int>>::iterator it = m.begin();
       for(it;it!=m.end();it++){
       	  cout<<(it->second).at(0)<<" ";
       }
	}
	cout<<endl;
	return;
}

// 1 2 3 -1 -1 4 -1 -1 5 6 -1 8 -1 9 -1 10 -1 -1 7 -1 -1

int main(){
   Node* root = TakeInput();
   cout<<endl;
   cout<<endl;
   //print(root);
   //cout<<endl;
   //Inorder_I(root);
   //Postorder_I(root);
   PrintVerticalOrder(root);
   cout<<endl;
   PrintTopView(root);
   return 0;
}