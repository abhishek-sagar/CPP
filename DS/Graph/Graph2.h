#ifndef GRAPH2_H
#define GRAPH2_H
#include<vector>
#include<queue>
#include "Vertex2.h"
#include<string.h>
#include<set>
#include<stack>
#include<map>
using namespace std;

class Graph{
	vector<Vertex*>* vertices;

	Vertex* getVertex(char* name){
		for(int i=0;i<vertices->size();i++){
			Vertex* v = vertices->at(i);
			if(strcmp(v->name,name) == 0){
				return v;
			}
		}
		return NULL;
	}
public:
	Graph(){
        vertices = new vector<Vertex*>();
	}

    int totalVertices(){
        return vertices->size();
    }

    int getVertexIndex(Vertex* v){
        for(int i=0;i<vertices->size();i++){
            if(vertices->at(i) == v){
                return i;
                break;
            }
        }
    }

    int totalEdges(){
        int count = 0;
        for(int i=0;i<vertices->size();i++){
           Vertex* v = vertices->at(i);
           count = count + v->totalEdge();
        }
        return count;
    }

    void addVertex(char* name){
       if(getVertex(name) == NULL){
            Vertex* v = new Vertex(name);
            vertices->push_back(v);
       }
       return;
    }

    void removeVertex(char* name){
       Vertex* v = getVertex(name);
       if(v == NULL){
          cout<<"Vertex not exist in Graph"<<endl;
          return;
       }else{
         vector<Vertex*>* adjacents = v->getAllAdjacentVertex();
         for(int i=0;i<adjacents->size();i++){
            (adjacents->at(i))->removeEdgeWith(v);
         }
         delete adjacents;
         vector<Vertex*>::iterator it = vertices->begin();
         while(it != vertices->end()){
            if((*it) == v){
                vertices->erase(it);
                break;
            }
            it++;
         } 
         delete v;
         return;
       }
    }

    void addEdge(char* name1, char* name2){
        Vertex* v = getVertex(name1);
        Vertex* u = getVertex(name2);

        if(v == NULL || u == NULL){
            cout<<"vertices not exist in graph"<<endl;
        	return;
        }else{
        	Edge* e = new Edge(v,u);
        	v->addEdge(e);
        	u->addEdge(e);
        	return;
        }
    }

    void removeEdge(char* name1,char* name2){
        Vertex* v = getVertex(name1);
        Vertex* u = getVertex(name2);
        if(v == NULL || u == NULL){
            cout<<"vertices not exist in graph"<<endl;
            return;
        }else{
            v->removeEdgeWith(u);
            u->removeEdgeWith(v);
        }
    }

    bool AreAdjecents(char* a,char* b){
        Vertex* v = getVertex(a);
        Vertex* u = getVertex(b);
        if(v == NULL || u == NULL){
            cout<<"vertices not exist in graph"<<endl;
            return false;
        }else{
            return v->isAdjacent(u);
        }
    }

    void PrintG(){
        for(int i=0;i<totalVertices();i++){
            (vertices->at(i))->PrintV();
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    void DFS2(set<Vertex*>& visited,Vertex* v){
         visited.insert(v);
         cout<<v->name<<",";
         set<Vertex*>::iterator it;
         vector<Vertex*>* adjacents = v->getAllAdjacentVertex();
         for(int i=0;i<adjacents->size();i++){
            it = visited.find(adjacents->at(i));
            if(it == visited.end()){
                DFS2(visited,adjacents->at(i));
            }
         }
         delete adjacents;
         return;
    }

    void DFSTraversal2(){
        set<Vertex*> visited;
        set<Vertex*>::iterator it;
        for(int i=0;i<totalVertices();i++){
            it = visited.find(vertices->at(i));
            if(it == visited.end()){
                DFS2(visited,vertices->at(i));
            }
        }
        cout<<endl;
        return;
    }

    void DFS(bool visited[],int u){
         visited[u] = true;
         Vertex* v = vertices->at(u);
         cout<<v->name<<",";
         vector<Vertex*>* adjacents = v->getAllAdjacentVertex();
         for(int i=0;i<adjacents->size();i++){
            int index = getVertexIndex(adjacents->at(i));
            if(!visited[index]){
                DFS(visited,index);
            }
         }
         delete adjacents;
         return;
    }

    void DFSTraversal(){
        bool* visited = new bool[totalVertices()];
        for(int i=0;i<totalVertices();i++){
            visited[i] = false;
        }
        for(int i=0;i<totalVertices();i++){
            if(!visited[i]){
                DFS(visited,i);
            }
        }
        cout<<endl;
        return;
    }

    void BFSTraversal(){
        // bool* visited = new bool[totalVertices()];
        // for(int i=0;i<totalVertices();i++){
        //     visited[i] = false;
        // }
        set<Vertex*> visited;
        queue<Vertex*> q;
        q.push(vertices->at(0));
        visited.insert(vertices->at(0));
        while(!q.empty()){
            Vertex* v = q.front();
            cout<<v->name<<",";
            q.pop();
            vector<Vertex*>* adjacents = v->getAllAdjacentVertex();
            for(int i=0;i<adjacents->size();i++){
                set<Vertex*>::iterator it = visited.find(adjacents->at(i));
                if(it == visited.end()){
                    visited.insert(adjacents->at(i));
                    q.push(adjacents->at(i));
                }
            }
            delete adjacents;
            if(q.empty()){
                break;
            }
        }
        cout<<endl;
        return;
    }

    int ShortestPath(char* name1,char* name2){ // for unweighted graph
      Vertex* v1= getVertex(name1);
      Vertex* v2 = getVertex(name2);
      if(v1 == NULL || v2 == NULL){
        return -1;
      }
      map<Vertex*,int> visited; // visited vertex and distance from start;
      queue<Vertex*> q; // maintaining the adjacent vertex;
      q.push(v1);
      int currentPathlen = 0;
      visited.insert(pair<Vertex*,int>(v1,0));
      while(!q.empty()){
        Vertex* v = q.front();
        q.pop();
        if(v!=v2){  // if v == v2 then do nothing for that vertex;
        map<Vertex*,int>::iterator it2 = visited.find(v);  // finding the pop out vertex
        currentPathlen = it2->second;  // and set current path length to its dist from start.
        vector<Vertex*>* adjacents = v->getAllAdjacentVertex(); // get all adja. to that vector
        for(int i=0;i<adjacents->size();i++){
           map<Vertex*,int>::iterator it = visited.find(adjacents->at(i));
           if(it == visited.end()){  // if not visited so visit it and store.
            visited.insert(pair<Vertex*,int>(adjacents->at(i),currentPathlen + 1));
            q.push(adjacents->at(i)); // push into the queue;
           }else{ // if the vertex is visited already then check that the path is optimal.
            if(currentPathlen < it->second-1){  // if currentpathlen is less than the visited
              visited.insert(pair<Vertex*,int>(adjacents->at(i),currentPathlen + 1));
              q.push(adjacents->at(i));  
            }
           }
        }
        delete adjacents;
        }
        if(q.empty()){  //when queue becomes empty then check dist value at visited map for v2 
          map<Vertex*,int>::iterator it = visited.find(v2);
          currentPathlen = it->second;
          break;
        } 
      }
      return currentPathlen;
    }


	~Graph(){
		delete vertices;
	}
	
};

#endif