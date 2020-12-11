#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Address.h"
#include "Date.h"

struct Person {
public:
	Person();
	Person(std::string name, std::string lastname, Address address, Date date);
	~Person();
	friend std::ostream& operator<<(std::ostream& os, const Person& person);
	friend std::istream& operator>>(std::istream& is, Person& person);
private:
	std::string name;
	std::string lastname;
	Address address;
	Date date;
};

#endif // PERSON_H