/*
	this  class will manege all level parts.
*/

#include "macros.h"
#include "Loader.h"
#include "display.h"
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
private:
	void clearData();
	void setPlayingMap();//by screen wight
	void slideWord(int dir);//left +1 right -1

private:
	
	list<SmartPtr<Still>> _allStillObj;
	multimap<int,SmartPtr<Still>> _playingobj;//playing obj, store by x
	multimap<string,int> _hits;
	
	bool _valid;
	Place _playerStart;
	Loader _loder;

};
//------------------
#define HIT_FAC 5