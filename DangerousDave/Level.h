/*
	this  class will manege all level parts.
*/

#include "macros.h"
#include "Loader.h"
#include "display.h"
#include <map>

//------------------
#define HIT_FAC 5

//--------------
typedef pair <int,SmartPtr<Still>> stillPair;

typedef multimap<int,SmartPtr<Still>>::iterator stillXmapIt;

typedef  pair<stillXmapIt,stillXmapIt> stillXmapRange;
class Bullet;


//--------------
class Level {

public:
	Level();
	Place loadLevel(char * levelFile);
	multimap<string,int> levelLoop(Place p_left_botem);
	void display();
	Place getStartPoint(){return _playerStart;};
	void setBulit(Place startP,direction dir);
private:
	void clearData();
	void setPlayingMap();//by screen wight
	void slideWord(int dir);//left +1 right -1
	void hitTest(Display * obj,float playerY);
private:
	
	list<SmartPtr<Still>> _allStillObj;
	list<SmartPtr<Enemy>>_allEnemys;
	multimap<int,SmartPtr<Still>> _playingobj;//playing obj, store by x
	multimap<string,int> _hits;
	
	bool _valid;
	Place _playerStart;
	Loader _loader;
	Bullet* _playerBullet;

};
