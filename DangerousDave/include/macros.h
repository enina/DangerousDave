#pragma once

#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <map>
#include <list>


#include "SmartPtr.h"

using  std::map ;
using  std::multimap;
using  std::pair ;
using  std::list ;
using  std::string;
using  std::iterator;
using  std::cout;
using  std::endl;
using  std::ifstream;

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

typedef struct ObjectInfo_s {
	ObjectInfo_s(	const char* name,const char* imageName,int value) {
		_name = name;
		_imageName = imageName;
		_value = value;
	}

	const char* _name;
	const char* _imageName;
	int		    _value;
} ObjectInfo;

typedef SmartPtr<ObjectInfo> ObjInfoHandle;
