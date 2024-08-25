#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>

using namespace std;  
#include <vector>

class Movie {
private:

	string name;
	int year;
	int time;
	string country;
	int reviews; //0 al 10

public:
	Movie();

	Movie(string name, int year, int time, string country, int reviews);

	~Movie();

	// Getters
	string getName();
	int getYear();
	int getTime();
	string getCountry();
	int getReviews();

	// Setters
	void setName(string name );
	void setYear(int year );
	void setTime(int time );
	void setCountry(string country);
	void setReviews(int reviews);

	//funciones a imolementar
	
	
	//muestra la informacion de la pelicula 
	void movieInformation();

};

#endif