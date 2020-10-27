#pragma once
#ifndef I_COMPARABLE_H
#define I_COMPARABLE_H
#include <string>
#include "IObject.h"

using namespace std;
class IComparable : virtual public IObject{
public:
	IComparable();
	virtual ~IComparable();
	virtual int CompareTo(IComparable* obj) const = 0;
};
#endif // !I_COMPARABLE.H