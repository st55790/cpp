#include <iostream>
#include <time.h>
#include "IComparable.h"
#include "Time.h"

#define SIZE 10

void SortArray(IComparable** array, int sizeArray);
int GetRandNum(int first, int last);

int main() {
	srand(time(NULL));

	Time** times = new Time * [SIZE];
	cout << "Generated numbers in unsorted array" << endl;
	for (int i = 0; i < SIZE; ++i) {
		times[i] = new Time(GetRandNum(0,23), GetRandNum(0,59), GetRandNum(0,59));
		cout << i << ".:" << times[i]->ToString() << endl;
	}
	cout << endl;

	SortArray((IComparable**)times, SIZE);

	cout <<"Generated numbers in sorted array" << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << i << ".:" << times[i]->ToString() << endl;
	}


	delete[] times;

	return 0;
}

void SortArray(IComparable** array, int sizeArray)
{
	for (int i = 0; i < sizeArray - 1;i++) {
		for (int j = 0; j < sizeArray - 1 - i;j++) {
			if (array[j+1]->CompareTo(array[j]) == -1) {
				IComparable* tmp = array[j+1];
				array[j+1] = array[j];
				array[j] = tmp;
			}
		}
	}
}

int GetRandNum(int first, int last)
{
	return (rand() % last) + first;
}
