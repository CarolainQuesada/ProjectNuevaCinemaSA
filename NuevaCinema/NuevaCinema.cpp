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
        cout << YELLOW << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "                                 " << RED <<" |Menu Principal| " << RESET << CYAN << "                       " <<"\n"<<endl;
        cout << YELLOW << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "1. Archivo" << endl;
        cout << YELLOW << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "2. Mantenimiento" << endl;
        cout << YELLOW << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "3. Reserva" << endl;
        cout << YELLOW << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "4. Venta" << endl;
        cout << YELLOW << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "5. Salir" << endl;
        cout << YELLOW << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "\nSelecciona una opcion:" << endl;        
        cout << YELLOW << "--------------------------------------------------------------------------------------" << RESET << endl;

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
            cout << RED << "--------------------------------------------------------------------------------------" << RESET << endl;
            cout << "Saliendo..." << endl;
            cout << RED << "--------------------------------------------------------------------------------------" << RESET << endl;

            system("cls");
            break;
        default:
            cout << RED << "--------------------------------------------------------------------------------------" << RESET << endl;
            cout << "Opcion invalida!!" << "\n" << endl;
            cout << RED << "--------------------------------------------------------------------------------------" << RESET << endl;

        }
    } while (option != 5);

    return 0;
}
