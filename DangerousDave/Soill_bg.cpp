# include "Soil_bg.h"
#include "Image.h"
//------------------
Image Soil_bg :: _image(SOIL_IMAGE); 

//------------------
Soil_bg::Soil_bg(float xplace,float yplace):Still(xplace,yplace){
	_className ="Soil_bg";
	Still::_image=&_image;
}
//-----------------------------------------------
