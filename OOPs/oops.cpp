#include "header.h"
#include<string>
#include<iostream>
using namespace std;


int main(){
	Prince po("Prince","Ambawata");
	cout<<po.getName()<<endl;
    po.print();
	// const object
	// const int x //   or create an const object by  // const Prince object //
    //** remember that a const object only call the const functions of a class. **//

	return 0;
}