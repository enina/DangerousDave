#pragma once

#include "macros.h"

//====testing===//

class Menu;
class Player;
class Level;


#define  START_SCREEN "levels/Splash.txt"

#define  FIRST_LEVEL "levels/first.txt"
//....''''....''''....''''
#define PASSING_LEVEL "levels/pass.txt"

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
	int getLevelNumber(){return _levelNum;};
	Player* getPlayer(){return _player;};

	
private:
	void hitTest(); 
	void levelManage(bool reset);
	void passingLevel();
	Player* _player ;
	//==================
	int _levelNum;
	Menu*  _menu;
	multimap<string,int> _hits;
	Level* _level;
	bool _passing;
};