#include "funciones.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include<iostream>


using namespace std;
///CREAR MAZO
vector<string> crearMazo()
{
    //Valores y palos de las cartas
    string valores[] = { "10", "J", "Q", "K", "A" };
    string palos[] = { "Corazones", "Diamantes", "Treboles", "Picas" };

    // Crear un mazo de cartas
    vector<string> mazo;
    for (int i = 0; i < 5; i++)   // 5 valores
    {
        for (int j = 0; j < 4; j++)   // 4 palos
        {
            mazo.push_back(valores[i] + " de " + palos[j]);
        }
    }
    return  mazo;
}

///MEZCLA EL MAZO
void mezclarMazo(vector<string>& mazo)
{
    srand(static_cast<unsigned>(time(nullptr)));
    random_shuffle(mazo.begin(), mazo.end());
}
