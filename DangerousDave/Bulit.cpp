#include "Bulit.h"


Bulit::Bulit  (float xplace,float yplace,direction dir):Move( xplace, yplace) {

	vector<char*> filenames;

	if(dir == LEFT){  
		filenames.insert(filenames.end(),LEFT_BULLET_IMAGE);  
	}
	else{
		filenames.insert(filenames.end(),RIGHT_BULLET_IMAGE); 
	}

	init(filenames);

	setDirection(dir);
}
//--------------------------------------------
void Bulit::move() {
	
	Move::move();

}
