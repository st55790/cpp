#include "Game.h"
#include <iostream>
#include "StaticObject.h"
#include <typeinfo>
#include <string>
#include "Object.h"
using namespace std;

int main() {

	Game* game = new Game();
	
	Object* obj1 = new Object(0);
	Object* obj2 = new Object(1);
	Object* so1 = new StaticObject(2, TypeOfObstacle::BigPlant);
	Object* so2 = new StaticObject(3, TypeOfObstacle::Rock);
	Object* mo1 = new MovingObject(4, 60);
	Object* mo2 = new MovingObject(5, 270);
	game->AddObject(obj1);
	game->AddObject(obj2);
	game->AddObject(so1);
	game->AddObject(so2);
	game->AddObject(mo1);
	game->AddObject(mo2);
	
	cout << "ID Statick objects\n";
	int* arrayIdStaticObjects = game->FindIdOfStaticObjects(-1,1,-1,1);
	for (int i = 0; i <= sizeof(arrayIdStaticObjects)/sizeof(*arrayIdStaticObjects); i++) {
		cout << i << ". prvek ma id->" << arrayIdStaticObjects[i] << "\n";
	}

	cout << "\nID Moving objects in area -1,-1,5\n";
	MovingObject** moArray = game->FindMovingObjectInArea(-1, -1, 5);
	for (int i = 0; i < 2; i++) {
		cout << i << ". prvek ma id->" << moArray[i]->GetId() << "\n";
	}

	cout << "\nID Moving object in area -1,-1,5,61,270\n";
	moArray = game->FindMovingObjectInArea(-1, -1, 5,61,270);
	for (int i = 0; i < 1; i++) {
		cout << i << ". prvek ma id->" << moArray[i]->GetId() << "\n";
	}
	game->~Game();
	delete obj1;
	return 0;
}
