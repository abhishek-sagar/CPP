#ifndef HASH_H
#define HASH_H

#include<iostream>
#include<list>
#include<string>
using namespace std;
template<typename T,typename V>

class Pair{
public:
    T s;
    V data;

    T first(){
    	return this->s;
    }

    V second(){
    	return data;
    }

    void updateSecond(V data){
    	this->data = data;
    	return;
    }
};

class Hash{
	int TableSize;
	list<Pair<string, int>>* Table;
public:

	Hash(int size){
		this->TableSize = size;
		Table = new list<Pair<string, int>>[TableSize];
	}

	void InsertItem(string s,int data){
       int key = HashFunction(s);
       Pair<string,int> P;
       P.s = s;
       P.data = data;
       Table[key].push_back(P);
	}

	int HashFunction(string s){ // return the key
        int l = s.length();
        int sum = 0;
        for(int i=0;i<l;i++){
        	sum = sum + int(s[i]);
        }
        return (sum%TableSize);
	}

	int Search(string s){
       int key = HashFunction(s);
       list<Pair<string, int>>::iterator it = Table[key].begin();
       while(it!=Table[key].end()){
       	if((it)->first() == s){
       		break;
       	}else{
       		it++;
       	}
       }
       if(it!=Table[key].end()){
       	 return (it)->second();
       }else return -1;
	}

	void DeleteKey(string s){
       int key = HashFunction(s);
       list<Pair<string, int>>::iterator it = Table[key].begin();
       while(it!=Table[key].end()){
       	if((it)->first() == s){
       		break;
       	}else{
       		it++;
       	}
       }
       if(it!=Table[key].end()){
       	 Table[key].erase(it);
       }
       return;
	}

	void update(string s,int val){
	   int key = HashFunction(s);
       list<Pair<string, int>>::iterator it = Table[key].begin();
       while(it!=Table[key].end()){
       	if((it)->first() == s){
       		break;
       	}else{
       		it++;
       	}
       }
       if(it!=Table[key].end()){
       	 (it)->updateSecond(val);
       	 cout<<"updated the value for key "<<s<<endl;
       }else{
       	 cout<<"value does't exist"<<endl;
       }
       return;
	}
};

#endif