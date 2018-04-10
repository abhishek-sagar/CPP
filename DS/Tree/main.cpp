#include<iostream>
#include "Node.h"

using namespace std;

Node* takeInput(){
  Node* root = NULL;
  int data;
  cout<<"enter the data :- ";
  cin>>data;
  if(data == -1){
    return root;
  }else{
    Node* newNode = new Node(data);
    root = newNode;
    root->left = takeInput();
    root->right = takeInput();
  }
  return root;
}

void printTree(Node* root){
  if(root == NULL){
    return;
  }else{
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
  }
  return;
}

int main(){
  Node* root = takeInput();
  printTree(root);
  return 0;
  //1,2,4,-1,-1,5,-1,-1,3,6,7,-1,-1,8,-1,-1,-1
}
