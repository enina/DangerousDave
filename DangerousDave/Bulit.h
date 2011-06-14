#include "macros.h"
#include "Move.h"

//-------------------------
class Bulit: public Move {
public:
	Bulit  (float xplace,float yplace,direction dir);
	virtual void move();
	void setPlace(Place newPlace){_place = newPlace;};
protected:
	//virtual int getImageIdx(){return _imageIn;};
private:
	//int _imageIn;
};

#define BULIT_IMAGE_R "graphix/world/kadurR.tga"
#define BULIT_IMAGE_L "graphix/world/kadurL.tga"
#define  ENEMY_SIZE 55

