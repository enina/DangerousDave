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
	while(!_levelFile.eof()){

		getline(_levelFile,objSymble);
		for(col=START; col<objSymble.length() ; col++){

			switch(objSymble[col]){

				case WALL :
					_stillObj.push_back( (new Wall ((MAP_FACTOR * col),
						(SCREEN_HEIGHT - MAP_FACTOR * row))));
					break;
					//----
				case PERL :
					_stillObj.push_back(new Perl ((MAP_FACTOR * col),
						(SCREEN_HEIGHT - MAP_FACTOR * row)));
					break;
					//----
				case DIAMOND :
					_stillObj.push_back(new Diamond ((MAP_FACTOR * col),
						(SCREEN_HEIGHT - MAP_FACTOR * row)));
					break;
					//-----
				case PLAYER:
					_playerStart=Place((MAP_FACTOR * col),(SCREEN_HEIGHT - MAP_FACTOR * row));
					break;
					//-----
				case JET_PACK :
					_stillObj.push_back(new JetPack (MAP_FACTOR * col,
						SCREEN_HEIGHT - MAP_FACTOR * row));
					break;
					//------
				case DOOR :
					_stillObj.push_back(new Door (MAP_FACTOR * col,
						SCREEN_HEIGHT - MAP_FACTOR * row));
					break;
					//------

				case PIPE :
					_stillObj.push_back( new Pipe (MAP_FACTOR * col,
						SCREEN_HEIGHT - MAP_FACTOR * row));
					break;
					//------
				case SOIL :
					_stillObj.push_back( new Soil_bg (MAP_FACTOR * col,
						SCREEN_HEIGHT - MAP_FACTOR * row));
					break;
					//------
				case CUP :
					_stillObj.push_back( new Cup(MAP_FACTOR * col,
						SCREEN_HEIGHT - MAP_FACTOR * row));
					break;
					//------
				case GUN :
					_stillObj.push_back( new Gun(MAP_FACTOR * col,
						SCREEN_HEIGHT - MAP_FACTOR * row));
					break;
					//===========move========================//
				case ENEMY :
					_moveObj.push_back( new Enemy (MAP_FACTOR * col,
						SCREEN_HEIGHT - MAP_FACTOR * row));
					break;
			}//swithch


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