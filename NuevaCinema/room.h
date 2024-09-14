#pragma once
#include <iostream>
#ifndef ROOM_H
#define ROOM_H

#include"schedule.h"
#include"Movie.h"
#include"seat.h"



using namespace std;

class Room {
private:
    int roomNumber;
    int numberOfSeats;
    double price;
    

public:

    Room();
    Room(int roomNumber, int numberOfSeats, double price);
    ~Room();

   //getters 
    int getRoomNumber();
    int getNumberOfSeats();
    double getPrice();
   

    //setters 
    void setRoomNumber(int roomNumber);
    void setNumberOfSeats(int seatsNumber);
    void setPrice(double price);
    

    //metodos 
    void showRoomInfo();
   
};
#endif