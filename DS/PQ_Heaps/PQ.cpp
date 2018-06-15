#include<iostream>
#include "PQ.h"
#include<vector>
using namespace std;

void HeapSort(int a[],int l){ // O(nlogn) & O(n) space
    PQ p;
    int i=0;
    while(i<l){   // O(n)
    	p.Insert(a[i]); // O(logn)
    	i++;
    }
    for(int i=0;(!p.IsEmpty());i++){
    	a[i] = p.min();
    	p.removeMin();
    }
    return;
} 

int main(){
	PQ p;
	p.Insert(2);
	p.Insert(5);
	p.Insert(1);
	p.Insert(7);
	p.Insert(4);
	p.Insert(3);
	p.Insert(9);
	p.Insert(6);
	p.PrintPQ();
	cout<<"min : "<<p.min()<<endl;
	// p.removeMin();
	// p.PrintPQ();
	// p.removeMin();
	// p.PrintPQ();

	// int a[] = {2,5,1,7,4,3,9,6};
	// HeapSort(a,8);
	// for(int i=0;i<8;i++){
	// 	cout<<a[i]<<",";
	// }
	// cout<<endl;

	return 0;
}