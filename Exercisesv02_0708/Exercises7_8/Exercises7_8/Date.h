#pragma once
#ifndef DATE_H
#define DATE_H

struct Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	~Date();
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend std::istream& operator>>(std::istream& is, Date& date);
};

#endif // DATE_H