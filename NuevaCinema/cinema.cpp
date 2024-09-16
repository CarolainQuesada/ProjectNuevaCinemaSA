#include <iostream>
#include "cinema.h"
#include "movie.h"
#include "room.h"
#include "schedule.h"
#include <string>

using namespace std;

Cinema::Cinema() : movieCount(4), roomCount(3), scheduleCount(4), reservationCount(0), reservationIndex(0) {

    movieList[0] = Movie("Deadpool", 2016, 120, "USA", 8);
    movieList[1] = Movie("Coraline", 2009, 120, "USA", 9);
    movieList[2] = Movie("Romper el Circulo", 2022, 120, "Espania", 7);
    movieList[3] = Movie("Tinkerbell", 2008, 60, "USA", 6);

   roomList[0] = Room(1, 80, 3500);
    roomList[1] = Room(2, 80, 4500);
    roomList[2] = Room(3, 80, 5500);

    scheduleList[0] = Schedule("Deadpool", 14, 16, "2024-09-01", 1);
    scheduleList[1] = Schedule("Coraline", 10, 12, "2024-09-01", 2);
    scheduleList[2] = Schedule("Romper el Circulo", 19, 21, "2024-09-01", 3);
    scheduleList[3] = Schedule("Tinkerbell", 21, 22, "2024-09-01", 1);
     
}

void Cinema::menuFile() {
    int subOption;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Archivo" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "1. Acerca de" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "2. Salir" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Selecciona una opcion: "<<endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    subOption= getInt();
    

    if (subOption == 1) {
        system("cls");
        cout << RED << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "Mostrando informacion acerca del sistema" << endl;
        cout << RED << "--------------------------------------------------------------------------------------\n" << RESET << endl;
        showAbout();
        system("pause");
    }
    else if (subOption == 2) {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "Saliendo del submenu de archivo." << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        system("pause");
    }
    else {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "Opcion invalida en archivo." << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    }
}

void Cinema::maintenanceMenu() {
    int subOption;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Mantenimiento" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "1. Peliculas" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "2. Salas" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "3. Horarios" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Selecciona una opcion: "<<endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cin >> subOption;

    if (subOption == 1) {
        int action;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "1. Mostrar peliculas\n2. Agregar nueva pelicula" << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "Selecciona una opcion: "<<endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        action = getInt();
        system("cls");
        if (action == 1) {
            displayMovieData();
            int movieIndex;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            cout << "Selecciona la pelicula que desea ver: "<<endl;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

            movieIndex = getInt();

            showMovieInformation(movieIndex - 1);
        }
        else if (action == 2) {
            addNewMovie();
            displayMovieData();
        }
        else {
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

            cout<<RED << "Opcion invalida en mantenimiento!!" <<RESET<< endl;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        }
    }
    else if (subOption == 2) {
        showRoomInformation(); 
    }
    else if (subOption == 3) {
        int action;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "1. Mostrar horarios \n2. Agregar nuevo horario" << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "Selecciona una opcion: "<<endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        action = getInt();
       

        if (action == 1) {
            displayScheduleData();
        }
 
        else if (action == 2) {
            addNewSchedule();
        }

        else {
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            cout << RED << "Opcion invalida en mantenimiento!!" << RESET << endl;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        }
    }
    else {
        cout<<RED << "Opcion invalida en mantenimiento!!"<<RESET << endl;
    }
}

void Cinema::reservationMenu() {
    int subOption;
    while (true) {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "Reserva" << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "1. Seleccionar pelicula" << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "2. Volver" << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "Selecciona una opcion: "<<endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
       subOption= getInt();
       
        if (subOption == 1) {
            handleSeatReservation(); 
        }
        else if (subOption == 2) {
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            cout << "Volviendo al menu principal." << endl;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            break;
        }
        else {
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            cout << RED << "Opcion invalida en reserva!!" << RESET << endl;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        }
    }
}
// Menu de Venta
void Cinema::saleMenu() {
    int subOption;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Venta" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "1. Realizar venta" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Selecciona una opcion: "<<endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
   subOption= getInt();
    if (subOption == 1) {
        showSale(); 
    }
    else {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << RED << "Opcion invalida en venta!!" << RESET << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    }
}
void Cinema::showAbout() {
 

    cout << CYAN << "*********************************************************" << RESET << endl;
    cout << CYAN << "*         " << GREEN << "Bienvenido al sistema de ventas" << CYAN << "          \t*" << RESET << endl;
    cout << CYAN << "*             " << GREEN <<   "de boletos para el cine "<< CYAN << "           \t*" << RESET << endl;
    cout << CYAN << "*                  " << RED << "Nueva Cinema SA" << CYAN << "                 \t*" << RESET << endl;
    cout << CYAN << "*                                                       *" << RESET << endl;
    cout << CYAN << "*      " << YELLOW << "Este innovador sistema ha sido creado" << CYAN << "     \t*" << RESET << endl;
    cout << CYAN << "*     " << YELLOW << "con dedicacion y pasion por Carolain Q.S" << CYAN << "      \t*" << RESET << endl;
    cout << CYAN << "*                                                       *" << RESET << endl;
    cout << CYAN << "*     " << GREEN << "Disfruta de una experiencia cinematografica" << CYAN << " \t*" << RESET << endl;
    cout << CYAN << "*   " << GREEN << "inolvidable y elige tus asientos con facilidad!" << CYAN << " \t*" << RESET << endl;
    cout << CYAN << "*********************************************************" << RESET << endl;
}


void Cinema::displayMovieData() {

    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "\nPeliculas disponibles:" << endl;
    cout<< CYAN << "--------------------------------------------------------------------------------------\n" <<RESET<< endl;

    for (int i = 0; i < movieCount; i++) {
        cout << (i + 1) << "- " << movieList[i].getName() << endl;
        cout << "--------------------------------------------------------------------------------------" << endl;

    }
}

void Cinema::showMovieInformation(int index) {
    if (index >= 0 && index < MAX_MOVIES) {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << "\nInformacion  de la pelicula:" << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        movieList[index].movieInformation();
    }
    else {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout << " Opcion invalida." << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    }
    system("pause");
    system("cls");
}


bool Cinema::addMovie(Movie& movie) {
    if (movieCount >= MAX_MOVIES) {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        cout <<RED<< "No se pueden agregar mas peliculas"<<RESET << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        return false;
    }
    movieList[movieCount++] = movie;
    return true;
}

void Cinema::addNewMovie() {
    string name, country;
    int year, reviews, time;
    Movie movie;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Ingrese el nombre de la pelicula: "<<endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    name = readString();
    movie.setName(name);

    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Ingrese el anio de la pelicula: "<<endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    year = getInt();
    movie.setYear(year);

    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Ingrese la duracion de la pelicula (minutos): "<<endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    time = getInt();
    movie.setTime(time);

    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Ingrese el pais de la pelicula: "<<endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    country = readString();
    movie.setCountry(country);

    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "Ingrese la resenia de la pelicula calificando del 1 al 10: "<<endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    reviews= getInt();
    movie.setReviews(reviews);

    if (reviews < 1 || reviews > 10) {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        cout<<RED<< "Calificacion invalida!! Debe ser un numero entre 1 y 10" <<RESET<< endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        return;
    }

    Movie newMovie(name, year, time, country, reviews);
    if (addMovie(newMovie)) {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout <<YELLOW<< "Pelicula agregada exitosamente"<< RESET << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    }
}

void Cinema::showRoomInformation() {
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "\nInformacion de las salas:\n" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    for (int i = 0; i < roomCount; ++i) {
        roomList[i].showRoomInfo();
    }
    system("pause");
    system("cls");
}


void Cinema::displayScheduleData() {
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << "\nHorarios disponibles:\n" << endl;
    cout << CYAN << "----------------------------------------------------------------------------------------------------" << RESET << endl;
    for (int i = 0; i < scheduleCount; i++) {
        cout << CYAN << "----------------------------------------------------------------------------------------------------" << RESET << endl;
        cout << (i + 1) << "-Pelicula: " << "|" <<scheduleList[i].getMovieName() << "|"
            << " Fecha: " << scheduleList[i].getDate()
            << " Hora de inicio: " << "|" <<scheduleList[i].getStartHour() << ":00" << "|"
            << " Hora de fin: " << "|" <<scheduleList[i].getEndHour() << ":00" << "|"
            << " Sala: " << "|" << scheduleList[i].getRoomNumber() << "|" << endl;
        cout << CYAN << "----------------------------------------------------------------------------------------------------" << RESET << endl;

    }
    system("pause");
    system("cls");
}

bool Cinema::addSchedule(Schedule& schedule) {
    if (scheduleCount >= MAX_SCHEDULES) {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        cout <<RED<< "No se pueden agregar más horarios!"<<RESET << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
        return false;
    }
    scheduleList[scheduleCount++] = schedule;
    return true;
}


bool Cinema::movieExists(int movieNumber) {
    if (movieNumber <= movieCount && movieNumber >= 1) {
        return true;
    }
    return false;
}



void Cinema::addNewSchedule() {
    string date;
    int movieNumber;
    int startHour, endHour, selectRoomNumber;

    displayMovieData();
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    cout << "Ingrese el nombre de la pelicula: " << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    movieNumber = getInt();
    if (movieExists(movieNumber)) {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        cout << "Ingrese la fecha del horario (YYYY-MM-DD): " << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        date = readString();
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        cout << "Ingrese la hora de inicio (24h): " << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        startHour = getInt();
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        cout << "Ingrese la hora de fin (24h): " << endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        endHour = getInt();
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        cout << "Ingrese el numero de sala: "<<endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        selectRoomNumber = getInt();
        

        if (selectRoomNumber <= MAX_ROOMS && selectRoomNumber >= 1) {
            
            
            if (startHour < 0 || startHour >= 24 || endHour < 0 || endHour >= 24 || endHour <= startHour) {
                cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
                cout << "Horario invalido. Asegurese de que la hora de inicio sea menor que la hora de fin y que este en el rango valido (0-23)." << endl;
                cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
                system("pause");
                return;


            }
            Schedule newSchedule(movieList[movieNumber - 1].getName(), startHour, endHour, date, selectRoomNumber);
            if (addSchedule(newSchedule)) {
                cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
                cout <<YELLOW<< "Horario agregado exitosamente!" <<RESET<< endl;
                cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

                system("pause");
            }
        }
        else {
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

            cout <<RED<< "Error! salida no valida!"<<RESET<<endl;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

            system("pause");
        }
    }
    else {
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        cout <<RED << "Error!! Pelicula no valida!"<<RESET<<endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        system("pause");
    }
}
void Cinema::displayScheduleDataForMovie(int movieIndex) {
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    cout<<RED << "\nHorarios disponibles para la pelicula " << movieList[movieIndex].getName() << ":\n"<<RESET << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    for (int i = 0; i < scheduleCount; i++) {
        if (scheduleList[i].getMovieName() == movieList[movieIndex].getName()) {
            cout << (i + 1) << "- Fecha: " << scheduleList[i].getDate()
                << ", Hora de inicio: " << scheduleList[i].getStartHour() << ":00"
                << ", Hora de fin: " << scheduleList[i].getEndHour() << ":00"
                << ", Sala: " << scheduleList[i].getRoomNumber() << endl;

        }
    }
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
}

void Cinema::showRoomInformationForSchedule(int scheduleIndex) {
    int roomNumber = scheduleList[scheduleIndex].getRoomNumber() - 1; 
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    cout <<RED<< "\nInformacion de la sala para el horario seleccionado:\n"<<RESET << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    roomList[roomNumber].showRoomInfo();
}


void Cinema::showSeats(Seat seatsRoom[ROWS][COLUMS]) {

    cout << "--------Butacas-------\n";
    cout << "\n    (1)(2)(3)(4)(5)(6)(7)(8)(9)(10)"<<endl;
    for (int i = 0; i < ROWS; i++) {
        cout <<"(" << i + 1 << ")"<<" ";
        for (int j = 0; j < COLUMS; j++) {
            char state = seatsRoom[i][j].getState();
            cout << "[" << state << "]";
        }
        cout << "\n";
    }
}

void Cinema::reserveSeat(Seat seatsRoom[ROWS][COLUMS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLUMS) {
        seatsRoom[row][col].reserve();
    }
    else {
        cout << "Asiento no valido." << endl;
    }
}

void Cinema::sellSeat(Seat seatsRoom[ROWS][COLUMS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLUMS) {
        seatsRoom[row][col].sell();
    }
    else {
        cout <<RED<< "Asiento no valido!" <<RESET<< endl;
    }
}

void Cinema::handleSeatReservation() {
    system("cls");
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout << RED <<"Aviso importante!!!\n" <<RESET<< endl;
    cout << "Si la reserva no ha sido cancelada 30 minutos antes de iniciar la pelicula" << endl;
    cout << "los asientos no pueden ser vendidos y no hay derecho a reclamos\n" << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    displayMovieData();

    int movieIndex;
    cout << "Selecciona la pelicula que desea reservar (1-" << movieCount << "): " << endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

    movieIndex = getInt() - 1;

    if (movieIndex >= 0 && movieIndex < movieCount) {
        displayScheduleDataForMovie(movieIndex);

        int scheduleIndex;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        cout<< "Selecciona el horario deseado (1-" << scheduleCount << "): "<<endl;
        cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

        scheduleIndex = getInt() - 1;

        if (scheduleIndex >= 0 && scheduleIndex < scheduleCount) {
            showRoomInformationForSchedule(scheduleIndex);

            int roomNumber = scheduleList[scheduleIndex].getRoomNumber() - 1;

            showSeats(seatsRoom[roomNumber]);

            int row, col;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

            cout << "Ingrese la fila del asiento (1-" << ROWS << "): " << endl;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

            row = getInt() - 1;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

            cout << "Ingrese la columna del asiento (1-" << COLUMS << "): " << endl;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;

            col = getInt() - 1;

            if (row >= 0 && row < ROWS && col >= 0 && col < COLUMS) {
                if (seatsRoom[roomNumber][row][col].getState() == 'D') {
                    reserveSeat(seatsRoom[roomNumber], row, col);
                    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
                    cout <<YELLOW<< "Asiento reservado exitosamente!" <<RESET<< endl;
                    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
                   
                    double price = roomList[roomNumber].getPrice();
                    cout << "Precio de la reserva: " << price << endl;

                    int reservationNumber = ++reservationIndex;
                    reservationNumbers[reservationCount] = reservationNumber;
                    reservationRoom[reservationCount] = roomNumber; 
                    reservationRow[reservationCount] = row;        
                    reservationCol[reservationCount] = col;    
                    reservationStatus[reservationCount++] = true;
                    cout << "Numero de reserva: " << reservationNumber << endl;

                    char another;
                    cout << "Desea reservar otro asiento? (s o n): ";
                    cin >> another;
                    if (another == 'n' || another == 'N') {
                        return;
                    }
                }
                else {
                    cout << "El asiento no esta disponible para reserva" << endl;
                }
            }
            else {
                cout << "Numero de asiento no valido" << endl;
            }
        }
        else {
            cout << "Horario no valido" << endl;
        }
    }
    else {
        cout << "Pelicula no valida" << endl;
    }
}

void Cinema::showSale() {
    int reservationNumber;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    cout <<RED<< "Ingrese el numero de reserva: "<<RESET<<endl;
    cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
    reservationNumber = getInt();

    bool found = false;

    for (int i = 0; i < reservationCount; i++) {
        if (reservationNumbers[i] == reservationNumber && reservationStatus[i]) {
            found = true;
            reservationStatus[i] = false; 

            int roomNumber = reservationRoom[i];
            int row = reservationRow[i];
            int col = reservationCol[i];

            if (row >= 0 && row < ROWS && col >= 0 && col < COLUMS) {
                if (seatsRoom[roomNumber][row][col].getState() == 'R') {
                    sellSeat(seatsRoom[roomNumber], row, col);
                }
                else {
                    cout<<RED << "El asiento no estaba reservado." <<RESET<< endl;
                }
            }
            else {
                cout << "Numero de asiento no valido!" << endl;
            }

            string idNumber, cardNumber;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            cout << "Ingrese el numero de cedula del cliente: "<<endl;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            idNumber = readString();
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            cout << "Ingrese el numero de tarjeta de credito del cliente: "<<endl;
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            cardNumber = readString();
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            cout<<YELLOW << "Pago realizado exitosamente. Numero de reserva: " << reservationNumber <<RESET<< endl; 
            cout << CYAN << "--------------------------------------------------------------------------------------" << RESET << endl;
            break;
        }
    }
    if (!found) {
        cout <<RED<< "Numero de reserva no valido o ya utilizado!" << RESET<< endl;
    }
    system("pause");
}
        
string Cinema::readString() {
    string read;
   getline(cin, read);
    return read;
}

int Cinema::getInt() {
    int number;
    bool notNumber = true;
    while (notNumber) {
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Favor Digite un Entero." << endl;
            notNumber = true;
        }
        else {
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            notNumber = false;
        }
    }
    return number;
}

double Cinema::getDouble() {
    double number;
    bool notNumber = true;
    while (notNumber) {
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Favor digitar un numero." << endl;
            notNumber = true;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            notNumber = false;
        }
    }
    return number;
}