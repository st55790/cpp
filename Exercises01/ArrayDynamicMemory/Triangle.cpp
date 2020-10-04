#include <iostream>
#include "../FirstStructure/Triangle.h"
using namespace std;

int main() {

	double a, b, c;
	int count;
	Triangle triangle;


	cout << "Test, zda lze sestrojit trojuhelnik" << endl;
	cout << "Zadej pocet trojuhelniku: ";
	cin >> count;

	if (count <= 0) {
		cout << "Zadal si neplatny vstup" << endl;
	}

	Triangle** ptriangle = new Triangle*[count];

	for (int i = 0; i < count;i++) {

		ptriangle[i] = new Triangle;

		cout << "Zadej stranu A:";
		cin >> a;
		cout << "Zadej stranu B:";
		cin >> b;
		cout << "Zadej stranu C:";
		cin >> c;

		ptriangle[i]->setA(a);
		ptriangle[i]->setB(b);
		ptriangle[i]->setC(c);

		if (triangle.canBeConstructed(ptriangle[i])) {
			double o = a + b + c;
			cout << i + 1 << ". Trojuhelnik lze sestrojit a jeho obvod je: " << o << endl;
		}
		else {
			cout << i + 1 << ". Trojuhelnik nelze sestrojit" << endl;
		}
	}

	delete[] ptriangle;

	return 0;
}

bool Triangle::canBeConstructed(Triangle t)
{

	if (t.a < 0 || t.b < 0 || t.c < 0) {
		return false;
	}
	else if ((t.a + t.b > t.c) && (t.a + t.c > t.b) && (t.b + t.c > t.a)) {
		return true;
	}
	else {
		return false;
	}
}

bool Triangle::canBeConstructed(Triangle* t)
{
	if (t->a < 0 || t->b < 0 || t->c < 0) {
		return false;
	}
	else if ((t->a + t->b > t->c) && (t->a + t->c > t->b) && (t->b + t->c > t->a)) {
		return true;
	}
	else {
		return false;
	}
}

