#include <iostream>
#include "room.h"
#include"schedule.h"
#include"movie.h"


using namespace std;

Schedule::Schedule() {
    movieName="";
    date = "";
    startHour = 0;
    endHour = 0;
    roomNumber = 0;
}

Schedule::Schedule(const string& movieName, int startHour, int endHour, const string& date, int roomNumber){
    this->movieName = movieName;
    this->date = date;
    this->startHour = startHour;
    this->endHour= endHour;
    this->roomNumber = roomNumber;
}
    
string Schedule::getMovieName() { return movieName; }
int Schedule::getRoomNumber() {return roomNumber;}
string Schedule::getDate() {return date;}
int Schedule::getStartHour() {return startHour;}
int Schedule::getEndHour() {return endHour;}

void Schedule::setMovieName(const string& movieName) {
    this->movieName= movieName;
}
void Schedule::setRoomNumber(int roomNumber) {
    this->roomNumber =roomNumber; 
}
void Schedule::setDate(const string& date) {
    this->date = date;
}

void Schedule::setStartHour(int startHour) {
    this->startHour = startHour;
}

void Schedule::setEndHour(int endHour) {
    this->endHour = endHour;
}


void Schedule::displaySchedule() {
    std::cout << "Película: " << movieName
        << ", Fecha: " << date
        << ", Hora de inicio: " << startHour << ":00"
        << ", Hora de fin: " << endHour << ":00"
        << ", Sala: " << roomNumber << std::endl;
}