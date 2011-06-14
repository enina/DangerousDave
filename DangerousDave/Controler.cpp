#include "Controler.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"

//============================================================================

Controler::Controler(){

	_player = new Player(145,500);
	_player->setPlace(_level.loadLevel("levels/level_1.txt"));

	_enemy = new Enemy(950,400);
	_menu = new Menu(0,0);
	_menu->setController(this);
	_levelNumber=0;

}
//-------------------------------
Controler :: ~Controler(){
	delete _menu;
	delete _player;
	delete _enemy;
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
	_enemy->display();
	_level.display();

}
//============================================================================
// A callback function for the event of a keyboard button pressed
void Controler::keyboard(unsigned char key, int x, int y) 
{  
	//------------
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
		default:
			_player->setDirection(NONE);
			break;

	}

}


//============================================================================
void Controler::mainLoop(){

	hitTest();
	_player->move();
	_enemy->move();
}
//=============================
void Controler::hitTest(){

	//-----------
	rangeIt hits;
	oneIt it ;
	//----------
	Place playerNext =_player->getNextPlace();
	_player->restDirections();
	_hits=_level.levelLoop(playerNext);

	//====player hit test ======//
	//--
	hits =_hits.equal_range("Wall");

	for(it = hits.first ;it != hits.second;++it){

		//==middele===
		if ((*it).second >=playerNext.getY()&&
			(*it).second<= playerNext.getY()+PLYER_SIZE ||
			(*it).second+PLYER_SIZE-HIT_FAC >=playerNext.getY()&&
			(*it).second+PLYER_SIZE<= playerNext.getY()+PLYER_SIZE){

			if (_player->getX_Direction() == LEFT ||_player->getX_Direction() == NONE ){
				_player->_validDirerctios[Left_t]=false;
			}
			if (_player->getX_Direction() == RIGHT ||_player->getX_Direction() == NONE) {
				_player->_validDirerctios[Right_t]=false;
			}
			
		}
			//==up / down ==
		if((*it).second < playerNext.getY()){
			_player->_validDirerctios[Down_t]=false;
			cout << "on down \n";
		}
		//--
		else if(((*it).second)>= playerNext.getY()){
			cout<< "no up \n";
			_player->_validDirerctios[Up_t]=false;
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
			exit(0);
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