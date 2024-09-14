#include "sale.h"
#include <iostream>
using namespace std;

Sale::Sale() {
}
Sale::Sale(string idCostumer, string cardNumber) {
	this->idCustomer = idCostumer;
	this->cardNumber = cardNumber;
}
Sale::~Sale() { 

}

string Sale::getIdCustomer() {
	return idCustomer;
}
string Sale::getCardNumber() {
	return cardNumber;
}
void Sale::setIdCustomer(string) {
	this->idCustomer = idCustomer;
}
void Sale::setCardNumber(string) {
	this->cardNumber = cardNumber;
}