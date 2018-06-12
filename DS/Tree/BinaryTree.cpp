#include<iostream>
#include "Node.h"
#include<math.h>
#include<stack>
#include<queue>
#include<climits>
#include<vector>
using namespace std;

Node<int>* takeBTInput() {
	cout << "Enter root data" << endl;
	int rootData;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	Node<int>* root = new Node<int>(rootData);
	root->left = takeBTInput();
	root->right = takeBTInput();
	return root;
}

// it the total no. of edge from the depest leaf node to root node.
// do not confuse it with the total no. of nodes.

int height_R(Node<int>* root){
	if(root == NULL){
		return -1;
	}else if(root->left == NULL && root->right == NULL){
		return 0;
	}else{
		return 1+max(height_R(root->left),height_R(root->right));
	}
}

int height_I(Node<int>* root){
	int h=0;
	queue<Node<int>*> q;
	Node<int>* temp1 = NULL;
	q.push(root);
    q.push(temp1);
    while(!q.empty()){
        root = q.front();
        q.pop();
        if(root == NULL){
        	q.push(temp1);
        	if(q.front() == NULL){
        		return h;
        	}
        	h++;
        }else{
        	if(root->left){
        		q.push(root->left);
        	}if(root->right){
        		q.push(root->right);
        	}
        }
    }
}


int totalNodes(Node<int>* root){
	if(root == NULL){
		return 0;
	}else{
		return 1+max(totalNodes(root->left),totalNodes(root->right));
	}
}

// it is the total no. of nodes b/w the longest path of two leafs node.

int diameter(Node<int>* root){
	if(root == NULL){
		return 0;
	}else{
	int option1 = 1 + totalNodes(root->left) + totalNodes(root->right);//1 is added for root
		int option2 = diameter(root->left);
		int option3 = diameter(root->right);
		return max(option1,max(option2,option3));
	}
}

void PrintT(Node<int>* root){
    if(root == NULL){
    	return;
    }else{
    	cout<<root->data<<",";
    	PrintT(root->left);
    	PrintT(root->right);
    	return;
    }
}

// Iterative preorder 

void preorder_I(Node<int>* root){
    if(root == NULL){
    	return;
    }else{
       stack<Node<int>*> s;
       s.push(root);
       while(!s.empty()){
           Node<int>* temp = s.top();
           s.pop();
           cout<<temp->data<<",";
           if(temp->right){
              s.push(temp->right);
           }if(temp->left){
              s.push(temp->left);
           }
       }
    }
   return;
}

void preorder_R(Node<int>* root){
	if(root == NULL){
		return;
	}else{
		cout<<root->data<<",";
		preorder_R(root->left);
		preorder_R(root->right);
	}
	return;
}

// Inorder Iterative

void Inorder_I(Node<int>* root){
    if(root == NULL){
    	return;
    }else{
    	stack<Node<int>*> s;
    	while(true){
    		if(root!=NULL){
    			s.push(root);
    			root = root->left;
    		}else{
    			if(s.empty()){
    				break;
    			}
    			root = s.top();
    			s.pop();
    			cout<<root->data<<",";
    			root = root->right;
    		}
    	}
    }
    return;
}

void Inorder_R(Node<int>* root){
	if(root==NULL){
		return;
	}else{
		Inorder_R(root->left);
		cout<<root->data<<",";
		Inorder_R(root->right);
	}
	return;
}

// Postorder Iterative

void Postorder_I(Node<int>* root){
	stack<Node<int>*> s;
	Node<int>* prev;
    while(true){
    	if(root != NULL){
    		s.push(root);
    		root = root->left;
    	}else{
    		if(s.empty()){
    		   break;
    		}
    		root = s.top();
    		if(root->right == NULL && root->left == NULL){
    			cout<<root->data<<",";
    			prev = root;
    		    s.pop();
    		    root = s.top();
    		}
    		if(root->right != prev && root->right!=NULL){
               root = root->right;
    		}else{
                cout<<root->data<<",";
                s.pop();
                prev = root;
                root = NULL;
    		}
    	}
    }
    return;
}

void Postorder_R(Node<int>* root){
	if(root == NULL){
		return;
	}else{
		Postorder_R(root->left);
		Postorder_R(root->right);
		cout<<root->data<<",";
	}
	return;
}

// level order traversal

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


void PrintZigZag(Node<int>* root){
	int flag = 1;
     stack<Node<int>*> s1,s2;
     s1.push(root);
     while(!s1.empty()){
         root = s1.top();
         s1.pop();
         cout<<root->data<<",";
         if(flag == 1){
         	if(root->left){
         		s2.push(root->left);
         	}
         	if(root->right){
         		s2.push(root->right);
         	}
         }else{
         	if(root->right){
         		s2.push(root->right);
         	}
         	if(root->left){
         		s2.push(root->left);
         	}
         }
         if(s1.empty()){
         	if(flag == 0){
         		flag = 1;
         	}else flag = 0;
            
            s1.swap(s2);     // using stl function swap 
         }
     }
     cout<<endl;
     return;
}

int DepthOfNode(Node<int>* root,int x){
	if(root == NULL){
		return -1;
	}else if(root->data == x){
		return 0;
	}else{
        int leftside = DepthOfNode(root->left,x);
        int rightside = DepthOfNode(root->right,x);
        if(leftside>=0){
        	return 1+leftside;
        }else if(rightside>=0){
        	return 1+rightside;
        }else{
        	return -1;
        }
	}
}

//******************************************* iterative diameter
//******************************************* swap two node


// max element
// for iterative approach do like preorder or levelorder treversal

int maxele_R(Node<int>* root){
	if(root == NULL){
		return INT_MIN;
	}else{
		return max(root->data,max(maxele_R(root->left),maxele_R(root->right)));
	}
}


int maxele_I(Node<int>* root){
    if(root == NULL){
    	return INT_MIN;
    }else{
    int max = INT_MIN;	
    Node<int>* temp = NULL;
    queue<Node<int>*> Q;
    Q.push(root);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(temp->data > max){
        	max = temp->data;
        }
        if(temp->left!=NULL){
        	Q.push(temp->left);
        }
        if(temp->right!=NULL){
        	Q.push(temp->right);
        }
    }
    return max;
    }
}

// search ele

bool SearchEle_R(Node<int>* root,int x){
	if(root == NULL){
		return false;
	}else if(root->data == x){
		return true;
	}else{
		bool leftside = SearchEle_R(root->left,x);
		bool rightside = SearchEle_R(root->right,x);
		if(leftside){
			return leftside;
		}else if(rightside){
			return rightside; 
		}else return false;
	}
}

void deleteTree(Node<int>* root){
	if(root == NULL){
		return;
	}else{
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
		return;
	}
}

//**************Print all Root to leaves path*****************//

void printarray(int a[],int l){
	for(int i=0;i<l;i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
	return;
}

void PrintPaths(Node<int>* root,int path[],int pathlen){
	if(root == NULL){
		return;
	}
    path[pathlen] = root->data;
    pathlen++;
    if(root->left == NULL && root->right == NULL){
          printarray(path,pathlen);
          return;
    } else{
    	PrintPaths(root->left,path,pathlen);
    	PrintPaths(root->right,path,pathlen);
    	return;
    }
}

// tree to its mirror image

Node<int>* Mirror_R(Node<int>* root){
    if(root == NULL){
    	return NULL;
    }else if(root->left == NULL && root->right ==NULL){
    	return root;
    }else{
    	Node<int>* leftside = Mirror_R(root->left);
    	Node<int>* rightside = Mirror_R(root->right);
    	root->left = rightside;
    	root->right = leftside;
    	return root;
    }
}


bool CheckMirror(Node<int>* root1 , Node<int>* root2){
	if(root1 == NULL && root2 == NULL){
		return true;
	}else if(root1 == NULL || root2 == NULL){
		return false;
	}else if(root1->data != root2->data){
        return false;
	}else{
		return(CheckMirror(root1->left,root2->right) && CheckMirror(root1->right,root2->left));
	}
}


Node<int>* lca(Node<int>* root,int x,int y){
	if(root == NULL){
		return root;
	}else if(root->data == x || root->data == y){
		return root;
	}else{
		Node<int>* leftside = lca(root->left,x,y);
		Node<int>* rightside = lca(root->right,x,y);
		if(leftside && rightside){
			return root;
		}else return (leftside? leftside : rightside);
	}
}

int AllAncesters(Node<int>* root,int x){  // Not getting ans
	if(root == NULL){
		return 0;
	}if(root->left->data == x || root->right->data == x || 
		     AllAncesters(root->left,x) || AllAncesters(root->right,x)){
		cout<<root->data<<",";
		return 1;
	}
	return 0;
}



void AllAnces(Node<int>* root,int x,int ans[],int index){ // correct
	if(root == NULL){
		return;
	}else{
	ans[index] = root->data;
	if(root->data == x){
		printarray(ans,index);
	    return;
	}
	index++;
    AllAnces(root->left,x,ans,index);
    AllAnces(root->right,x,ans,index);
    return;
    }

}

Node<int> * Construct_I_Pre(int in[],int pre[],int si_p,int end_p,int si_i, int end_i){
	if(si_p > end_p || si_i>end_i){
		return NULL;
	}
	else if(si_i == end_i){
        int data = pre[si_p];
        Node<int>* root = new Node<int>(data);
        return root;
	}else{
        int data = pre[si_p];
        Node<int>* root = new Node<int>(data);
        int i=si_i;
        int j=0;
        while(in[i]!=data){
        	i++;
        	j++;
        }
        root->left = Construct_I_Pre(in,pre,si_p+1,si_p+j,si_i,i-1);
        root->right = Construct_I_Pre(in,pre,si_p+j+1,end_p,i+1,end_i);
        return root;
	}

}

bool Is_BST(Node<int>* root){ // simple but wrong
	if(root == NULL){
		return true;
	}else if(root->left!=NULL && root->left->data > root->data){
		return false;
	}else if(root->right!=NULL && root->right->data < root->data){
		return false;
	}else{
		bool leftside = Is_BST(root->left);
		bool rightside = Is_BST(root->right);
		if(leftside && rightside){
			return true;
		}else{
			return false;
		}
	}
}

bool Is_BST2(Node<int>* root,int min,int max){ // root data should in between min and max
	if(root == NULL){
		return true;
	}else if(root->data < min || root->data > max){
		return false;
	}else{
		return(Is_BST2(root->left,min,root->data - 1) && 
			   Is_BST2(root->right,root->data + 1, max));
	}
}
// Another method can be Inorder traversal and storing the elements in array
// then check weather the array is sorted or not.

// for improving the time complexity we can check only the prev node data;



// **************** // Max bst Size

vector<int> maxbstinbt(Node<int>* root){
    vector<int> v;
    if(root == NULL){
        return v;
    }else{
        vector<int> vleft = maxbstinbt(root->left);
        vector<int>::iterator it = vleft.begin();
        while(it != vleft.end()){
            v.push_back(*it);
            it++;
        }
        v.push_back(root->data);
        vector<int> vright = maxbstinbt(root->right);
        it = vright.begin();
        while(it != vright.end()){
            v.push_back(*it);
            it++;
        }
        return v;
    }
}

int maxBST_In_BT(Node<int>* root){  // O(n) and O(n)
    vector<int> v = maxbstinbt(root);
    int max=1,i=0,j=1;
    int l = v.size();
    while(i<l-1){
        if(v.at(i) <= v.at(i+1)){
            i++;
            j++;
        }else{
            if(j>max){
                max = j;
            }
            i++;
            j=1;
        }
    }
    return (j>max? j : max);
}

//*****************//


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



// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1
// 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
//1 2 4 -1 -1 10 -1 -1 3 5 7 -1 -1 8 -1 -1 6 -1 9 -1 -1
// 25 18 19 -1 15 -1 -1 20  18 -1 -1 25 -1 -1 50 35 20 -1 25 -1 -1 40-1 -1 60 55 -1 -1 70 -1 -1
int main(){
    Node<int>* root = takeBTInput();
    levelorder(root);
    
    // cout<<"height : "<<height_I(root)<<endl;
    // cout<<"diameter : "<<diameter(root)<<endl;
    // cout<<"max ele : "<<maxele_I(root)<<endl;

    // if(SearchEle_R(root,11)){
    // 	cout<<"found"<<endl;
    // }else{
    // 	cout<<"not found"<<endl;
    // }
    
    //deleteTree(root);

    // int path[10];
    // PrintPaths(root,path,0);

    // root = Mirror_R(root);
    // Node<int>* root2 = takeBTInput();
    // cout<<CheckMirror(root,root2)<<endl;
    
    // Node<int>* x = lca(root,2,5);
    // cout<<"lca : "<<x->data<<endl;

    // int a[10];
    // cout<<"all ancesters of 7 : ";
    // AllAnces(root,7,a,0);

    // PrintZigZag(root);
    // cout<<"depth of 7 : "<<DepthOfNode(root,7)<<endl;

    // int in[] = {4,2,10,1,7,5,8,3,6,9};
    // int pre[] = {1,2,4,10,3,5,7,8,6,9};
    // Node<int>* root = Construct_I_Pre(in,pre,0,9,0,9);
    // levelorder(root);

    //cout<<endl<<Is_BST2(root,INT_MIN,INT_MAX)<<endl;

    cout<<"max bst size : "<<maxBST_In_BT(root)<<endl;
    return 0;
}