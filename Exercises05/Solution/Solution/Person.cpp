#include "Person.h"

Entity::Person::Person(std::string name, std::string phone, int id)
{
	this->name = name;
	this->phone = phone;
	this->id = id;
}

Entity::Person::~Person()
{
}

std::string Entity::Person::GetName() const
{
	return name;
}

std::string Entity::Person::GetPhone() const
{
	return phone;
}

int Entity::Person::GetId() const
{
	return id;
}
