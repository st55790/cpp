#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include "Person.h"

namespace Model {
	class Phonebook
	{
	public:
		class Node {

		public:
			Node* next;
			Entity::Person data;
			Node(Entity::Person p) : data(p), next(nullptr) {};
			~Node() {};
		};

		Phonebook();
		~Phonebook();
		void AddPerson(Entity::Person p);
		std::string FindPhone(std::string name)const;
		std::string FindPhone(int id)const;
		void PrintPhoneBook();

	private:
		Node* first;
	};
}

#endif // !PHONEBOOK_H
