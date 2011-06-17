
#pragma once
#include "macros.h"
#include "Place.h"
#include <string>

using std::string;


//-------------------------
//return value to update flags (value name,second=value to set)
//level will get this and update the view accordingly
typedef pair <string,int> HitResult;

//-------------------------
class Display {
	public:
		Display (float xPlace,float yPlace);
		Display( ObjInfoHandle infoHandle,float xplace,float yPlace);
		virtual ~Display();	
		virtual const Place getPlace(){return _place;};
		virtual HitResult setHit() {return HitResult(getName(),_objValue);}; 
		virtual string getName(){return _className;};
		virtual bool isValid (){return _valid;}; // tell if need to free instance
		virtual void display() ;
		virtual void glide(int dir){_place.moveX(dir);};

	protected:
		Image* _image;
		bool _valid; 
		Place _place;
		string _className;
		int    _objValue;
	private:
		void init(const char* objName,const char* imageFileName=NULL,int objValue=0) ;

};