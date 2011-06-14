#pragma once

#include "macros.h"
#include "Move.h"

#include <vector>
class Image;
using std::vector;
//======================
#define  DIRETIONS 4
#define FULL_TANK 500
#define NO_JUMP -1
//----------------------
class Player : public Move {
public:
	Player  (float xplace,float yplace);
	Player  (vector<char*> filenames);
	virtual ~Player ();
	virtual int getImageIdx() ;
	virtual void move();

	void activeJetPack();
	void setJump();
	void tugeleGravety(){_gravety= !_gravety;};

	void setPlace(Place newPlace){_place = newPlace;};
	Place getNextPlace();

	int getScore(){return _score;};
	void addPoints (int points){_score+=points;};

	void fuelJetPack(){JP_fule = FULL_TANK;};
	int getLife(){return _life;};
	bool getJetPack(){return _hasJetpack;};
	bool getGun() {return _gun;};
	void setGun(){_gun=true;};

	void clearKeys(){_gun=_gutCup=_hasJetpack=false;_jumping=NO_JUMP;};
public://private:
	void restDirections();
	bool _validDirections [DIRETIONS];
	bool _gutCup;
private:
	int _life;
	int _imageIndex;
	bool _hasJetpack;
	bool _gravety;
	int _jumping;
	int _score;
	int JP_fule;
	bool _gun;
	

};

enum direct_t {Up_t,Down_t,Left_t,Right_t};

#define  PL_SIZE 55

#define JUMP_MAX 30
//========   images ===========
#define JAMP_LEFT_PATH "graphix/player/jamp_left.tga"
#define JAMP_LEFT 0

#define JAMP_RIGHT_PATH "graphix/player/jatpak_right.tga"
#define JAMP_RIGHT 1

#define  JETPAK_LEFT_PATH "graphix/player/jatpek_left.tga"
#define  JETPAK_LEFT 2

#define JETPAK_RIGHT_PATH "graphix/player/jump_right.tga"
#define JETPAK_RIGHT 3

#define PLAYER_STEND_LEFT_PATH "graphix/player/player_stand_left.tga"
#define PLAYER_STEND_LEFT 4

#define PLAYER_WALK_LEFT_PATH "graphix/player/player_walk_left.tga"
#define PLAYER_WALK_LEFT 5

#define PLAYER_STEND_RIGHT_PATH "graphix/player/player_stand_right.tga"
#define PLAYER_STEND_RIGHT 6

#define PLAYER_WALK_RIGHT_PATH "graphix/player/player_walk_right.tga"
#define PLAYER_WALK_RIGHT 7

#define PLAYER_STEND_STRAIGHT_PATH "graphix/player/player_stand.tga"
#define PLAYER_STEND_STRAIGHT 8
