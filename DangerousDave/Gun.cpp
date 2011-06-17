#include "davepch.h"
#include "Gun.h"

//-----------
Gun ::Gun(float xplace,float yplace):Keys(xplace,yplace){

	cout<<"Gun constructor \n";
	_className ="Gun";
	_image= new Image(GUN_IMAGE);
}
//-------------------