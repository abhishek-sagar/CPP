#include<iostream>
#include "Node.h"
#include<climits>
#include<set>
using namespace std;

Node* TakeInput(){
	Node* root = NULL;
	Node* tail = NULL;
	int data;
	cout<<"enter the data : ";
	cin>>data;
	while(data!=-1){
		Node* newNode = new Node(data);
		if(root == NULL){
			root = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
		cout<<"enter the data : ";
	    cin>>data;
	}
	return root;
}

Node* Swap(Node* root, int x,int y){
	 if(x == y){
	 	return root;
	 }
     Node* temp1 = NULL;
     Node* temp2 = NULL;
     int i=0;
     for(i;i<x-1;i++){
     	if(temp1 == NULL){
     		temp1 = root;
     	}else{
     	  temp1 = temp1->next;
        }
     }
     for(i=0;i<y-1;i++){
        if(temp2 == NULL){
     		temp2 = root;
     	}else{
     	  temp2 = temp2->next;
        }  	
     }
     if(temp1 != NULL){
     	Node* t1 = temp1->next;
     	Node* t2 = temp2->next;
     	temp2->next = t1;
     	Node* temp = t1->next;
     	t1->next = t2->next;
     	temp1->next = t2;
     	t2->next = temp;
     }else{
     	Node* t1 = root;
     	Node* t2 = temp2->next;
        temp2->next = t1;
        Node* temp = t1->next;
        t1->next = t2->next;
        root = t2;
        t2->next = temp;
     }
     return root;
}

Node* Merge(Node* root1,Node* root2){
	if(root1 == NULL){
		return root2;
	}else if(root2 == NULL){
		return root1;
	}else{
		if(root1->data <= root2->data){
			root1->next = Merge(root1->next,root2);
            return root1;
		}else{
			root2->next = Merge(root1,root2->next);
			return root2;
		}
	}
}

void Mid(Node* const root){
	Node* fast = root->next;
	Node* slow = root;
	while(fast!=NULL){
		fast = fast->next;
		slow = slow->next;
		if(fast!=NULL){
			fast = fast->next;
		}
	}
	cout<<"mid : "<<slow->data<<endl;
}

int Length(Node* const root){
     int l=0;
     if(root == NULL){
     	return 0;
     }else{
     	Node* temp = root;
     	while(temp!=NULL){
     		temp = temp->next;
     		l++;
     	}
     }
     return l;
}

// Selection Sort

Node* SelectionSort(Node* root){
	Node* i = root;
	int indexi = 1;
	for(i;i!=NULL;i = i->next,indexi++){
		int small = INT_MAX;
		int indexj;
		int fakeindexj = indexi;
		Node* updatedi = NULL;    // i is updated after every loop because of swap.
		Node* j = i;
		for(j;j!=NULL;j = j->next,fakeindexj++){
            if(j->data < small){
            	small = j->data;
            	updatedi = j;
            	indexj = fakeindexj;
            }
		}
		root = Swap(root,indexi,indexj);
		i = updatedi;
	}
	return root;
}

void PrintLL(Node* const root){
	Node* temp = root;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<endl;
	return;
}

Node* BubbleSort(Node* root){
	for(int i=0;i<Length(root);i++){
		Node* prev = NULL;
		Node* j = root;
		while(j->next!=NULL){
			if(j->data > j->next->data){
				if(prev == NULL){
                    Node* temp = j->next;
                    j->next = temp->next;
                    root = temp;
                    temp->next = j;
				}else{
					Node*temp = j->next;
					j->next = temp->next;
					prev->next = temp;
                    temp->next = j;
				}
			}else{
				j = j->next;
			}
			if(prev == NULL){
				prev = root;
			}else if(prev != NULL){
				prev = prev->next;
			}
		}
	}
	return root;
}

Node* InsertionSort(Node* root){
	if(root == NULL || root->next == NULL){
		return root;
	}else{
	    Node* i = root->next;
	    Node* updatedi = NULL;
	    int indexi = 2;
	    for(i;i!=NULL;i = i->next,indexi++){
		    Node* j = root;
		    int indexj = 1;
		    while(j!=i){
               if(j->data > i->data){
                 updatedi = j;
                 j = i;
                 i = updatedi;
               	 root = Swap(root,indexj,indexi);
               	 j = j->next;
               	 indexj++;
               }else{
               	 j = j->next;
               	 indexj++;
               }
		    }
	    }
	    return root;
    }
}

void Split(Node* source,Node** h1, Node** h2){
	if(source == NULL || source->next == NULL){
		*h1 = source;
		*h2 = NULL;
		return;
	}else{
		Node* fast = source->next;
		Node* slow = source;
		while(fast!=NULL){
			fast = fast->next;
			if(fast!=NULL){
				fast = fast->next;
				slow = slow->next;
			}
		}
		*h1 = source;
		*h2 = slow->next;
		slow->next = NULL;
        return;
	}
}

void MergeSort(Node** root){
    Node* head = *root;
    if(head == NULL || head->next == NULL){
    	return;
    }else{
    	Node* h1 = NULL;
    	Node* h2 = NULL;
    	Split(head,&h1,&h2);
    	MergeSort(&h1);
    	MergeSort(&h2);
    	*root = Merge(h1,h2);
    	return;
    }
}

Node* ReverseI(Node* root){
    if(root == NULL || root->next == NULL){
        return root;
    }else{
	   Node* prev = NULL;
	   Node* current = root;
	   Node* cn = root->next;
	   while(cn != NULL){
           current->next = prev;
           prev = current;
           current = cn;
           cn = current->next;
	   }
	   current->next = prev;
	   return current;
	}
}

Node* ReverseR(Node* root){
	if(root == NULL || root->next == NULL){
		return root;
	}else{
		Node* temp = ReverseR(root->next);
        root->next->next = root;
        root->next = NULL;
        return temp;
	}
}

// detect loop using hashmap by saving the address of pointer in O(n) and O(n)space
// another algo is by fast and slow method

void DetectLoop(Node* root){
    set<Node*> myset;
    set<Node*>::iterator itr;
    Node* temp = root;
    while(temp!=NULL){
       itr = myset.find(temp);
       if(itr != myset.end()){
       	 cout<<"Loop Found at : "<<temp->data<<endl;
         break;
       }else{
         myset.insert(temp);
         temp = temp->next;
       }
    }
    int i=1;
    Node* x = temp;
    while(x->next != temp){
    	i++;
    	x = x->next;
    }
    cout<<"length of loop is : "<<i<<endl;
    return;
}


int main(){
    // Node* root1 = TakeInput();
    // Node* root2 = TakeInput();
    // PrintLL(root1);
    // PrintLL(root2);
    // Node* root = NULL;
    // root = Merge(root1,root2);
    // PrintLL(root);
    // root = Swap(root,1,7);
    // PrintLL(root);

    // Node* root = TakeInput();
    // PrintLL(root);
    // MergeSort(&root);
    // PrintLL(root);
    // root = ReverseR(root);
    // PrintLL(root);

    
    // Node* root = new Node(3);
    // int i=0,data;
    // cout<<"enter data : ";
    // cin>>data;
    // Node* tail = root;
    // while(data!=-1){
    // 	Node* newNode = new Node(data);
    // 	tail->next = newNode;
    // 	tail = newNode;
    // 	cout<<"enter data : ";
    //     cin>>data;
    // }
    // Node* temp = root;
    // while(i<3){
    // 	temp = temp->next;
    // 	i++;
    // }
    // tail->next = temp;
    // DetectLoop(root);


    return 0;
}