#include "Creature.h"
#include "Backpack.h"
#include "Animal.h"
#include <iostream>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player:public Creature
{
private:
	char* name;
	int XP;
	int hunger;
	int energy;
	Backpack* backpack;
public:
	//N�v input
	void InputName();
		
	//Konstruktorok
	Player();
	Player(const Player&);
	Player(int,int);
	//Destruktor
	~Player();
	//Oper�tor
	bool operator>=(const Animal&)const;
	//Getterek
	Backpack* getBackpack()const;
	char* getName()const;
	int getHunger()const;
	int getEnergy()const;
	int getXP()const;
	//Setterek
	void setName(char*);
	void setEnergy(int);
	//Egy�b
	bool LVLUP();
	void AddXP();
	void AddHunger(int);
	void Eat();
	void UseEnergy(int);

	void getInfo()const;
};
#endif