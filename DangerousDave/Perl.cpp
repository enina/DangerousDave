#include "Perl.h"

Image Perl :: _image(PERL_IMAGE); 
//-----------
Perl::Perl(float xplace,float yplace):Prize(xplace,yplace,PERL_VAL){

	_className ="Perl";
	Still::_image=&_image;
}