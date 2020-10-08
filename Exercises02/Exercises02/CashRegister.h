#pragma once
#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include "Receipt.h"

class CashRegister {

	static int idCounter;

public:
	CashRegister();
	~CashRegister();
	Receipt& CreateReceipt(double cost, double vat);
	Receipt& GetReceipt(int id);
	double GetSumOfAllReceipt() const;
	double GetSumOfAllReceiptWithVat() const;

private:
	int numReceipt;
};
#endif // !CASH_REGISTER_H
