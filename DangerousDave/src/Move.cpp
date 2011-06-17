#include "davepch.h"
#include "Move.h"


//============================================================================

Move::Move(float Xplace,float Yplace): Display( Xplace,Yplace) {
	_className = "Move";
	_xDirection = NONE;
		_yDirection= NONE;
}

//============================================================================

Move::~Move(){
	for(size_t i = 0;i < _images.size();++i) {
		delete _images[i];
	}
	_images.clear();
}

//============================================================================

void Move::init(vector<const char*>& filenames) {

	Image* image = NULL;

	for(size_t i = 0;i < filenames.size();++i) {
		image = new Image(filenames[i]);
		_images.insert(_images.end(),image);
	}
}

//============================================================================

void Move::setDirection(direction dir){

	//---------------------
	if(dir== NONE){
		_movingX=NONE;
		_movingY = NONE;

		_xDirection=dir;
		_yDirection=dir;
		return;
	}

	if (dir == DOWN|| dir == UP){
		_movingY = dir;
		_yDirection=dir;
	}
	else{
		_movingX = dir; 
		_xDirection=dir;
	}

}

//============================================================================
void Move::move(){

	if(_movingY != NONE ){
		switch(_yDirection) {

		case UP:
			addTransY(DELTA_Y); 			
			break ;
		case DOWN:
			addTransY(-DELTA_Y); 			
			break ;
		}
	}
	//---
	if(_movingX != NONE ){
		switch(_xDirection) {
		case LEFT:
			addTransX((-DELTA_X)); 
			break ;
		case RIGHT:			
			addTransX(DELTA_X);			
			break ;
		}
	}
}
//============================================================================
void Move::display(){

	Image* curImage = NULL;
	int imageIdx = getImageIdx();
	glRasterPos2d(_place.getX(),_place.getY());
	curImage = _images[imageIdx];
	curImage->Draw();

}
//============================================================================
double Move::getTransX() {
	return _place.getX();
}
//============================================================================
double Move::getTransY() {
	return _place.getY();
}
//============================================================================
void Move::addTransX(double x) {

	_place.moveVector(x,START);

}
//============================================================================
void Move::addTransY(double y) {

	_place.moveVector(START,y);
}
//============================================================================


//============================================================================