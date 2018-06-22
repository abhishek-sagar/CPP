#include<iostream>
#include "Graph.h"
using namespace std;

int main(){
	Graph g;
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();
    g.addEdge(0,1,4);
    g.addEdge(0,2,8);
    g.addEdge(1,2,2);
    g.addEdge(3,1,2);
    g.addEdge(2,3,1);
    g.addEdge(2,4,8);
    g.addEdge(4,3,3);

	// g.addVertex();
	// g.addVertex();
	// g.addVertex();
	// g.addVertex();
	// g.addVertex();
	// g.addVertex();
	// g.addVertex();
	// g.addVertex();
	// g.addEdge(0,1,1);
	// g.addEdge(2,1,1);
	// g.addEdge(2,3,1);
	// g.addEdge(3,4,1);
	// g.addEdge(4,5,1);
	// g.addEdge(4,7,1);
	// g.addEdge(4,6,1);
	// g.addEdge(6,5,1);
	// g.addEdge(6,7,1);
	g.print();
	//g.DFSTraversal();
	//g.BFSTraversal();
	//g.TopologicalSort();
	//g.ShortestPath(2,7);
	g.dijkastra(2);
	g.BellmanFord(2);
	g.PrimsAlgo(0);
	g.KruskalsAlgo();
	return 0;
}