#pragma once
#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "MovingObject.h"
#define SIZE 100

class Game {

private:
	Object** objectsArray;
	int objectsCounter;

public:
	Game();
	~Game();
	void AddObject(Object* object);
	int* FindIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax);
	MovingObject** FindMovingObjectInArea(double x, double y, double r);
	MovingObject** FindMovingObjectInArea(double x, double y, double r, double umin, double umax); 
};

#endif // !GAME_H

