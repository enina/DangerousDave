#include "davepch.h"
#include "Menu.h"
#include "Display.h"
#include "Place.h"
#include "Controler.h"
#include "Player.h"

Menu::Menu (float xPlace,float yPlace):Display(xPlace,yPlace)
{
	char fileName[MAX_NUMBER*3];

	_imageMap.insert(IMG_MAP_ENTRY(DAVE,"graphix/menu_bar/head.tga"));
	_imageMap.insert(IMG_MAP_ENTRY(SCORE,"graphix/menu_bar/score.tga"));
	_imageMap.insert(IMG_MAP_ENTRY(LEVEL,"graphix/menu_bar/level.tga"));

	_imageMap.insert(IMG_MAP_ENTRY(DAVES,"graphix/menu_bar/daves.tga"));
	_imageMap.insert(IMG_MAP_ENTRY(JETPACK,"graphix/menu_bar/jetpack.tga"));
	_imageMap.insert(IMG_MAP_ENTRY(GUN,"graphix/menu_bar/gun.tga"));
	_imageMap.insert(IMG_MAP_ENTRY(MSG_ID,"graphix/menu_bar/message.tga"));

	for(int i =0;i < 10;++i) {
		memset(fileName,MAX_NUMBER*3,0);
		sprintf_s(fileName,MAX_NUMBER*3,"graphix/menu_bar/number_%d.tga",i);
		_imageMap.insert(IMG_MAP_ENTRY(i,fileName));
	}

	_placeMap.insert(PLC_MAP_ENTRY(SCORE_CAPTION,60,655));
	_placeMap.insert(PLC_MAP_ENTRY(SCORE,280,655));

	_placeMap.insert(PLC_MAP_ENTRY(LEVEL_CAPTION,450,655));
	_placeMap.insert(PLC_MAP_ENTRY(LEVEL,670,655));

	_placeMap.insert(PLC_MAP_ENTRY(DAVES,800,655));
	_placeMap.insert(PLC_MAP_ENTRY(DAVE,1000,655));

	_placeMap.insert(PLC_MAP_ENTRY(JETPACK,60,0));
	_placeMap.insert(PLC_MAP_ENTRY(GUN,950,0));
	_placeMap.insert(PLC_MAP_ENTRY(MSG_ID,450,0));


}


Menu::~Menu() {
	
	_placeMap.clear();
	_imageMap.clear();
}

void Menu::display() 
{
	char buf[BUF_LEN];
	memset(buf,0,BUF_LEN);

	drawMenuItemCaption(_placeMap[SCORE_CAPTION].operator ->(),_imageMap[SCORE].operator ->());
	drawMenuItemData(_placeMap[SCORE].operator ->(),getScore());
	
	
	drawMenuItemCaption(_placeMap[LEVEL_CAPTION].operator ->(),_imageMap[LEVEL].operator->());
	drawMenuItemData(_placeMap[LEVEL].operator ->(),getLevel());
	
	drawMenuItemCaption(_placeMap[DAVES].operator ->(),_imageMap[DAVES].operator->());
	drawLifes();


	if (_controller->getPlayer()->getJetPack())
		drawMenuItemCaption(_placeMap[JETPACK].operator ->(),_imageMap[JETPACK].operator ->());

	if (_controller->getPlayer()->getGun())
		drawMenuItemCaption(_placeMap[GUN].operator ->(),_imageMap[GUN].operator ->());

	if (_controller->getPlayer()->_gutCup)
		drawMenuItemCaption(_placeMap[MSG_ID].operator ->(),_imageMap[MSG_ID].operator ->());
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
			drawMenuItemCaption(place,_imageMap[curDigit].operator->());
			place->moveX(20,1);
		}
	}
	else
		drawMenuItemCaption(place,_imageMap[ZERO_DIGIT].operator->());

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

	SmartPtr<Place> lifePlace = _placeMap[DAVE];

	float initialX = lifePlace->getX();

	for (int i = 0; i < numLifes;++i) {

		drawMenuItemCaption(lifePlace.operator ->(),_imageMap[DAVE].operator->());

		lifePlace->moveX(40,1);
	}
	
	lifePlace->setX(initialX);
}