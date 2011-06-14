#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <map>
#include "SmartPtr.h"

using namespace std ;
#pragma warning (disable : 4018)

//==========utils=========//
#define  START 0 
#define  FIRST 1
#define  MAP_FACTOR 55
//===========================
typedef  pair<multimap<string,int>::iterator,multimap<string,int>::iterator> rangeIt;
typedef multimap<string,int>::iterator oneIt;
//===========================
#define SCREEN_HEIGHT 715
#define SCREEN_WIDTH  1210
#define DELTA_X  10
#define DELTA_Y  5
#define NUM_OF_ALL_LEVELS  10
#define BUF_LEN 256
const int MAX_NUMBER = 20;						//max size of file names

//------------------
#define PLAYER_SIZE 50

struct RGB{
	float _r, _g, _b;
};

enum direction {
	UP,DOWN,LEFT,RIGHT,NONE
};