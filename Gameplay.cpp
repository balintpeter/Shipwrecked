#include "Gameplay.h"

using namespace Game;

void Gameplay::Intro(){
	string TEMP;
	char c;
	cout<<"Tedd nagykepernyosre a konzolt a maximalis elvezetert!"<<endl<<endl;
	c=getch();

	ifstream f;
	try{
		f.open("Intro.txt");
		if(f.is_open()){
			while(!f.eof()){
				getline(f,TEMP);
				cout<<TEMP<<endl;
				if(TEMP!="")c=getch();
			}
			cout<<endl;
		}
		else throw("A fajlt nem lehet megnyitni!");
	}
	catch(char* err)
	{
		cout<<"Hibauzenet: "<<err<<endl<<endl;
	}
	f.close();
}

void Gameplay::BadOutro(){
	string TEMP;
	char c;			
	ifstream f;

	try{
		f.open("BadOutro.txt");
		if(f.is_open()){
			while(!f.eof()){
				getline(f,TEMP);
				cout<<TEMP<<endl;
				if(TEMP!="")c=getch();
			}
			cout<<endl;
		}
		else throw("A fajlt nem lehet megnyitni!");
	}
	catch(char* err)
	{
		cout<<"Hibauzenet: "<<err<<endl<<endl;
	}
	f.close();
}

void Gameplay::GoodOutro(){
	string TEMP;
	char c;
	c=getch();

	ifstream f;
	try{
		f.open("GoodOutro.txt");
		if(f.is_open()){
			while(!f.eof()){
				getline(f,TEMP);
				cout<<TEMP<<endl;
				if(TEMP!="")c=getch();
			}
			cout<<endl;
		}
		else throw("A fajlt nem lehet megnyitni!");
	}
	catch(char* err)
	{
		cout<<"Hibauzenet: "<<err<<endl<<endl;
	}
	f.close();
}

bool Gameplay::SelectTask(Player& p){
	string task;
	bool gameover=false;
	try{
		getline(cin,task);

		if(task=="sleep"){
			gameover=Gameplay::Sleep(p);
		}
		else if(task=="eat"){
			Gameplay::Eat(p);
		}
		else if(task=="cut tree"){
			gameover=Gameplay::Tree(p);
		}
		else if(task=="hunt"){
			gameover=Gameplay::Hunt(p);
		}
		else if(task=="info"){
			p.getInfo();
		}

		else throw("Nincs ilyen cselekves!");
	}
	catch(char* err){
		cout<<"Hibauzenet: "<<err<<endl;
	}

	return gameover;
}

void Gameplay::Eat(Player& p){
	if(p.getHunger()>=20){
	if(p.getBackpack()->getFood()>0){
		p.Eat();
		cout<<"Ettel egy etelt."<<endl<<endl;
	}
	else cout<<"Nincs eteled."<<endl<<endl;
	}
		else cout<<"Nem vagy ehes!"<<endl<<endl;
}


bool Gameplay::Hunt(Player& p){
	int energy=20;
	int hunger=20;
	if(p.getEnergy()<=energy){
		cout<<"Menj el aludni, nincs eleg energiad!"<<endl<<endl;
		return false;
	}
	else{
		p.AddHunger(hunger);
		if(p.getHunger()>=100) return true;
		else{
			cout<<"Elmentel etelt keresni."<<endl;
			p.UseEnergy(energy);
			p.getBackpack()->PlusFood(p.getLevel());
			cout<<"Szereztel "<<p.getLevel()<<"db etelt."<<endl<<endl;
			p.AddXP();
			if(p.LVLUP()) p++;
			return false;
		}
	}
}

bool Gameplay::Tree(Player& p){
	int energy=20;
	int hunger=20;
	if(p.getEnergy()<=energy){
		cout<<"Menj el aludni, nincs eleg energiad!"<<endl<<endl;
		return false;
	}
	else{
		if(p.getHunger()>=(100-hunger)) return true;
		else{
			cout<<"Elmentel fat vagni."<<endl;
			p.AddHunger(hunger);
			p.UseEnergy(energy);
			p.getBackpack()->AddWood();
			cout<<"Szereztel 1 db fat."<<endl<<endl;
			if(p.getBackpack()->getWood()>=15) return true;
			return false;
		}
	}
}


bool Gameplay::Sleep(Player& p){
	int lvl,stl,esely;
	int hunger=20;
	if(p.getHunger()>=100-hunger) return true;
	else{
		time_t t;
		p.AddHunger(hunger);
		srand((unsigned int) time(&t));
		esely=1+rand()%2;
		lvl=1+rand()%4;
		stl=1+rand()%5;
		if(esely==1){
			cout<<"Nyugodt ejszakad volt, ki tudtad pihenni magad."<<endl<<endl;
			p.setEnergy(100);
		}
		else if(esely==2)
		{
			Animal enemy(lvl,stl);
			cout<<"Almodban megtamadott egy vadallat."<<endl;
			cout<<"A Te szinted: "<<p.getLevel()<<", a tamado "<<enemy.getLevel()<<"-es szintu."<<endl;
			p.setEnergy(40);
			if(p>=enemy){
				cout<<"Sikeresen legyozted a tamadot!"<<endl<<endl;
			}
			else{
				cout<<"Az ellenseg erosebb volt, mint Te, elvitte az eteled!"<<endl;
				p.getBackpack()->StealFood(stl);
				cout<<endl;
			}
		}
		return false;
	}
}