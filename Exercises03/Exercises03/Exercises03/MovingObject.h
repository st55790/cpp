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
	double GetAngleOfRotation() const; //od:0 – do:2*π, 0 – sever, π/2 - vychod, π - jih, 3π/2 - zapad
};
#endif // !MOVING_OBJECT_H
