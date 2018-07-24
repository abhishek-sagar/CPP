#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include<vector>
using namespace std;

class Graph{
public:
	vector<Vertex*>* vertices;

	Graph(){
		vertices = new vector<Vertex*>();
	}

	Vertex* getVertex(int data){
        vector<Vertex*>::iterator it = vertices->begin();
        while(it!=vertices->end()){
        	if((*it)->data == data){
        		return *it;
        	}else{
        		it++;
        	}
        }
        return NULL; 
	}

	void AddVertex(int data){
         Vertex* v = getVertex(data);
         if(v == NULL){
            Vertex* v = new Vertex(data);
            vertices->push_back(v);
            return;
         }else return;
	}

	void RemoveVertex(int data){
		Vertex* v = getVertex(data);
        if(v == NULL){
           return;
        }else{
        	vector<Vertex*>* adj = v->getAdjacents();
            vector<Vertex*>::iterator it = adj->begin();
            while(it != adj->end()){
                (*it)->removeEdge(v);
                it++;
            }
            delete adj;
            it = vertices->begin();
            while(it!=vertices->end()){
            	if(*it == v){
            		vertices->erase(it);
            		return;
            	}
            	it++;
            }
        }
	}

	void AddEdge(int d1,int d2){
		Vertex* v1 = getVertex(d1);
		Vertex* v2 = getVertex(d2);
		if(v1 == NULL || v2 == NULL){
			cout<<"either of the vertex is missing."<<endl;
            return;
		}else{
			Edge* e = new Edge(v1,v2);
			v1->addEdge(e);
			v2->addEdge(e);
			return;
		}
	}

	void RemoveEdge(int d1,int d2){
		Vertex* v1 = getVertex(d1);
		Vertex* v2 = getVertex(d2);
		if(v1 == NULL || v2 == NULL){
			cout<<"either of the vertex is missing."<<endl;
            return;
		}else{
			v1->removeEdge(v2);
			v2->removeEdge(v1);
			return;
		}
	}

	bool IsAdjacents(int d1,int d2){
        Vertex* v1 = getVertex(d1);
		Vertex* v2 = getVertex(d2);
		if(v1 == NULL || v2 == NULL){
			cout<<"either of the vertex is missing."<<endl;
            return false;
		}else{
			return v1->isAdjacents(v2);
		}
	}

    void Print(){
    	vector<Vertex*>::iterator it = vertices->begin();
    	while(it!=vertices->end()){
    		(*it)->print();
    		it++;
    	}
    	return;
    }

    ~Graph(){
    	delete vertices;
    }
};

#endif