#include <iostream>
#include <string>
#include <stdlib.h>
#include "Player.h"
#include <time.h> 
#include <fstream>
#include <conio.h>

using namespace std;


#ifndef GAMEPLAY_H
#define GAMEPLAY_H
namespace Game{
	class Gameplay
	{
	public:	
		static void Intro();

		static void BadOutro();

		static void GoodOutro();

		static bool SelectTask(Player&);

		static void Eat(Player&);

		static bool Hunt(Player&);

		static bool Tree(Player&);

		static bool Sleep(Player&);

	};
}
#endif