#include <string>
#ifndef ADDRESS_H
#define ADDRESS_H

struct Address {
private:
	std::string street;
	std::string city;
	int postCode;
public:
	Address();
	Address(std::string street, std::string city, int postCode);
	~Address();
	std::string getStreet();
	std::string getCity();
	friend std::ostream& operator<<(std::ostream& os, const Address& address);
	friend std::istream& operator>>(std::istream& is, Address& address);
};

#endif // ADDRESS_H