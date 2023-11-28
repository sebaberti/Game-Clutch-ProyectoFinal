#include "funciones.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include<iostream>


using namespace std;


void imprimirManoJugadores(string nombresJugadores[], vector<string> manoJugadores[], int numJugadorTurno)
{
    for(int i=0 ; i<2 ; i++)
    {
        cout << "| Mano del Jugador: "  << nombresJugadores[i];

        // si es 0 no se muestra el turno (impresión final de las manos al encontrar un ganador)
        if (numJugadorTurno != 0 && (numJugadorTurno - 1) == i)
        {
            cout << " (ES TU TURNO)";
        }

        cout << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << j + 1 << ". "<< manoJugadores[i][j] << endl;
        }
        cout << endl;
    }
}

int tieneCartasEnOrden(const vector<string> manoJugadores[], const vector<string>& cartasOrdenadas)
{
    int ganadorJugadorNum = 0;

    // RECORRE CADA MANO LOS JUGADORES
    for (int i = 0; i < 2; i++)
    {
        bool ordenado = true;
        // recorre las cartas de cada jugador
        for (size_t j = 0; j < manoJugadores[i].size(); j++)
        {
            string valorCarta = manoJugadores[i][j].substr(0, manoJugadores[i][j].find(" "));
            if (valorCarta != cartasOrdenadas[j])
            {
                ordenado = false;
            }
        }

        if (ordenado)
        {
            ganadorJugadorNum = i + 1;

        }
    }
    return ganadorJugadorNum;
}

//CUENTA LAS CARTAS DESORDENADAS PARA PODER VERIFICAR LOS PUNTAJES AL FINAL
int contarCartasDesordenadas(const vector<string> manoJugador, const vector<string>& cartasOrdenadas)
{
    int cartasDesordenadas = 0 ;
    // recorre las cartas de cada jugador
    for (size_t j = 0; j < manoJugador.size(); j++)

    {
        string valorCarta = manoJugador[j].substr(0, manoJugador[j].find(" "));
        if (valorCarta != cartasOrdenadas[j])
        {
            cartasDesordenadas++;
        }
    }
    return cartasDesordenadas;
}


vector<string> repartirCartasJugador(vector<string>& mazo)
{
    vector<string> manoJugador;
    for (int i = 0; i < 5; i++)
    {
        manoJugador.push_back(mazo.back());
        mazo.pop_back();

    }
    return manoJugador;
}

// FUNCION PARA CONTAR LOS VALORES DE CADA JUGADOR
int contarCartasDeValor(const vector<string>& manoJugador, const string& valor)
{
    int contador = 0;

    for (size_t i = 0; i < manoJugador.size(); i++)
    {
        if (manoJugador[i].find(valor) != string::npos)
        {
            contador++;
        }
    }

    return contador;
}

/// LLAMO A LA FUNCION CONTAR CARTAR Y LE PASO POR PARAMETRO LA MANO DE CADA
/// JUGADOR, Y COMPARO PRIMERO LOS A Y DESPUES LAS J
int determinarJugadorQueComienza(vector<string> manoJugadores[])
{
    int contadorAsesJugador1 = contarCartasDeValor(manoJugadores[0], "A");
    int contadorAsesJugador2 = contarCartasDeValor(manoJugadores[1], "A");
    int contadorKsJugador1 = contarCartasDeValor(manoJugadores[0],"K");
    int contadorKsJugador2 = contarCartasDeValor(manoJugadores[1], "K");
    int contadorQsJugador1 = contarCartasDeValor(manoJugadores[0], "Q");
    int contadorQsJugador2 = contarCartasDeValor(manoJugadores[1], "Q");
    int contadosJsJugador1 = contarCartasDeValor(manoJugadores[0], "J");
    int contadorJsJugador2 = contarCartasDeValor(manoJugadores[1], "J");
    int contadorDiezJugador1 = contarCartasDeValor(manoJugadores[0], "10");
    int contadorDiezJugador2 = contarCartasDeValor(manoJugadores[1], "10");
    // Determinar qué jugador comienza a jugar
    if (contadorAsesJugador1 > contadorAsesJugador2)
    {
        return 1;
    }
    else if (contadorAsesJugador1 < contadorAsesJugador2)
    {
        return 2;
    }
    else if(contadorKsJugador1 > contadorKsJugador2)
    {
        return 1;
    }
    else if(contadorKsJugador1 < contadorKsJugador2 )
    {
        return 2;
    }
    else if (contadorQsJugador1 > contadorQsJugador2)
    {
        return 1;
    }
    else if(contadorQsJugador1 < contadorQsJugador2)
    {
        return 2;
    }
    else if(contadosJsJugador1 > contadorJsJugador2)
    {
        return 1;
    }
    else if (contadosJsJugador1 < contadorJsJugador2)
    {
        return 2;
    }
    else if (contadorDiezJugador1 > contadorDiezJugador2)
    {
        return 1;
    }
    else if(contadorDiezJugador1 < contadorDiezJugador2)
    {
        return 2;
    }
    return 0;
}
