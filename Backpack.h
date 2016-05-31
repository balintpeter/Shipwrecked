#include <iostream>

using namespace std;

#ifndef BACKPACK_H
#define BACKPACK_H

class Backpack{
	int food;
	int wood;
public:
	//Konstruktorok
	Backpack();
	Backpack(const Backpack&);
	Backpack(int,int);
	//Getterek
	int getFood()const;
	int getWood()const;
	//Setterek
	void setFood(int);
	void setWood(int);
	//Egyéb
	void PlusFood(int);
	void AddWood();
	void StealFood(int);
	void Print()const;
};

#endif