#include<iostream>

#include "Seat.h"

// Implementaci�n de los constructores
Seat::Seat() {
    id = 0;
    state = "";

}

Seat::Seat(int id, string state) {
    this->id = id;
    this->state = state;
}

// Implementaci�n de los getters
int Seat::getId() {
    return id;
}

string Seat::getState() {
    return state;
}

// Implementaci�n de los setters
void Seat::setId(int id) {
    this->id = id;
}

void Seat::setState(string state) {
    this->state = state;
}