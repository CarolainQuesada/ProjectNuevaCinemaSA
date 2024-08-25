#include<iostream>

#include "Seat.h"

// Implementación de los constructores
Seat::Seat() {
    id = 0;
    state = "";

}

Seat::Seat(int id, string state) {
    this->id = id;
    this->state = state;
}

// Implementación de los getters
int Seat::getId() {
    return id;
}

string Seat::getState() {
    return state;
}

// Implementación de los setters
void Seat::setId(int id) {
    this->id = id;
}

void Seat::setState(string state) {
    this->state = state;
}