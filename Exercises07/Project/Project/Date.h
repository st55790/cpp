#pragma once
#ifndef DATE_H
#define DATE_H
#include <istream>

class Date {
public:
	Date();
	Date(int day, int month, int year);
	~Date();
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend std::istream& operator>>(std::istream& is,Date& date);
private:
	int day;
	int month;
	int year;
};
#endif // !DATE_H
