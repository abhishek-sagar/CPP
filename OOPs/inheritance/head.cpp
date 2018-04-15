#include<iostream>
#include "head.h"
#include "Daughter.h"
using namespace std;

Mother::Mother(){
  cout<<"I am the mothers constructor!"<<endl;
}

Mother::~Mother(){
  cout<<"I am the mothers deconstructor!"<<endl;
}

void Mother::Print(){
	cout<<"yo yo what's going on guys, MKBHD here!!"<<endl;
}