#pragma once

#include "Display.h"
#include <map>

using std::map;

class Controler;
class Image;

class Menu : public Display{
public:
	Menu (float xPlace,float yPlace);
	virtual ~Menu();
	virtual HitResult setHit(){return HitResult(getName(),1);};
	virtual void display();
	void setController(Controler*  controller){_controller=controller;};
private:
	void drawMenuItemData(Place* place,int data);
	void drawMenuItemCaption(Place* place,Image* caption);
	void drawLifes();
	int getScore();
	int getLevel();
	int getLifes();
private:
	Controler* _controller;
	Image*		_dave;
	Image*		_scoreCaption;
	Image*		_davesCaption;
	Image*		_levelCaption;
	Image*		_jetpack;
	Image*		_gun;
	Image*		_message;

	map<int,Image*> _digitMap;
	Place*	    _scoreCaptionPlace;
	Place*	    _scorePlace;
	Place*		_levelCaptionPlace;
	Place*	    _levelPlace;
	Place*		_lifesCaptionPlace;
	Place*		_lifesPlace;
	Place*		_jetpackCaptionPlace;
	Place*		_gunCaptionPlace;
	Place*		_messagePlace;
};