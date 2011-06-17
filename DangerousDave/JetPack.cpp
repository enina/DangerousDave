#include "davepch.h"
#include "JetPack.h"
//---------------
Image JetPack :: _image(J_P_IMAGE); 
//-----------
JetPack::JetPack(float xplace,float yplace):Keys(xplace,yplace){

	cout<<"jet pack constructor \n";
	_className ="JetPack";
	Still::_image=&_image;
}
//-------------------