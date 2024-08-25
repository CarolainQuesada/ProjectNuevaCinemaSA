#include <iostream>
using namespace std;
#include "room.h"
#include"seat.h"


Room::Room() {
    id = 0;
    seatsNumber = 0;
    price = 0;
    Seat roomSeats[10][10];
}
Room::Room(int id, int seatsNumber, double price, Seat roomSeats[10][10]) {

    this->id = id;
    this->seatsNumber = seatsNumber;
    this->price = price;

}

//getters
int Room::getId() { return id ;}
int Room::getSeatsNumber() { return seatsNumber;}
double Room::getPrice() { return price;}
Seat(*getRoomSeats())[10]; // Devuelve un puntero a una matriz de 10x10 de Seat

//setters