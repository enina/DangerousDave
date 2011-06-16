#include "Controler.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
#include "Level.h"

//============================================================================

Controler::Controler(){

	_player = new Player(145,500);
	_level = new Level();

	_menu = new Menu(0,0);
	_menu->setController(this);
	_levelNum=START;
	_level=NULL;
	_passing=false;
	levelManage(false);
}
//-------------------------------
Controler :: ~Controler(){
	delete _menu;
	delete _player;
}
//-------------------------
void Controler::idle(){

	mainLoop();
	glutPostRedisplay();

}
//============================================================================
// The display into the window
void Controler::display() {

	_menu->display();
	_player->display();
	_level->display();

}
//============================================================================
// A callback function for the event of a keyboard button pressed
void Controler::keyboard(unsigned char key, int x, int y) 
{  
	if (_levelNum==START)
	{
		cout << "dsfsdfsdfsdfdsfdsdfsdf\n";
		_levelNum++;
		levelManage(false);
	}
	//==================
	switch(key) {
		case 'a':
		case 'A':
		case '4':
			_player->setDirection(LEFT); 
			break ;
		case 'd':
		case 'D':
		case '6':
			_player->setDirection(RIGHT); 
			break ;
		case 'w':
		case 'W':
		case '8':
			_player->setJump();
			break ;
		case 's':
		case 'S':
		case '2':
			_player->setDirection(DOWN); 
			break ;

		case 'j':
		case 'J':
			_player->activeJetPack();
			break;
		case 'b':
		case 'B':
			if(_player->getGun()){
				_level->setBullet(_player->getPlace(),_player->getX_Direction());
			}
			break;
		default:
			_player->setDirection(NONE);
			break;

	}

}


//============================================================================
void Controler::mainLoop(){

	if(_levelNum==START){
		return;
	}
	hitTest();
	_player->move();
}
//=============================
void Controler::hitTest(){

	//-----------
	rangeIt hits;
	oneIt it ;
	//----------
	Place playerNext =_player->getNextPlace();
	_player->restDirections();
	_hits=_level->executeTurn(_player);


	if (!_player->isAlive()) {
		levelManage(true);
		_player->resurrect();
		return;
	}


	//--------------------
	if(_passing){
		if(_player->getPlace().getX()+PLAYER_SIZE>=SCREEN_WIDTH){
			_levelNum++;
			levelManage(false);
			return;
		}
		_player->setDirection(RIGHT);
		_player->_validDirections[Down_t]=false;
		return;
	}

	//====player hit test ======//
	//--
	hits =_hits.equal_range("Wall");

	for(it = hits.first ;it != hits.second;++it){

		//==middele===
		if ((*it).second >=playerNext.getY()&&
			(*it).second<= playerNext.getY()+PLAYER_SIZE ||
			(*it).second+PLAYER_SIZE-HIT_FAC >=playerNext.getY()&&
			(*it).second+PLAYER_SIZE<= playerNext.getY()+PLAYER_SIZE){

				if (_player->getX_Direction() == LEFT ||_player->getX_Direction() == NONE ){
					_player->_validDirections[Left_t]=false;
				}
				if (_player->getX_Direction() == RIGHT ||_player->getX_Direction() == NONE) {
					_player->_validDirections[Right_t]=false;
				}

		}
		//==up / down ==
		if((*it).second < playerNext.getY()){
			_player->_validDirections[Down_t]=false;
		}
		//--
		else if(((*it).second)>= playerNext.getY()){
			_player->_validDirections[Up_t]=false;
		}
	}
	//=====KEYS=======//
	oneIt cup = _hits.find("Cup");

	if (cup!= _hits.end()){
		_player->_gutCup = true;
	}
	//======//
	oneIt door =_hits.find("Door");

	if (_player->_gutCup&&door!= _hits.end()){
		_levelNum++;
		levelManage(false);
		return;
	}
	oneIt jetPak =_hits.find("JetPack");
	if (jetPak!= _hits.end()){
		_player->fuelJetPack();
	}
	oneIt gun =_hits.find("Gun");
	if (gun != _hits.end()){
		_player->setGun();
	}
	//======prizes============//
	hits =_hits.equal_range("Prize");
	for(it = hits.first ;it != hits.second;++it){
		_player->addPoints(((*it).second));
	}
	//==========================//
	//====glide==================
	oneIt glide =_hits.find("Glide");

	if (glide!= _hits.end()){
		Place temp =_player->getPlace();
		temp.moveX((*glide).second);
		_player->setPlace(temp);
	}


	//	cout << _player->getScore();
	//	cout << endl;
}
void Controler ::levelManage(bool reset){
	_passing = false;
	if (reset){
		_player->setPlace(_level->getStartPoint());
		return;
	}
	if(_level != NULL){
		free(_level);
		_level=NULL;
	}
	_level =  new Level();
	if(_levelNum%2 == 0&&_levelNum!=START){//moving level
		_passing=true;
		_player->setPlace(_level->loadLevel(PASSING_LEVEL));
		_player->clearKeys();
		return;
	}
	switch (_levelNum){
	case START:
		cout <<"lalala111\n";
		_player->setPlace(_level ->loadLevel(START_SCREEN));
		break;
	case FIRST:
		cout <<"lalala222\n";
		_player->setPlace(_level->loadLevel(FIRST_LEVEL));
		break;
	}
}
void Controler :: passingLevel(){
	_player->setPlace(_level->loadLevel(PASSING_LEVEL));
	_player->setDirection(RIGHT);
	delete _level;
	_level= new Level();
}