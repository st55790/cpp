#include <iostream>
#include "GrowingContainer.h"

using namespace std;

int main() {

	GrowingContainer<string, 5> gc = GrowingContainer<string, 5>();
	
	string kocka = "kocka";
	string medved = "medved";
	gc.Add("Pes");
	gc.Add(kocka);
	gc.AddTo(1, medved);
	gc.AddTo(1, "opice");
	gc.AddTo(4, "zebra");
	gc.AddTo(0, "jezek");
	gc.Add("prase");
	gc.Add("papousek");
	gc.Add("ryba");
	gc.Add("slepice");
	gc.AddTo(5, "brouk");
	gc.Add("kun");
	gc.Remove(1);
	gc.Add("delfin");

	for (int i = 0; i < 12; i++) {
		cout << gc[i] << endl;
	}

	try {
		cout << gc[15] << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	cout << "Coung of array: " << gc.Count() << endl;

	return 0;
}