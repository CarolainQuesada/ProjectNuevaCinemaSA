#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "Movie.h"
#include "room.h"

#include <iostream>
using namespace std;

class Schedule {

private:

    string date;
    int startHour;
    int endHour;
    Movie movie;
    Room room; 

public:

    Schedule();
    Schedule(string date, int startHour, int endHour, Movie movie, Room room);

    //Getters 
    string getDate();
    int getStartHour();
    int getEndHour();
    Movie getMovie();
    Room getRoom();

    //setters 
    void setDate(string date);
    void setStartHour(int starHour);
    void setEndHour(int endHouer);
    void setMovie(Movie movie);
    void setRoom(Room room);

};
#endif
