#include "Person.h"

Person::Person()
{
	name = "Person";
	weight = 70;
}

std::string Person::ToString()
{
	return name + ' ' + std::to_string(weight);
}
