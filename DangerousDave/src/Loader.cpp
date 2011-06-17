#include "davepch.h"
#include "Loader.h"
#include "Prize.h"

Loader :: Loader(){

	//stills -start
	
	_objInfoMap.insert(OBJ_MAP_ENTRY(WALL)); 
	_objInfoMap.insert(OBJ_MAP_ENTRY(PIPE)); 
	_objInfoMap.insert(OBJ_MAP_ENTRY(DOOR)); 
	_objInfoMap.insert(OBJ_MAP_ENTRY(SOIL)); 
	
	//stills -end

	//prizes -start
	_objInfoMap.insert(OBJ_MAP_ENTRY(JP)); 
	_objInfoMap.insert(OBJ_MAP_ENTRY(DIAMOND)); 
	_objInfoMap.insert(OBJ_MAP_ENTRY(PERL)); 
	_objInfoMap.insert(OBJ_MAP_ENTRY(GUN)); 
	_objInfoMap.insert(OBJ_MAP_ENTRY(CUP)); 
	//prizes -end
}
//--------------------
void Loader ::loadLevel(const char * levelPath){

	_stillObj.clear();

	_levelFile.open(levelPath);

	if (_levelFile.is_open()) {
		parseFile();
		_levelFile.close();
	}else
		cout<<"Failed to open level file:" << levelPath << endl;
}
//-----------------------------
void Loader::parseFile(){

	string  objSymble;
	//----------------
	int row=START;
	int col =START;
	//-------------
	double xPos,yPos=0;

	while(!_levelFile.eof()){

		getline(_levelFile,objSymble);
		for(col=START; col<objSymble.length() ; col++){
			
			xPos = MAP_FACTOR * col;
			yPos = SCREEN_HEIGHT - MAP_FACTOR * row;
			char curSymbol = objSymble[col];
			
			ObjInfoHandle objInfo = _objInfoMap[curSymbol];

			switch(curSymbol){
				case WALL :
					objInfo->_value = yPos;
				case PIPE :
				case SOIL :
				case DOOR:
				    _stillObj.push_back(new Display (objInfo,xPos,yPos));
					break;
				case DIAMOND :
				case PERL:
				case JP:
				case CUP:
				case GUN :
				    _stillObj.push_back(new Prize (objInfo,xPos,yPos));
					break;
					//-----
					//===========move========================//
				case PLAYER:
					_playerStart=Place(xPos,yPos);
					break;
				case ENEMY :
					_enemys.push_back( new Enemy (xPos,yPos));
					break;
			}//switch

		}//for
		row++;

	}

}
//----------------------------------------
Loader ::~Loader(){

	if (_levelFile.is_open()){

		_stillObj.clear();

		_levelFile.close();
	}
}
