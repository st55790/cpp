#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Address.h"
#include "Person.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void Save();
void Load();



int main() {



	Save();
	Load();

	//Memory LEAK Check start
	_CrtCheckMemory();
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	//Memory Leak Check end

	return 0;
}

void Save()
{
	Person arp[3];
	arp[0] = Person("Petr", "Pomaly", Address("Dlouha 523", "Olomouc", 62533), Date(7,3,1982));
	arp[1] = Person("Jakub", "Sudy", Address("Kratka 8", "Holesin", 54884), Date(19, 11, 2001));
	arp[2] = Person("Jarmila", "Cerna", Address("Slepa 144", "Zabrdov", 65220), Date(22, 8, 1966));

	std::string fileName= "people.dat";
	std::ofstream writeFile(fileName.c_str(), std::ios::binary | std::ios::out);
	if (!writeFile) {
		throw std::runtime_error("Could not open file!\n");
	}
	for (int i = 0; i < 3;i++) {
		writeFile.write((char*)&arp[i], sizeof(Person));
	}
	writeFile.close();
}

void Load()
{
	std::string fileName = "people.dat";
	std::ifstream readFile(fileName.c_str(), std::ios::binary | std::ios::in);
	readFile.seekg(0, std::ios::end);
	int fileSize = readFile.tellg();
	int countObject = fileSize / sizeof(Person);
	readFile.seekg(0, std::ios::beg);

	if (!readFile) {
		throw std::runtime_error("Cannot open file\n");
	}
	Person* p = new Person[countObject];
	for (int i = 0; i < countObject; i++) {
		readFile.read((char*)&p[i], sizeof(Person));
	}

	readFile.close();

	for (int i = 0; i < countObject; i++) {
		std::cout << p[i] << std::endl;
	}

	delete[] p;
}
