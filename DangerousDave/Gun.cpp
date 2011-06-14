#include "Gun.h"
#include "Image.h"
//---------------
Image Gun :: _image(GUN_IMAGE); 
//-----------
Gun ::Gun(float xplace,float yplace):Keys(xplace,yplace){

	cout<<"Gun constructor \n";
	_className ="Gun";
	Still::_image=&_image;
}
//-------------------