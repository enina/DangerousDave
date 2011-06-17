/*
	this is a service class that help the level
*/
#pragma once 
#include "macros.h"
#include "Place.h"
#include "Display.h"
#include "Enemy.h"

#define WALL 'w'
#define PERL 'e'
#define PLAYER 'p'
#define JP 'j'
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

#define WALL_NAME  "Wall"
#define WALL_IMAGE "graphix/world/blue_wall.tga"
#define WALL_VALUE 1

#define PIPE_NAME WALL_NAME
#define PIPE_IMAGE "graphix/world/Pipeline.tga"
#define PIPE_VALUE WALL_VALUE


#define SOIL_NAME  "SoilBG"
#define SOIL_IMAGE "graphix/world/soil_bg.tga" 
#define SOIL_VALUE -1

#define  DOOR_NAME "Door"
#define  DOOR_IMAGE "graphix/world/door.tga"
#define  DOOR_VALUE 1

///////////////////////////////

#define PERL_NAME  "Prize"
#define PERL_IMAGE "graphix/world/perl.tga"
#define PERL_VALUE 50


#define DIAMOND_NAME "Prize"
#define DIAMOND_IMAGE "graphix/world/green_diamond.tga"
#define DIAMOND_VALUE 100


#define JP_NAME "JetPack"
#define JP_IMAGE "graphix/world/jetPack.tga"
#define JP_VALUE 1

#define CUP_NAME "Cup"
#define CUP_IMAGE "graphix/world/cup.tga"
#define CUP_VALUE 1

#define  GUN_NAME "Gun"
#define  GUN_IMAGE "graphix/misc/gun.tga"
#define  GUN_VALUE 1
/////////////////////////////////////////////

#define OBJ_INFO_HANDLE(OBJ) ObjInfoHandle(new ObjectInfo (OBJ##_NAME,OBJ##_IMAGE,OBJ##_VALUE))
#define OBJ_MAP_ENTRY(OBJ)   pair<char,ObjInfoHandle>(OBJ,ObjInfoHandle(new ObjectInfo (OBJ##_NAME,OBJ##_IMAGE,OBJ##_VALUE)))


//-------------
class Loader {

public:

	Loader();
	~Loader();

	void loadLevel(const char * levelPath);
	list<SmartPtr<Display>> getStilList(){return _stillObj;} ;
	list<SmartPtr<Enemy>> getMoveList(){return _enemys;};
	Place getPlayerPlace(){return _playerStart ;};
private:
	void parseFile();
	

private:
	ifstream _levelFile;
	list<SmartPtr<Display>>_stillObj;
	list<SmartPtr<Enemy>>_enemys;
	map<char,ObjInfoHandle> _objInfoMap;

	Place _playerStart;
		
};
