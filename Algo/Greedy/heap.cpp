#include<iostream>
#include "MinHeap.h"
#include "MinHeapNode.h"
using namespace std;

int main(){
    MinHeap h;
    for(int i=0;i<7;i++){
        MinHeapNode* node = new MinHeapNode(char(97+i),(i*17)%11);
        h.addElement(node);
    }
    h.print();
    cout<<"removed : "<<(h.removeMin())->c<<endl;
    cout<<"removed : "<<(h.removeMin())->c<<endl;
    h.print();
    return 0;
}