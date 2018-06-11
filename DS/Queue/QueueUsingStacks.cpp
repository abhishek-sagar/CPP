#include<iostream>
#include<stack>
using namespace std;

class Queue{
	stack<int> s1; 
	stack<int> s2;
public:
	void Enqueue(int data){
       s1.push(data);
       return;
	}

	void Dequeue(){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();  // dequeue

		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		return;
	}

	void printq(){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		while(!s2.empty()){
			cout<<s2.top()<<"->";
			s1.push(s2.top());
			s2.pop();
		}
		cout<<endl;
		return;
	}
};

int main(){
     Queue Q;
     for(int i=1;i<8;i++){
     	Q.EnqueueEff(i);
     }
     Q.printq();
     Q.Dequeue();
     Q.printq();
     return 0;
}