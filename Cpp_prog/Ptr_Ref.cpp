#include<iostream>
using namespace std;

void CallByValue(int x){ // send a copy value not change.
	x++;
	return;
}

void CallByPtr(int *x){ // value will change but it's copy of new pointer to same var.
	(*x)++;                    // not the orignal pointer
	return;
}

void CallByRef(int &x){ // value will change.
	(x)++;
	return;
}

// After this also checkout the lec-10 output question;
// 7th,8th and 9th questions are good.

int main(){
   int a = 10;
   int &b = a;  //****************** by this 'a' variable can also be called by 'b';
   cout<<a<<endl;
   int * ptr = &a;
   CallByValue(a);
   cout<<"Call by val : "<<a<<endl;
   CallByPtr(ptr);
   cout<<"Call by ptr : "<<a<<endl;
   CallByRef(a);
   cout<<"Call by ref : "<<a<<endl;
   cout<<"b : "<<b<<endl;
   return 0;
}