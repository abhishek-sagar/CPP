#include<iostream>
#include"Prince.h"
using namespace std;

int main(){
   Prince obj1(34);
   Prince obj2(25);
   Prince obj;
   obj = obj1 + obj2;

   cout<<obj.getNum()<<endl;
} 