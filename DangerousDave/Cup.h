#pragma  once

#include "Keys.h"
//----------------
class Cup :public Keys {
public:
	Cup (float xplace,float yplace);

private:
	static Image _image ;
};
//---------
#define CUP_IMAGE "graphix/world/cup.tga"