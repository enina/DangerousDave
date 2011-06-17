#pragma once
#include "Obstacles.h"


class Pipe : public Obstacles {

public:
	Pipe(float xplace,float yplace);
	virtual hitRet_t setHit(){return hitRet_t("Wall",_place.getY());};//for hit test
private:
	static Image _image ;

};
//-------------------
#define PIPE_IMAGE "graphix/world/Pipeline.tga"