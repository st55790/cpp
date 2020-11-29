#pragma once
#ifndef TIME_H
#define TIME_H
#include "IComparable.h"
class Time :  public IComparable{

private:
	int _Hours;
	int _Minutes;
	int _Seconds; 
public:
	Time();
	~Time();
	Time(int hours, int minutes, int seconds);
	int CompareTo(IComparable* obj) const override; 
	string ToString() const; 
};
#endif // !TIME_H
