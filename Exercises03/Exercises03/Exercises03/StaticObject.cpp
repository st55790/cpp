#include "StaticObject.h"

StaticObject::StaticObject(int id, TypeOfObstacle typeOfObstacle) : Object(id)
{
    this->typeOfObstacle = typeOfObstacle;
}

TypeOfObstacle StaticObject::GetTypeOfOBstacle() const
{
    return typeOfObstacle;
}
