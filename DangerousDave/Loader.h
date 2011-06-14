/*
	this is a service class that help the level
*/
#pragma once 
#include "macros.h"

#include "Place.h"
#include "Still.h"
#include "Move.h"
//=============
#include "Wall.h"
#include "Perl.h"
#include "Door.h"
#include "Pipe.h"
#include "Soil_bg.h"
#include "Cup.h"
#include "Diamond.h"
#include "Enemy.h"
#include "JetPack.h"
#include "Gun.h"

#include <list>
//-------------
class Loader {

public:

	Loader();
	~Loader();

	void loadLevel(char * levelPath);
	list<SmartPtr<Still>> getStilList(){return _stillObj;} ;
	list<SmartPtr<Move>> getMoveList(){return _moveObj;};
	Place getPlayerPlace(){return _playerStart ;};
private:
	void parseFile();
	

private:
	ifstream _levelFile;
	list<SmartPtr<Still>>_stillObj;
	list<SmartPtr<Move>>_moveObj;

	Place _playerStart;
		
};
//------------------------
#define WALL 'w'
#define PERL 'e'
#define PLAYER 'p'
#define JET_PACK 'j'
#define	DOOR 'd'
#define PIPE 'b'
#define SOIL 'm'
#define CUP 'c'
#define GROUND 'm'//the bg that looks like durt
#define DIAMOND 'a'
#define ENEMY 'q'
#define GUN 'G'
//=======
#define FIRE 'f'
#define WATER 't'