#pragma once

#include "macros.h"
#include <string>
#include <fstream>
#include "macros.h"

using namespace std;

class Image;

class SomeObject{
public:
	SomeObject(char* imageName);
	~SomeObject();
	RGB getPixel(int i,int j);
	double getTransX();
	double getTransY();
	void addTransX(double x);
	void addTransY(double y);
	void setDirection(direction dir); 

	void display();
	void keyboard(unsigned char key, int x, int y);
	void move();
private:
	void normalizeCoordinate(double& coor);
	Image* _image;
	// translate values for moving the object
	//(_transX,_transY) is the bottom left corner of the object
	double _transX;
	double _transY;
	direction _direction;
	FILE* _logFile;
};