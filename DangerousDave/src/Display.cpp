#include "davepch.h"
# include "display.h"

Display::Display(float xplace,float yPlace):_place(xplace,yPlace) {
	init("Display");
}
Display::Display( ObjInfoHandle infoHandle,float xplace,float yPlace):_place(xplace,yPlace){
	init(infoHandle->_name,infoHandle->_imageName,infoHandle->_value);
}
Display::~Display() {
	if (_image)
		delete _image;
}

void Display ::init(const char* objName,const char* imageFileName,int objValue) {
	_className=objName;
	_objValue = objValue;
	_valid =true;
	if (imageFileName)
		_image = new Image(imageFileName);
	else
		_image = NULL;
}
void Display::display(){
	if (_image) {
		glRasterPos2d(_place.getX(),_place.getY());
		_image->Draw();
	}
}