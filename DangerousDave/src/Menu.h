#pragma once

#include "Display.h"
#include <map>

using std::map;

class Controler;
class Image;


#define IMG_MAP_ENTRY(KEY,FILE) pair<int,SmartPtr<Image>>(KEY,SmartPtr<Image>(new Image(FILE)))
#define PLC_MAP_ENTRY(KEY,X,Y)  pair<int,SmartPtr<Place>>(KEY,SmartPtr<Place>(new Place(X ,Y)))


typedef enum IMAGE_ID_E {
	ZERO_DIGIT,ONE_DIGIT,TWO_DIGIT,THREE_DIGIT,FOUR_DIGIT,FIVE_DIGIT,
	SIX_DIGIT,SEVEN_DIGIT,EIGHT_DIGIT,NINE_DIGIT,
	DAVE,DAVES,SCORE,LEVEL,JETPACK,GUN,MSG_ID,
	SCORE_CAPTION,LEVEL_CAPTION
} IMAGE_ID;

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

	map<int,SmartPtr<Image>> _imageMap;
	map<int,SmartPtr<Place>> _placeMap;

};