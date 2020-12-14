#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include "Person.h"
#include "Address.h"
#include "Date.h"

void saveToText(Person p[]);
void saveToBin(Person p[]);
Person* loadFromText();
Person* loadFromBin();
void vypisPeople(Person p[]);

int main() {
	Person persons[] = {
		{ "Petr", "Pan", Address("Purkynova41", "Brno", 56500), Date(26, 4, 1981) },
		{ "Karetirna", "Sablikova", Address("Kounicova169", "Brno", 56500), Date(11, 9, 1980) },
		{ "Pavla", "Kratka", Address("Ceska5", "Brno", 56500), Date(24, 12, 2020) },
	};

	Person* p;

	std::cout << "TextFile" << std::endl;
	saveToText(persons);
	p = loadFromText();
	vypisPeople(p);
	saveToBin(persons);
	std::cout << std::endl;
	std::cout << "BinFile" << std::endl;
	p = loadFromBin();
	vypisPeople(p);

	return 0;
}

void saveToText(Person p[]) {
	std::ofstream write{ "data.txt" };
	if (write.is_open()) {
		for (int i = 0; i < 3; i++) {
			write << p[i] << std::endl;
		}
		write.close();
	}
	else {
		std::cout << "Chyba pri otvirani souboru";
	}
	
}

Person* loadFromText() {
	std::ifstream read{ "data.txt" };
	if (read.is_open()) {

		Person* persons = new Person[3];

		for (int i = 0; i < 3; i++) {
			read >> persons[i];
		}
		read.close();

		return persons;
	}else{
		std::cout << "Chyba pri otvirani souboru";
	}
	return NULL;
}

void saveToBin(Person p[]) {
	std::ofstream read{ "Data.dat", std::ios_base::out | std::ios_base::binary };
	if (read.is_open()) {
		for (int i = 0; i < 3; i++) {
			read.write((char*)&p[i], sizeof Person);
		}
		read.close();
	}
	else {
		std::cout << "Chyba pri otvirani souboru";
	}

}

Person* loadFromBin() {
	std::ifstream read{ "Data.dat", std::ios_base::in | std::ios_base::binary };
	if (read.good())
	{
		Person* persons = new Person[3];

		for (int i = 0; i < 3; i++) {
			read.read((char*)&persons[i], sizeof Person);
		}
		read.close();

		return persons;
	}

	return NULL;
}

void vypisPeople(Person p[])
{
	for(int i = 0; i < 3; i++) {
		std::cout << p[i] << std::endl;
	}
}
