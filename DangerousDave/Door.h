#pragma once

#include "Keys.h"

class Door :public Keys {

public:
	Door(float xplace ,float yplace);
	virtual hitRet_t setHit();
private:
	static Image _image;

};
//-----------------------
#define  DOOR_IMAGE "graphix/world/door.tga"