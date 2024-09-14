#include <iostream>
#include "Movie.h"

Movie::Movie(){
	name = "";
	year = 0;
	time = 0 ;
	country = "";
	reviews = 0;
}
Movie::Movie (string name, int year, int time, string country, int reviews){

	this->name = name;
	this->year = year;
	this->time = time;
	this->country = country;
	this->reviews = reviews;
}
Movie::~Movie() {
}
// Metodos getter
string Movie::getName() { return name; }
int Movie::getYear() { return year; }
int Movie::getTime() { return time; }
string Movie::getCountry() { return country; }
int Movie::getReviews() { return reviews; }


// M�todos setter
void Movie::setName(string name) { this->name = name; }
void Movie::setYear(int year) { this->year = year; }
void Movie::setTime(int time) { this->time = time; }
void Movie::setCountry(string country) { this->country = country; }
void Movie::setReviews (int reviews) { this->reviews = reviews; }


void Movie::movieInformation() { 
	cout << "Nombre: " << name << endl;
	cout << "Anio: " << year << endl;
	cout << "Duracion: " << time << " minutos" << endl;
	cout << "Pais: " << country << endl;
	cout << "Resenia: " << reviews << endl;
}




