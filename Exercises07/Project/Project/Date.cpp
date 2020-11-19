#include "Date.h"



Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 1;
}

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date()
{
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.day << "." << date.month << "." << date.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& date)
{
    is >> date.day >> date.month >> date.year;
    return is;
}
