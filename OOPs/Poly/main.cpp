#include<iostream>
using namespace std;

class Enemy{
protected:   // protected members are accessable in drived class
	int attackPower;
public:
   virtual void attack(){} //this is a virtual function and it can be a *pure virtual function* 
	                         // if it is like virtual void attack()=0; and then this class is 
	                         // called as an *Abstract class*.
	void setAttackPower(int x){
		this->attackPower = x;
	}
};

class Ninja: public Enemy{
public:
	void attack(){
		cout<<"I am Ninja, Ninja Chop!!  -"<<attackPower<<endl;
	}
};

class Monster: public Enemy{
public:
	void attack(){
		cout<<"I am Monster, Monster Chop!!!!  -"<<attackPower<<endl;
	}
};

int main(){
     Ninja n;
     Monster m;
     Enemy *e1 = &n;
     Enemy *e2 = &m;
     e1->setAttackPower(59);
     e2->setAttackPower(99);
     e1->attack();
     e2->attack();
     return 0;
}