#include <iostream>
#include "../FirstStructure/Triangle.h"
using namespace std;

int main() {

	double a, b, c;
	int count;
	Triangle triangle;
	Triangle* ptriangle = new Triangle;

	cout << "Test, zda lze sestrojit trojuhelnik" << endl;

	cout << "Zadej stranu A:";
	cin >> a;
	cout << "Zadej stranu B:";
	cin >> b;
	cout << "Zadej stranu C:";
	cin >> c;

	ptriangle->setA(a);
	ptriangle->setB(b);
	ptriangle->setC(c);

	if (triangle.canBeConstructed(ptriangle)) {
		double o = a + b + c;
		cout << "Trojuhelnik lze sestrojit a jeho obvod je: " << o << endl;
	}
	else {
		cout << "Trojuhelnik nelze sestrojit" << endl;
	}

	delete ptriangle;
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

