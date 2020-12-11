#include "Address.h"

Address::Address()
{
    this->street = "noAdr";
    this->city = "noCity";
    this->postCode = 00000;
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
    os << " address: " << adr.street << ", " << adr.city << " " << adr.postCode;
    return os;
}

std::istream& operator>>(std::istream& is, Address& adr)
{
    is >> adr.street >> adr.city >> adr.postCode;
    return is;
}
