#include <iostream>
#include "room.h"
#include"schedule.h"
using namespace std;

// Implementación de los constructores
Schedule::Schedule() {
    string date = "";
    int startHour = 0;
    int endHour = 0;
    Movie movie; 
    Room room;
}
Schedule::Schedule(string date, int startHour, int endHour, Movie movie, Room room) {

    this->movie = movie;
    this->startHour = startHour;
    this->endHour= endHour;
    this->movie = movie;
    this->room = room;
}

// Implementación de los getters
string Schedule::getDate() {return date;}
int Schedule::getStartHour() {return startHour;}
int Schedule::getEndHour() {return endHour;}
Movie Schedule::getMovie() {return movie;}
Room Schedule::getRoom() { return room;}

// Implementación de los setters
void Schedule::setDate(string date) {
    this->date = date;
}

void Schedule::setStartHour(int startHour) {
    this->startHour = startHour;
}

void Schedule::setEndHour(int endHour) {
    this->endHour = endHour;
}

void Schedule::setMovie(Movie movie) {
    this->movie = movie;
}

void Schedule::setRoom(Room room) {
    this->room = room;
}
