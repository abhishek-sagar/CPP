#include<iostream>
#include "Hash.h"
using namespace std;

int main(){
   Hash H(7);
   H.InsertItem("Prince",9);
   H.InsertItem("kakku",5);
   H.InsertItem("kallu",1);
   H.InsertItem("dona",7);
   H.InsertItem("pitthu",0);
   H.InsertItem("mitthu",8);
   cout<<H.Search("dona")<<endl;
   H.update("dona",3);
   cout<<H.Search("dona")<<endl;
   H.DeleteKey("dona");
   cout<<H.Search("dona")<<endl;
   return 0;
}