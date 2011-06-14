#pragma once 
#include "Prize.h"
//----------------
#define DIAMOND_VAL 100
//---------------
class Diamond: public Prize {

public:
	Diamond(float xplace,float yplace);

private:

	static Image _image;
};
//------------------
#define DIAMOND_IMAGE "graphix/world/green_diamand.tga"
