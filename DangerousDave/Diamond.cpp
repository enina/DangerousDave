#include "Diamond.h"

Image Diamond :: _image(DIAMOND_IMAGE); 
//-----------
Diamond::Diamond(float xplace,float yplace):Prize(xplace,yplace,DIAMOND_VAL){

	_className ="Diamond";
	Still::_image=&_image;
}