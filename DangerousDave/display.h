
#pragma once
#include "macros.h"
#include "Place.h"
#include <string>

using std::string;


//-------------------------
typedef pair <string,int> hitRet_t;//return value to update flags (value name,second=value to set)
//level will get this and put it a map
//-------------------------
class Display {
	public:
		Display (float xPlace,float yPlace);
		
		virtual const Place getPlace(){return _place;};
		virtual hitRet_t setHit()=0; //set valid false nothing to return 
		virtual string getName(){return _className;};
		virtual bool isValid (){return _valid;}; // tell if need to free instase
		virtual void display()=0 ;
		virtual void glide(int dir){_place.moveX(dir);};

	protected:
		bool _valid; 
		Place _place;
		string _className;
};