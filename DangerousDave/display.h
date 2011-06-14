
#pragma once
#include "macros.h"
#include "Place.h"
#include <string>

using std::string;

class Place;

class Display {
	public:
		Display (float xPlace,float yPlace);
		
		virtual const Place getPlace(){return _place;};
		//virtual void sideFlow(int direction);
		virtual string getName(){return _className;};

		virtual void display()=0 ;

	protected:
		Place _place;
		string _className;
};