#include "header.h"
#include<string>
#include<iostream>
using namespace std;

Prince::Prince(string x,string y):lastName(y){  // this is called member initializer
                                               // only way to initialize the const variable
	setName(x);
}

void Prince::setName(string x){
	firstName = x;
}

string Prince::getName(){
	return firstName +" "+lastName;
}

void Prince::print(){
	cout<<"regular var : "<<firstName<<endl;
	cout<<"const var : "<<lastName<<endl;
}


// void Prince::constfunc() const {
// 	cout<<"it is a const function."<<endl;
// }

