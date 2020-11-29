#include "Phonebook.h"
#include <iostream>
#include <exception>

Model::Phonebook::Phonebook()
{
	first = nullptr;
}

Model::Phonebook::~Phonebook()
{
	Node* actual = first;
	while (actual != nullptr) {
		Node* tmp = actual->next;
		delete actual;
		actual = tmp;
	}
}

void Model::Phonebook::AddPerson(Entity::Person p)
{
	Node* node = new Node(p);
	if (first == nullptr) {
		first = node;
	}else{
		Node* lastNode = first;
		while (lastNode->next != nullptr) {
			lastNode = lastNode->next;
		}
		lastNode->next = node;
	}
}

std::string Model::Phonebook::FindPhone(std::string name) const
{
	if (name.empty()) {
		throw std::invalid_argument("Name was empty!");
	}
	Node* actual = first;
	while (actual != nullptr) {
		if (actual->data.GetName() == name) {
			return actual->data.GetPhone();
		}
		actual = actual->next;
	}
	throw std::invalid_argument("Name wasnt found in phonebook!");
}

std::string Model::Phonebook::FindPhone(int id) const
{
	if (id < 0) {
		throw std::invalid_argument("ID was empty!");
	}
	Node* actual = first;
	while (actual != nullptr) {
		if (actual->data.GetId() == id) {
			return actual->data.GetPhone();
		}
		actual = actual->next;
	}
	throw std::invalid_argument("ID wasnt found in phonebook!");
}

void Model::Phonebook::PrintPhoneBook() const
{
	Node* actual = first;
	while (actual != nullptr) {
		std::cout << actual->data.GetName() << " tel: " << actual->data.GetPhone() << " id: " << actual->data.GetId() << std::endl;
		actual = actual->next;
	}
}
