# include "Pipe.h"
#include "Image.h"
//------------------
Image Pipe :: _image(PIPE_IMAGE); 

//------------------
Pipe::Pipe(float xplace,float yplace):Obstacles(xplace,yplace){
	_className ="Pipe";
	Still::_image=&_image;
}
//-----------------------------------------------
