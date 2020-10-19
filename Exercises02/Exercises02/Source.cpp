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

	cout << "Trzba bez dph ->" << cashRegister.GetSumOfAllReceipt();
	cout << "\nTrzba s dph ->" << cashRegister.GetSumOfAllReceiptWithVat();
	cout << "\n" << cashRegister.GetReceipt(1001).GetSum() << ",-Kc = 2. uctenka cena bez DPH";
	cout << "\n" << cashRegister.GetReceipt(1001).GetSum() * ((cashRegister.GetReceipt(1001).GetVat()/100)+1) << ",-Kc = 2. uctenka cena s DPH";


	return 0;
}