#include<iostream>
#include "Graph.h"
using namespace std;

int main(){
	Graph g;
	g.AddVertex();
	g.AddVertex();
	g.AddVertex();
	g.AddVertex();
	g.AddVertex();

    g.AddEdge(0,1,4);
    g.AddEdge(0,2,8);
    g.AddEdge(3,1,2);
    g.AddEdge(2,3,1);
    g.AddEdge(2,4,8);
    g.AddEdge(4,3,3);
    g.AddEdge(4,1,3);

    g.DFS(); 
    g.BFS(); 
    g.Dijkastra(2);
	return 0;
}