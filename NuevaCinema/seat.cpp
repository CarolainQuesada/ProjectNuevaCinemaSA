#include<iostream>
#include "Seat.h"


Seat::Seat() {
    id = 0;
    state = 'D';
}

Seat::Seat(int id, char state) {
    this->id  =id;
    this->state= state;
}

// Getters
int Seat::getId() {
    return id;
}

char Seat::getState() {
    return state;
}

// Setters
void Seat::setId(int id) {
    this->id = id;
}

void Seat::setState(char state) {
    this->state = state;
}

// Metodos para manejar el estado del asiento
void Seat::reserve() {
    if (state == 'D') { 
        state = 'R'; 
    }
}

void Seat::sell() {
    if (state == 'R') {
        state = 'V'; 
    }
}

void Seat::reset() {
    if (state == 'R') {
        state = 'D'; 
    }
}


