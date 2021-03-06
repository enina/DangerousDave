#include "davepch.h"
#include "Place.h"

//----------------
//************************************
// Method:    constructor
// FullName:  Place::Place
// Access:    public  
// place in the wrold
// Parameter: float x
// Parameter: float y
//************************************
Place::Place (float  x,float y):_x(x),_y(y){

}
//---------------------------------
//************************************
// Method:    moveX
// FullName:  Place::moveX
// Access:    public 
// allow to move only x without go 
// of the SCREEN_WIDTH as defined in macros
// Parameter: float moveFactor : how much to move
// Parameter: float sizeFactor : obj size
//************************************
void Place::moveX(float moveFactor,float sizeFactor){
	_x+=moveFactor;
	return;
}
//--------------------
//************************************
// Method:    moveX
// FullName:  Place::moveY
// Access:    public 
// allow to move only y without go 
// of the SCREEN_HEIGHT as difined in macros
// Parameter: float moveFactor : how much to move
// Parameter: float sizeFactor : obj size
//************************************
void Place::moveY(float moveFactor,float sizeFactor){
	if (_y+moveFactor + sizeFactor >=SCREEN_HEIGHT)
	{
		return;
	}

	_y+=moveFactor;
	return;
}
//-------------------------------------------

//************************************
// Method:    moveVector
// FullName:  Place::moveVector
// Access:    public 
// allow to move the place modulu 
// world size as difined in macros
// Parameter: float xFactor
// Parameter: float yFactor
//************************************
void Place :: moveVector(float xFactor ,float yFactor ){
	
	for(_x += xFactor ;_x > SCREEN_WIDTH;_x -= SCREEN_WIDTH);//% with doubles

	for(_y += yFactor ;_y > SCREEN_HEIGHT;_y-=SCREEN_HEIGHT);//% with doubles

}
//--------------------------------------------
//************************************
// Method:    operator==
// FullName:  Place::operator==
// Access:    public 
// Returns:   true if same place
// Parameter: const Place & oter
//************************************
bool Place :: operator == (const Place& oter ){
	
	bool eqX ,eqY;
	
	eqX =(_x <= oter._x+DEFULT_FACTOR && _x >= oter._x-DEFULT_FACTOR);

	eqY =(_y <= oter._y+DEFULT_FACTOR && _y >= oter._y-DEFULT_FACTOR);

	return (eqX && eqY);
}
//------------------------------------------
//************************************
// Method:    operator!=
// FullName:  Place::operator!=
// Access:    public 
// Returns:   false if same place
// Parameter: const Place & oter
//************************************
bool Place :: operator != (const Place& oter ){

	return (!(*this == oter));
}
//-----------------------------------------
//************************************
// Method:    facEq
// FullName:  Place::facEq
// Access:    public
// allow us to tell if two places are ABOUT the same
// Returns:   true if two places are ABOUT the same
// Parameter: const Place & other : other place
// Parameter: float factor acurecy factor
//************************************
bool Place :: facEq (const Place& other,float factor){

	bool xResult = false;
	bool yResult = false;
	//-----------
	if ((other._x > _x-factor)&& (other._x < _x+factor))
	{
		xResult=true;
	}
	//---
	if ((other._y > _y-factor)&& (other._y < _y+factor))
	{
		yResult=true;
	}

	return ( yResult && xResult);
}
//-----------------------------------------
bool Place :: facXYEq(const Place& oter,float xfactor,float yfactor){

	bool xResult = false;
	bool yResult = false;
	//-----------
	if ((oter._x > _x-xfactor)&& (oter._x < _x+xfactor))
	{
		xResult=true;
	}
	//---
	if ((oter._y > _y-yfactor)&& (oter._y < _y+yfactor))
	{
		yResult=true;
	}

	return ( yResult && xResult);
}