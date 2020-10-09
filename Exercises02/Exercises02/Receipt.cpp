#include "Receipt.h"

void Receipt::SetId(int id)
{
	this->id = id;
}

int Receipt::GetId() const
{
	return id;
}

void Receipt::SetSum(double sum)
{
	this->sum = sum;
}

double Receipt::GetSum() const
{
	return sum;
}

void Receipt::SetVat(double vat)
{
	this->vat = vat;
}

double Receipt::GetVat() const
{
	return vat;
}
