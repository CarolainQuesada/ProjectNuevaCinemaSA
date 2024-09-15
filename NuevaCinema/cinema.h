#pragma once
#ifndef CINEMA_H
#define CINEMA_H

#include <iostream>
#include "movie.h"
#include "room.h"
#include "schedule.h" 

using namespace std;

const int MAX_MOVIES = 10;
const int MAX_ROOMS = 3;
const int MAX_SCHEDULES=10;
const int ROWS = 8;
const int COLUMS = 10;
const int MAX_RESERVATIONS = 20;

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string RESET = "\033[0m";

class Cinema {
private:

    Movie movieList[MAX_MOVIES];
    Room roomList[MAX_ROOMS];
    Schedule scheduleList[MAX_SCHEDULES];
    Seat seatsRoom[MAX_ROOMS][ROWS][COLUMS];
    int movieCount;
    int roomCount;
    int scheduleCount;
    int reservationCount;
    int reservationIndex;

    int reservationNumbers[MAX_RESERVATIONS];
    bool reservationStatus[MAX_RESERVATIONS];
    int reservationRoom[MAX_RESERVATIONS]; 
    int reservationRow[MAX_RESERVATIONS];   
    int reservationCol[MAX_RESERVATIONS];

public:
    Cinema(); 

    // menu
    void menuFile();
    void maintenanceMenu();
    void reservationMenu();
    void saleMenu();

    // metodos para manejar las peliculas 
    void displayMovieData();
    void showMovieInformation(int index);
    void showAbout();
    bool addMovie(Movie& movie);
    void addNewMovie();

    //metodos para  manejar los horarios 
    void displayScheduleData();
    void showScheduleInformation(int index);
    bool addSchedule(Schedule& schedule);
    void addNewSchedule();
    bool movieExists(int movieName);
    void displayScheduleDataForMovie(int movieIndex);
    void showRoomInformationForSchedule(int scheduleIndex);

    //metodos para manejar la sala y reservas
    void showRoomInformation();
    void reserveSeat(Seat seatsRoom[ROWS][COLUMS], int row, int col);
    void sellSeat(Seat seatsRoom[ROWS][COLUMS], int row, int col);
    void showSeats(Seat seatsRoom[ROWS][COLUMS]);

    //funciones para venta
    void printVoucher(int reservationIndex);
    void showSale();
    void handleSeatReservation();

    //funciones para verificar la entrada de datos 
    string readString();
    int getInt();
    double getDouble();
    
};
#endif
