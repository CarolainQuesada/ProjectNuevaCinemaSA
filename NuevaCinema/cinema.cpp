#include <iostream>
#include "cinema.h"
#include "movie.h"
#include "room.h"
#include "schedule.h"
#include <string>

using namespace std;

Cinema::Cinema() : movieCount(4), roomCount(3), scheduleCount(4), reservationCount(0), reservationIndex(0) {

    movieList[0] = Movie("Deadpool", 2016, 108, "USA", 8);
    movieList[1] = Movie("Coraline", 2009, 100, "USA", 9);
    movieList[2] = Movie("Romper el Circulo", 2022, 120, "Espania", 7);
    movieList[3] = Movie("Tinkerbell", 2008, 76, "USA", 6);

   roomList[0] = Room(1, 80, 3500);
    roomList[1] = Room(2, 80, 4500);
    roomList[2] = Room(3, 80, 5500);

    scheduleList[0] = Schedule("Deadpool", 14, 30, "2024-09-01", 1);
    scheduleList[1] = Schedule("Coraline", 16, 45, "2024-09-01", 2);
    scheduleList[2] = Schedule("Romper el Circulo", 19, 30, "2024-09-01", 3);
    scheduleList[3] = Schedule("Tinkerbell", 21, 00, "2024-09-01", 1);
     
}

void Cinema::menuFile() {
    int subOption;
    cout << "Archivo" << endl;
    cout << "1. Acerca de" << endl;
    cout << "2. Salir" << endl;
    cout << "Selecciona una opcion: ";

    subOption= getInt();
    

    if (subOption == 1) {
        cout << "\nMostrando informacion acerca del sistema.\n" << endl;
        showAbout();
        system("pause");
    }
    else if (subOption == 2) {
        cout << "Saliendo del submenu de archivo." << endl;
        system("pause");
    }
    else {
        cout << "Opcion invalida en archivo." << endl;
    }
}

void Cinema::maintenanceMenu() {
    int subOption;
    cout << "Mantenimiento" << endl;
    cout << "1. Peliculas" << endl;
    cout << "2. Salas" << endl;
    cout << "3. Horarios" << endl;
    cout << "Selecciona una opcion: ";
    cin >> subOption;

    if (subOption == 1) {
        int action;
        cout << "1. Mostrar peliculas\n2. Agregar nueva pelicula" << endl;
        cout << "Selecciona una opcion: ";
        action = getInt();
        

        if (action == 1) {
            displayMovieData();
            int movieIndex;
            cout << "Selecciona la pelicula que desea ver: ";
            movieIndex = getInt();

            showMovieInformation(movieIndex - 1);
        }
        else if (action == 2) {
            addNewMovie();
            displayMovieData();
        }
        else {
            cout << "Opcion invalida en mantenimiento" << endl;
        }
    }
    else if (subOption == 2) {
        showRoomInformation(); 
    }
    else if (subOption == 3) {
        int action;
        cout << "1. Mostrar harios \n2. Agregar nuevo horario" << endl;
        cout << "Selecciona una opcion: ";
        action = getInt();
       

        if (action == 1) {
            displayScheduleData();
        }
 
        else if (action == 2) {
            addNewSchedule();
        }

        else {
            cout << "Opcion invalida en mantenimiento" << endl;
        }
    }
    else {
        cout << "Opcion invalida en mantenimiento" << endl;
    }
}

void Cinema::reservationMenu() {
    int subOption;
    while (true) {
        cout << "Reserva" << endl;
        cout << "1. Seleccionar pelicula" << endl;
        cout << "2. Volver" << endl;
        cout << "Selecciona una opcion: ";
       subOption= getInt();
       

        if (subOption == 1) {
            handleSeatReservation(); 
        }
        else if (subOption == 2) {
            cout << "Volviendo al menu principal." << endl;
            break;
        }
        else {
            cout << "Opcion invalida en reserva." << endl;
        }
    }
}
// Menu de Venta
void Cinema::saleMenu() {
    int subOption;
    cout << "Venta" << endl;
    cout << "1. Realizar venta" << endl;
    cout << "Selecciona una opcion: ";
   subOption= getInt();

    if (subOption == 1) {
        showSale(); 
    }
    else {
        cout << "Opcion invalida en venta." << endl;
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
    cout << "\nPeliculas disponibles:\n" << endl;

    for (int i = 0; i < movieCount; i++) {
        cout << (i + 1) << "- " << movieList[i].getName() << endl;
    }
}

void Cinema::showMovieInformation(int index) {
    if (index >= 0 && index < MAX_MOVIES) {
        cout << "\nInformacion  de la pelicula:" << endl;
        movieList[index].movieInformation();
    }
    else {
        cout << " Opcion invalida." << endl;
    }
    system("pause");
    system("cls");
}


bool Cinema::addMovie(Movie& movie) {
    if (movieCount >= MAX_MOVIES) {
        cout << "No se pueden agregar mas peliculas" << endl;
        return false;
    }
    movieList[movieCount++] = movie;
    return true;
}

void Cinema::addNewMovie() {
    string name, country;
    int year, reviews, time;
    Movie movie;

    cout << "Ingrese el nombre de la pelicula: ";
    name = readString();
    movie.setName(name);

    cout << "Ingrese el anio de la pelicula: ";
    year = getInt();
    movie.setYear(year);

    cout << "Ingrese la duracion de la pelicula (minutos): ";
    time = getInt();
    movie.setTime(time);

    cout << "Ingrese el pais de la pelicula: ";
    country = readString();
    movie.setCountry(country);

    cout << "Ingrese la resenia de la pelicula calificando del 1 al 10: ";
    reviews= getInt();
    movie.setReviews(reviews);

    if (reviews < 1 || reviews > 10) {
        cout << "Calificacion invalida, debe ser un numero entre 1 y 10" << endl;
        return;
    }

    Movie newMovie(name, year, time, country, reviews);
    if (addMovie(newMovie)) {
        cout << "Pelicula agregada exitosamente" << endl;
    }
}

void Cinema::showRoomInformation() {
    cout << "\nInformacion de las salas:\n" << endl;

    for (int i = 0; i < roomCount; ++i) {
        roomList[i].showRoomInfo();
    }
    system("pause");
    system("cls");
}


void Cinema::displayScheduleData() {

    cout << "\nHorarios disponibles:\n" << endl;

    for (int i = 0; i < scheduleCount; i++) {
        cout << (i + 1) << "-Pelicula: " << scheduleList[i].getMovieName()
            << ", Fecha: " << scheduleList[i].getDate()
            << ", Hora de inicio: " << scheduleList[i].getStartHour() << ":00"
            << ", Hora de fin: " << scheduleList[i].getEndHour() << ":00"
            << ", Sala: " << scheduleList[i].getRoomNumber() << endl;
    }
    system("pause");
    system("cls");
}

bool Cinema::addSchedule(Schedule& schedule) {
    if (scheduleCount >= MAX_SCHEDULES) {
        cout << "No se pueden agregar más horarios" << endl;
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
    cout << "Ingrese el nombre de la pelicula: ";
    movieNumber = getInt();
    if (movieExists(movieNumber)) {
        cout << "Ingrese la fecha del horario (YYYY-MM-DD): ";
        date = readString();

        cout << "Ingrese la hora de inicio (24h): ";
        startHour = getInt();

        cout << "Ingrese la hora de fin (24h): ";
        endHour = getInt();

        cout << "Ingrese el numero de sala: ";
        selectRoomNumber = getInt();
        

        if (selectRoomNumber <= MAX_ROOMS && selectRoomNumber >= 1) {
            
            
            if (startHour < 0 || startHour >= 24 || endHour < 0 || endHour >= 24 || endHour <= startHour) {
                cout << "Horario invalido. Asegurese de que la hora de inicio sea menor que la hora de fin y que este en el rango valido (0-23)." << endl;
                system("pause");
                return;


            }
            Schedule newSchedule(movieList[movieNumber - 1].getName(), startHour, endHour, date, selectRoomNumber);
            if (addSchedule(newSchedule)) {
                cout << "Horario agregado exitosamente" << endl;
                system("pause");
            }
        }
        else {
            cout << "Error! salida no valida!";
            system("pause");
        }
    }
    else {
        cout << "Error!! Pelicula no valida!";
        system("pause");
    }
}
void Cinema::displayScheduleDataForMovie(int movieIndex) {
    cout << "\nHorarios disponibles para la pelicula " << movieList[movieIndex].getName() << ":\n" << endl;

    for (int i = 0; i < scheduleCount; i++) {
        if (scheduleList[i].getMovieName() == movieList[movieIndex].getName()) {
            cout << (i + 1) << "- Fecha: " << scheduleList[i].getDate()
                << ", Hora de inicio: " << scheduleList[i].getStartHour() << ":00"
                << ", Hora de fin: " << scheduleList[i].getEndHour() << ":00"
                << ", Sala: " << scheduleList[i].getRoomNumber() << endl;
        }
    }
}

void Cinema::showRoomInformationForSchedule(int scheduleIndex) {
    int roomNumber = scheduleList[scheduleIndex].getRoomNumber() - 1; 
    cout << "\nInformacion de la sala para el horario seleccionado:\n" << endl;
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
        cout << "Asiento no valido." << endl;
    }
}

void Cinema::handleSeatReservation() {
    system("cls");
 
    cout << RED <<"Aviso importante!!!\n" <<RESET<< endl;
    cout << "Si la reserva no ha sido cancelada 30 minutos antes de iniciar la pelicula" << endl;
    cout << "los asientos no pueden ser vendidos y no hay derecho a reclamos\n" << endl;
    
    displayMovieData();

    int movieIndex;
    cout << "Selecciona la pelicula que desea reservar (1-" << movieCount << "): ";
    movieIndex = getInt() - 1;

    if (movieIndex >= 0 && movieIndex < movieCount) {
        displayScheduleDataForMovie(movieIndex);

        int scheduleIndex;
        cout << "Selecciona el horario deseado (1-" << scheduleCount << "): ";
        scheduleIndex = getInt() - 1;

        if (scheduleIndex >= 0 && scheduleIndex < scheduleCount) {
            showRoomInformationForSchedule(scheduleIndex);

            int roomNumber = scheduleList[scheduleIndex].getRoomNumber() - 1;

            showSeats(seatsRoom[roomNumber]);

            int row, col;
            cout << "Ingrese la fila del asiento (1-" << ROWS << "): ";
            row = getInt() - 1;
            cout << "Ingrese la columna del asiento (1-" << COLUMS << "): ";
            col = getInt() - 1;

            if (row >= 0 && row < ROWS && col >= 0 && col < COLUMS) {
                if (seatsRoom[roomNumber][row][col].getState() == 'D') {
                    reserveSeat(seatsRoom[roomNumber], row, col);
                    cout << "Asiento reservado exitosamente" << endl;
                    


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
    cout << "Ingrese el numero de reserva: ";
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
                    cout << "El asiento no estaba reservado." << endl;
                }
            }

            else {
                cout << "Numero de asiento no valido" << endl;
            }

            string idNumber, cardNumber;
            cout << "Ingrese el numero de cedula del cliente: ";
            idNumber = readString();
            cout << "Ingrese el numero de tarjeta de credito del cliente: ";
            cardNumber = readString();
            cout << "Pago realizado exitosamente. Numero de reserva: " << reservationNumber << endl; 
            break;
        }
    }
    if (!found) {
        cout << "Numero de reserva no valido o ya utilizado." << endl;
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