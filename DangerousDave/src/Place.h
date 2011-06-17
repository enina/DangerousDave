#pragma once
#include "macros.h"
//--------------
#define  DEFULT_FACTOR 2

class Place {
public:

	Place (float x=0,float y=0);
	bool operator == (const Place& oter);
	bool operator != (const Place& oter);

	bool facEq(const Place& oter,float factor);
	bool facXYEq(const Place& oter,float xfactor,float yfactor);

	float getX () {return _x;};
	float getY () {return _y;};

	float getX ()const {return _x;};
	float getY ()const {return _y;};

	void moveX (float moveFactor  ,float sizeFactor=0);
	void moveY(float moveFactor,float sizeFactor);
	void moveVector(float xFactor ,float yFactor );

	void setX(double x) {_x=x;};//Not Good
	void setY(double y) {_y=y;};//Not Good
private:
	float _x,  //location in world
		_y;

};