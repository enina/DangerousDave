#include "Level.h"
//---------------

Level ::Level(){

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

}
//---------------------------
multimap<string,int> Level :: levelLoop(Place p_left_botem){

	stillXmapIt curObj;
	stillXmapRange xRange;
	float objY;
	float playerY = p_left_botem.getY();
	//=============
	if(!_valid){
		clearData();
		return _hits;
	}
	if(p_left_botem.getX()<=START-(PLYER_SIZE/3)){
		slideWord(1);
		_hits.insert(hitRet_t("Glide",SCREEN_WIDTH-PLYER_SIZE));
		return _hits ;
	}
	if(p_left_botem.getX()+PLYER_SIZE>=SCREEN_WIDTH){
		slideWord(-1);
		_hits.insert(hitRet_t("Glide",-(SCREEN_WIDTH-PLYER_SIZE)));
		return _hits ;
	}
	//==============
	_hits.clear();

	for(int i = - PLYER_SIZE ; i<PLYER_SIZE; i++){

		xRange =_playingobj.equal_range(p_left_botem.getX()+i);//get all close x

		for(curObj=xRange.first;curObj!=xRange.second;++curObj){ // check if y is close

			objY = (*curObj).second -> getPlace().getY();

			if(objY+PLYER_SIZE-HIT_FAC<=playerY && objY+PLYER_SIZE+HIT_FAC>playerY||//below
			playerY+PLYER_SIZE-HIT_FAC<=objY&&playerY+PLYER_SIZE+HIT_FAC>=objY||//up
			objY>=playerY && objY <= playerY+PLYER_SIZE||
			objY+PLYER_SIZE>=playerY && objY +PLYER_SIZE <= playerY+PLYER_SIZE){
				
				cout<<(*curObj).second -> getPlace().getX();
				cout<<endl;
				
				_hits.insert((*curObj).second -> setHit());
			}
		}
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