#include <iostream>
#include "Creature.h"

using namespace std;

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal:public Creature
{
private:
	int steal;
public:

	//Konstruktorok
	Animal();
	Animal(const Animal&);
	Animal(int,int);

	//Getterek
	int getSteal()const;
	//Setterek
	void setSteal(int);
	//Egyéb
	void getInfo()const;
};
#endif