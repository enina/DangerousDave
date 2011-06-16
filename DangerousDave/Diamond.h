#pragma once 
#include "Prize.h"
//----------------
#define DIAMOND_VAL 100
//---------------
class Diamond: public Prize {

public:
	Diamond(float xplace,float yplace);
};
//------------------
#define DIAMOND_IMAGE "graphix/world/green_diamand.tga"
