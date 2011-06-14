#include <stdio.h>
#include <math.h>
#include "Menu.h"
#include "Still.h"
#include "Image.h"
#include "Place.h"
#include "Controler.h"
#include "Player.h"

Menu::Menu (float xPlace,float yPlace):Still(xPlace,yPlace)
{
	char fileName[MAX_NUMBER*3];

	_dave = new Image("graphix/menu_bar/head.tga");
	_scoreCaption = new Image("graphix/menu_bar/score.tga");
	_davesCaption = new Image("graphix/menu_bar/daves.tga");
	_levelCaption = new Image("graphix/menu_bar/level.tga");

	_jetpack = new Image("graphix/menu_bar/jetpack.tga");
	_gun = new Image("graphix/menu_bar/gun.tga");
	_message = new Image("graphix/menu_bar/message.tga");

	for(int i =0;i < 10;++i) {
		memset(fileName,MAX_NUMBER*3,0);
		sprintf_s(fileName,MAX_NUMBER*3,"graphix/menu_bar/number_%d.tga",i);
		_digitMap.insert(pair<int,Image*>(i,new Image(fileName)));
	}

	_scoreCaptionPlace = new Place(60,655);
	_scorePlace = new Place(280,655);
	
	_levelCaptionPlace = new Place(450,655);
	_levelPlace = new Place(670,655);
	_lifesCaptionPlace = new Place(800,655);
	_lifesPlace = new Place(1000,655);

	_jetpackCaptionPlace= new Place(60,0);
	_gunCaptionPlace= new Place(950,0);
	_messagePlace= new Place(450,0);


}


Menu::~Menu() {
	if (_scoreCaptionPlace) {
		delete _scoreCaptionPlace;
		_scoreCaptionPlace = NULL;
	}
	if (_scorePlace) {
		delete _scorePlace;
		_scorePlace = NULL;
	}
	if (_levelCaptionPlace) {
		delete _levelCaptionPlace;
		_levelCaptionPlace = NULL;
	}
	if (_levelPlace) {
		delete _levelPlace;
		_levelPlace = NULL;
	}
	if (_lifesCaptionPlace) {
		delete _lifesCaptionPlace;
		_lifesCaptionPlace = NULL;
	}
	if (_lifesPlace) {
		delete _lifesPlace;
		_lifesPlace = NULL;
	}
	if (_lifesCaptionPlace) {
		delete _lifesCaptionPlace;
		_lifesCaptionPlace = NULL;
	}
	if (_lifesPlace) {
		delete _lifesPlace;
		_lifesPlace = NULL;
	}
	if (_jetpackCaptionPlace) {
		delete _jetpackCaptionPlace;
		_jetpackCaptionPlace = NULL;
	}
	if (_gunCaptionPlace) {
		delete _gunCaptionPlace;
		_gunCaptionPlace = NULL;
	}
	if (_messagePlace) {
		delete _messagePlace;
		_messagePlace = NULL;
	}

	delete _dave;
}

void Menu::display() 
{
	char buf[BUF_LEN];
	memset(buf,0,BUF_LEN);

	drawMenuItemCaption(_scoreCaptionPlace,_scoreCaption);
	drawMenuItemData(_scorePlace,getScore());
	
	
	drawMenuItemCaption(_levelCaptionPlace,_levelCaption);
	drawMenuItemData(_levelPlace,getLevel());
	
	drawMenuItemCaption(_lifesCaptionPlace,_davesCaption);
	drawLifes();


	if (_controller->getPlayer()->getJetPack())
		drawMenuItemCaption(_jetpackCaptionPlace,_jetpack);

	if (_controller->getPlayer()->getGun())
		drawMenuItemCaption(_gunCaptionPlace,_gun);

	if (_controller->getPlayer()->_gutCup)
		drawMenuItemCaption(_messagePlace,_message);
}

void Menu::drawMenuItemData(Place* place,int number){
	
	int curDigit = 0;
	double base = 10.0;
	int tmp = number;
	int exponent = 0;
	int orderMagnitude;


	while(tmp) {
		tmp/=10;
		exponent++;
	}

	float initialX = place->getX();

	if (number) {
		while(number) {
			orderMagnitude = pow(base,--exponent);
			curDigit = number / orderMagnitude ;
			number = number - curDigit*orderMagnitude ;
			drawMenuItemCaption(place,_digitMap[curDigit]);
			place->moveX(20,1);
		}
	}
	else
		drawMenuItemCaption(place,_digitMap[0]);

	place->setX(initialX);
	
}

void Menu::drawMenuItemCaption(Place* place,Image* caption){

	glRasterPos2d(place->getX(),place->getY());
	caption->Draw();

}
int Menu::getScore() {
	

	return _controller->getPlayer()->getScore();
}

int Menu::getLevel() {

	return _controller->getLevelNumber();
}

void Menu::drawLifes() 
{
	int numLifes = _controller->getPlayer()->getLife();

	float initialX = _lifesPlace->getX();

	for (int i = 0; i < numLifes;++i) {

		drawMenuItemCaption(_lifesPlace,_dave);

		_lifesPlace->moveX(40,1);
	}
	
	_lifesPlace->setX(initialX);
}