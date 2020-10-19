#pragma once
#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "Object.h"
#include "TypeOfObstacle.h"
class StaticObject : virtual public Object{

private:
	TypeOfObstacle typeOfObstacle;
public:
	StaticObject(int id, TypeOfObstacle typeOfObstacle);
	TypeOfObstacle GetTypeOfOBstacle() const;
	
};
#endif // !STATIC_OBJECT_H
