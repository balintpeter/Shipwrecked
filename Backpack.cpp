#include "Backpack.h"

//Konstruktorok
Backpack::Backpack(){
	food=2;
	wood=0;
}
Backpack::Backpack(const Backpack& theOther){
	food=theOther.food;
	wood=theOther.wood;
}
Backpack::Backpack(int f,int w):food(f),wood(w){};
//Getterek
int Backpack::getFood()const{return food;}
int Backpack::getWood()const{return wood;}
//Setterek
void Backpack::setFood(int f){food=f;}
void Backpack::setWood(int w){wood=w;}
//Egyéb
void Backpack::PlusFood(int f){food+=f;}
void Backpack::AddWood(){wood++;}
void Backpack::StealFood(int steal){
	if(food>=steal) food-=steal;
	else food = 0;
	cout<<food<<"db eteled maradt."<<endl;
}
void Backpack::Print()const{
	cout<<"Food: "<<food<<endl;
	cout<<"Wood: "<<wood<<endl<<endl;
}