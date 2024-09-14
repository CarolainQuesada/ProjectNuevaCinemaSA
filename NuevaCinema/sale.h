#pragma once
#ifndef SALE_H
#define SALE_H
#include <iostream>
#include "booking.h"
using namespace std;

class Sale {
private:

	string idCustomer;
	string cardNumber;
public:
	Sale();
	Sale(string, string);
	~Sale();

	void setIdCustomer(string);
	void setCardNumber(string);

	string getIdCustomer();
	string getCardNumber();

};
#endif