#pragma once

#include "macros.h"
#include "Level.h"
//====testing===//

class Menu;
class Player;
class Enemy;

//--------------------
class Controler{
public:
	Controler();
	~Controler();
	void display();
	void keyboard(unsigned char key, int x, int y);
	void idle();
	void getSubLevelNames();
	void mainLoop();
	int getLevelNumber(){return _levelNumber;};
	Player* getPlayer(){return _player;};

	
private:
	void hitTest(); 
	Player* _player ;
	Enemy*  _enemy;
	int _levelNumber;
	//==================
	Menu*  _menu;
	multimap<string,int> _hits;
	Level _level;
};