#include<iostream>
#include "Graph2.h"
#include<vector>
using namespace std;

int main(){
	Graph g;
	char a[] = "A";
	char b[] = "B";
	char c[] = "C";
	char d[] = "D";
	char e[] = "E";
	char f[] = "F";
	// char h[] = "H";
	// char i[] = "I";
	g.addVertex(a);
	g.addVertex(b);
	g.addVertex(c);
	g.addVertex(d);
	g.addVertex(e);
	g.addVertex(f);
	// g.addVertex(i);
	// g.addVertex(h);
    g.addEdge(a, b);
	g.addEdge(a, c);
	g.addEdge(b, c);
	g.addEdge(b, d);
	g.addEdge(b, e);	
	g.addEdge(c, e);
	g.addEdge(e, d);
	g.addEdge(e, f);
	g.addEdge(f, d);
	g.PrintG();
	g.BFSTraversal();
    //g.TopologicalSort();
    cout<<g.ShortestPath(a,f)<<endl;
    cout<<"total vertex : "<<g.totalVertices()<<", total Edges : "<<g.totalEdges()<<endl;
	return 0;
}