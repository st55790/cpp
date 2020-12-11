#include <iostream>
#include "Address.h"

Address::Address() {
	street = "";
	city = "";
	postCode = 0;
}

Address::Address(std::string street, std::string city, int postCode) {
	this->street = street;
	this->city = city;
	this->postCode = postCode;
}

Address::~Address() {}

std::string Address::getStreet() {
	return street;
}

std::string Address::getTown() {
	return city;
}

std::ostream& operator<<(std::ostream& os, const Address& address) {
	return os << address.street << " " << address.city << " " << address.postCode;
}

std::istream& operator>>(std::istream& is, Address& address) {
	return is >> address.street >> address.city >> address.postCode;
}