#pragma once
#ifndef MONSTER_H
#define MONSTER_H
#include "MovingObject.h"
class Monster : virtual public MovingObject {

private:
	int hp;
	int maxHp;
public:
	void SetHp(int hp);
	void SetMaxHp(int maxHp);
	int GetHp() const;
	int GetMaxHp() const;
};
#endif // !MONSTER_H
