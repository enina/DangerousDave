#include "davepch.h"
#include "Still.h"
//-------------------

Still ::Still(float xplace,float yPlace):Display(xplace,yPlace){
	_className="Still";
}
//----------------------------
void Still::display(){
	glRasterPos2d(_place.getX(),_place.getY());
	_image->Draw();
}