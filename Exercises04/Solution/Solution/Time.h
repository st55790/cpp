#pragma once
#ifndef TIME_H
#define TIME_H
#include "IComparable.h"
class Time : public IComparable{

private:
	int _Hours; //0-23
	int _Minutes; //0-59
	int _Seconds; //0-59
public:
	Time(int hours, int minutes, int seconds);
	int CompareTo(IComparable* obj) const override; 
	string ToString() const override; 
};
#endif // !TIME_H
