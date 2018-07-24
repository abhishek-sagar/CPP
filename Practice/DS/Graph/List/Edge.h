#ifndef EDGE_H
#define EDGE_H
#include<vector>
using namespace std;

class Vertex;

class Edge{
public:
   Vertex* first;
   Vertex* second;
   
   Edge(Vertex* v,Vertex* u){
   	this->first = v;
   	this->second = u;
   }
};

class  Vertex{
public:
    vector<Edge*>* adjacents;
    int data; 

	Vertex(int data){
	   this->data = data;
       adjacents = new vector<Edge*>();
	}

	void addEdge(Edge* e){
		vector<Edge*>::iterator it = adjacents->begin();
        while(it!=adjacents->end()){
        	if(*it != e){
                it++;
        	}else{
        		return;
        	}
        }
		adjacents->push_back(e);
		return;
	}

	void removeEdge(Vertex* v){
        vector<Edge*>::iterator it = adjacents->begin();
        while(it!=adjacents->end()){
        	if((*it)->first == this && (*it)->second == v){
                 adjacents->erase(it);
                 return;
        	}else if((*it)->first == v && (*it)->second == this){
        		adjacents->erase(it);
        		return;
        	}else{
        		it++;
        	}
        }
        cout<<"there is no any edge of this type"<<endl;
        return;
	}

	bool isAdjacents(Vertex* v){
		vector<Edge*>::iterator it = adjacents->begin();
        while(it!=adjacents->end()){
        	if((*it)->first == this && (*it)->second == v){
                 return true;
        	}else if((*it)->first == v && (*it)->second == this){
        		return true;
        	}else{
        		it++;
        	}
        }
        return false;
	}

	vector<Vertex*>* getAdjacents(){
		vector<Vertex*>* v = new vector<Vertex*>();
		vector<Edge*>::iterator it = adjacents->begin();
		while(it!=adjacents->end()){
			if((*it)->first == this){
				v->push_back((*it)->second);
			}else{
				v->push_back((*it)->first);
			}
			it++;
		}
		return v;
	}

	void print(){
		cout<<this->data<<" : ";
		vector<Edge*>::iterator it = adjacents->begin();
		while(it!=adjacents->end()){
			if((*it)->first == this){
				cout<<(*it)->second->data<<",";
			}else{
				cout<<(*it)->first->data<<",";
			}
			it++;
		}
		cout<<endl;
		return;
	}

	~ Vertex(){
		delete adjacents;
	}
	
};

#endif