#define _CRT_SECURE_NO_WARNINGS
#include "Creature.h"
#include "Player.h"
#include "Gameplay.h"
#include <iostream>

using namespace std;
using namespace Game;

int main(void){
	bool gameover=false;

	Game::Gameplay::Intro();
	Player p(100,1);

	cout<<"A neved mostantol "<<p.getName()<<endl<<endl;
	cout<<"Ird be, hogy mit szeretnel csinalni."<<endl<<endl;
	while (!gameover)
	{
		gameover=Gameplay::SelectTask(p);
	}
	if(p.getBackpack()->getWood()>=15)
		Gameplay::GoodOutro();
	else
		Gameplay::BadOutro();
	return 0;
}
