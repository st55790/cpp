#include <iostream>
#include <time.h>
#include "Person.h"
#include "Phonebook.h"

using namespace std;
using namespace Entity;
using namespace Model;

string GetRandPhone();
int GetRandNum(int first, int last);

int main() {
	srand(time(NULL));

	Phonebook* list = new Phonebook();

	for (int i = 0; i < 10; i++) {
		Person p = Person("Name" + to_string(i), GetRandPhone(), i);
		list->AddPerson(p);
	}

	cout << "Generated Phonebook" << endl;
	list->PrintPhoneBook();

	//FindPhone(string)
	cout << endl << "Phone number for name: Name3 is -> " << list->FindPhone("Name3") << endl;
	try{
		cout << endl << "Phone number for name: Name is -> " << list->FindPhone("Petr") << endl;
	}
	catch (const exception e) {
		cout << e.what() << endl;
	}
	try {
		cout << endl << "Phone number for name: "" is -> " << list->FindPhone("") << endl;
	}
	catch (const exception e) {
		cout << e.what() << endl;
	}

	//FindString(id)
	cout << endl << "Phone number for id: 9 is -> " << list->FindPhone(9) << endl;
	try {
		cout << endl << "Phone number for id: -9 is -> " << list->FindPhone(-9) << endl;
	}
	catch (const exception e) {
		cout << e.what() << endl;
	}
	try {
		cout << endl << "Phone number for id: 100 is -> " << list->FindPhone(100) << endl;
	}
	catch (const exception e) {
		cout << e.what() << endl;
	}

	return 0;
}

string GetRandPhone()
{
	string tmp = "";
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0 && i != 0) {
			tmp += " ";
		}
		tmp += to_string(GetRandNum(0, 9));
	}
	return tmp;
}

int GetRandNum(int first, int last)
{
	return (rand() % last) + first;
}