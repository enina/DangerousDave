
#include "Prize.h"
//---------------

Prize ::Prize(float xplace,float yplace,int prizeValu):Still(xplace,yplace)
,_value(prizeValu){
	_className = "Prize";
}
//----------------------------------