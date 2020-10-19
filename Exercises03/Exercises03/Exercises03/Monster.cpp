#include "Monster.h"

void Monster::SetHp(int hp)
{
    this->hp = hp;
}

void Monster::SetMaxHp(int maxHp)
{
    this->maxHp = maxHp;
}

int Monster::GetHp() const
{
    return hp;
}

int Monster::GetMaxHp() const
{
    return maxHp;
}
