#pragma once
#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H
#include "Object.h"
class MovingObject : virtual public Object {

private:
	double angleOfRotation;
public:
	MovingObject(int id, double angleOfRotation);
	void SetAngleOfRotation(double angle);
	double GetAngleOfRotation() const;
};
#endif // !MOVING_OBJECT_H
