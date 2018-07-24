#include<iostream>
#include "Node.h"
using namespace std;

Node* TakeInput(){
	Node* head = NULL;
	Node* tail = NULL;
	int data;
	cout<<"enter data : ";
	cin>>data;
	while(data != -1){
		Node* newNode = new Node(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
		cout<<"enter data : ";
	    cin>>data;
	}
	return head;
}

// void Split(Node* source,Node** h1,Node** h2){
// 	if(source == NULL || source->next == NULL){
// 		*h1 = source;
// 		*h2 = NULL;
// 		return;
// 	}
// 	Node* fast = source->next;
// 	Node* slow = source;
// 	while(fast!=NULL){
//         fast = fast->next;
//         if(fast != NULL){
//         	fast = fast->next;
//             slow = slow->next;
//         }
// 	}
// 	Node* temp = slow;
// 	slow = slow->next;
// 	temp->next = NULL;
// 	*h1 = source;
//     *h2 = slow;
//     return;
// }

// Node* Merge(Node* head1,Node* head2){
// 	if(head1 == NULL){
//         return head2;
// 	}else if(head2 == NULL){
// 		return head1;
// 	}else{
// 		if(head1->data <= head2->data){
// 			head1->next = Merge(head1->next,head2);
// 			return head1;
// 		}else{
//             head2->next = Merge(head1,head2->next);
//             return head2;
// 		}
// 	}
// }

// void MergeSort(Node** head){
// 	Node* h = *head;
// 	if(h == NULL || h->next == NULL){
// 		return;
// 	}else{
// 	    Node* h1 = NULL;
// 	    Node* h2 = NULL;
// 	    Split(h,&h1,&h2);
//         MergeSort(&h1);
//         MergeSort(&h2);
//         *head = Merge(h1,h2);
// 	}
// 	return;
// }

void Split(Node* head,Node** h1,Node** h2){
	if(head == NULL || head->next == NULL){
		*h1 = head;
		*h2 = NULL;
		return;
	}else{
		Node* fast = head->next;
		Node* slow = head;
		while(fast != NULL){
			fast = fast->next;
			if(fast!=NULL){
				fast = fast->next;
				slow = slow->next;
			}
		}
		*h2 = slow->next;
		slow->next = NULL;
		*h1 = head;
		return;
	}
}

Node* Merge(Node* head1,Node* head2){
	if(head1 == NULL){
		return head2;
	}else if(head2 == NULL){
		return head1;
	}
	else{
		if(head1->data<=head2->data){
			head1->next = Merge(head1->next,head2);
			return head1;
		}else{
			head2->next = Merge(head1,head2->next);
			return head2;
		}
	}
}

void MergeSort(Node** head){
	Node* h = *head;
	if(*head == NULL || (*head)->next == NULL){
		return;
	}else{
		Node* h1 = NULL;
		Node* h2 = NULL;
		Split(h,&h1,&h2);
		MergeSort(&h1);
		MergeSort(&h2);
		*head = Merge(h1,h2);
	}
	return;
}

void Print(Node* head){
	if(head == NULL){
		return;
	}else{
		while(head != NULL){
			cout<<head->data<<",";
			head = head->next;
		}
	}
	cout<<endl;
	return;
}


// int FindLen(struct node* head){
//     if(head == NULL){
//         return 0;
//     }
//     int l = 0;
//     while(head!=NULL){
//         head = head->next;
//         l++;
//     }
//     cout<<"l : "<<l<<endl;
//     return l;
// }

// struct node* findIntersection(struct node* head1, struct node* head2)
// {
//     if(head1 == NULL || head2 == NULL){
//         return 0;
//     }
//     int l1 = FindLen(head1);
//     int l2 = FindLen(head2);
//     if(l1<l2){
//         int l = l2-l1;
//         while(l!=0){
//             head2 = head2->next;
//             l--;
//         }
//         while(head1!=head2){
//             head1 = head1->next;
//             head2 = head2->next;
//         }
//         return head1;
//     }else{
//         int l = l1-l2;
//         while(l!=0){
//             head1 = head1->next;
//             l--;
//         }
//         while(head1!=head2){
//             head1 = head1->next;
//             head2 = head2->next;
//         }
//         return head1;
//     }
// }


// 2 6 -4 0 1 5 2 -1

void Sort(int a[],int n){
    int i=-1,j=0;
    while(j<n){
        if(a[j]>0){
            j++;
        }else{
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
    i=-1;
    j=0;
    while(j<n){
        if(a[j]>1){
            j++;
        }else{
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
    return;
}

Node* sortList(Node *head)
{
    if(head == NULL){
        return NULL;
    }
    int a[1000];
    int i=0;
    Node* temp = head;
    while(temp!=NULL){
        a[i] = temp->data;
        i++;
        temp = temp->next;
    }
    Sort(a,i);
    head = NULL;
    temp = NULL;
    int j=0;
    while(j<i){
        Node* newNode = new Node(a[j]);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp->next = newNode;
            temp = newNode;
        }
        j++;
    }
    return head;
}


int main(){
     Node* head = TakeInput();
     Print(head);
    // MergeSort(&head);
     head = sortList(head);
     Print(head);
     return 0;
}