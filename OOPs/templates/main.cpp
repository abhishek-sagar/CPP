#include<iostream>
using namespace std;

// SIMPLE TEMPLATES

// template <class T,class S>
// T bigger(T a,S b){
// 	return (a>b?a:b);
// }

// int main(){
//    int x = 53;
//    double y = 73.22;
//    cout<<bigger(x,y)<<endl;  // it will print only 73 in this case because as x is an int 
//    return 0;                 // then T will become int type template but if the function
//                              // is called like bigger(y,x) then T will become double.  
// }


// CLASS TEMPLATES

// template <class T>
// class Main{
// public:
// 	Main(){

// 	}
//     T num;
// 	T bigger(T a,T b);
// };

// template <class T> // we have to redesfine the template before each function of this class
//                    // which is outside the class
// T Main<T>::bigger(T a,T b){  // also this is the syntax to write <T>;
//     return (a>b?a:b); 
// }                   

// int main(){
// 	Main<int> obj;
// 	cout<<obj.bigger(33,54)<<endl;
// 	return 0;
// }


// TEMPLATE SPESIALIZATION

template <class T>
class Main{
public:
	Main(){}
	void Print(T x){
		cout<<x<<" is not a character!."<<endl;
	}
};

template<>   // this is a specialized template 
class Main<char>{  // this is a specialized class
public:
	Main(){}
	void Print(char x){
		cout<<x<<" is a character!!."<<endl;
	}
};

int main(){
	Main<int> obj1;
	obj1.Print(32);
	Main<double> obj2;
    obj2.Print(23.32);
    Main<char> obj;
    obj.Print('a');
    return 0;
}