#include "funciones.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include<iostream>


using namespace std;

///MOSTRAR ESTADISTICAS
void mostrarEstadisticas(string nombresJugadores[],string& nombre,int& acumuladorPuntosJugador, int ganadorJugadorNum, int& maxPuntaje)
{
    if(acumuladorPuntosJugador > maxPuntaje)
    {
        nombre = nombresJugadores[ganadorJugadorNum - 1];
        maxPuntaje = acumuladorPuntosJugador;
    }
    cout << "M"<< char(160)<<"ximo puntaje alcanzado: " << maxPuntaje << " PDV por el jugador: " << nombre << endl;
}
