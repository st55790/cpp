#include "Receipt.h"
#include "CashRegister.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	CashRegister cashRegister = CashRegister();

	cashRegister.CreateReceipt(80, 21);
	cashRegister.CreateReceipt(190, 21);
	cashRegister.CreateReceipt(1163, 21);
	cashRegister.CreateReceipt(8, 19);
	cashRegister.CreateReceipt(90, 19);

	cout << "\nTržba bez dph ->" << cashRegister.GetSumOfAllReceipt();
	cout << "\nTržba s dph ->" << cashRegister.GetSumOfAllReceiptWithVat();
	cout << "\n" << cashRegister.GetReceipt(1001).GetSum() << " 2. uctenka cena";


	return 0;
}