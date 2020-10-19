#include "Game.h"
#include <exception>
#include <typeinfo>
#include "StaticObject.h"

Game::Game()
{
    objectsArray = new Object * [SIZE];
    objectsCounter = 0;
}

Game::~Game()
{
    delete[] objectsArray;
}

void Game::AddObject(Object* object)
{
    if(objectsCounter < SIZE){
        objectsArray[objectsCounter++] = object;
    }else{
        throw std::exception("Array with objects is full!");
    }
}

int* Game::FindIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax)
{
    int* tmpArray = new int[objectsCounter];
    int idCounter = 0;
    for (int i = 0; i < objectsCounter; i++) {
        if(StaticObject* so = dynamic_cast<StaticObject*>(objectsArray[i])){
            if ((so->GetX() >= xmin && so->GetX() <= xmax) && (so->GetY() >= ymin && so->GetY() <= ymax)){
                tmpArray[idCounter++] = so->GetId();
            }
        }
    }
    return tmpArray;
}

MovingObject** Game::FindMovingObjectInArea(double x, double y, double r)
{
    MovingObject** tmpArray = new MovingObject * [objectsCounter];
    int moCounter = 0;
    for (int i = 0; i < objectsCounter;i++) {
        if (MovingObject* mo = dynamic_cast<MovingObject*>(objectsArray[i])) {
            if ((pow(mo->GetX() - x, 2) + pow(mo->GetY() - y, 2)) < pow(r, 2)) {
                tmpArray[moCounter++] = mo;
            }
        }
    }
    return tmpArray;
}

MovingObject** Game::FindMovingObjectInArea(double x, double y, double r, double umin, double umax)
{
    MovingObject** tmpArray = new MovingObject * [objectsCounter];
    int moCounter = 0;
    for (int i = 0; i < objectsCounter;i++) {
        if (MovingObject* mo = dynamic_cast<MovingObject*>(objectsArray[i])) {
            if ((pow(mo->GetX() - x, 2) + pow(mo->GetY() - y, 2)) < pow(r, 2)) {
                if (mo->GetAngleOfRotation() >= umin && mo->GetAngleOfRotation() <= umax) {
                    tmpArray[moCounter++] = mo;
                }
            }
        }
    }
    return tmpArray;
}

