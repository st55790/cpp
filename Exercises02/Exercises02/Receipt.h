#ifndef RECEIPT_H
#define RECEIPT_H

class Receipt {

private:
	int id;
	double sum;
	double vat; //DPH

public:
	void SetId(int id);
	int GetId() const;
	
	void SetSum(double sum);
	double GetSum();

	void SetVat(double vat);
	double GetVat();

};

#endif // !RECEIPT_H