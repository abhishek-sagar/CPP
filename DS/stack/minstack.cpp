#include<iostream>
#include<stack>
using namespace std;

class MinStack{
	stack<int> s;
	int minval;
public:
    
    bool Empty(){
    	return s.empty();
    }

    void Push(int x){
    	if(s.empty()){
    		s.push(x);
    		minval = x;
    	}else if(x<minval){
    		int val = 2*x-minval;
    		minval = x;
    		s.push(val);
    	}else s.push(x);
    	return;
    }

    void Pop(){
    	if(s.empty()){
    		return;
    	}
    	if(s.top() > minval){
    		s.pop();
    	}else{  // in this case,the minval is the actual value that is going to popped out
    		minval = 2*minval - s.top(); // finding the next minval ;
    		s.pop();
    	}
    }

    int getmin(){
    	if(!s.empty()){
    		return minval;
    	}else return 999999;
    }

    int Top(){
    	if(!s.empty()){
           if(s.top() > minval){
           	  return s.top();
           }else{
           	  return minval;
           }
    	}else return -999999;
    }

    void print(){
    	while(!s.empty()){
    		cout<<s.top()<<endl;
    		s.pop();
    	}
    }
};

int main(){
    MinStack s;
    s.Push(3);
    s.Push(5);
    s.Push(2);
    s.Push(1);
    s.Push(1);
    s.Push(-1);
    while(!s.Empty()){
    	cout<<"Top : "<<s.Top()<<" ,  min : "<<s.getmin()<<endl;
    	s.Pop();
    }
    return 0;
}