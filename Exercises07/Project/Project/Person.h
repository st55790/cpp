#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "Address.h"
#include "Date.h"
class Person {
public:
	Person();
	Person(std::string name, std::string lastname, Address address, Date dateOfBirthday);
	~Person();
	friend std::ostream& operator<<(std::ostream& os, const Person& person);
	friend std::istream& operator>>(std::istream& is, Person& person);
private:
	std::string name;
	std::string lastname;
	Address address;
	Date dateOfBirthday;
	Person* father;
	Person* mother;
};
#endif // !PERSON_H
