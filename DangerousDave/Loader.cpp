#include "davepch.h"
#include "Loader.h"

Loader :: Loader(){

	_stillObj.clear();
	//_moveObj.clear();

}
//--------------------
void Loader ::loadLevel(char * levelPath){

	_stillObj.clear();
	//_moveObj.clear();

	_levelFile.open(levelPath);
	// chek open ();
	if (_levelFile.is_open()) {
		parseFile();
		_levelFile.close();
	}else
		cout<<"Failed to open level file:"<<levelPath<<endl;
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
			switch(objSymble[col]){

				case WALL :
					_stillObj.push_back( new Wall (xPos,yPos));
					break;
					//----
				case PERL :
					_stillObj.push_back(new Perl (xPos,yPos));
					break;
					//----
				case DIAMOND :
					_stillObj.push_back(new Diamond (xPos,yPos));
					break;
					//-----
				case PLAYER:
					_playerStart=Place(xPos,yPos);
					break;
					//-----
				case JET_PACK :
					_stillObj.push_back(new JetPack (xPos,yPos));
					break;
					//------
				case DOOR :
					_stillObj.push_back(new Still (DOOR_NAME,DOOR_IMAGE,DOOR_VALUE,xPos,yPos));
					break;
					//------

				case PIPE :
					_stillObj.push_back( new Pipe (xPos,yPos));
					break;
					//------
				case SOIL :
					_stillObj.push_back( new Soil_bg (xPos,yPos));
					break;
					//------
				case CUP :
					_stillObj.push_back( new Cup(MAP_FACTOR * col,
						SCREEN_HEIGHT - MAP_FACTOR * row));
					break;
					//------
				case GUN :
					_stillObj.push_back( new Gun(xPos,yPos));
					break;
					//===========move========================//
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
		//_moveObj.clear();
		_levelFile.close();
	}
}