#include<iostream>
#include "../stack/Node.h"
using namespace std;

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

// Do this Question Find the merge point of two ll;
//and the other questions of LL also you can see the code blocks file or go to hackerrank;

Node* InsertAtEnd(Node* head,int d){
	Node* newNode = new Node(d);
	if(head == NULL){
		head = newNode;
	}
	else{
		Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	return head;
}

void deleteNode(Node*head,int pos){
	if(pos == 1){
        Node*temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
	}
	else{
		Node*current = head;
		while(pos!=2 && current->next != NULL){
           current = current->next;
           pos--;
		}
        Node*temp = current->next;
        current->next = temp->next;
        temp->next = NULL;
        delete temp;
	}
	return;
}

void PrintLL(Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
	return;
}

Node* merge(Node* head1 , Node* head2){
	if(head1 == NULL){
		return head2;
	}
	else if(head2 == NULL){
		return head1;
	}
	else if(head1 == NULL && head2 ==NULL){
		return NULL;
	}
	else if(head1->data <= head2->data){
		head1->next = merge(head1->next,head2);
		return head1;
	}
	else{
		head2->next = merge(head1,head2->next);
		return head2;
	}
}

void split(Node* source, Node** h1,Node** h2){
      if(source == NULL || source->next == NULL){
      	*h1 = source;
      	*h2 = NULL;
      }
      else{
      	Node* slow = source;
      	Node* fast = source->next;
      	while(fast != NULL){
      		fast = fast->next;
      		if(fast != NULL){
      			fast = fast->next;
      			slow = slow->next;
      		}
      	}
      	*h2 = slow->next;
      	*h1 = source;
      	slow->next = NULL;
      }
      return;
}

void mergesort(Node** head){
    Node* h = *head;
    if(h == NULL || h->next == NULL){
    	return;
    }
    else{
    	Node* h1 = NULL;
    	Node* h2 = NULL;
    	split(h,&h1,&h2);
    	mergesort(&h1);
    	mergesort(&h2);
    	*head = merge(h1,h2);
    }
    return;
}

//****** detect loop and remove it *****//

void DetectAndDelete(Node* head){
    if(head == NULL || head->next == NULL){
    	return;
    }
	Node* slow = head;
	Node* fast = head;
	Node* ptr = NULL;
	while(fast!=NULL){
		fast = fast->next;
		if(fast!=NULL){
			slow = slow->next;
			fast = fast->next;
			if(slow == fast){
               ptr = slow;
               cout<<"Loop Present"<<endl;
               break;
			}
		}
	}
	if(ptr == NULL){
		cout<<"No Loop Present"<<endl;
	}
	else{
		Node* temp = head;
		while(temp->next != ptr->next){
			ptr = ptr->next;
			temp = temp->next;
		}
		ptr->next = NULL;
		cout<<"Loop Removed"<<endl;
	}
	return;
}

//*********** Doubli Linked List *****************//

class Dll{
public:
	int data;
	Dll* next;
	Dll* prev;
	Dll(int data){
		this->data = data;
		this->next = NULL;
		this->prev = NULL; 
	}
};

void InsertNode(Dll** head,int data){
	Dll* newNode = new Dll(data);
	if(*head == NULL){
		*head = newNode;
	}
	else{
		Dll* temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		newNode->prev = temp;
		temp->next = newNode;
	}
	return;
}

void PrintDLL(Dll* head){
	Dll* temp = head;
	while(temp!=NULL){
       cout<<temp->data<<" ";
       temp = temp->next;
	}
	cout<<endl;
	return;
}

void PrintDLLFromTail(Dll* tail){
	Dll* temp =tail;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
	cout<<endl;
	return;
}

Dll* ReverseDLL(Dll* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	else{
       Dll* newNode = ReverseDLL(head->next);
       Dll* temp = head->next;
       temp->next = head;
       head->prev = temp;
       head->next = NULL;
       newNode->prev = NULL;
       return newNode; 
	}
}

int main(){
      Dll* head = NULL;
      InsertNode(&head,4);
      InsertNode(&head,6);
      InsertNode(&head,2);
      InsertNode(&head,0);
      InsertNode(&head,-6);
      PrintDLL(head);
      head = ReverseDLL(head);
      PrintDLL(head);
      return 0;
}