#include "Receipt.h"
#include "CashRegister.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	//Receipt receipt = Receipt();
	//receipt.SetId(1001);
	//receipt.GetId();

	//const Receipt receipt2 = Receipt();
	//receipt2.GetId();
	//receipt2.SetId(1002); ->crací chybu, protože je to konstantní, nemìné asi? 

	CashRegister cashRegister = CashRegister();


	cashRegister.CreateReceipt(80, 21);
	cashRegister.CreateReceipt(190, 21);
	cashRegister.CreateReceipt(1163, 21);

	cout << cashRegister.GetSumOfAllReceipt();

	return 0;
}