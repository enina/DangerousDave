#pragma  once

#include "Keys.h"

class Gun : public Keys {

public: 
	Gun(float xplace,float yplace);

private:
	static Image _image;

};
#define  GUN_IMAGE "graphix/misc/gun.tga"