#include "davepch.h"
#include "Player.h"




Player::Player (float xplace,float yplace):Move( xplace, yplace) {

	_className = "Player";
	_hasJetpack = false;
	_movingY = NONE;
	_movingX= NONE;
	_jumping=NO_JUMP;
	_gravety =true;
	_gutCup = false;
	_score = 0;
	_life=3;
	JP_fule = 0;
	_gun = false;

	restDirections();

	vector<const char*> filenames;

	/*0*/filenames.insert(filenames.end(),JAMP_LEFT_PATH);   
	/*1*/filenames.insert(filenames.end(),JETPAK_RIGHT_PATH);
	/*2*/filenames.insert(filenames.end(),JETPAK_LEFT_PATH);
	/*3*/filenames.insert(filenames.end(),JAMP_RIGHT_PATH);
	/*4*/filenames.insert(filenames.end(),PLAYER_STEND_LEFT_PATH);
	/*5*/filenames.insert(filenames.end(),PLAYER_WALK_LEFT_PATH);
	/*6*/filenames.insert(filenames.end(),PLAYER_STEND_RIGHT_PATH);
	/*7*/filenames.insert(filenames.end(),PLAYER_WALK_RIGHT_PATH);
	/*8*/filenames.insert(filenames.end(),PLAYER_STEND_STRAIGHT_PATH);

	_imageIndex = PLAYER_STEND_STRAIGHT;
	

	init(filenames);

}
//------------------
Player::~Player () {
}
//-------------------
void Player :: restDirections(){

	for(int i = START ;i <DIRECTIONS;i++){
		_validDirections[i]=true;
	}
}
//-----------------------
Place Player :: getNextPlace(){

	float nextX = _place.getX();
	float nextY = _place.getY();
	//------------------------
	if(getX_Direction() == RIGHT){

		nextX+=DELTA_X;
	}
	//----
	if(getX_Direction() == LEFT){

		nextX-=DELTA_X;
	}
	//==
	if(getY_Direction()== DOWN){

		nextY-=DELTA_Y;
	}
	//--
	if(getY_Direction()== UP){

		nextY+=DELTA_Y;
	}
	//--
	return(Place(nextX,nextY));
}

//---------------------
void Player::setJump(){

	setDirection(UP);

	if(_jumping == NO_JUMP&&!_validDirections[Down_t]){	
		_jumping=START;
	}
}
//----------------------
void Player::activeJetPack() {

	if(JP_fule<=START&&!_hasJetpack){
		return;
	}
	_jumping = NO_JUMP;
	_hasJetpack = !_hasJetpack ;

	if(_hasJetpack){
		_gravety=false;
	}
	else{
		_gravety=true;
		_imageIndex=PLAYER_STEND_STRAIGHT;
	}
}
//--------------
int Player::getImageIdx()  {
	
	if(_hasJetpack){
		if(getX_Direction()==LEFT){

			_imageIndex= JETPAK_LEFT;
		}
		else{
			_imageIndex= JETPAK_RIGHT;
		}
	
		JP_fule--;
		if(JP_fule<= START){
			activeJetPack();
		}
	}
	return _imageIndex;
}
//-------------------------------
void Player ::move(){

	bool jump=false;
	//-----------
	if(!_validDirections[Up_t]){//||!_validDirections[Down_t]){

		_jumping=NO_JUMP;
		setDirection(DOWN);
	}

	//----
	if (_jumping!=NO_JUMP && !_hasJetpack){
		jump =true;
		//-----
		if(_jumping<JUMP_MAX){
			_jumping++;
			setDirection(UP);
		}
		else{
			_jumping++;
			if(_jumping>2*JUMP_MAX){
				_jumping=NO_JUMP;
				jump =false;
				setDirection(NONE);
			}
			setDirection(DOWN);
		}
		//=======
		if (getX_Direction() == LEFT){
			_imageIndex=JAMP_LEFT;
		}
		else {
			_imageIndex=JAMP_RIGHT;
		}
	}
	if(getX_Direction() == NONE||(!jump &&(_imageIndex==JAMP_RIGHT||_imageIndex==JAMP_LEFT))) {
		_imageIndex=PLAYER_STEND_STRAIGHT;
	}
	//---------------------------------------
	if(!_validDirections[Up_t] &&_movingY == UP){ 
		_movingY=NONE;
	}
	if (!_validDirections[Down_t]&&_movingY==DOWN){
		_movingY=NONE;
	}
	//--
	if(!_validDirections[Left_t] &&_movingX == LEFT){
		_movingX=NONE;
	}
	if(!_validDirections[Right_t] && _movingX==RIGHT){
		_movingX=NONE;
	}
//===================
	Move::move();
//===================
	if(!jump){
		//===========
		if(_movingX !=NONE && getX_Direction() == LEFT){

			if(_imageIndex==PLAYER_STEND_LEFT){
				_imageIndex=PLAYER_WALK_LEFT;
			}
			else{
				_imageIndex=PLAYER_STEND_LEFT;
			}

		}
		else if (_movingX !=NONE && getX_Direction() == RIGHT){

			if(_imageIndex==PLAYER_STEND_RIGHT){
				_imageIndex=PLAYER_WALK_RIGHT;
			}
			else{
				_imageIndex=PLAYER_STEND_RIGHT;
			}
		}
	}
	//================
	if(_gravety ){
		setDirection(DOWN);
	}
	//--
	_movingX = NONE;
	//-----------
	if(_hasJetpack){

		_movingY=NONE;;			
	}

}

void Player::kill() {
	_alive = false;
}

bool Player::isAlive() {
	return _alive ;
}

bool Player::resurrect() {
	if (_life) {
		_life--;
		_alive = true;
	}
	return isAlive();
}