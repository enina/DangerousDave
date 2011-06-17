#include "davepch.h"
#include "Keys.h"
//------------------

Keys::Keys(float xplace,float yplace):Still(xplace,yplace){
	_className="Keys";
}
//---------------
hitRet_t Keys :: setHit(){
	_valid = false;
	return hitRet_t(getName(),GUT_KEY);
};