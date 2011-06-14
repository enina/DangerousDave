#include "Bulit.h"


Bulit::Bulit  (float xplace,float yplace,direction dir):Move( xplace, yplace) {

	vector<char*> filenames;

	if(dir == LEFT){  
		filenames.insert(filenames.end(),BULIT_IMAGE_L);  
	}
	else{
		filenames.insert(filenames.end(),BULIT_IMAGE_R); 
	}

	init(filenames);

	setDirection(dir);
}
//--------------------------------------------
void Bulit::move() {
	
	Move::move();

}
