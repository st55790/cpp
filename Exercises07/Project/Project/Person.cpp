#include "Person.h"

Person::Person()
{
}

Person::Person(std::string name, std::string lastname, Address address, Date dateOfBirthday)
{
    this->name = name;
    this->lastname = lastname;
    this->address = address;
    this->dateOfBirthday = dateOfBirthday;
}

Person::~Person()
{
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << person.name << " " << person.lastname << ", address: " << person.address << ", birthday: " << person.dateOfBirthday;
    return os;
}

std::istream& operator>>(std::istream& is, Person& person)
{
    is >> person.name >> person.lastname >> person.address >> person.dateOfBirthday;;
    return is;
}
