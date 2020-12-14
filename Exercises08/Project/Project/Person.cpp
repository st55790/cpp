#include <iostream>
#include "Person.h"

Person::Person() {
	name = "";
	surname = "";
	address = Address();
	date = Date();
}

Person::Person(std::string name, std::string surname, Address address, Date date) {
	this->name = name;
	this->surname = surname;
	this->address = address;
	this->date = date;
}

Person::~Person() {}

std::ostream& operator<<(std::ostream& os, const Person& person) {
	return os << person.name << " " << person.surname << " " << person.address << " " << person.date;
}

std::istream& operator>>(std::istream& is, Person& person) {
	return is >> person.name >> person.surname >> person.address >> person.date;
}