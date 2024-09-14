#include <iostream>
using namespace std;
#include "room.h"
#include"seat.h"


Room::Room() {

    roomNumber = 0;
    numberOfSeats = 0;
    price = 0;
    
    
}
Room::Room(int roomNumber, int numberOfSeats, double price) {

    this->roomNumber = roomNumber;
    this->numberOfSeats = numberOfSeats;
    this->price = price;

}
Room::~Room() {
}

//getters
int Room::getRoomNumber() { 
    return roomNumber;
}
int Room::getNumberOfSeats() {
    return numberOfSeats;
}
double Room::getPrice() { 
    return price;
}
//setters
void Room::setRoomNumber(int roomNumber) {
    this->roomNumber = roomNumber;  
}
void  Room::setNumberOfSeats(int numberOfSeats) {  
    this->numberOfSeats = numberOfSeats;

}
void Room::setPrice(double price) {
    this->price = price;

}

void Room::showRoomInfo() {
    std::cout << "Sala: " << roomNumber << std::endl;
    std::cout << "Precio: " << price << std::endl;
    std::cout << "Cantidad de asientos: " << numberOfSeats << std::endl;
    std::cout << std::endl;
}

