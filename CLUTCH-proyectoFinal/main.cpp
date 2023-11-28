#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "funciones.h"

using namespace std;

string nombresJugadores[2];
string nombre;
int acumuladorPuntosJugador = 0;
int ganadorJugadorNum =0 ;
int maxPuntaje = 0;

int main()
{
    char opcion, fin ;
    //////////////////// MENU ////////////////////
    while (true)
    {
        cout << "CLUTCH" << endl;
        cout << "------------------------" << endl;
        cout << "1 - Jugar" << endl;
        cout << "2 - Estad" << (char)161 << "sticas" << endl;
        cout << "3 - Cr" << (char)130 << "ditos" << endl;
        cout << "------------------------" << endl;
        cout << "0 - Salir" << endl << endl ;

        cout << "Elegir Opci" << (char)162 << "n: ";

        cin >> opcion;

        system("cls");
        switch (opcion)
        {
        case '1':
            jugar(nombresJugadores,acumuladorPuntosJugador,ganadorJugadorNum);
            break;

        case '2':
            mostrarEstadisticas(nombresJugadores,nombre,acumuladorPuntosJugador,ganadorJugadorNum, maxPuntaje);
            break;

        case '3':
            mostrarCreditos();
            break;

        case '0':
            cout << "Desea salir del juego? (s/n)";
            cin >> fin ;

            if (fin == 's' || fin == 'S')
            {
                return 0;
            }

            break;

        default:
            cout << "La opci" << (char)162 << "n seleccionada no existe" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
