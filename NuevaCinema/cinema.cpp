#include <iostream>

#include"cinema.h"
#include"movie.h"

#include <string>
#include <limits> 

using namespace std;


// Constructor que inicializa la lista de peliculas
Cinema::Cinema(): movieCount(4) {

    movieList[0] = Movie("Deadpool", 2016, 108, "USA", 8);
    movieList[1] = Movie("Coraline", 2009, 100, "USA", 9);
    movieList[2] = Movie("Romper el Circulo", 2022, 120, "Espania", 7);
    movieList[3] = Movie("Tinkerbell", 2008, 76, "USA", 6);
}

// Mostrar la lista de peliculas
void Cinema::displayMovieData() {
    cout << "\nPeliculas disponibles:\n" << endl;

    for (int i = 0; i < 5; i++) {
        cout << (i +1) << "- " << movieList[i].getName()<<endl;
    }
}

// Mostrar detalles de una pelicula
void Cinema::showMovieInformation(int index) {

    if (index >= 0 && index < MAX_MOVIES) {
       
        cout << "\nInformacion  de la pelicula:" << endl;
        movieList[index].movieInformation();
        //cout << "Presiona enter para continuar";
       // cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    else {
        cout << " Opcion invalida." << endl;
    }
    system("pause");

    system("cls");
}
void Cinema::showAbout() {
    cout << "El sistema de venta de tickets para el cine Nueva Cienma SA fue desarrollado por Carolain Quesada Soto" << endl;
}


// Add a movie to the collection
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
    int year, review, time;

    cout << "Ingrese el nombre de la pelicula: ";
   getline(cin,name);

    cout << "Ingrese el anio de la pelicula: ";
    cin >> year;

    cout << "Ingrese la duracion de la pelicula (minutos): ";
    cin >> time;

    cout << "Ingrese el país de origen de la pelíocula: ";
    cin.ignore(); // Clear the newline character left in the input buffer
    getline(cin,country);

    cout << "Ingrese la resenia de la pelicula calificando del 1 al 10: ";
    cin>> review;

    // Validar calificación
    if (review < 1 || review> 10) {
        cout << "Calificacion invalida. Debe ser un numero entre 1 y 10." << endl;
        return;
    }

    // Create a new movie object and add it to the collection
    Movie newMovie(name, year, time, country, review);
    if (addMovie(newMovie)) {
        cout << "Pelicula agregada exitosamente." << endl;
    }
}



// Menu de Archivo
void Cinema::menuFile() {
    int subOption;
    cout << "Archivo" << endl;
    cout << "1. Acerca de" << endl;
    cout << "2. Salir" << endl;
    cout << "Selecciona una opcion: ";
    cin >> subOption;
    cin.ignore();
    switch (subOption) {
    case 1:
        cout << "\nMostrando informacion acerca del sistema.\n" << endl;
        {
            showAbout();
        }
        system("pause");
        break;
    case 2:
        cout << "Saliendo del submenu de archivo." << endl;
        system("pause");
        break;
    default:
        cout << "Opcion invalida en archivo." << endl;
    }
}

// Menu de Mantenimiento
void Cinema::maintenanceMenu() {
    int subOption;
    cout << "Mantenimiento" << endl;
    cout << "1. Películas" << endl;
    cout << "2. Salas" << endl;
    cout << "3. Horarios" << endl;
    cout << "Selecciona una opción: ";
    cin >> subOption;
    switch (subOption) {
    case 1:
        int action;
        cout << "1. Mostrar películas\n2. Agregar nueva pelicula" << endl;
        cout << "Selecciona una opción: ";
        cin >> action;
        cin.ignore();
        switch (action) {
        case 1:
            displayMovieData();
            int movieIndex;
            cout << "Selecciona la pelicula que desea ver: ";
            cin >> movieIndex;
            cin.ignore();
            showMovieInformation(movieIndex - 1);
            break;
        case 2:
            addNewMovie();
            break;
        default:
            cout << "Opcion invalida en mantenimiento" << endl;
        }
        break;
    case 2:
        cout << "Opciones para gestionar salas" << endl;
        break;
    case 3:
        cout << "Opciones para gestionar horarios" << endl;
        break;
    default:
        cout << "Opcion invalida en mantenimiento" << endl;
    }
}

// Menu de Reserva
void Cinema::reservationMenu() {
    int subOption;
    cout << "Reserva" << endl;
    cout << "1. Peliculas" << endl;
    cout << "Selecciona una opcion: ";
    cin >> subOption;
    switch (subOption) {
    case 1:
        cout << "Opciones para reservar peliculas." << endl;
        break;
    default:
        cout << "Opcion invalida en reserva." << endl;
    }
}

// Menu de Venta
void Cinema::saleMenu() {
    int subOption;
    cout << "Venta" << endl;
    cout << "1. Peliculas" << endl;
    cout << "Selecciona una opcion: ";
    cin >> subOption;
    switch (subOption) {
    case 1:
        cout << "Opciones para vender peliculas." << endl;
        break;
    default:
        cout << "Opcion invalida en venta." << endl;
    }
}
