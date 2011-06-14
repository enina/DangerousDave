#pragma  once

#include "Keys.h"

class JetPack : public Keys {

public: 
	JetPack(float xplace,float yplace);

private:
	static Image _image;

};
#define  J_P_IMAGE "graphix/world/jetPack.tga"