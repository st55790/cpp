#include <iostream>
#include "Person.h"

Person::Person() {
	name = "";
	lastname = "";
	address = Address();
	date = Date();
}

Person::Person(std::string name, std::string lastname, Address address, Date date) {
	this->name = name;
	this->lastname = lastname;
	this->address = address;
	this->date = date;
}

Person::~Person() {}

std::ostream& operator<<(std::ostream& os, const Person& person) {
	return os << person.name << " " << person.lastname << " " << person.address << " " << person.date;
}

std::istream& operator>>(std::istream& is, Person& person) {
	return is >> person.name >> person.lastname >> person.address >> person.date;
}