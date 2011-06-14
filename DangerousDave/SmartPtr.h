#pragma once

template<class T>
class Wrapper;

//-----------------------------------------------------------------------------
//------------------------------ Class SmartPtr -------------------------------
template<class T>
class SmartPtr 
{
public:
	//constructors
	SmartPtr(): _pWrap(NULL){};
	SmartPtr(T & object):_pWrap(new Wrapper<T> (object)){};
	SmartPtr(T * object):_pWrap(new Wrapper<T> (*object)){};
	//destructor
	~SmartPtr(){free();};
	// Copy constrector:
	SmartPtr(const SmartPtr<T> & other){copy(other);};

	const SmartPtr<T> & operator=(const SmartPtr<T> &);
	//operator ==
	bool  operator==(const SmartPtr<T> & other){return _pWrap==other._pWrap;};
	//operator !=
	bool  operator!=(const SmartPtr<T> & other){return _pWrap!=other._pWrap;};
	//operator *
	T& operator*();
	const T& operator*() const;
	//operator ->
	T* operator->();
	const T* operator->() const;

private:
	void copy(const SmartPtr<T> &);
	void free();
	

	Wrapper<T> * _pWrap;		// The object wrapper.
};
//-------------------------- End of Class SmartPtr ----------------------------

//-----------------------------------------------------------------------------
//------------------------------- Class Wrapper -------------------------------
template<class T>
class Wrapper 
{
friend class SmartPtr<T>;
private:
	Wrapper<T>::Wrapper(T & );

	int		 _counter;
	T	 &	 _obj;		// The object we point on.
};
//--------------------------- End of Class Wrapper ----------------------------
//-----------------------------------------------------------------------------
template<class T>
Wrapper<T>::Wrapper(T& object): _obj(object), _counter(1){};
// SmartPtr Class implementation:
//-----------------------------------------------------------------------------
/*
	implentation of operator =
*/
template<class T>
const SmartPtr<T>& SmartPtr<T>::operator=( const SmartPtr<T> & other ) 
{
	free();
	copy(other);
	return *this;
}
//-----------------------------------------------------------------------------
/*
	implentation of operator *
*/
template<class T>
T& SmartPtr<T>::operator*() 
{
	return _pWrap->_obj;
}
//-----------------------------------------------------------------------------
/*
	implentation of operator *
*/
template<class T>
const T& SmartPtr<T>::operator*() const 
{
	return _pWrap->_obj;
}
//-----------------------------------------------------------------------------
/* 
	implentation of operator ->
*/
template<class T>
T* SmartPtr<T>::operator->() 
{
	return &(_pWrap->_obj);
}
//-----------------------------------------------------------------------------
/*
	implentation of operator ->
*/
template<class T>
const T* SmartPtr<T>::operator->() const 
{
	return &( _pwrap->_obj );
}
//-----------------------------------------------------------------------------
/*
	implentation of copy
*/
template<class T>
void SmartPtr<T>::copy(const SmartPtr<T> & other)
{
	_pWrap = other._pWrap;
	if(_pWrap)
		_pWrap->_counter++;
}
//-----------------------------------------------------------------------------
/*
	implentation of delete. Just when the counter eq to zero the method delete
	_pwrap (oterwise someone still uses the smart pointer).
*/
template<class T>
void SmartPtr<T>::free()
{
	if(_pWrap != NULL)
	{
		_pWrap->_counter--;
		
		if (_pWrap->_counter == 0) 
		{
			delete _pWrap;
		}
	}
}
