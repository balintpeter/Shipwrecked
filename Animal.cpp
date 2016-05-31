#include "Animal.h"

//Konstruktorok
Animal::Animal():Creature(),steal(1){};
Animal::Animal(const Animal& theOther):Creature(theOther.getHealth(),theOther.getLevel()),steal(theOther.getSteal()){};
Animal::Animal(int lvl,int st):Creature(1,lvl),steal(st){};

//Getterek
int Animal::getSteal()const{return steal;}
//Setterek
void Animal::setSteal(int st){steal=st;}
//Egyéb
void Animal::getInfo()const{
	cout<< "Health: "<<getHealth()<<", Level: "<<getLevel()<<", Num of Creatures: "<<db<<endl;	
}