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
		//Vytvor a pridej uctenku
		arrayOfReceipt[numReceipt] = new Receipt;
		arrayOfReceipt[numReceipt]->SetId(idCounter++);
		arrayOfReceipt[numReceipt]->SetSum(cost);
		arrayOfReceipt[numReceipt]->SetVat(vat);
		cout << numReceipt << ". uctenka byla uspesne pridana a vytvorena\n";
		return *arrayOfReceipt[numReceipt++];
	}
	else {
		throw new std::exception("CashRegister is full!");
	}
	// - if pocet vytvorenych uctenek = 10, vyhod chybovou hlasku nebo udelat list 
	//
	//if (receiptCounter == 10)
	//	throw new std::exception("CashRegister is full.");
	//receipts[receiptCounter].SetId(receiptCounter + 1);

	// - Nastaveni uctenky (vytvoreni instance?) - id, cost, dph
	// - inkrementace poctu uctenek idCounter
	// - vratit danou uctenku
	// receipts[receiptsCounter++];
	
}

Receipt& CashRegister::GetReceipt(int id)
{
	return *arrayOfReceipt[id];
}

double CashRegister::GetSumOfAllReceipt() const
{
	double tmpSum = 0;
	for (int i = 0; i < 10; i++) {
		tmpSum += arrayOfReceipt[i]->GetSum();
	}
	return tmpSum;
}

double CashRegister::GetSumOfAllReceiptWithVat() const
{
	double tmpSum = 0;
	for (int i = 0; i < 10; i++) {
		tmpSum += arrayOfReceipt[i]->GetSum() * arrayOfReceipt[i]->GetVat();
	}
	return tmpSum;
}
