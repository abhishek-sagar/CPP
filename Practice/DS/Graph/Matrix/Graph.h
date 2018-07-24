#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <math.h>
#include <climits>
#include <queue>
using namespace std;

class Graph{
   vector<vector<int>*>* vertices;
public:
   Graph(){
   	  vertices = new vector<vector<int>*>();
   }


   void AddVertex(){
   	    vector<int>* newVertex = new vector<int>();
   	    for(int i=0;i<vertices->size()+1;i++){
   	  	   newVertex->push_back(0);
   	    } 
   	    for(int i=0;i<vertices->size();i++){
   	  	   vector<int>* v = vertices->at(i);
   	  	   v->push_back(0);
   	    }
   	    vertices->push_back(newVertex);
        return;
   }

   void RemoveVertex(int data){
   	  for(int i=0;i<vertices->size();i++){
   	  	vector<int>* v = vertices->at(i);
   	  	v->erase(v->begin()+data);
   	  }
   	  vertices->erase(vertices->begin()+data);
      return;
   }

   void AddEdge(int d1,int d2,int w){
   	  (vertices->at(d1))->at(d2) = w;
   	  (vertices->at(d2))->at(d1) = w;
   	  return;
   }

   void RemoveEdge(int d1,int d2){
   	 	(vertices->at(d1))->at(d2) = 0;
   	    (vertices->at(d2))->at(d1) = 0;
   	    return;
   }

   bool IsAdjacents(int d1,int d2){
   	 	if((vertices->at(d1))->at(d2) == 1){
   	 		return true;
   	 	}
   	    else return false;
   }

   void Print(){
   	 for(int i=0;i<vertices->size();i++){
   		vector<int>* each = vertices->at(i);
   		cout<<i<<" : ";
   		for(int j=0;j<each->size();j++){
            cout<<each->at(j)<<",";
   		}
   		cout<<endl;
   	}
   	return;
   }

   void DFSUtil(bool visited[],int i){
   	  visited[i] = true;
      cout<<i<<",";
      vector<int>* v = vertices->at(i);
      for(int j=0;j<vertices->size();j++){
      	if(!visited[j] && v->at(j) != 0){
      		DFSUtil(visited,j);
      	}
      }
      return;
   }

   void DFS(){
   	 bool * visited = new bool[vertices->size()];
   	 for(int i=0;i<vertices->size();i++){
   	 	visited[i] = false;
   	 }
   	 for(int i=0;i<vertices->size();i++){
   	 	if(!visited[i]){
   	 		DFSUtil(visited,i);
   	 	}
   	 }
   	 cout<<endl;
   	 return;
   }

   void BFSUtil(bool visited[],queue<int>& q){
   	  if(q.empty()){
   	  	return;
   	  }
      int i = q.front();
      q.pop();
      cout<<i<<",";
      visited[i] = true;
      vector<int>* v = vertices->at(i);
      for(int j=0;j<v->size();j++){
      	if(!visited[j] && v->at(j) != 0){
      		visited[j] = true;
      		q.push(j);
      	}
      }
      BFSUtil(visited,q);
      return;
   }

   void BFS(){
   	 bool * visited = new bool[vertices->size()];
   	 for(int i=0;i<vertices->size();i++){
   	 	visited[i] = false;
   	 }
     queue<int> q;
   	 for(int i=0;i<vertices->size();i++){
   	 	if(!visited[i]){
   	 		q.push(i);
   	 		BFSUtil(visited,q);
   	 	}
   	 }
   	 cout<<endl;
   	 return;
   }

   int MinIndex(int dist[],bool vis[]){
       int minval=INT_MAX,minindex;
       for(int i=0;i<vertices->size();i++){
       	  if(!vis[i] && dist[i]<minval){
       	  	minval = dist[i];
       	  	minindex = i;
       	  }
       }
       return minindex;
   }

   void Dijkastra(int x){
   	  bool vis[vertices->size()];
   	  for(int i=0;i<vertices->size();i++){
         vis[i] = false;
   	  }
   	  int dist[vertices->size()];
   	  for(int i=0;i<vertices->size();i++){
   	  	dist[i] = INT_MAX;
   	  }
   	  dist[x] = 0;
   	  for(int i=0;i<vertices->size()-1;i++){
   	  	int index = MinIndex(dist,vis);
   	  	vis[index] = true;
   	  	vector<int>* v = vertices->at(index);
   	  	for(int j=0;j<v->size();j++){
   	  		if(dist[index] + v->at(j) < dist[j] && dist[index]!=INT_MAX &&
   	  		    !vis[j] && v->at(j)!= 0){
   	  			dist[j] = dist[index] + v->at(j);
   	  		}
   	  	}
   	  }
   	  for(int i=0;i<vertices->size();i++){
   	  	cout<<dist[i]<<",";
   	  }
   	  cout<<endl;
   	  return;
   }

   

};

#endif