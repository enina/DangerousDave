#include "JetPack.h"
#include "Image.h"
//---------------
Image JetPack :: _image(J_P_IMAGE); 
//-----------
JetPack::JetPack(float xplace,float yplace):Keys(xplace,yplace){

	_className ="JetPack";
	Still::_image=&_image;
}
//-------------------