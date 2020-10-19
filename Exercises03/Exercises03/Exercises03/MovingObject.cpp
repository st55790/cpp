#include "MovingObject.h"

MovingObject::MovingObject(int id, double angleOfRotation) : Object(id)
{
    this->angleOfRotation = angleOfRotation;
}

void MovingObject::SetAngleOfRotation(double angle)
{
    this->angleOfRotation = angle;
}

double MovingObject::GetAngleOfRotation() const
{
    return angleOfRotation;
}
