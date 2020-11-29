#pragma once
#ifndef I_OBJECT_H
#define I_OBJECT_H
#include <string>

using namespace std;


class IObject {
private:
public:
	virtual ~IObject();
	virtual string ToString() const = 0;
};
#endif // !I_OBJECT.H