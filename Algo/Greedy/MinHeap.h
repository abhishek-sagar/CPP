#ifndef MINHEAP_H
#define MINHEAP_H
#include<iostream>
#include<vector>
#include "MinHeapNode.h"
using namespace std;

class MinHeap{
	vector<MinHeapNode*>* v;
public:
	MinHeap(){
		v = new vector<MinHeapNode*>();
	    MinHeapNode* temp = NULL;
	    v->push_back(temp);
	} 

	int Heap_size(){
		return v->size()-1;
	}
    
    void addElement(MinHeapNode* node){
        v->push_back(node);
        heapify();
    }

    MinHeapNode* removeMin(){
      MinHeapNode* out = v->at(1);
      v->at(1) = v->at(Heap_size());
      v->pop_back();
      for(int i=1;i<=Heap_size()/2;i++){
           int minimumI = i;
           MinHeapNode* mini = v->at(i);
           if(2*i <= Heap_size()){
           	   MinHeapNode* leftchild = v->at(2*i);
               if(leftchild->freq < mini->freq){
               	  minimumI = 2*i;
               }
           }
           mini = v->at(minimumI);
           if((2*i)+1 <= Heap_size()){
           	   MinHeapNode* rightchild = v->at(2*i+1);
           	   if(rightchild->freq < mini->freq){
           	   	  minimumI = 2*i+1;
           	   } 
           }
           if(minimumI == i){
           	break;
           }else{
           	   MinHeapNode* temp1 = v->at(i);
           	   v->at(i) = v->at(minimumI);
           	   v->at(minimumI) = temp1;
           }
      }
      return out;
    }

    void heapify(){
    	for(int i=Heap_size()/2; i>0 ;i--){
           int minimumI = i;
           MinHeapNode* mini = v->at(i);
           if(2*i <= Heap_size()){
           	   MinHeapNode* leftchild = v->at(2*i);
               if(leftchild->freq < mini->freq){
               	  minimumI = 2*i;
               }
           }
           mini = v->at(minimumI);
           if((2*i)+1 <= Heap_size()){
           	   MinHeapNode* rightchild = v->at(2*i+1);
           	   if(rightchild->freq < mini->freq){
           	   	  minimumI = 2*i+1;
           	   } 
           }
           if(minimumI != i){
           	   MinHeapNode* temp1 = v->at(i);
           	   v->at(i) = v->at(minimumI);
           	   v->at(minimumI) = temp1;
           }
      }
      return;
    }

    void print(){
    	for(int i=1;i<v->size();i++){
    		MinHeapNode* n = v->at(i);
    		cout<<n->c<<" -> "<<n->freq<<endl;
    	}
    	return;
    }

};

#endif