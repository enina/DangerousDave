#include "Level.h"
//---------------

Level ::Level(){
	_playerBulit =NULL;
	clearData();
	
};
//-----------------------
Place Level :: loadLevel(char * levelFile){
	if(_valid){
		clearData();
	}
	//------------
	_loder.loadLevel(levelFile);
	_allStillObj = _loder.getStilList();
	_playerStart = _loder.getPlayerPlace();
	_allMoveObj = _loder.getMoveList();
	//--------
	_valid = true;
	setPlayingMap();
	return(_playerStart);
}
//---------------------------
void Level :: clearData(){

	_valid=false;
	_allStillObj.clear();
	_hits.clear();
	_playingobj.clear();
	_allMoveObj.clear();

	if(_playerBulit!= NULL){
		free(_playerBulit);
	}
	_playerBulit =NULL;
}
//---------------------------
multimap<string,int> Level :: levelLoop(Place p_left_botem){

	stillXmapIt curObj;
	stillXmapRange xRange;
	
	float playerY = p_left_botem.getY();
	//=============
	if(!_valid){
		clearData();
		return _hits;
	}
	if(p_left_botem.getX()<=START-(PLAYER_SIZE/3)){
		slideWord(1);
		_hits.insert(hitRet_t("Glide",SCREEN_WIDTH-PLAYER_SIZE));
		return _hits ;
	}
	if(p_left_botem.getX()+PLAYER_SIZE>=SCREEN_WIDTH){
		slideWord(-1);
		_hits.insert(hitRet_t("Glide",-(SCREEN_WIDTH-PLAYER_SIZE)));
		return _hits ;
	}
	//==============
	_hits.clear();

	for(int i = - PLAYER_SIZE ; i<PLAYER_SIZE; i++){

		xRange =_playingobj.equal_range(p_left_botem.getX()+i);//get all close x

		for(curObj=xRange.first;curObj!=xRange.second;++curObj){ // check if y is close

			hitTest(&(*((*curObj).second)) ,playerY);
		}
	}
	//============move=========================
	list<SmartPtr<Move>>::iterator Mit;
	//-------------
	for(Mit= _allMoveObj.begin();Mit != _allMoveObj.end();++Mit){

		(*Mit)->move();
		hitTest(&(*((*Mit))) ,playerY);
	}
	if(_playerBulit){
		_playerBulit -> move();
	}

	return (_hits);
}
//------------------------------------------------------
void Level::display(){
	stillXmapIt it;
	//--------------------

	for(it=_playingobj.begin();it != _playingobj.end();++it){

		if(!(*it).second->isValid()){ //==free un neede obj

			it =_playingobj.erase(it);

			if (it == _playingobj.end()){
				return;
			}
		}
		(*it).second->display();
	}
	//========move======================
	list<SmartPtr<Move>>::iterator Mit;
	//-------------
	for(Mit= _allMoveObj.begin();Mit != _allMoveObj.end();++Mit){

		(*Mit)->display();
	}
	if(_playerBulit){
		_playerBulit->display();
	}
	//===================================
}
//----------------------------
void Level::hitTest(Display * obj,float playerY){

	float objY;
	//---------
	objY = obj-> getPlace().getY();

	if(objY+PLAYER_SIZE-HIT_FAC<=playerY && objY+PLAYER_SIZE+HIT_FAC>playerY||//below
		playerY+PLAYER_SIZE-HIT_FAC<=objY&&playerY+PLAYER_SIZE+HIT_FAC>=objY||//up
		objY>=playerY && objY <= playerY+PLAYER_SIZE||
		objY+PLAYER_SIZE>=playerY && objY +PLAYER_SIZE <= playerY+PLAYER_SIZE){

			_hits.insert(obj-> setHit());
	}
}
//----------------------------
void Level:: setPlayingMap(){

	list<SmartPtr<Still>>::iterator it;
	int objX;
	stillPair playing;
	//--------------------
	_playingobj.clear();

	for(it=_allStillObj.begin();it != _allStillObj.end();++it){
		//==valid test==
		if (!(*it)->isValid())
		{
			it = _allStillObj.erase(it);
			if (it == _allStillObj.end())
			{
				return;
			}
		}
		//--------
		objX = ((*it)->getPlace()).getX();

		if(objX>SCREEN_WIDTH ||objX< START ){ // no on screen
			continue;
		}
		playing.first = objX;
		playing.second = (*it);

		_playingobj.insert(playing);
	}
}
//----------------------------------------
void Level:: slideWord(int dir){

	list<SmartPtr<Still>>::iterator it;
	const int slidSpeed =5;
	//--------------------
	
	for(int i=START ; i<SCREEN_WIDTH ; i+=slidSpeed){
		for(it=_allStillObj.begin();it != _allStillObj.end();++it){
			
			(*it)->glide(dir*slidSpeed);
		}
		setPlayingMap();
		glutPostRedisplay();	
	}
}
//-----------------------------------------
void Level:: setBulit(Place startP,direction dir){
	if (_playerBulit != NULL){
		return;
	}
	//-------
	if(dir == NONE){

		dir = RIGHT;
	}

	_playerBulit = new Bulit(startP.getX(),startP.getY(),dir);
}