#pragma once
#include "macros.h"
#include "display.h"
#include <vector>

class Image;

using std::vector;

class Move : public Display {
	public:
		Move(float Xplace,float Yplace);
		//virtual void setPlace(Place newPlace);

		virtual ~Move ();
		virtual void display();
		virtual void move();
		void setDirection(direction dir);
		virtual HitResult setHit(){return HitResult(getName(),_place.getY());};
		direction getX_Direction() {return _xDirection;};
		direction getY_Direction() {return _yDirection;};
	protected:

		virtual int getImageIdx(){return START;};
		virtual void init(vector<const char*>& filenames);

		direction _movingX,
			_movingY;

protected:
		double getTransX();
		double getTransY();
		void addTransX(double x);
		void addTransY(double y);
		void normalizeCoordinate(double& coor);
		vector<SmartPtr<Image>> _images;
	
protected:

		direction _xDirection,
				_yDirection;
};