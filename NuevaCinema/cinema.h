#pragma once
#ifndef CINEMA_H
#define CINEMA_H
#include <iostream>
#include"movie.h"
using namespace std;

const int MAX_MOVIES = 100; // Maximum number of movies

class Cinema {
private:
    Movie movieList[MAX_MOVIES];
    int movieCount;

public:
    Cinema(); // Constructor

    // Menu functions
    void menuFile();
    void maintenanceMenu();
    void reservationMenu();
    void saleMenu();

    // Helper functions
    void displayMovieData();
    void showMovieInformation(int index);
    void showAbout();
    bool addMovie( Movie& movie);
    void addNewMovie();
};
#endif