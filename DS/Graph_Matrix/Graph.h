#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<queue>
using namespace std;

class Graph{
vector<vector<int>*>* vertices; 
public:
   Graph(){
       vertices = new vector<vector<int>*>();
   }

   void addVertex(){
   	   vector<int>* v = new vector<int>();
   	   for(int i=0;i<vertices->size()+1;i++){
   	   	  v->push_back(0);
   	   }
   	   for(int i=0;i<vertices->size();i++){
          vector<int>* each = vertices->at(i);
          each->push_back(0);
   	   }
   	   vertices->push_back(v);
   }

   void removeVertex(int v){
   	  vector<int>* vec = vertices->at(v);
   	  for(int i=0;i<vertices->size();i++){
   	  	vector<int>* each = vertices->at(i);
   	  	each->erase(each->begin()+v);
   	  }
   	  vertices->erase(vertices->begin()+v);
   	  delete vec;
   }

   void addEdge(int u,int v){
   	vector<int>* first = vertices->at(u);
   	vector<int>* sec = vertices->at(v);
   	first->at(v) = 1;
   	sec->at(u) = 1;
   	return;
   }

   void removeEdge(int u,int v){
   	vector<int>* first = vertices->at(u);
   	vector<int>* sec = vertices->at(v);
   	first->at(v) = 0;
   	sec->at(u) = 0;
   	return;
   }

   bool adjacents(int u,int v){
   	vector<int>* first = vertices->at(u);
   	vector<int>* sec = vertices->at(v);
   	if(first->at(v) == 1){
   		return true;
   	}
   	return false;
   }

   void print(){
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

   void DFS(bool visited[],int i){
   	visited[i] = true;
   	vector<int>* v = vertices->at(i);
   	cout<<i<<",";
   	for(int j=0;j<v->size();j++){
   		if(v->at(j) == 1 && visited[j] == false){
           DFS(visited,j);
   		}
   	}
   	return;
   }

   void DFSTraversal(){
   	 bool* visited = new bool[vertices->size()];
   	 for(int i=0;i<vertices->size();i++){
   	 	visited[i] = false;
   	 }
   	 for(int i=0;i<vertices->size();i++){
   	 	if(visited[i] == false){
   	 		DFS(visited,i);
   	 	}
   	 }
   	 cout<<endl;
   	 delete visited;
   	 return;
   }

   void BFSTraversal(){
   	 queue<int> q;
   	 int x = 0;
   	 bool visited[vertices->size()];
   	 for(int i=0;i<vertices->size();i++){
   	 	visited[i] = false;
   	 }
   	 q.push(x);
   	 visited[0] = true;
   	 while(!q.empty()){
   	 	int i = q.front();
   	 	q.pop();
   	 	cout<<i<<",";
        vector<int>* v = vertices->at(i);
        for(int j=0;j<v->size();j++){
        	if(v->at(j) == 1 && visited[j] == false){
        		visited[j] = true;
        		q.push(j);
        	}
        } 
        if(q.empty()){
        	break;
        }
   	 }
   	 cout<<endl;
   	 return;
   }
};

#endif