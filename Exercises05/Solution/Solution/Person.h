#pragma once
#ifndef PERSON_H
#include <string>

namespace Entity {

	class Person
	{
	private:
		std::string name;
		std::string phone;
		int id;

	public:
		Person(std::string name, std::string phone, int id);
		~Person();
		std::string GetName() const;
		std::string GetPhone() const;
		int GetId() const;
	};
}

#endif // !PERSON_H


