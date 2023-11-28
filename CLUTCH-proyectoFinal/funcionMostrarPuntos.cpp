#include "funciones.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include<iostream>


using namespace std;

void mostrarMenuPuntos(int& acumuladorPuntosJugador, int& cartasDesordenadasPerdedor,int ultimaAccion, bool& pasoTurno1, bool& pasoTurno2, int& numJugadorTurno, bool& sufrioRobo1, bool& sufrioRobo2,int ganadorJugadorNum,bool& tieneGallinean)
{
    acumuladorPuntosJugador = 0;
    int puntajeMalUbicadasRival = cartasDesordenadasPerdedor * 5;
    const int GALLINEAN_RHAPSODY = 50;
    const int SUMAR_DIEZ = 10;
    const int SUMAR_CINCO = 5;
    const int SUMAR_QUINCE = 15;
    acumuladorPuntosJugador += puntajeMalUbicadasRival;
    cout << "CLUTCH" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "HITO                                       " << endl;
    cout << "------------------------------------------------------------------------" << endl;

    //sumar 50 si tiene gallinean
    if(tieneGallinean == true){
    cout << "Tiene Gallinean Rhapsody                  +50 PDV" << endl;
        acumuladorPuntosJugador += GALLINEAN_RHAPSODY;
    }

    //SUMAR 15 POR GANAR LA PARTIDA
    if(ganadorJugadorNum == 1)
    {
        acumuladorPuntosJugador += SUMAR_QUINCE;
    }
    else
    {
        acumuladorPuntosJugador += SUMAR_QUINCE;

    }
    cout << "Ganar la partida                           +15 PDV" << endl;
    //SUMAR 10 POR ROBARLE LA ULTIMA CARTA AL RIVAL
    if(ultimaAccion == 3)
    {
        acumuladorPuntosJugador+= SUMAR_DIEZ;
        cout << "Robo ultima carta al jugador rival         +10  PDV" << endl;

    }
    else
    {
        cout << "Robo ultima carta al jugador rival         +0  PDV" << endl;

    }
    //SUMAR 5 POR CADA CARTA DESORDENADA DEL RIVAL
    cout << "Cartas mal ubicadas del rival x " << cartasDesordenadasPerdedor << "          +"<< puntajeMalUbicadasRival <<" PDV" << endl;
    //SUMAR 10 SI NUNCA PASO DE TURNO
    if(ganadorJugadorNum == 1 && pasoTurno1 == false)
    {
        acumuladorPuntosJugador+= SUMAR_DIEZ;

        cout << "Sin pasar de turno                         +10 PDV" << endl;
    }
    else if (ganadorJugadorNum == 2 && pasoTurno2 == false)
    {
        acumuladorPuntosJugador+= SUMAR_DIEZ;

        cout << "Sin pasar de turno                         +10 PDV" << endl;
    }
    else
    {
        cout << "Sin pasar de turno                         +0 PDV" << endl;
    }
    //SUMAR 5 SI NO SUFRIO ROBO DEL CONTRARIO
    if(ganadorJugadorNum == 1 && sufrioRobo1 == false)
    {
        acumuladorPuntosJugador+= SUMAR_CINCO;
        cout << "Sin haber sufrido un robo del rival        +5  PDV" << endl;
    }
    else if(ganadorJugadorNum == 2 && sufrioRobo2 == false)
    {
        acumuladorPuntosJugador+= SUMAR_CINCO;
        cout << "Sin haber sufrido un robo del rival        +5  PDV" << endl;
    }
    else
    {
        cout << "Sin haber sufrido un robo del rival        +0  PDV" << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL                                      " << acumuladorPuntosJugador << " PDV" << endl;
    cout << endl;
}
