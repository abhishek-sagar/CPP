#ifndef VERTEX2_H
#define VERTEX2_H
#include<vector>
#include<string.h>
using namespace std;

class Vertex;

class Edge{
   public:
   	  Vertex* first;
   	  Vertex* second;

   	  Edge(Vertex* f, Vertex* s){
          this->first = f;
          this->second = s;
   	  }
};

class Vertex{
	vector<Edge*>* adjacent;
public:
	char* name;

	Vertex(char* name){
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		adjacent = new vector<Edge*>();
	}

	int totalEdge(){
        return adjacent->size();
	}

	void addEdge(Edge* e){
		adjacent->push_back(e);
		return;
	}

	void removeEdgeWith(Vertex* othervertex){
		for(int i=0;i<adjacent->size();i++){
			Edge* e = adjacent->at(i);
			if(e->first == othervertex || e->second == othervertex){
				adjacent->erase(adjacent->begin()+i);
				return;
			}
		}
		cout<<othervertex->name<<" vertex is not adjacent to "<<this->name<<endl;
		return;
	}

	bool isAdjacent(Vertex* othervertex){
		for(int i=0;i<adjacent->size();i++){
			Edge* e = adjacent->at(i);
			if(e->first == othervertex || e->second == othervertex){
				return true;
			}
		}
		return false;
	}

	vector<Vertex*>* getAllAdjacentVertex(){
        vector<Vertex*>* v = new vector<Vertex*>();
        for(int i=0;i<adjacent->size();i++){
        	Edge* e = adjacent->at(i);
        	if(e->first == this){
        		v->push_back(e->second);
        	}else{
        		v->push_back(e->first);
        	}
        }
        return v;
	}

	void PrintV(){
		cout<<this->name<<" : ";
		for(int i=0;i<adjacent->size();i++){
			Edge* e = adjacent->at(i);
			if(e->first == this){
				cout<<e->second->name<<",";
			}else{
				cout<<e->first->name<<",";
			}
		}
		return;
	}

	~Vertex(){
		delete adjacent;
		delete [] name;
	}

};


#endif