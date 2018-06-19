#include<iostream>
#include "DirectedGraph.h"
using namespace std;

int main(){
	Graph g;
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addEdge(0,1);
	g.addEdge(2,1);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(4,7);
	g.addEdge(4,6);
	g.addEdge(6,5);
	g.addEdge(6,7);
	g.print();
	g.DFSTraversal();
	g.BFSTraversal();
	g.TopologicalSort();
	g.ShortestPath(2,7);
	return 0;
}