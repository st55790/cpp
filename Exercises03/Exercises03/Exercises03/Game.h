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
	void AddObject(Object* object); //Vloží objekt do pole.
	int* FindIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax); //Vrátí pole id všech statických objektù v zadaných souøadnicích.
	MovingObject** FindMovingObjectInArea(double x, double y, double r); //Vrátí pole ukazelù na pohyblivé objekty v kruhové oblasti (S=[x,y],radius = r).
	MovingObject** FindMovingObjectInArea(double x, double y, double r, double umin, double umax); //Viz pøedchozí, navíc kontrola úhlu natoèení.
};

#endif // !GAME_H

