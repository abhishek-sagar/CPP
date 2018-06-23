#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Heap{
   vector<pair<int,int>>* v;
   map<int,int> m;
public:
   Heap(){
   	  v = new vector<pair<int,int>>();
   	  pair<int,int> p(-1,-1);
   	  v->push_back(p);
   }

   int Heap_size(){
   	return v->size()-1;
   }

   pair<int,int> getMin(){
   	return v->at(1);
   }

   void addElement(pair<int,int> p){
   	 v->push_back(p);
     m.insert(pair<int,int>(p.first,v->size()));
     heapify();
   }

   void removeMin(){
   	  v->at(1) = v->at(Heap_size());
      pair<int,int> x = v->at(1);
      m.at(x.first) = 1;
      v->pop_back();
      for(int i=1;i<=Heap_size()/2;i++){
           int minimumI = i;
           pair<int,int> minimumPair = v->at(minimumI);
           if(2*i <= Heap_size()){
           	   pair<int,int> leftchildPair = v->at(2*i);
               if(leftchildPair.second < minimumPair.second){
               	  minimumI = 2*i;
               }
           }
           minimumPair = v->at(minimumI);
           if((2*i)+1 <= Heap_size()){
           	   pair<int,int> rightchildPair = v->at(2*i+1);
           	   if(rightchildPair.second < minimumPair.second){
           	   	  minimumI = 2*i+1;
           	   } 
           }
           if(minimumI == i){
           	break;
           }else{
           	   pair<int,int> temp1 = v->at(i);
               pair<int,int> temp2 = v->at(minimumI); 
           	   v->at(i) = v->at(minimumI);
           	   v->at(minimumI) = temp1;
               m.at(temp1.first) = minimumI;
               m.at(temp2.first) = i;
           }
      }
      return;
   }

   void heapify(){
   	 for(int i=Heap_size()/2;i>0;i--){
           int minimumI = i;
           pair<int,int> minimumPair = v->at(minimumI);
           if(2*i <= Heap_size()){
           	   pair<int,int> leftchildPair = v->at(2*i);
               if(leftchildPair.second <= minimumPair.second){
               	  minimumI = 2*i;
               }
           }
           minimumPair = v->at(minimumI);
           if((2*i)+1 <= Heap_size()){
           	   pair<int,int> rightchildPair = v->at(2*i+1);
           	   if(rightchildPair.second <= minimumPair.second){
           	   	  minimumI = 2*i+1;
           	   } 
           }
           if(minimumI != i){
           	   pair<int,int> temp1 = v->at(i);
               pair<int,int> temp2 = v->at(minimumI); 
               v->at(i) = v->at(minimumI);
               v->at(minimumI) = temp1;
               m.at(temp1.first) = minimumI;
               m.at(temp2.first) = i;
           }
      }
      return;
   }

   void print(){
   	  for(int i=1;i<v->size();i++){
   	  	pair<int,int> p = v->at(i);
   	  	cout<<"("<<p.first<<","<<p.second<<")"<<",";
   	  }
   	  cout<<endl;
   	  return;
   }

   void printmap(){
      map<int,int>::iterator it = m.begin();
      while(it!=m.end()){
        cout<<"("<<it->first<<","<<it->second<<")"<<",";
        it++;
      }
      cout<<endl;
   }
};

#endif
