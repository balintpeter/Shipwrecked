#include "Creature.h"

int Creature::db=0;
//Konstruktorok
Creature::Creature(){
	health=100;
	level=1;
	db++;
}

Creature::Creature(const Creature& theOther){
	health=theOther.health;
	level=theOther.level;
	db++;
}

Creature::Creature(int h,int l){
	if(h<=100 && h>=0)
		health=h;
	else health=100;

	if(l>=1 && l<=100)
		level=l;
	else level=1;
	db++;
}

//Operátor
Creature& Creature::operator++(){
	level++;
	return Creature(health,level);
}
//Getterek
int Creature::getHealth()const{return health;}
int Creature::getLevel()const{return level;}
//Setterek
void Creature::setHealth(int health){this->health=health;}
void Creature::setLevel(int level){this->level=level;}
//Egyéb
void Creature::getInfo()const{
	cout<<"Health: "<<health<<", Level: "<<level<<", Num of Creatures: "<<db<<endl<<endl;
}

