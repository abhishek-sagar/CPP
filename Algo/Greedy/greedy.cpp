#include<iostream>
#include<vector>
#include<algorithm>
#include "MinHeapNode.h"
#include "MinHeap.h"
using namespace std;

//********* Top 20 Greedy Algo Questions **********//

// 1. activity selection prob;

static bool compare(pair<int,int> p1,pair<int,int> p2){
	return (p1.second < p2.second);
}

void ActivitySelc(int startTime[],int finishTime[],int n){
     vector<pair<int,int>> v;
     for(int i=0;i<n;i++){
     	pair<int,int> p(startTime[i],finishTime[i]);
     	v.push_back(p);
     }
     sort(v.begin(),v.end(),compare);
     int prevend = -1;
     for(int i=0;i<n;i++){
     	pair<int,int> p = v.at(i);
        if(prevend <= p.first){
        	cout<<"{"<<p.first<<","<<p.second<<"}"<<",";
            prevend = p.second;
        }
     }
     cout<<endl;
     return;
}

 // 2. Kruskal's algo

// static bool compare1(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2){
// 	return (p1.second < p2.second);
// }

// int parentI(int i,int parent[]){
// 	if(parent[i] == i){
// 		return i;
// 	}else{
// 		return parentI(parent[i],parent);
// 	}
// }

// void KruskalAlgo(){
// 	vector<pair<pair<int,int>,int>>* edges = new vector<pair<pair<int,int>,int>>();
// 	for(int i=0;i<vertices->size();i++){
// 		vector<int>* adj = vertices->at(i);
// 		for(int j=0;j<adj->size();j++){
// 			if(adj->at(j) != 0){
// 				pair<int,int> p(i,j);
// 				pair<pair<int,int>,int> P(p,adj->at(j));
// 				edges->push_back(P);
// 			}
// 		}
// 	}
//     int parent[vertices->size()];
//     for(int i=0;i<vertices->size();i++){
//     	parent[i] = i;
//     }

//     sort(edges->begin(),edges->end(),compare1);
//     int count = 0;
//     int v=0;
//     while(v<vertices->size()-1){
//     	pair<pair<int,int>,int> P = edges->at(count);
//     	count++;
//     	pair<int,int> edge = P.first;
//     	int start = edge.first;
//     	int end = edge.second;
//     	int startParentI = parentI(start,parent);
//     	int endParentI = parentI(end,parent);
//     	if(startParentI != endParentI){
//     		cout<<start<<" -- "<<end<<", W : "<<P.second;
//     		parentI[end] = start;
//     		v++;
//     	}
//     }
//     return;
// }

//3. Huffman Algo

void printArr(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	cout<<endl;
	return;
}

void PrintCode(MinHeapNode* root,int a[],int si){
	if(root->left){
		a[si] = 0;
		PrintCode(root->left,a,si+1);
	}
	if(root->right){
		a[si] = 1;
		PrintCode(root->right,a,si+1);
	}
	if(root->left == NULL && root->right == NULL){
		cout<<"HuffMan Code for "<<root->c<<" is : ";
		printArr(a,si);
		return;
	}
}

MinHeapNode* Huffman(char c[],int fr[],int n){ // O(nlogn)
	MinHeap h;
	int i=0;
	for(i;i<n;i++){
		MinHeapNode* node = new MinHeapNode(c[i],fr[i]);
		h.addElement(node);
	}
    while(h.Heap_size() != 1){
        MinHeapNode* left = h.removeMin();
        MinHeapNode* right = h.removeMin();

        MinHeapNode* newNode = new MinHeapNode(char(97+i),left->freq+right->freq);
        i++;
        newNode->left = left;
        newNode->right = right;
        h.addElement(newNode);
    }
    return (h.removeMin());
}

// 4. Huffman coding Efficiently if the given freq[] is sorted with Complexity : O(n)
/* 
   1.In this case we maintain two queues q1,q2
   2.Enter all MinHeapNode type data (object having c,freq,left,right) to the q1.
   3.While(!q1.empty() && q2.size() != 1){
	  -> again extract two min nodes either both of them are from q1 or 1 from q1 and other
	     from q2 or both from q2 but condition is that both should be minimum of all.
      -> make new Node with random char but freq as some of the extrscted one's
         and Node->left = left & Node->right = right and push this new Node to 'q2' .
      -> repeat the process
   4.return the last Node left in q2
   5.Print the haffman code. 
   } 
  */



int main(){
    // int start[] = {1, 3, 0, 5, 8, 5};
    // int end[] = {2, 4, 6, 7, 9, 9};
    // ActivitySelc(start,end,6);

    char c[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int fr[] = { 5, 9, 12, 13, 16, 45 };
    MinHeapNode* root = Huffman(c,fr,6);
    int a[50];
    PrintCode(root,a,0);
    return 0;
}