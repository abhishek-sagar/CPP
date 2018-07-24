#include<iostream>
#include "DirectedGraph.h"
using namespace std;

int main(){
	Graph g;
	g.addVertex();
	g.addVertex();
	g.addVertex();
	g.addVertex();

    g.addEdge(0,1,1);
    g.addEdge(0,2,15);
    g.addEdge(0,3,6);
    g.addEdge(1,0,2);
    g.addEdge(1,2,7);
    g.addEdge(1,3,3);
    g.addEdge(2,0,9);
    g.addEdge(2,1,6);
    g.addEdge(2,3,12);
    g.addEdge(3,0,10);
    g.addEdge(3,1,4);
    g.addEdge(3,2,8);
    
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

	// g.dijkastra(2);
	// g.BellmanFord(2);
	// g.PrimsAlgo(0);
	// g.KruskalAlgo();
	
	//g.GraphColoring();

	//g.MinimizeCashFlow(); -> directed graph problem

	int dp[1<<4][4];
	for(int i=0;i<(1<<4);i++){
		for(int j=0;j<4;j++){
			dp[i][j] = -1;
		}
	}

	int VISITED_ALL = (1<<4)-1;
	//for(int i=0;i<4;i++){
	  cout<<"Minimum Hamiltonian cycle OR TSP : "<<g.TSP(dp,1,0,VISITED_ALL,4,0)<<endl;
    //}
	for(int i=0;i<(1<<4);i++){
		for(int j=0;j<4;j++){
			cout<<dp[i][j]<<",";
		}
		cout<<endl;
	}
	return 0;
}