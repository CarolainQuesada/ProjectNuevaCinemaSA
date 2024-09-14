#ifndef SEAT_H
#define SEAT_H

class Seat {
private:
    int id;
    char state; // 'D'aviavle,'R' boked,'V' sold

public:
    Seat();
    Seat(int id, char state);

    // Getters
    int getId();
    char getState();

    // Setters
    void setId(int id);
    void setState(char state);

     
    // Cambia el estado a reservada
    void reserve();
    // Cambia el estado a vendida
    void sell();
    // Cambia el estado a disponible
    void reset();
};

#endif
