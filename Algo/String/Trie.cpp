#include<iostream>
#include "TrieNode.h"
#include<map>
#include<string>
using namespace std;

class Trie{
public:
	Node* root = NULL;
	
	Trie(){
       root = new Node();
	}

	void Insert(string s){
       int l = s.length();
       Node* current = root;
       for(int i=0;i<l;i++){
       	  char c = s[i];
       	  if(current->children->find(c) != current->children->end()){
               current = current->children->at(c);
       	  }else{
               Node* newNode = new Node();
               current->children->insert(pair<char,Node*>(c,newNode));
               current = newNode;
       	  }
       }
       current->endofWord = true;
       return;
	}

	bool Search(string s){
		int l = s.length();
		Node* current = root;
		for(int i=0;i<l;i++){
			char c = s[i];
			if(current->children->find(c) != current->children->end()){
               current = current->children->at(c);
       	    }else{
               return false;
       	    }
		}
		return current->endofWord;
	}

	bool PrifixSearch(string s){
		int l = s.length();
		Node* current = root;
		for(int i=0;i<l;i++){
			char c = s[i];
			if(current->children->find(c) != current->children->end()){
               current = current->children->at(c);
       	    }else{
               return false;
       	    }
		}
		return true;
	}

    void Delete(string s){
       DeleteStr(root,s,0);
    }

    bool DeleteStr(Node* current, string s, int index){
    	if(index == s.length()){
            if(current->endofWord){
            	current->endofWord = false;
            	return (current->children->size() == 0);
            }else{
            	return false;
            }
    	}
    	if(current->children->find(s[index]) == current->children->end()){
           return false;
    	}
        bool DeleteOrNot = DeleteStr(current->children->at(s[index]),s,index+1);
        if(DeleteOrNot){
           	map<char,Node*>::iterator it = current->children->find(s[index]);
           	current->children->erase(it); 
           	if(current->endofWord || current->children->size() != 0){
           		return false;
           	}else{
           		return true;
           	}
        }
        return false;
    }

};


int main(){
	Trie T;
	T.Insert("car");
	T.Insert("card");
	T.Insert("abcd");
	T.Insert("abc");
	T.Insert("cdf");
	T.Insert("abgl");
	T.Insert("lmn");
	cout<<"lmn : "<<T.Search("lmn")<<endl;
	cout<<"ab : "<<T.Search("ab")<<endl;
	cout<<"lmnksjd : "<<T.Search("lmnksjd")<<endl;
	cout<<"car : "<<T.Search("car")<<endl;
	cout<<"abcd : "<<T.Search("abcd")<<endl;
	T.Delete("car");
    T.Delete("abcd");
    T.Delete("lmn");
    cout<<endl;
	cout<<"card : "<<T.Search("card")<<endl;
	cout<<"abcd : "<<T.Search("abcd")<<endl;
	cout<<"abc : "<<T.Search("abc")<<endl;
	cout<<"lmn : "<<T.Search("lmn")<<endl;	
	T.Insert("abcd");
    cout<<endl;
    cout<<"abcd : "<<T.Search("abcd")<<endl;
}