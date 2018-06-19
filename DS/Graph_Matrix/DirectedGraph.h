#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<climits>
#include<limits>
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
   	first->at(v) = 1;
   	return;
   }

   void removeEdge(int u,int v){
   	vector<int>* first = vertices->at(u);
   	first->at(v) = 0;
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

   void BFS(bool visited[],queue<int>& q){
    if(q.empty()){
      return;
    }
    int v = q.front();
    q.pop();
    cout<<v<<",";
    visited[v] = true;
    vector<int>* adj = vertices->at(v);
    for(int j=0;j<adj->size();j++){
      if(adj->at(j) == 1 && visited[j] == false){
         visited[j] = true;
         q.push(j);
      }
    }
    BFS(visited,q);
    return;
   }

   void BFSTraversal(){ // prob in case if a vertex is not an edge of any other vertex
   	 queue<int> q;
   	 bool visited[vertices->size()];
   	 for(int i=0;i<vertices->size();i++){
   	 	visited[i] = false;
   	 }
   	 for(int i=0;i<vertices->size();i++){
      if(visited[i] == false){
        q.push(i);
        BFS(visited,q);
      }
     }
     cout<<endl;
     return;
   }

   void Topo(bool visited[],stack<int>& s,int i){
    visited[i] = true;
    vector<int>* adj = vertices->at(i);
    for(int j=0;j<adj->size();j++){
      if(adj->at(j) == 1 && visited[j] == false){
        Topo(visited,s,j);
      }
    }
    s.push(i);
    return;
   }

   void TopologicalSort(){
     stack<int> s;
     bool visited[vertices->size()];
     for(int i=0;i<vertices->size();i++){
      visited[i] = false;
     }

     for(int i=0;i<vertices->size();i++){
       if(visited[i] == false){
         Topo(visited,s,i);
       }
     }
     while(!s.empty()){
      cout<<s.top()<<",";
      s.pop();
     }
     cout<<endl;
     return;
   }

   void path(bool visited[],queue<int>& q,map<int ,int>& m,int b){
    if(q.front() == b){
      return;
    }
    int v = q.front();
    q.pop();
    int cpl = m.at(v);
    vector<int>* adj = vertices->at(v);
    for(int i=0;i<adj->size();i++){
      if(adj->at(i) == 1 && visited[i] == false){
        m.insert(pair<int,int>(i,cpl + 1));
        q.push(i);
      }else if(adj->at(i) == 1 && visited[i] == true){
        int PathLenTillThis = m.at(i);
        if(cpl < PathLenTillThis -1){
          m.at(i) = cpl+1;
          q.push(i);
        }
      }
    }
    path(visited,q,m,b);
    return;
   }

   void ShortestPath(int a,int b){  // prob if there is no path b/w 'a' nad 'b'
     if(a==b){
      cout<<"ShortestPath len b/w "<<a<<" and "<<b<<" is : 0"<<endl;
     }
     queue<int> q;
     map<int ,int> m;
     int cpl = 0; // currentpathlen
     bool visited[vertices->size()];
     for(int i=0;i<vertices->size();i++){
      visited[i] = false;
     }
     q.push(a);
     m.insert(pair<int,int>(a,0));
     path(visited,q,m,b);
     cout<<"ShortestPath len b/w "<<a<<" and "<<b<<" is : "<<m.at(b)<<endl;
     return;
   }

   
};

#endif