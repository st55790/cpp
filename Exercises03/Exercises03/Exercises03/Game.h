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
	void AddObject(Object* object); //Vlo�� objekt do pole.
	int* FindIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax); //Vr�t� pole id v�ech statick�ch objekt� v zadan�ch sou�adnic�ch.
	MovingObject** FindMovingObjectInArea(double x, double y, double r); //Vr�t� pole ukazel� na pohybliv� objekty v kruhov� oblasti (S=[x,y],radius = r).
	MovingObject** FindMovingObjectInArea(double x, double y, double r, double umin, double umax); //Viz p�edchoz�, nav�c kontrola �hlu nato�en�.
};

#endif // !GAME_H

