// #include "SomeObject.h"
// #include "Image.h"
// 
// SomeObject::SomeObject(char* imageName) : _transX(0), _transY(0), _direction(NONE)  {
// 
// 	_image = new Image();
// 	_image->Load(imageName);
// 	string logFileName = imageName;
// 	logFileName+=".log";
// 	fopen_s(&_logFile,logFileName.c_str(),"w+");
// 	fprintf(_logFile ,"SomeObject::SomeObject transX=%d,transy=%d\n",_transX,_transY);
// }
// 
// SomeObject::~SomeObject() {
// 
// 	_image->Release();
// 
// 	fclose(_logFile);
// 
// 	delete _image;
// }
// 
// void SomeObject::move(){
// 	switch(_direction) {
// 		case LEFT:
// 			addTransX(-DELTA); 
// 			break ;
// 		case RIGHT:			
// 			addTransX(DELTA);			
// 			break ;
// 		case UP:
// 			addTransY(DELTA); 			
// 			break ;
// 		case DOWN:
// 			addTransY(-DELTA); 			
// 			break ;
// 		default:
// 			break;
//       }
// }
// 
// double SomeObject::getTransX() {
// 	return _transX;
// }
// 
// double SomeObject::getTransY() {
// 	return _transY;
// }
// 
// void SomeObject::addTransX(double x) {
// 	_transX+=x;
// 	normalizeCoordinate(_transX);
// 	fprintf(_logFile,"SomeObject::addTransx transX=%f,transy=%f\n",_transX,_transY);
// }
// 
// void SomeObject::addTransY(double y) {
// 	_transY+=y;
// 	normalizeCoordinate(_transY);
// 	fprintf(_logFile,"SomeObject::addTransY transX=%f,transy=%f\n",_transX,_transY);
// }
// 
// 
// 
// void SomeObject::setDirection(direction dir){
// 	_direction = dir;
// }
// 
// void SomeObject::display() {
// 	
// 	// Drawing the objects
// 	double x = getTransX();
// 	double y = getTransY();
// 
// 
// 	fprintf(_logFile,"SomeObject::display  x=%f,y=%f\n",x,y);
// 	glRasterPos2d(x,y);
// 
// 	_image->Draw();
// 
// }	
// 
// 
// void SomeObject::keyboard(unsigned char key, int x, int y) {
// 	switch(key) {
// 		case 'l':
// 			setDirection(LEFT); 
// 			break ;
// 		case 'r':
// 			setDirection(RIGHT); 
// 			break ;
// 		case 'u':
// 			setDirection(UP); 
// 			break ;
// 		case 'd':
// 			setDirection(DOWN); 
// 			break ;
// 		default:
// 			setDirection(NONE);
// 			break;
//       }
// }
// 
// void SomeObject::normalizeCoordinate(double& coor) {
// 	if (coor > 1)
// 		coor = 0.9;
// 	if (coor<-1)
// 		coor=-0.9;
// }