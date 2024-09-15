#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

class Movie {
private:
    string name;
    int year;
    int time;
    string country;
    int reviews;
    
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
    void setName(string name);
    void setYear(int year);
    void setTime(int time);
    void setCountry(string country);
    void setReviews(int reviews);
    void movieInformation();
};

#endif 
