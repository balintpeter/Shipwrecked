#include "Player.h"

//Név input KIVÉTELKEZELÉS!!!
	void Player::InputName(){
		char temp[100];
		cout<<"Ird be a neved!"<<endl;
		bool OK=false;
		while(!OK)
		{
			try
			{
				OK=true;
				gets(temp);
				if(!strlen(temp))
					throw("Nem irtal be semmit!");
			}
			catch(char* err)
			{
				cout<<"Hibauzenet: "<<err<<endl<<endl;
				OK=false;
			}
		}
		name=new char[strlen(temp)];
		strcpy(name,temp);
	}
	//Konstruktorok
	Player::Player():Creature(){
		InputName();
		XP=0;
		hunger=0;
		energy=100;
		backpack=new Backpack();
	}
	Player::Player(const Player& p):Creature(p.getHealth(),p.getLevel()){
		InputName();
		XP=0;
		hunger=0;
		energy=100;
		backpack=new Backpack();
	}
	Player::Player(int h,int l):Creature(h,l){
		InputName();
		XP=0;
		hunger=0;
		energy=100;
		if(!strcmp(name,"iamrich")) {
			backpack=new Backpack(100,100);
			setLevel(100);
		}
		else 
			backpack=new Backpack();
	}
	//Destruktor
	Player::~Player(){
		name = NULL;
		delete []name;
		backpack= NULL;
		delete backpack;
	}
	//Operátor
	bool Player::operator>=(const Animal& two)const{
		if(getLevel()>=two.getLevel())
			return true;
		return false;
	}
	//Getterek
	Backpack* Player::getBackpack()const{return backpack;}
	char* Player::getName()const{return name;}
	int Player::getHunger()const{return hunger;}
	int Player::getEnergy()const{return energy;}
	int Player::getXP()const{return XP;}
	//Setterek
	void Player::setName(char* newname){
		name=NULL;
		name=new char[strlen(newname)];
		strcpy(name,newname);
	}
	void Player::setEnergy(int e){energy=e;}
	//Egyéb
	bool Player::LVLUP(){
		if (XP==getLevel()){
			XP=0;
			return true;
		}
		else return false;
	}
	void Player::AddXP(){XP++;}
	void Player::AddHunger(int h){hunger+=h;}
	void Player::Eat(){
		if(hunger>=20){
		hunger-=20;
		backpack->setFood(backpack->getFood()-1);
		}
		else cout<<"Nem vagy ehes!"<<endl<<endl;
	}
	void Player::UseEnergy(int e){energy-=e;}

	void Player::getInfo()const{
		cout<<"Name: "<<name<< ", Health: "<<getHealth()<<", Level: "<<getLevel()<<", Hunger: "<<hunger<<", Energy: "<<energy<<endl;
		backpack->Print();
	}