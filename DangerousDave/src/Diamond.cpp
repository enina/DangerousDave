#include "davepch.h"
#include "Diamond.h"

//-----------
Diamond::Diamond(float xplace,float yplace):Prize(xplace,yplace,DIAMOND_VAL){

	_className ="Diamond";
	_image=new Image(DIAMOND_IMAGE);
}