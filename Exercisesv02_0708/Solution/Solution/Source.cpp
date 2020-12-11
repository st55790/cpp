#include "Person.h"
#include <fstream>
#include <iostream>

void SaveToText(Person* p);
Person* LoadFromText();
void SaveToBin(Person* p);
Person* LoadFromBin();


int main() {

	Person pData[] = {
		{"Petr", "Novak", Address("Kounicova 52", "Brno", 56950), Date(16,12,1990)},
		{"Martina", "Divá", Address("Jiraskova 369", "Praha", 56000), Date(23,1,1982)},
		{"Lukáš", "Frydrych", Address("Purkynova 1", "Olomouc", 59566), Date(8,11,2000)}
	};

	SaveToText(pData);
	Person* pLoadTxt = LoadFromText();
	for (int i = 0; i < 3; i++) {
		std::cout << pLoadTxt[i] << std::endl;
	}

	return 0;
}

void SaveToText(Person* p)
{
	std::ofstream writeToText{ "data.txt" };
	for (int i = 0; i < 3; i++) {
		writeToText << p[i] << std::endl;
	}
	writeToText.close();
}

Person* LoadFromText()
{
	Person* p = new Person[3];
	std::ifstream readFromText{ "data.txt" };
	if (!readFromText.good()) {
		//ERROR
	}
	for (int i = 0; i < 3; i++) {
		readFromText >> p[i];
	}
	readFromText.close();

	return p;
}
