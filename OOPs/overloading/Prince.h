#ifndef PRINCE_H
#define PRINCE_H

class Prince{
public:
	Prince();
	Prince(int x);
	Prince operator+(Prince obj);
	int getNum();
private:
	int num;
};

#endif