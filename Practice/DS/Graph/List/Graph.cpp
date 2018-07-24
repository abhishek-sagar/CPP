#include<iostream>
#include "Graph.h"
using namespace std;

int main(){
	Graph g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddVertex(4);
	g.AddVertex(5);

	g.AddEdge(1,2);
	g.AddEdge(1,3);
	g.AddEdge(2,3);
	g.AddEdge(2,4);
	g.AddEdge(3,5);
	g.AddEdge(4,5);

    g.Print();
    g.RemoveEdge(4,5);
    cout<<endl;
    g.RemoveVertex(1);
	g.Print();

	return 0;
}