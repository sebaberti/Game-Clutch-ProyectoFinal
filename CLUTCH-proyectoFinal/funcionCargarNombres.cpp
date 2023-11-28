#include "funciones.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include<iostream>


using namespace std;
void cargarNombres(string nombresJugadores[])
{
    char confirmados;


    cout << "Antes de comenzar deben ingresar sus nombres."<< endl;
    for (int i=0 ; i<2 ; i++)
    {

        cout << "Ingresar jugadores: " ;
        cin >> nombresJugadores[i];
    }

    while(nombresJugadores[0] == nombresJugadores[1] )
    {
        cout << endl << "Los nombres de los jugadores NO pueden ser iguales\n\nPor favor ingresar nombre del jugador 2: " <<endl ;
        cin >> nombresJugadores[1];

    }

    cout << "Nombre jugador 1: " << nombresJugadores[0] << endl;
    cout << "Nombre jugador 2: " << nombresJugadores[1] << endl;


    cout << endl << "\nConfirmar nombres? (S/N): ";
    cin >> confirmados ;
    system("cls");

    while (confirmados == 'n' || confirmados == 'N')
    {
        cout << endl << "Ingresar nombre jugador 1: " ;
        cin >> nombresJugadores[0];

        cout << endl << "Ingresar nombre jugador 2: " ;
        cin >> nombresJugadores[1];

        while(nombresJugadores[0] == nombresJugadores[1])
        {
            cout << endl<< "Los nombres de los jugadores NO pueden ser iguales\nPor favor ingresar nombre del jugador 2: ";
            cin >> nombresJugadores[1];

        }
        cout << "Confirmar nombres? (S/N): " ;
        cin >> confirmados ;
    }
}
