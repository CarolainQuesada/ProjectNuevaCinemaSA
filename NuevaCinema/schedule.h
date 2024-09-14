#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "Movie.h"
#include "room.h"

#include <iostream>
using namespace std;

class Schedule {

private:
    string movieName;
    string date;
    int startHour;
    int endHour;
    int roomNumber;
public:

    Schedule();
    Schedule(const string& movieName, int startHour, int endHour,  const string& date, int roomNumber);

    //Getters 
    string getDate();
    int getStartHour();
    int getEndHour();

    int getRoomNumber();
    string getMovieName();


    //setters 

    void setMovieName(const string& movieName);
    void setRoomNumber(int roomNumber);

    void setDate(const string& date);
    void setStartHour(int startHour);
    void setEndHour(int endHour);

    //impreme fecha,hora inicula y final
    void displaySchedule();
};
#endif
