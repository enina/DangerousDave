#include "Level.h"
#include "Bullet.h"
#include "Player.h"
//---------------

Level ::Level(){
	_playerBullet =NULL;
	clearData();
	
};
//-----------------------
Place Level :: loadLevel(char * levelFile){
	if(_valid){
		clearData();
	}
	//------------
	_loader.loadLevel(levelFile);
	_allStillObj = _loader.getStilList();
	_playerStart = _loader.getPlayerPlace();
	_allEnemys = _loader.getMoveList();
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
	_allEnemys.clear();

	if(_playerBullet!= NULL){
		free(_playerBullet);
	}
	_playerBullet =NULL;
}
//---------------------------
multimap<string,int> Level :: executeTurn(Player* player)
{
	stillXmapIt curObj;
	stillXmapRange xRange;
	
	float playerY = player->getPlace().getY();
	//=============
	if(!_valid){
		clearData();
		return _hits;
	}
	if(player->getPlace().getX()<=START-(PLAYER_SIZE/3)){
		slideWord(1);
		_hits.insert(hitRet_t("Glide",SCREEN_WIDTH-PLAYER_SIZE));
		return _hits ;
	}
	if(player->getPlace().getX()+PLAYER_SIZE>=SCREEN_WIDTH){
		slideWord(-1);
		_hits.insert(hitRet_t("Glide",-(SCREEN_WIDTH-PLAYER_SIZE)));
		return _hits ;
	}
	//==============
	_hits.clear();

	for(int i = - PLAYER_SIZE ; i<PLAYER_SIZE; i++){

		xRange =_playingobj.equal_range(player->getPlace().getX()+i);//get all close x

		for(curObj=xRange.first;curObj!=xRange.second;++curObj){ // check if y is close

			hitTest(&(*((*curObj).second)) ,playerY);
		}
	}
	//============move=========================
	list<SmartPtr<Enemy>>::iterator enemyIter;
	SmartPtr<Enemy> monster;
	//-------------

	enemyIter = _allEnemys.begin();

	while (enemyIter !=_allEnemys.end()) {
		monster = (*enemyIter);
		
		if(!monster->isValid()) {
			enemyIter = _allEnemys.erase(enemyIter);
			continue;
		}
		monster->move();
		hitTest(&(*monster),playerY);
		checkEnemyBulletHits(&(*monster),player);
		if (!player->isAlive())
			break;
		enemyIter++;
	}

	if (player->isAlive()) {
		checkPlayerBulletHits();
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
	list<SmartPtr<Enemy>>::iterator enemyIter;
	//-------------
	for(enemyIter= _allEnemys.begin();enemyIter != _allEnemys.end();++enemyIter){

		(*enemyIter)->display();
	}
	if(_playerBullet){
		_playerBullet->display();
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
	list<SmartPtr<Enemy>>::iterator Mit;
	const int slidSpeed =5;
	//--------------------
	
	for(int i=START ; i<SCREEN_WIDTH ; i+=slidSpeed){
		for(it=_allStillObj.begin();it != _allStillObj.end();++it){
			
			(*it)->glide(dir*slidSpeed);
		}
		//========enemys===
		for(Mit= _allEnemys.begin();Mit != _allEnemys.end();++Mit){
			(*Mit)->display();
		}
		setPlayingMap();
		glutPostRedisplay();	
	}
}
//-----------------------------------------
void Level:: setBullet(Place startP,direction dir){
	if (_playerBullet != NULL){
		return;
	}
	//-------
	if(dir == NONE){

		dir = RIGHT;
	}

	_playerBullet = new Bullet(startP.getX(),startP.getY(),dir);
}


void Level::checkEnemyBulletHits(Enemy* pEnemy,Player* player)  {

	stillXmapIt curObj;

	list<SmartPtr<Enemy>>::iterator enemyIter;
	Place bulletPlace;

	if(pEnemy->getBullet()){
		Place hitObjPlace;
		bulletPlace= pEnemy->getBullet()->getPlace();
		//--------
		//==Check collissions with wall or other still object ==
		pEnemy->getBullet()->move();
		for (curObj=_playingobj.begin();curObj!=_playingobj.end();++curObj){
			hitObjPlace =((*curObj).second)-> getPlace();
			if(bulletPlace.facEq(hitObjPlace,PLAYER_SIZE)){
				
				pEnemy->destroyBullet();
				break;
			}
		}
	}

	if(pEnemy->getBullet()){
		bulletPlace= pEnemy->getBullet()->getPlace();
		//==bullet hit player  ==
		if(bulletPlace.facEq(player->getPlace(),PLAYER_SIZE)){
			player->kill();
			pEnemy->destroyBullet();
		}
	}

	if(pEnemy->getBullet())
		pEnemy->getBullet()->move();
}


void Level::checkPlayerBulletHits() {

	stillXmapIt curObj;

	Place hitObjPlace;
	Place bulletPlace ;


	list<SmartPtr<Enemy>>::iterator enemyIter;



	if(_playerBullet){

		bulletPlace = _playerBullet->getPlace();
		//--------
		//==bullet hit something ==
		_playerBullet -> move();
		for (curObj=_playingobj.begin();curObj!=_playingobj.end();++curObj){
			hitObjPlace =((*curObj).second)-> getPlace();

			if(bulletPlace.facEq(hitObjPlace,PLAYER_SIZE)){
				
				delete (_playerBullet);
				_playerBullet=NULL;
				break;
			}
		}
	}

	if(_playerBullet){
		//==bullet hit enemy  ==
		SmartPtr<Enemy> monster;
		for(enemyIter= _allEnemys.begin();enemyIter!= _allEnemys.end();++enemyIter){
			monster = (*enemyIter);
			hitObjPlace = monster->getPlace();

			if(bulletPlace.facEq(hitObjPlace,PLAYER_SIZE)){
				monster->kill();
			}
		}	
	}
}