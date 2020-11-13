#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <istream>

class Address {
public:
	Address();
	Address(std::string street, std::string city, int postCode);
	~Address();
	friend std::ostream& operator<<(std::ostream& os, const Address& adr);
	friend std::istream& operator>>(std::istream& is, Address& adr);
private:
	std::string street;
	std::string city;
	int postCode;
};
#endif // !ADDRESS_H
