#include <iostream>
using namespace std;
#include <string>
#include"movie.h"
#include"seat.h"
#include"room.h"
#include"booking.h"
#include"sale.h"
#include"schedule.h"
#include"cinema.h"

int main()
{
    Cinema cinema; 
    int option;

    do {
        cout << "Menu Principal" << "\n" << endl;
        cout << "1. Archivo" << endl;
        cout << "2. Mantenimiento" << endl;
        cout << "3. Reserva" << endl;
        cout << "4. Venta" << endl;
        cout << "5. Salir" << endl;
        cout << "\nSelecciona una opcion:" << endl;
        cin >> option;
        system("cls");

        switch (option) {
        case 1:
            cinema.menuFile();
            system("cls");
            break;
        case 2:
            cinema.maintenanceMenu();
            system("cls");
            break;
        case 3:
            cinema.reservationMenu();
            system("cls");
            break;
        case 4:
            cinema.saleMenu();
            system("cls");
            break;
        case 5:
            cout << "Saliendo..." << endl;
            system("cls");
            break;
        default:
            cout << "Opcion invalida!!" << "\n" << endl;
        }
    } while (option != 5);

    return 0;
}
