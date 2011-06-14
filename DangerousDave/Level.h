/*
	this  class will manege all level parts.
*/

#include "macros.h"
#include "Loader.h"
#include "display.h"
#include "Bulit.h"
#include <map>
//--------------
typedef pair <int,SmartPtr<Still>> stillPair;

typedef multimap<int,SmartPtr<Still>>::iterator stillXmapIt;

typedef  pair<stillXmapIt,stillXmapIt> stillXmapRange;



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
	list<SmartPtr<Move>>_allMoveObj;
	multimap<int,SmartPtr<Still>> _playingobj;//playing obj, store by x
	multimap<string,int> _hits;
	
	bool _valid;
	Place _playerStart;
	Loader _loder;
	Bulit* _playerBulit;

};
//------------------
#define HIT_FAC 5