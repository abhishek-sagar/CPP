#include<iostream>
#include"Prince.h"
using namespace std;

Prince::Prince(){}
Prince::Prince(int x){
	this->num = x;
}

int Prince::getNum(){
	return this->num;
}

Prince Prince::operator+(Prince obj){
	Prince newobj;
	newobj.num = this->num + obj.num;
	return newobj;
}