#include<iostream>
#include "heap.h"
using namespace std;

int main(){
	Heap h;
	pair<int,int> p1(0,2);
	pair<int,int> p2(1,6);
	pair<int,int> p3(2,3);
	pair<int,int> p4(3,1);
	pair<int,int> p5(4,2);
	pair<int,int> p6(5,7);
    h.addElement(p1);
    h.addElement(p2);
    h.addElement(p3);
    h.addElement(p4);
    h.addElement(p5);
    h.addElement(p6);
    h.print();
    h.printmap();
    h.removeMin();
    h.print();
    h.printmap();
    return 0;
}