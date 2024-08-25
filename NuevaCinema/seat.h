#pragma once

#include <iostream>

using namespace std;

class Seat {
private:
    int id;
    string state; //Disponible | Reservada | Vendida
public:
    Seat();
    Seat(int id, string state);

    // Getters
    int getId();
    string getState();

    // Setters
    void setId(int id);
    void setState(string state);
};