#ifndef HEAP_H
#define HEAP_H
#include<vector>
using namespace std;

class Heap{
    vector<int>* v;
public:
	Heap(){
		v = new vector<int>();
		v->push_back(-1);
	}

	int HeapSize(){
        return (v->size()-1);
	}

    bool empty(){
    	if(HeapSize() == 0){
    		return true;
    	}else return false;
    }

	int getMin(){
        if(!empty()){
        	return v->at(1);
        }
	}

	void insert(int data){
		v->push_back(data);
		int childI = HeapSize();
		while(childI>1){
            int parentI = childI/2;
            if(v->at(childI) < v->at(parentI)){
            	int temp = v->at(parentI);
            	v->at(parentI) = v->at(childI);
            	v->at(childI) = temp;
            	childI = parentI;
            }else{
            	break;
            }
		}
		return;
	}

	void RemoveMin(){
        if(!empty()){
           v->at(1) = v->at(HeapSize());
           v->pop_back();
           int i=1;
           while(i<=HeapSize()/2){
               int mini = i;
           	   int lc = 2*i;
           	   int rc = 2*i+1;
           	   if(lc<=HeapSize() && v->at(lc)<v->at(mini)){
           	   	   mini = lc;
           	   }
           	   if(rc<=HeapSize() && v->at(rc)<v->at(mini)){
           	   	   mini = rc;
           	   }

           	   if(mini == i){
           	   	return;
           	   }else{
           	   	 int temp = v->at(i);
           	   	 v->at(i) = v->at(mini);
           	   	 v->at(mini) = temp;
           	   	 i = mini;
           	   }
           }
        }
        return;
	}

	void heapify(){ // O(n);
	       int i=1;
           while(i<=HeapSize()/2){
               int mini = i;
           	   int lc = 2*i;
           	   int rc = 2*i+1;
           	   if(lc<=HeapSize() && v->at(lc)<v->at(mini)){
           	   	   mini = lc;
           	   }
           	   if(rc<=HeapSize() && v->at(rc)<v->at(mini)){
           	   	   mini = rc;
           	   }
           	   	int temp = v->at(i);
           	   	v->at(i) = v->at(mini);
           	   	v->at(mini) = temp;
           	   	i++;
           }
           return;	
	}

	void print(){
		for(int i=1;i<=HeapSize();i++){
			cout<<v->at(i)<<",";
		}
		cout<<endl;
		return;
	}
};

#endif