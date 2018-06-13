#ifndef PQ_H
#define PQ_H
#include<vector>
#include<iostream>
using namespace std;

// it is the implimentation of PQ using min heap array representation.

class PQ{
	vector<int>* v;
public:
	PQ(){
		v = new vector<int>();
		v->push_back(-1); 
	}
    
    ~PQ(){
    	delete v;
    }

	int Size(){
		return (v->size() - 1);
	}

	bool IsEmpty(){
		if(Size() == 0){
			return true;
		}else return false;
	}

	int min(){
		if(!IsEmpty()){
			return (v->at(1));
		}else return -1;
	}

	void PrintPQ(){
		if(!IsEmpty()){
		  int i=1;
		  int l = Size();
		  while(i<=l){
             cout<<(v->at(i))<<",";
             i++;
		  }
		  cout<<endl;
		}
		return;
	}

	void Insert(int element){ // O(logn)
		v->push_back(element);
        int childI = v->size()-1;
        int parentI = childI/2;
        while(childI != 1){
        	if(v->at(parentI) > v->at(childI)){
        		int temp = (*v)[childI];
        		(*v)[childI] = v->at(parentI);
        		v->at(parentI) = temp;
        		childI = parentI;
        		parentI = childI/2;
        	}else{
        		break;
        	}
        }
        return;
	}

	void removeMin(){ // O(logn)
        if(!IsEmpty()){
            v->at(1) = v->at(Size());
            v->pop_back();
            int parentI = 1;
            while(parentI <= Size()/2){
            	 int lchildI = 2*parentI;
                 int rchildI = lchildI+1;
                 if(rchildI != Size()+1){ // right child exist

                    if(v->at(lchildI) < v->at(rchildI)){
                 	    if(v->at(lchildI) < v->at(parentI)){
                           int temp = v->at(parentI);
                           v->at(parentI) = v->at(lchildI);
                           v->at(lchildI) = temp;
                           parentI = lchildI;
                 	    }else{
                 		   break;
                 	    }
                    }else{
                 	    if(v->at(rchildI) < v->at(parentI)){
                            int temp = v->at(parentI);
                            v->at(parentI) = v->at(rchildI);
                            v->at(rchildI) = temp;
                            parentI = rchildI;
                 	    }else{
                 		    break;
                 	    }
                    }

                 }else{    // right child does't exist

                 	if(v->at(lchildI) < v->at(parentI)){
                           int temp = v->at(parentI);
                           v->at(parentI) = v->at(lchildI);
                           v->at(lchildI) = temp;
                           parentI = lchildI;
                 	}else{
                 		   break;
                 	}

                 }
            }
        }else{
        	cout<<"removing from empty PQ."<<endl;
        }
        return;
	}

};

#endif