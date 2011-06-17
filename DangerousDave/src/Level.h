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
typedef pair <int,SmartPtr<Display>> stillPair;

typedef multimap<int,SmartPtr<Display>>::iterator stillXmapIt;

typedef  pair<stillXmapIt,stillXmapIt> stillXmapRange;
class Bullet;
class Player;


//--------------
class Level {

public:
	Level();
	Place loadLevel(char * levelFile);
	multimap<string,int> executeTurn(Player* pPlayer);
	void display();
	Place getStartPoint(){return _playerStart;};
	void setBullet(Place startP,direction dir);
private:
	void clearData();
	void setPlayingMap();//by screen wight
	void slideWord(int dir);//left +1 right -1
	void hitTest(Display * obj,float playerY);
	void checkPlayerBulletHits() ;
	void checkEnemyBulletHits(Enemy* pEnemy,Player* player) ;
private:
	
	list<SmartPtr<Display>> _allStillObj;
	list<SmartPtr<Enemy>>_allEnemys;
	multimap<int,SmartPtr<Display>> _playingobj;//playing obj, store by x
	multimap<string,int> _hits;
	
	bool _valid;
	Place _playerStart;
	Loader _loader;
	Bullet* _playerBullet;

};
