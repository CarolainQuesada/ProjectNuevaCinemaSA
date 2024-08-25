#pragma once
#include <iostream>
#ifndef ROOM_H
#define ROOM_H
#include"Movie.h"
#include"seat.h"

using namespace std;

class Room {
private:
    int id;
    int seatsNumber;
    double price;
    Seat roomSeats[10][10];

public:

    Room();
    Room(int id, int seatsNumber, double price, Seat roomSeats[10][10]);

   //getters 
    int getId();
    int getSeatsNumber();
    double getPrice();
   Seat(*getRoomSeats())[10]; // Devuelve un puntero a una matriz de 10x10 de Seat

    //setters 
    void setId(int id);
    void setSeatsNumber(int seatsNumber);
    void setPrice(double price);
    void setRoomSeats(Seat roomSeats[10][10]);
};
#endif