#ifndef HEADER_H
#define HEADER_H
#include<string>
#include<iostream>
using namespace std;

 
class Prince{
public:
	Prince(string x,string y);
	void setName(string x);
	string getName();
	void print();
private:
    string firstName;
    const string lastName;
};

#endif