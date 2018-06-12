#include<iostream>
#include "Node.h"
#include<queue>
#include<vector>
using namespace std;

class BST{
public: 
  Node<int>* root;

  BST(){
  	root= NULL;
  }
  
  void TakeBSTInput(int data){
  	root = BSTInput(root,data);
  	return;
  }

  Node<int>* BSTInput(Node<int>* root, int data){
	if(root == NULL){
		Node<int>* newNode = new Node<int>(data);
		root = newNode;
 	}else if(root->data > data){
 		root->left = BSTInput(root->left,data);
 	}else{
 		root->right = BSTInput(root->right,data);
 	}
 	return root;
  }
 
  bool findEle(int element){
  	Node<int>* current = root;
  	while(true){
  		if(current == NULL){
  			return false;
  		}else if(current->data == element){
  			return true;
  		}else if(current->data > element){
  			current = current->left;
  		}else{
  			current = current->right;
  		}
  	}
  }

  Node<int>* highest(Node<int>* root){
  	Node<int>* current = root;
  	while(true){
  		if(current->right == NULL){
  			return current;
  		}else{
  			current = current->right;
  		}
  	}
  }

  Node<int>* lowest(Node<int>* root){
  	Node<int>* current = root;
  	while(true){
  		if(current->left == NULL){
  			return current;
  		}else{
  			current = current->left;
  		}
  	}
  }

  Node<int>* DeleteNode(Node<int>* root,int data){
    if(root->data == data){
  		if(root->left == NULL && root->right == NULL){
  			delete root;
  			return NULL;
  		}else if(root->left){
             Node<int>* l_high = highest(root->left);
             int temp = root->data;
             root->data = l_high->data;
             l_high->data = temp;
             root->left = DeleteNode(root->left,temp);
             return root;
  		}else if(root->right){
             Node<int>* r_low = lowest(root->right);
             int temp = root->data;
             root->data = r_low->data;
             r_low->data = temp;
             root->right = DeleteNode(root->right,temp);
             return root;
  		}
  	}else{
        if(data > root->data){
        	root->right = DeleteNode(root->right,data);
        }else{
        	root->left = DeleteNode(root->left,data);
        }
        return root;
  	}
  }

  void removeNode(int data){
  	if(findEle(data)){
  	   root = DeleteNode(root,data);
  	}
  	return;
  }

};

void BST_sortedArray(BST & b,int a[],int l,int r){
    if(l<=r){
        int mid = l + (r-l)/2;
        b.TakeBSTInput(a[mid]);
        BST_sortedArray(b,a,l,mid-1);
        BST_sortedArray(b,a,mid+1,r);
    }
    return; 
}

Node<int>* bst_sortedArr(int a[],int l, int r){
  if(l<=r){
    int mid = l+(r-l)/2;
    Node<int>* root = new Node<int>(a[mid]);
    root->left = bst_sortedArr(a,l,mid-1);
    root->right = bst_sortedArr(a,mid+1,r);
    return root;
  }
  else return NULL;
}

void levelorder(Node<int>* root){
    if(root!=NULL){
    Node<int>* temp = NULL;
    queue<Node<int>*> Q;
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

void PrintBST(Node<int>* root){
	if(root == NULL){
		return;
	}else{
		cout<<root->data<<",";
		PrintBST(root->left);
		PrintBST(root->right);
	}
	cout<<endl;
	return;
}

Node<int>* lca(Node<int>* root,int x, int y){
  if(root == NULL){
    return NULL;
  }else if( (root->data >= x && root->data <= y) || (root->data >= y && root->data <= x)){
     return root;
  }else if(root->data > x && root->data > y){
    return lca(root->left,x,y);
  }else{
    return lca(root->right,x,y);
  }
}

void count(Node<int>* root,int data,int & num){
    if(root->data == data){
      return;
    }else{
       if(root->data > data){  
           num++;
           count(root->left,data,num);
       }else{
           num++;
           count(root->right,data,num);
       }
    }  
}

int shortestpathlen(Node<int>* root,int x,int y){
  if(root == NULL){
    return -1;
  }else{
    Node<int>* LCA = lca(root,x,y);
    int leftcount = 0,rightcount = 0;
    count(LCA,x,leftcount);
    count(LCA,y,rightcount);
    return (leftcount+rightcount);
  }
}

//***********//
// kth smallest with O(n) and O(n) space
vector<int> findthekthsmall(Node<int>* root){
    vector<int> v;
    if(root == NULL){
      return v;
    }else{
      vector<int> vleft = findthekthsmall(root->left);
      vector<int>::iterator it = vleft.begin();
      while(it!=vleft.end()){
          v.push_back(*it);
          it++;
      }
      v.push_back(root->data);
      vector<int> vright = findthekthsmall(root->right);
      it = vright.begin();
      while(it!=vright.end()){
          v.push_back(*it);
          it++;
      }
      return v;
    }
}

int KthSmallest(Node<int>* root,int k){
  if(root == NULL){
    return -1;
  }else{
    vector<int> v = findthekthsmall(root);
    vector<int>::iterator itr = v.begin();
    int i=1;
    while(i<k){
      i++;
      itr++;
    }
    return *itr;
  }
}

//********************//

int KthSmallest2(Node<int>* root,int k,int& count){
    if(root == NULL){
      return -1;
    }else{
      int leftside = KthSmallest2(root->left,k,count);
      if(count == k){
        count++;
        return root->data;
      }else{
        count++;
      }
      int rightside = KthSmallest2(root->right,k,count);
      return (leftside!=-1 ? leftside : rightside);
    }
}

int Kthlargest(Node<int>* root,int k,int& count){
    if(root == NULL){
      return -1;
    }else{
      int rightside = Kthlargest(root->right,k,count);
      if(count == k){
        count++;
        return root->data;
      }else{
        count++;
      }
      int leftside = Kthlargest(root->left,k,count);
      return (rightside!=-1 ? rightside : leftside);
    }
}

void PrintBtwK1k2(Node<int>* root,int k1,int k2){
  if(root == NULL){
    return;
  }else if(root->data < k1){
    PrintBtwK1k2(root->right,k1,k2);
    return;
  }else if(root->data > k2){
    PrintBtwK1k2(root->left,k1,k2);
    return;
  }else if(root->data >= k1 && root->data <= k2){
    cout<<root->data<<",";
    PrintBtwK1k2(root->left,k1,k2);
    PrintBtwK1k2(root->right,k1,k2);
    return;
  }
}

Node<int>* TrimTheTreeBteK1K2(Node<int>* root,int k1 ,int k2){
  if(root == NULL){
    return NULL;
  }else if(root->data < k1){
    root = TrimTheTreeBteK1K2(root->right,k1,k2);
    return root;
  }else if(root->data > k2){
    root = TrimTheTreeBteK1K2(root->left,k1,k2);
    return root;
  }else{
     root->left = TrimTheTreeBteK1K2(root->left,k1,k2);
     root->right = TrimTheTreeBteK1K2(root->right,k1,k2);
     return root;
  }
}


//*********************MOST IMPORTANT ************************//
/*Print all Nodes at a distance of k from a given node 
  devide the question into two parts 
  1. Nodes in the subtree rooted with target node. print all of those
  2. for the remaining nodes find lca of each node with the given node
     and from lca calculate the min distance b/w them if lies at k 
     distance apart so print it.

  complexity seems to be greater than O(n) but on close look , find that
  each node is visited atmost twice so time complexity is O(n).
  */
//************************************************************//

int main(){
    BST b;
    b.TakeBSTInput(7);
    b.TakeBSTInput(3);
    b.TakeBSTInput(11);
    b.TakeBSTInput(2);
    b.TakeBSTInput(4);
    b.TakeBSTInput(8);
    b.TakeBSTInput(15);
    b.TakeBSTInput(6);
    b.TakeBSTInput(10);
    b.TakeBSTInput(5);

    levelorder(b.root);
    cout<<endl;

    //cout<<b.findEle(8)<<endl;
    
    // cout<<"highest : "<<b.highestval(b.root)<<endl;
    // cout<<"lowest : "<<b.lowestval(b.root)<<endl;

    // b.removeNode(3);
    // levelorder(b.root);
    // cout<<endl;
    // b.removeNode(2);
    // levelorder(b.root);

    // BST x;
    //int a[] = {2,3,4,5,6,7,8,10,11,15};
    // BST_sortedArray(x,a,0,9);
    // levelorder(x.root);

    // Node<int>* root = bst_sortedArr(a,0,9);
    // levelorder(root);

    // cout<<"lca : "<<(lca(b.root,2,15))->data<<endl;
    // cout<<"shortest path len : "<<shortestpathlen(b.root,2,15)<<endl;

    // int i=1,j=1;
    // cout<<"8th smallest : "<<KthSmallest2(b.root,8,i)<<endl;
    // cout<<"2nd largest : "<<Kthlargest(b.root,2,j)<<endl;
    
    // PrintBtwK1k2(b.root,2,3);
    //cout<<endl;

    // b.root = TrimTheTreeBteK1K2(b.root,2,7);
    // levelorder(b.root);


    return 0;
}