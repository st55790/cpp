#include "CashRegister.h"
#include <exception>
#include <iostream>
#define MAX_UCTENEK 10
using namespace std;

int CashRegister::idCounter = 1000;

CashRegister::CashRegister()
{
	arrayOfReceipt = new Receipt[MAX_UCTENEK];
	numReceipt = 0;
}

CashRegister::~CashRegister()
{
	delete[] arrayOfReceipt;
}

Receipt& CashRegister::CreateReceipt(double cost, double vat)
{
	if (numReceipt < MAX_UCTENEK) {
		arrayOfReceipt[numReceipt] = Receipt();
		arrayOfReceipt[numReceipt].SetId(idCounter++);
		arrayOfReceipt[numReceipt].SetSum(cost);
		arrayOfReceipt[numReceipt].SetVat(vat);
		return arrayOfReceipt[numReceipt++];
	}
	else {
		throw exception("CashRegister is full!");
	}
}

Receipt& CashRegister::GetReceipt(int id)
{
	for (int i = 0; i < numReceipt; i++) {
		if (arrayOfReceipt[i].GetId() == id) {
			return arrayOfReceipt[i];
		}
	}
	return arrayOfReceipt[0];
}

double CashRegister::GetSumOfAllReceipt() const
{
	double tmpSum = 0;
	for (int i = 0; i < numReceipt; i++) {
		tmpSum += arrayOfReceipt[i].GetSum();
	}
	return tmpSum;
}

double CashRegister::GetSumOfAllReceiptWithVat() const
{
	double tmpSum = 0;
	for (int i = 0; i < numReceipt; i++) {
		tmpSum += arrayOfReceipt[i].GetSum() * (arrayOfReceipt[i].GetVat()/100+1);
	}
	return tmpSum;
}

