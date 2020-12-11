#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include "Person.h"
#include "Address.h"
#include "Date.h"

void saveToText(Person persons[]);
Person* loadFromText();
void saveToBin(Person persons[]);
Person* loadFromBin();

int main() {
	Person people[] = {
		{ "Tomas", "Rosa", Address("Dlouha", "Brno", 65600), Date(3, 1, 1982)},
		{ "Bedrich", "Ondrasek", Address("Purkynova", "Brno", 65600), Date(23, 12, 1982)},
		{ "Martina", "Belaskova", Address("Kounicova", "Brno", 65600), Date(31, 1, 2001)}
	};

	Person* people2;

	try
	{
		saveToText(people);

		people2 = loadFromText();
		for (int i = 0; i < 3; i++) {
			std::cout << people2[i] << std::endl;
		}

		std::cout << std::endl;

		saveToBin(people);
		people2 = loadFromBin();
		for (int i = 0; i < 3; i++) {
			std::cout << people2[i] << std::endl;
		}
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;

	}
	return 0;
}

void saveToText(Person persons[]) {
	std::string filename = "data.txt";
	std::ofstream wruteToText{ filename };
	for (int i = 0; i < 3; i++) {
		wruteToText << persons[i] << std::endl;
	}
	wruteToText.close();
}

Person* loadFromText() {
	std::string filename = "data.txt";
	std::ifstream readFromText{ filename };
	if (!readFromText.good())
	{
		std::cout << "Chyba pøi otvírání souboru" << std::endl;
	}

	Person* persons = new Person[3];

	for (int i = 0; i < 3; i++) {
		readFromText >> persons[i];
	}
	readFromText.close();

	return persons;
}

void saveToBin(Person persons[]) {
	std::string filename = "data.dat";
	std::ofstream writeToBin{ filename, std::ios_base::out | std::ios_base::binary };

	for (int i = 0; i < 3; i++) {
		writeToBin.write((char*)&persons[i], sizeof Person);
	}
	writeToBin.close();
}

Person* loadFromBin() {
	std::string filename = "data.dat";
	std::ifstream readFromBin{ filename, std::ios_base::in | std::ios_base::binary };
	if (!readFromBin.good())
	{
		std::cout << "Chyba pøi otvírání souboru" << std::endl;
	}

	Person* persons = new Person[3];

	for (int i = 0; i < 3; i++) {
		readFromBin.read((char*)&persons[i], sizeof Person);
	}
	readFromBin.close();

	return persons;
}