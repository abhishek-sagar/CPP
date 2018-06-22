#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Edge{
public:
	int start;
	int end;
	int weight;
    
    Edge(){
    	this->start = 0;
		this->end = 0;
		this->weight = 0;
    }

	Edge(int start,int end,int weight){
		this->start = start;
		this->end = end;
		this->weight = weight;
	}
};

bool compare(Edge e1,Edge e2){
    return (e1.weight < e2.weight);
}

int main(){
    vector<Edge>* v = new vector<Edge>();
    for(int i=0;i<6;i++){
    	Edge e(i,i+1,(i*5)%7);
    	v->push_back(e);
    }
    sort(v->begin(),v->begin()+6,compare);
    for(int i=0;i<6;i++){
    	Edge e = v->at(i);
    	cout<<"("<<e.start<<","<<e.end<<","<<e.weight<<")"<<endl;
    }
    return 0;
}