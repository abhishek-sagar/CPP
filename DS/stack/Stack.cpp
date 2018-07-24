#include<iostream>
#include "Node.h"
#include<string>
#include<math.h>
using namespace std;
template <typename T>

class Stack{
public:
	Node<T>* top = NULL;
	
	void push(T data){
		Node<T>* newNode = new Node<T>(data);
		if(this->top == NULL){
			this->top = newNode;
		}else{
			newNode->next = this->top;
			this->top = newNode;
		}
		return;
	}

	void pop(){
		if(top == NULL){
			return;
		}else{
		    Node<T>* temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
            return;
        } 
	}

	T Top(){
		if(top != NULL){
			return top->data;
		}
	}

	void PrintS(){
        Node<T>* temp = top;
        while(temp!=NULL){
        	cout<<temp->data<<endl;
        	temp = temp->next;
        }
        return;
	}

};

int priority(char x){
	if(x == '+' || x == '-'){
		return 1;
	}else if(x == '*' || x == '/'){
		return 2;
	}else if(x == '^'){
		return 3;
	}else{
		return 0;
	}
}

void InfixtoPostfix(string a,string &output){
	 int l = a.length();
     char out[l];
     Stack<char> s;
     int j=0;
     for(int i=0;i<l;i++){
        if(a[i] == '('){
        	s.push(a[i]);
        }else if(a[i] == ')'){
            while(s.top!=NULL && s.top->data != '('){
            	 if(s.top == NULL && s.top->data != '('){
            	 	// char y[15] = "Wrong Input";
            	 	// return y;
            	 }
                 if(s.top->data != '('){
                 	out[j] = s.Top();
                    j++;
                 	s.pop();
                 }
            }
            s.pop();
        }else if((a[i] >='a' && a[i]<='z') || (a[i]>='A' && a[i]<= 'Z')){
        	out[j] = a[i];
        	j++;
        }else{
        	while(s.top!=NULL && priority(s.Top()) >= priority(a[i])){
        		out[j] = s.Top();
        		j++;
        		s.pop();
        	}
        	s.push(a[i]);
        }
     }
     while(s.top!=NULL){
     	out[j] = s.Top();
     	j++;
     	s.pop();
     }
     out[j] = '\0';
     for(int i=0;i<=j;i++){
     	output[i] = out[i];
     }
     return;
}

void reverse(string & x){
	int l = x.length();
	Stack<char> s;
    for(int i=0;i<l;i++){
    	s.push(x[i]);
    }
    for(int i=0;s.top!=NULL;i++){
    	if(s.Top() == '('){
    		x[i] = ')';
    	}else if(s.Top() == ')'){
    		x[i] = '(';
    	}else{
    		x[i] = s.Top();
    	}
    	s.pop();
    }
    return;
}

void InfixtoPrefix(string s){
	reverse(s);
	string out = "(a-b/c)*(a/";
	InfixtoPostfix(s,out);
	reverse(out);
	cout<<out<<endl;
    return;
}

void StockSpan(int stock[],int span[],int n){
     Stack<int> s;
     span[0] = 1;
     s.push(0);
     for(int i=1;i<n;i++){
    	int x = stock[i];
        while(s.top != NULL && x >= stock[s.Top()]){
            s.pop();
        }
        span[i] = (s.top == NULL)? i+1 : (i-s.Top());
    	s.push(i);
     }
    return;
}

bool BalancedPara(string s){
	int l = s.length();
	Stack<char> st;
	for(int i=0;i<l;i++){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			st.push(s[i]);
		}else if(s[i] == ')'){
			if(st.Top() == '('){
				st.pop();
			}else{
				return false;
			}
		}else if(s[i] == ']'){
			if(st.Top() == '['){
				st.pop();
			}else{
				return false;
			}
		}else if(s[i] == '}'){
			if(st.Top() == '{'){
				st.pop();
			}else{
				return false;
			}
		}
	}
	if(st.top == NULL){
		return true;
	}else{
		return false;
	}
}

void EvaluatePostfix(string s){  // handle the case of 2 or more digit no.
	int l = s.length();
	Stack<int> st;
	for(int i=0;i<l;i++){ 
		int x = int(s[i]) - int('0');
		if(x >= 0 && x <= 9){
			st.push(x);
		}else if(s[i] == ' '){
			// do nothing; 
		}
		else{
			int a,b;
			if(st.top!=NULL){
				a = st.Top();
				st.pop();
				if(st.top!=NULL){
					b = st.Top();
					st.pop();
				}else{
					cout<<"vala wrong expression"<<endl;
					return;
				}
			}else{
				cout<<"ye wrong expression at : "<<i<<endl;
				return;
			}
			if(s[i] == '+'){
				st.push(b+a);
			}else if(s[i] == '-'){
                st.push(b-a);
			}else if(s[i] == '*'){
				st.push(b*a);
			}else if(s[i] == '/'){
				st.push(b/a);
			}else if(s[i] == '^'){
				int z = pow(b,a);
				st.push(z);
			}
		}
	}
	if(st.top!=NULL){
		cout<<"value : "<<st.Top()<<endl;
	}else{
		cout<<"ye vala wrong expression"<<endl;
	}
	return;
}

int Histogram(int hist[],int l){
	int max_area = -1;
	Stack<int> s;
	int i=0;
	while(i<l){
		if(s.top == NULL || hist[i] >= hist[s.Top()]){
			s.push(i);
			i++;
		}else{
			int x = s.Top();
			s.pop();
			int area = hist[x]*((s.top == NULL)? (i) : (i-1-s.Top()));
			if(area>max_area){
				max_area = area;
			}
		}
	}
	while(s.top!=NULL){
		int x = s.Top();
		s.pop();
		int area = hist[x]*((s.top == NULL)? (i) : (i-1-s.Top()));
		if(area>max_area){
			max_area = area;
		}
	}
	return max_area;
}

int main(){
       //string s = "(a-b/c)*(a/k-l)";
       // string out = "a+b*(c^d-e)^(f+g*";
       // InfixtoPostfix(s,out);
       // cout<<out<<endl;

       // InfixtoPrefix(s);

       // int stock[] = {10, 4, 5, 90, 120, 80};
       // int span[7];
       // StockSpan(stock,span,6);
       // for(int i=0;i<6;i++){
       // 	cout<<span[i]<<",";
       // }
       // cout<<endl;
       
       // string s = "{()}[]";
       // if(BalancedPara(s)){
       // 	cout<<"Balanced"<<endl;
       // }else{
       // 	cout<<"Unbalanced"<<endl;
       // }

       // string s = "2 2 + 2 / 5 * 7 +";
       // EvaluatePostfix(s);

	   int hist[] = {1,2,3,4,5,3,3,2};
	   cout<<"Largest rectangle area : "<<Histogram(hist,8)<<endl;
       return 0;
}