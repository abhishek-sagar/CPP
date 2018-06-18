#ifndef VERTEX_H
#define VERTEX_H
#include<vector>
#include<string.h>
using namespace std;
class Vertex;

class Edge{
public:
   Vertex* first;
   Vertex* second;

   Edge(Vertex* first,Vertex* second){
        this->first = first;
        this->second = second;
   }
};

class Vertex{
   vector<Edge*>* adjecent;
public:
   char* name;
 
   Vertex(char* name){
      this->name = new char[strlen(name)+1];
      strcpy(this->name,name);
      adjecent = new vector<Edge*>();
   }

   int numEdges(){
   	  return adjecent->size();
   }
 
   void addedge(Edge* e){
   	 adjecent->push_back(e);
   	 return;
   }

   void removeEdgeWith(Vertex* othervertex){
   	for(int i =0;i<adjecent->size();i++){
   		Edge* e = adjecent->at(i);
   		if(e->first == othervertex || e->second == othervertex){
   			adjecent->erase(adjecent->begin()+i);
   			return;
   		}
   	}
   	cout<<"There is no any edge b/w "<<this->name<<" and "<<othervertex->name<<endl;
   	return;
   }

   bool isAdjecent(Vertex* othervertex){
   	 for(int i=0;i<adjecent->size();i++){
   	 	Edge* e = adjecent->at(i);
   	 	if(e->first == othervertex || e->second == othervertex){
   	 		return true;
   	 	}
   	 }
   	 return false;
   }

   vector<Vertex*>* AllAdjecentVertex(){
   	 vector<Vertex*>* v = new vector<Vertex*>();
   	 for(int i=0;i<adjecent->size();i++){
   	 	Edge* e = adjecent->at(i);
   	 	if(e->first == this){
   	 		v->push_back(e->second);
   	 	}else{
   	 		v->push_back(e->first);
   	 	}
   	 }
   	 return v;
   }

   void print(){
   	cout<<this->name<<" : ";
   	for(int i=0;i<adjecent->size();i++){
   		Edge* e = adjecent->at(i);
   		if(e->first == this){
   			cout<<e->second->name<<",";
   		}else{
   			cout<<e->first->name<<",";
   		} 
   	}
   	return;
   }

   ~Vertex() {
		delete adjecent;
		delete [] name;
	}
};

#endif