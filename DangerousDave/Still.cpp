#include "davepch.h"
#include "Still.h"
//-------------------

Still::Still(float xplace,float yPlace):Display(xplace,yPlace) {
	init("still");
}

Still ::Still( const char* objName,const char* imageFileName,int objValue,float xplace,float yPlace)
																:Display(xplace,yPlace){
	init(objName,imageFileName,objValue);
}

Still::~Still() {
	if (_image)
		delete _image;
}

void Still ::init(const char* objName,const char* imageFileName,int objValue) {
	_className=objName;
	_objValue = objValue;
	if (imageFileName)
		_image = new Image(imageFileName);
	else
		_image = NULL;
}

//----------------------------
void Still::display(){
	if (_image) {
		glRasterPos2d(_place.getX(),_place.getY());
		_image->Draw();
	}
}