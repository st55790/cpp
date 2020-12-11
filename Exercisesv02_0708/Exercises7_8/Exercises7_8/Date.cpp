#include <iostream>
#include "Date.h"
#include <string>
Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date() {}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	return os << date.day << " " << date.month << " " << date.year;
}

std::istream& operator>>(std::istream& is, Date& date) {
	return is >> date.day >> date.month >> date.year;
}