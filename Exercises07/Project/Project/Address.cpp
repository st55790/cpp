#include "Address.h"
#include <string>


Address::Address()
{
    this->street = "null";
    this->city = "null";
    this->postCode = 0;
}

Address::Address(std::string street, std::string city, int postCode)
{
    this->street = street;
    this->city = city;
    this->postCode = postCode;
}

Address::~Address()
{
}

std::ostream& operator<<(std::ostream& os, const Address& adr)
{
    os << adr.street << ", " << adr.city << " " << adr.postCode;
    return os;
}

std::istream& operator>>(std::istream& is, Address& adr)
{
    is >> adr.street >> adr.city >> adr.postCode;
    return is;
}
