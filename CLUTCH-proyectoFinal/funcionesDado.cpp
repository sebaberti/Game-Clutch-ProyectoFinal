#include "funciones.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include<iostream>


using namespace std;

/// FUNCION QUE SIMULA TIRAR EL DADO ME DA UN NUMERO ALEATORIA ENTRE 1 Y 6
int tirarDado()
{
    vector<int> dado = {1,2,3,4,5,6};

    srand(static_cast<unsigned>(time(nullptr)));
    random_shuffle(dado.begin(), dado.end());

    int numeroDado = dado[0];

    dibujarCaraDado(numeroDado);

    return numeroDado;
}

void accionDadoJugador(int num, vector<string>& manoJugadorTurno, vector<string>& mazo, vector<string>& manoOtroJugador, bool& pasoTurno1, bool& pasoTurno2, int& numJugadorTurno, int& ultimaAccion,bool& sufrioRobo1,bool& sufrioRobo2,vector<char>& cartasBloqueadas)
{
    cout << "LANZAMIENTO DADO " << " # " << num << endl;

    switch (num)
    {
    case 1:

        accionDado1(manoJugadorTurno, mazo, cartasBloqueadas);
        break;
    case 2:
        accionDado2(manoOtroJugador, mazo,cartasBloqueadas);
        break;
    case 3:
        accionDado3(manoJugadorTurno, manoOtroJugador,sufrioRobo1,sufrioRobo2,numJugadorTurno,cartasBloqueadas);
        break;
    case 4:
        accionDado4(manoJugadorTurno, cartasBloqueadas);
        break;
    case 5:
        accionDado5(manoJugadorTurno, cartasBloqueadas);
        break;
    case 6:
        accionDado6(manoJugadorTurno, manoOtroJugador, mazo,pasoTurno1,pasoTurno2,numJugadorTurno, ultimaAccion,sufrioRobo1,sufrioRobo2,cartasBloqueadas);
        break;
    default:
        cout << "N" << (char)163 << "mero de dado no válido." << endl;
    }
}

void accionDado1(vector<string>& manoJugador, vector<string>& mazo, vector<char>& cartasBloqueadas )
{
    int indiceCartaMano;


    cout << "Ingresa el n" << (char)163 << "mero de carta que quieres descartar (de tu corral)" << endl;
    cin >> indiceCartaMano;
    while(indiceCartaMano < 1 || indiceCartaMano >5)
    {
        cout << "N" << (char)163 << "mero de carta no valido. Ingresar un n" <<(char)163 << "mero entre 1 y 5." << endl;
        cin >> indiceCartaMano;
    }

    if(cartasBloqueadas[indiceCartaMano -1]== 'B')
    {
        cartasBloqueadas[indiceCartaMano -1]= ' ';
    }
    swap(manoJugador[indiceCartaMano - 1], mazo[0]);
}

void accionDado2(vector<string>& manoJugador, vector<string>& mazo, vector<char>& cartasBloqueadas)
{
    int indiceCartaManoRival;
    cout << "Ingresa el n" << (char)163 << "mero de carta que quieres descartar (del corral del rival)" << endl;
    cin >> indiceCartaManoRival;
    while(indiceCartaManoRival < 1 || indiceCartaManoRival >5 || cartasBloqueadas[indiceCartaManoRival - 1]== 'B')
    {
        if(cartasBloqueadas[indiceCartaManoRival -1] == 'B')
        {
            cout << "La carta elegida se encuentra bloqueada por su rival. Debe elegir otra " << endl;
        }
        else
        {
            cout << "N" << (char)163 << "mero de carta no valido. Ingresar un n" <<(char)163 << "mero entre 1 y 5." << endl;
        }
        cin >> indiceCartaManoRival;
    }

    swap(manoJugador[indiceCartaManoRival - 1], mazo[0]);
}

void accionDado3(vector<string>& manoJugadorTurno, vector<string>& manoOtroJugador,bool& sufrioRobo1, bool& sufrioRobo2, int& numJugadorTurno, vector<char>& cartasBloqueadas)
{
    if(numJugadorTurno == 1)
    {
        sufrioRobo2 = true;
    }
    else
    {
        sufrioRobo1 =true;
    }
    int indiceCartaMano, indiceCartaManoRival;

    cout << "Ingresa el n" << (char)163 << "mero de carta (de tu corral) que quieres intercambiar con el rival" << endl;
    cin >> indiceCartaMano;
    while(indiceCartaMano < 1 || indiceCartaMano >5 )
    {
        cout << "N" << (char)163 << "mero de carta no valido. Ingresar un n" <<(char)163 << "mero entre 1 y 5." << endl;
        cin >> indiceCartaMano;
    }
    if (cartasBloqueadas[indiceCartaMano - 1] == 'B')
    {
        // si la carta del jugador esta bloqueada la desbloqueo
        cartasBloqueadas[indiceCartaMano - 1] = ' ';
    }


    cout << "Ingresa el n" << (char)163 << "mero de carta que quieres del jugador rival" << endl;
    cin >> indiceCartaManoRival;
    while(indiceCartaManoRival < 1 || indiceCartaManoRival >5 || cartasBloqueadas[indiceCartaManoRival-1]== 'B' )
    {
        if(cartasBloqueadas[indiceCartaManoRival-1] == 'B')
        {
            cout << "La carta elegida se encuentra bloqueada por su rival. Debe elegir otra " << endl;
        }
        else
        {
            cout << "N" << (char)163 << "mero de carta no valido. Ingresar un n" <<(char)163 << "mero entre 1 y 5." << endl;
        }
        cin >> indiceCartaManoRival;
    }
    swap(manoJugadorTurno[indiceCartaMano - 1], manoOtroJugador[indiceCartaManoRival - 1]);

}

void accionDado4(vector<string>& manoJugador, vector<char>& cartasBloqueadas)
{
    int indiceCartaMano1, indiceCartaMano2;

    cout << "Ingresa el n" << (char)163 << "mero de carta que quieres cambiar de posicion (de tu corral)" << endl;
    cin >> indiceCartaMano1;

    while(indiceCartaMano1 < 1 || indiceCartaMano1 >5 )
    {

        cout << "N" << (char)163 << "mero de carta no valido. Ingresar un n" <<(char)163 << "mero entre 1 y 5." << endl;
        cin >> indiceCartaMano1;
    }


    cout << "Ingresa el n" << (char)163 << "mero de carta que quieres cambiar de posicion (de tu corral)" << endl;
    cin >> indiceCartaMano2;

    while(indiceCartaMano2 < 1 || indiceCartaMano2 >5 || indiceCartaMano1 == indiceCartaMano2)
    {
        cout << "N" << (char)163 << "mero de carta no valido. Ingresar un n" <<(char)163 << "mero entre 1 y 5. O que sea distinto del primero" << endl;
        cin >> indiceCartaMano2;
    }
    if(cartasBloqueadas[indiceCartaMano1 -1]== 'B')
    {
        cartasBloqueadas[indiceCartaMano1 -1]= ' ';
    }
    else if(cartasBloqueadas[indiceCartaMano2 -1]== 'B')
    {
        cartasBloqueadas[indiceCartaMano2 -1] = ' ';
    }
    swap(manoJugador[indiceCartaMano1 - 1], manoJugador[indiceCartaMano2 - 1]);
}

void accionDado5(vector<string>& manoJugadorTurno, vector<char>& cartasBloqueadas)
{
    int indiceCartaMano;
    cout << "Bloquear una carta de su corral para que no sea utilizada con la cara 2 y 3 del dado" << endl;
    cout << "Ingrese la posicion de la carta de su corral: ";
    cin >> indiceCartaMano;
    while(indiceCartaMano < 1 || indiceCartaMano >5 )
    {
        cout << "N" << (char)163 << "mero de carta no valido. Ingresar un n" <<(char)163 << "mero entre 1 y 5." << endl;
        cin >> indiceCartaMano;
    }

    cartasBloqueadas[indiceCartaMano -1] = 'B';

    cout << "La carta " << manoJugadorTurno[indiceCartaMano-1] << " ha sido bloqueada " << endl;
}



void accionDado6(vector<string>& manoJugadorTurno, vector<string>& manoOtroJugador, vector<string>& mazo, bool& pasoTurno1, bool& pasoTurno2,int& numJugadorTurno, int& ultimaAccion, bool& sufrioRobo1, bool& sufrioRobo2,vector<char>& cartasBloqueadas)
{
    int opcion;
    cout << "Elige una acci" << (char)162 << "n para el dado 6:" << endl;
    cout << "1. Descartar una carta (de tu corral) y recoger una del mazo" << endl;
    cout << "2. Descartar una carta (del corral rival) y que recoja una del mazo" << endl;
    cout << "3. Intercambiar una carta de tu corral por una del corral rival" << endl;
    cout << "4. Cambiar dos cartas de tu corral de lugar" << endl;
    cout << "5. Proteger una carta de tu corral (el rival no puede robarla ni descartarla)" << endl;
    cout << "6. Pasar turno" << endl;

    cin >> opcion;
    while(opcion < 1 || opcion > 6 )
    {

        cout << "N" << (char)163 << "mero de opcion no valido. Ingresar un n" <<(char)163 << "mero entre 1 y 6." << endl;
        cin >> opcion;
    }

    switch (opcion)
    {
    case 1:
        accionDado1(manoJugadorTurno, mazo,cartasBloqueadas);
        break;
    case 2:
        accionDado2(manoOtroJugador, mazo,cartasBloqueadas);
        break;
    case 3:
        ultimaAccion = opcion;
        accionDado3(manoJugadorTurno, manoOtroJugador,sufrioRobo1,sufrioRobo2, numJugadorTurno,cartasBloqueadas);
        break;
    case 4:
        accionDado4(manoJugadorTurno, cartasBloqueadas);
        break;
    case 5:
        accionDado5(manoJugadorTurno,cartasBloqueadas);
        break;
    case 6:
        if(numJugadorTurno ==1)
        {
            pasoTurno1 = true;
        }
        else
        {
            pasoTurno2= true;
        }
        cout << "Turno pasado." << endl;
        break;
    default:
        cout << "Opci" << (char)162 << "n no válida." << endl;
    }
}
//// FUNCION QUE NOS DIBUJA LA FORMA DEL DADO

void dibujarCaraDado(int puntos)
{
    cout << "\t" << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << endl;

    switch (puntos)
    {
    case 1:
        cout<< "\t" << (char)186 << "       " << (char)186 << endl;
        cout<< "\t" << (char)186 << "   " << (char)254 << "   " << (char)186 << endl;
        cout<< "\t" << (char)186 << "       " << (char)186 << endl;
        break;
    case 2:
        cout<< "\t" << (char)186 << " " << (char)254 << "     " << (char)186 << endl;
        cout<< "\t" << (char)186 << "       " << (char)186 << endl;
        cout<< "\t" << (char)186 << "     " << (char)254 << " " << (char)186 << endl;
        break;
    case 3:
        cout<< "\t" << (char)186 << " " << (char)254 << "     " << (char)186 << endl;
        cout<< "\t" << (char)186 << "   " << (char)254 << "   " << (char)186 << endl;
        cout<< "\t" << (char)186 << "     " << (char)254 << " " << (char)186 << endl;
        break;
    case 4:
        cout<< "\t" << (char)186 << " " << (char)254 << "   " << (char)254 << " " << (char)186 << endl;
        cout<< "\t" << (char)186 << "       " << (char)186 << endl;
        cout<< "\t" << (char)186 << " " << (char)254 << "   " << (char)254 << " " << (char)186 << endl;
        break;
    case 5:
        cout<< "\t" << (char)186 << " " << (char)254 << "   " << (char)254 << " " << (char)186 << endl;
        cout<< "\t" << (char)186 << "   " << (char)254 << "   " << (char)186 << endl;
        cout<< "\t" << (char)186 << " " << (char)254 << "   " << (char)254 << " " << (char)186 << endl;
        break;
    case 6:
        cout<< "\t" << (char)186 << " " << (char)254 << "   " << (char)254 << " " << (char)186 << endl;
        cout<< "\t" << (char)186 << " " << (char)254 << "   " << (char)254 << " " << (char)186 << endl;
        cout<< "\t" << (char)186 << " " << (char)254 << "   " << (char)254 << " " << (char)186 << endl;
        break;
    default:
        cout << "N" << (char)163 << "mero de puntos inválido en el dado." << endl;
        return ;
    }

    cout << "\t" << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << endl;
    cout << endl;
}
