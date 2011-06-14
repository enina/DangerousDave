#include "Cup.h"
//---------------------
Image Cup :: _image(CUP_IMAGE); 
//----------------------------

Cup::Cup(float xplace,float yplace):Keys(xplace,yplace){
	_className ="Cup";
	Still::_image=&_image;
}
//-----------------------------