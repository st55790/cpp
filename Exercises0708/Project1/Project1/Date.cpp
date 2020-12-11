#include "Date.h"

Date::Date()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
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
    os << " dateOfBirthday: " << date.day << "." << date.month << "." << date.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& date)
{
    is >> date.day >> date.month >> date.year;
    return is;
}
