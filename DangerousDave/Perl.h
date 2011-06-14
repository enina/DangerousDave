#pragma once 
#include "Prize.h"
//----------------
#define PERL_VAL 50
//---------------
class Perl: public Prize {

public:
	Perl(float xplace,float yplace);

private:

	static Image _image;
};
//------------------
#define PERL_IMAGE "graphix/world/perl.tga"