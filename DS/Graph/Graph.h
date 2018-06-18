#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<string.h>
#include "Vertex.h"
using namespace std;
 
class Graph{
	vector<Vertex*>* vertices;

	Vertex* getVertex(char* name){
		for(int i=0;i<totalverteces();i++){
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

	int totalverteces(){
		return vertices->size();
	}

	int totalEdges(){
		int count = 0;
		for(int i=0;i<vertices->size();i++){
            count = count + (vertices->at(i))->numEdges(); 
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
		if(v != NULL){
           vector<Vertex*>* adjecents = v->AllAdjecentVertex();
           for(int i=0;i<adjecents->size();i++){
           	 adjecents->at(i)->removeEdgeWith(v);
           }
           delete adjecents;
           vector<Vertex*>::iterator it = vertices->begin();
           while(it!=vertices->end()){
           	if((*it) == v){
           		vertices->erase(it);
           		break;
           	}
           	it++;
           }
           delete v;
           return;
		}else return;
	}

	void addEdge(char* first,char* second){
         Vertex* f = getVertex(first);
         Vertex* s = getVertex(second);
         if(f == NULL || s == NULL){
            cout<<"either of the vertex do not exist in graph";
         	return;
         }else{
            Edge* e = new Edge(f,s);
            f->addedge(e);
            s->addedge(e);
         }
         return;
	}

	void removeEdge(char* first,char* second){
        Vertex* f = getVertex(first);
        Vertex* s = getVertex(second);
        if(f == NULL || s == NULL){
            cout<<"both do not exist in graph";
         	return;
        }else{
        	f->removeEdgeWith(s);
        	s->removeEdgeWith(f);
        	return;
        }
	}

	bool AreAdjecents(char* first,char* second){
		Vertex* f = getVertex(first);
        Vertex* s = getVertex(second);
        if(f == NULL || s == NULL){
            cout<<"not adjecent"<<endl;
         	return false;
        }else{
        	return (f->isAdjecent(s));
        }
	}

	void PrintG(){
		for(int i=0;i<vertices->size();i++){
			(vertices->at(i))->print();
			cout<<endl;
		}
		return;
	}

	~Graph(){
		delete vertices;
	}
};

#endif