#include<iostream>
#include<vector>
#include<algorithm>
#include "MinHeapNode.h"
#include "MinHeap.h"
#include "Job.h"
#include<queue>
#include<math.h>
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


// 9. Job sequencing Prob  O(n^2)

static bool compare2(Job j1,Job j2){
	return (j1.profit > j2.profit);
}

void JobSequencing(char id[],int deadline[],int profit[],int n){ //O(n^2)
	vector<Job>* v = new vector<Job>();
	for(int i=0;i<n;i++){
		Job j(id[i],deadline[i],profit[i]);
		v->push_back(j);
	}
    sort(v->begin(),v->end(),compare2);
    char bookedslot[n];
    for(int i=0;i<n;i++){
       bookedslot[i] = '$';
    }

    for(int i=0;i<n;i++){
        Job j = v->at(i);
        int deadline = j.deadline;
        if(bookedslot[deadline-1] == '$'){ // if deadline is 4 then it should at 3rd index.
            bookedslot[deadline-1] = j.id;
        }else{
        	for(int k=deadline-1;k>=0;k--){
        		if(bookedslot[k] == '$'){
                    bookedslot[k] = j.id;
                }
        	}
        }
    }

    for(int i=0;i<n;i++){
    	if(bookedslot[i] != '$'){
    		cout<<bookedslot[i]<<",";
    	}
    }
    cout<<endl;
    return;
}


// 10. rupee exchange or Minimum no. of coins or chhutte karwana

void MinimumCoin(int n){ //simple
	vector<int> v;
	int arr[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};
	while(n != 0){
		int i=0;
		while(i<9){
			if(arr[i]<=n){
				i++;
			}else break;
		}
        i--;
        n = n-arr[i];
        v.push_back(arr[i]);
	}
	for(int i=0;i<v.size();i++){
		cout<<v.at(i)<<",";
	}
	cout<<endl;
	return;
}

// 11. K centers problem
/* apply floyd warshall algo and caculate the path from each vertex to other vertices
   make a vector of pair, each pair having vertex name and total sum to other vertices
   sort this vector of pairs acco. to sum,select the first k cities. this is the algorithm.   
*/


// 12. Minimum no. of platforms required for rail/bus station O(nlogn)

   /* Best solution is merge the arrival and departure array
      sort the array then count++ until its arrival and count-- whenever
      a departure comes and store the max count for the result of
      max no. of platforms required at rail/bus station. 
   */


// 13. connects n ropes with minimum cost // simple algo

int MinimumCost(int ropes[],int n){   // O(nlogn)
    priority_queue<int, vector<int>, greater<int> > q; // create min priority_queue
    for(int i=0;i<n;i++){
    	q.push(ropes[i]);
    }
    int cost = 0;
    while(q.size() != 1){
    	int first = q.top();
    	q.pop();
    	int second = q.top();
    	q.pop();
    	int connection = first+second;
        cost = cost + connection;
        q.push(connection);
    }
    return cost;
}

// 14. minimum no. of colors required to color the whole graph such that no two adj
//     vertices have same color. 
// 


// class Visited{
// public:
//   int index;
//   int color;

//   Visited(int i,int c){
//        this->index = i;
//        this->color = c;
//   }
// };

// void GC(vector<Visited>& vis,int i,int& totalcolorNum){
//   vector<int>* adj = vertices->at(i);
//   int DiffAdjColor = 0;   // it will count how many of ajs hav diff colors
//   map<int,int> adjcolors;     // it contains the assigned color and the index of vertex.
  
//   // here we are finding the total different colored vertices only
//   for(int j=0;j<adj->size();j++){
//         if(adj->at(j) != 0){
//             Visited v = vis.at(j);
//             if(v.index != -1){
//               map<int,int>::iterator it = adjcolors.find(v.color);
//               if(it == adjcolors.end()){
//                 DiffAdjColor++;
//                 adjcolors.insert(pair<int,int>(v.color,v.index));
//               }
//             }
//         }
//     }

//     // if the total diff adj color are equal to the total color used, so we introduce
//     // a new color, otherwise select any color from non adjacent colored vertices

//     if(DiffAdjColor == totalcolorNum){ // This is the main logic 
//       Visited v = vis.at(i); 
//       v.index = i;
//       v.color = totalcolorNum;
//       vis.at(i) = v;
//       totalcolorNum++;
//     }else{
//       for(int j=0;j<adj->size();j++){
//            if(adj->at(j) == 0){
//              Visited v = vis.at(j);
//              if(v.index != -1){
//               Visited u = vis.at(i);
//               u.index = i;
//               u.color = v.color;
//               vis.at(i) = u;
//              }
//            }
//       }
//     }
//     return;
// }

// void GraphColoring(){  // TimeComplexity is O(VE);
//     vector<Visited> vis;
//     for(int i=0;i<vertices->size();i++){
//       Visited v(-1,-1);
//       vis.push_back(v);
//     }
//     int totalcolorNum = 0;//it maintains total color, and also for assigning new color no.
    
//     for(int i=0;i<vertices->size();i++){ // O(V)
//       Visited v = vis.at(i);
//       if(v.index == -1){
//         GC(vis,i,totalcolorNum);   // O(E)
//       }
//     }

//     for(int i=0;i<vertices->size();i++){
//       Visited v = vis.at(i);
//       cout<<"index : "<<v.index<<", color : "<<v.color<<endl;
//     }
// }


// 15. Fractional knapsack Problem

bool compare3(pair<pair<int,int>,float> p1,pair<pair<int,int>,float> p2){
	return (p1.second > p2.second);
}

float knapsack(float weight[],float value[],int n,float w){  //O(nlogn)
	vector<pair<pair<float,float>,float>> v;
	for(int i=0;i<n;i++){
	   float ratio = value[i]/weight[i];
	   pair<float,float> p(value[i],weight[i]);
	   pair<pair<float,float>,float> P(p,ratio);
	   v.push_back(P);
	}
    sort(v.begin(),v.end(),compare3);

    int pos = 0;
    float totalvalue = 0;
    while(w != 0 && pos != v.size()){
       pair<pair<float,float>,float> P = v.at(pos);
       pos++;
       pair<float,float> p = P.first;
       float val = p.first;
       float wt = p.second;
       if(w-wt >= 0){
           w = w-wt;
           totalvalue = totalvalue + val;
       }else{
       	  float fraction = w/wt;
       	  totalvalue = totalvalue + fraction*val;
       	  break;
       }
    }
    return totalvalue;
}

// 16. Minimize Cash Flow among a given set of friends who have borrowed money from each other
// directed graph problem.

/* Algo : 
    1. make an array of net amount of each vertex(total credited - total debited);
    2. send this array to the recursive function 
    3. get the most debited index(db) and most credited index(cr)
    4. get min of of the most debited and most credited amount;
    5. let say debited is less so and for example it be 3500;
    6. amount[cr] -= 3500 & amount[debited] += 3500; so debited will become 0;
    7. again call the recursive function on this updated amount.  
*/

// int getMin(int x,int y){
// 	return(x<y ? x : y);
// }

// int getMaxI(int amount[]){
// 	int max_index = -1;
//     int max = -999999;
//     for(int i=0;i<vertices->size();i++){
//     	if(amount[i] > max){
//     		max = amount[i];
//     		max_index = i;
//     	}
//     }
//     return max_index;
// }

// int getMinI(int amount[]){
// 	int min_index = -1;
//     int min = 999999;
//     for(int i=0;i<vertices->size();i++){
//     	if(amount[i] < min){
//     		min = amount[i];
//     		min_index = i;
//     	}
//     }
//     return min_index;
// }

// void MinimizeCashFlowRec(int amount[]){
//      int min_index = getMinI(amount);
//      int max_index = getMaxI(amount);

//      if(amount[max_index] == 0 && amount[min_index] == 0){
//      	return;
//      }

//      int min = getMin(-amount[min_index],amount[max_index]);
//      amount[max_index] -= min;
//      amount[min_index] += min;

//      cout<<min_index<<" pays "<<min<<" to "<<max_index<<endl;

//      MinimizeCashFlowRec(amount);
// }

// void MinimizeCashFlow(){
// 	int amount[vertices->size()];
// 	for(int i=0;i<vertices->size();i++){
// 		int total_debit = 0;
// 		int total_credit = 0;
// 		for(int j=0;j<vertices->size();j++){
//            	total_debit += (vertices->at(i))->at(j);
// 		}
//         for(int j=0;j<vertices->size();j++){
//         	total_credit += (vertices->at(j))->at(i);
//         }
//         amount[i] = total_credit - total_debit;
// 	}
// 	MinimizeCashFlowRec(amount);
// 	return;
// }



// 18. three stack common sum problem

int getSum(vector<int> v){
	int sum = 0;
	for(int i=0;i<v.size();i++){
        sum += v.at(i);
	}
	return sum;
}

void ThreeStack(vector<int> v1,vector<int> v2,vector<int> v3){
	if(v1.size() == 0 || v2.size() == 0 || v3.size() == 0){
		cout<<"common sum : 0"<<endl;
		return;
	}else{
        int sum1 = getSum(v1);
        int sum2 = getSum(v2);
        int sum3 = getSum(v3);
        if(sum1 == sum2 && sum2 == sum3){
        	cout<<"commom sum : "<<sum1<<endl;
        	return;
        }else{
            int minsum = min(sum1,min(sum2,sum3));
            if(minsum == sum1){
            	if(sum2 > sum1){
            		v2.erase(v2.begin());
            	}
            	if(sum3 > sum1){
            		v3.erase(v3.begin());
            	}
            }else if(minsum == sum2){
            	if(sum1 > sum2){
            		v1.erase(v1.begin());
            	}
            	if(sum3 > sum2){
            		v3.erase(v3.begin());
            	}
            }else if(minsum == sum3){
            	if(sum1 > sum3){
            		v1.erase(v1.begin());
            	}
            	if(sum2 > sum3){
            		v2.erase(v2.begin());
            	}
            }
            ThreeStack(v1,v2,v3);
        }
	}
}

int main(){
    // int start[] = {1, 3, 0, 5, 8, 5};
    // int end[] = {2, 4, 6, 7, 9, 9};
    // ActivitySelc(start,end,6);

    // char c[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    // int fr[] = { 5, 9, 12, 13, 16, 45 };
    // MinHeapNode* root = Huffman(c,fr,6);
    // int a[50];
    // PrintCode(root,a,0);

    // char c[] = {'a','b','c','d','e'};
    // int deadline[] = {2,1,2,1,3};
    // int profit[] = {100,19,27,25,15};
    // JobSequencing(c,deadline,profit,5);

    // MinimumCoin(70);
    // MinimumCoin(12527);

    // int ropes[] = {4, 3, 2, 6};
    // cout<<"min cost in connecting : "<<MinimumCost(ropes,4)<<endl;

    // float value[] = {280,100,120,120};
    // float weight[] = {40,10,20,24};
    // cout<<"total Value can get : "<<knapsack(weight,value,4,60.0)<<endl;;

    vector<int> v1,v2,v3;
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v2.push_back(4);
    v2.push_back(3);
    v2.push_back(2);
    v3.push_back(2);
    v3.push_back(5);
    v3.push_back(4);
    v3.push_back(1);
    ThreeStack(v1,v2,v3);
    return 0;
}