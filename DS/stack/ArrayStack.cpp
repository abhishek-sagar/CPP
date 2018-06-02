#include<iostream>
using namespace std;

class Stack{
	int* a;
	int capacity;
	int top = -1;
public:
	Stack(int size){
		a = new int[size];
		capacity = size;
	}
    void push(int data){
    	if(top+1 == capacity){
            int * b = new int[2*capacity];
            for(int i=0;i<=top;i++){
            	b[i] = a[i];
            }
            int * temp = a;
            a = b;
            delete [] temp;
            capacity = 2*capacity;
            top++;
            a[top] = data;
    	}else{
    	    top++;
            a[top] = data;
        } 
    }

    void pop(){
    	if(top == -1){
    		cout<<"stack is empty cannot pop"<<endl;
            return;
    	}
    	cout<<"pop : "<<a[top]<<endl<<endl;
    	top--;
    }

    void PrintS(){
        for(int i=top;i>=0;i--){
        	cout<<a[i]<<endl;
        }
        cout<<endl;
        return;
    }
};


int main(){
       Stack s(2);
       s.push(3);
       s.push(2);
       s.push(-6);
       s.push(5);
       s.push(8);
       s.push(4);
       s.PrintS();
       s.pop();
       s.PrintS();
       return 0;
}