#include <iostream>

using namespace std;

#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
private:
	int health;
	int level;

public:
	static int db;
	//Konstruktorok
	Creature();
	Creature(const Creature&);
	Creature(int,int);
	~Creature(){db--;}
	//Operátor
	Creature& operator++();
	//Getterek
	int getHealth()const;
	int getLevel()const;
	//Setterek
	void setHealth(int);
	void setLevel(int);
	//Egyéb
	virtual void getInfo()const;
};
#endif