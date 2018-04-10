#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

Node* takeinput(){
  Node* head = NULL;
  Node* tail = NULL;
  int d;
  cout<<"enter the data : ";
  cin>>d;
  while(d!=-1){
    Node* newNode = new Node(d);
    if(head == NULL){
      head = newNode;
      tail = newNode;
    }
    else{
      tail->next = newNode;
      tail = newNode;
    }
    cout<<"enter the data : ";
    cin>>d;
  }
  return head;
}

void printLL(Node* head){
    while(head != NULL){
    	cout<<head->data<<"->";
    	head = head->next;
    }
    cout<<endl;
    return;
}

int main(){
   Node* head = takeinput();
   printLL(head);
   printLL(head);
   return 0;
}
