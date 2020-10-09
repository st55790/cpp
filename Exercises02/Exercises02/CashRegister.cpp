#include "CashRegister.h"
#include <exception>
#include <iostream>

using namespace std;

int CashRegister::idCounter = 1000;
Receipt** arrayOfReceipt;

CashRegister::CashRegister()
{
	arrayOfReceipt = new Receipt*[10];
	numReceipt = 0;
}

CashRegister::~CashRegister()
{
	delete[] arrayOfReceipt;
}

Receipt& CashRegister::CreateReceipt(double cost, double vat)
{
	if (numReceipt < 10) {
		arrayOfReceipt[numReceipt] = new Receipt;
		arrayOfReceipt[numReceipt]->SetId(idCounter++);
		arrayOfReceipt[numReceipt]->SetSum(cost);
		arrayOfReceipt[numReceipt]->SetVat(vat);
		return *arrayOfReceipt[numReceipt++];
	}
	else {
		throw exception("CashRegister is full!");
	}
}

Receipt& CashRegister::GetReceipt(int id)
{
	for (int i = 0; i < numReceipt; i++) {
		if (arrayOfReceipt[i]->GetId() == id) {
			return *arrayOfReceipt[i];
		}
	}
	return *arrayOfReceipt[0];
}

double CashRegister::GetSumOfAllReceipt() const
{
	double tmpSum = 0;
	for (int i = 0; i < numReceipt; i++) {
		tmpSum += arrayOfReceipt[i]->GetSum();
	}
	return tmpSum;
}

double CashRegister::GetSumOfAllReceiptWithVat() const
{
	double tmpSum = 0;
	for (int i = 0; i < numReceipt; i++) {
		tmpSum += arrayOfReceipt[i]->GetSum() * (arrayOfReceipt[i]->GetVat()/100+1);
	}
	return tmpSum;
}

