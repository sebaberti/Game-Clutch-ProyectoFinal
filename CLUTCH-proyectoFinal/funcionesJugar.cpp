#include "funciones.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include<iostream>


using namespace std;
/// JUEGO////

void jugar(string nombresJugadores[],int& acumuladorPuntosJugador,int& ganadorJugadorNum)
{
    int perdedorJugadorNum;
    int cartasDesordenadasPerdedor = 0;
    bool pasoTurno1 = false;
    bool pasoTurno2 = false;
    bool sufrioRobo1 = false;
    bool sufrioRobo2 = false;
    int contadorRondas = 1;
    int ultimaAccion = 0;

    int gallinean = 0;
    bool tieneGallinean = false;
    vector<char> cartasBloqueadas = {' '};

    cout << "CLUTCH" << endl;
    cout << "------------------------" << endl;

    cargarNombres(nombresJugadores);

    ////////////////////////////////////
///CREAR MAZO
    vector<string> mazo = crearMazo();

//MECLAR MAZO
    mezclarMazo(mazo);

//REPARTIR Y MOSTRAR CARTAS
    vector<string> manoJugadores[2];
    manoJugadores[0] = repartirCartasJugador(mazo);
    manoJugadores[1] = repartirCartasJugador(mazo);

    vector<string> cartasOrdenadas = {"10","J","Q", "K","A"};


    //CON ESTA FUNCION DETERMINAMOS EN PRIMER INSTANCIA SI ALGUNO DE LOS 2 JUGADORES
    //TIENE LAS CARTAS EN ORDEN, DE SER ASI SE VUELVE A REPARTIR
    ganadorJugadorNum = tieneCartasEnOrden(manoJugadores, cartasOrdenadas);
    while(ganadorJugadorNum == 1|| ganadorJugadorNum == 2)
    {
        cout << "Las cartas de un jugador salieron ordenadas se reparte nuevamente" << endl;
        mazo = crearMazo();
        mezclarMazo(mazo);
        manoJugadores[0] = repartirCartasJugador(mazo);
        manoJugadores[1] = repartirCartasJugador(mazo);
    }

// DETERMINAMOS QUE JUGADOR VA A SER EL QUE COMENZARA JUGANDO
    int numJugadorTurno = determinarJugadorQueComienza(manoJugadores);
    int numOtroJugador = 0;

    // si empieza el 1, el otro jugador (numOtroJugador) debe ser el 2
    // sino a la inversa
    if (numJugadorTurno == 1)
    {
        numOtroJugador = 2;
    }
    else
    {
        numOtroJugador = 1;
    }

// devuelve 0 si no hay ganador, 1 si ganó el jugador 1, 2 si ganó el jugador 2

// mientras que no haya ganador continúa el juego
    while(ganadorJugadorNum == 0)
    {
        system("cls");
        // Mostrar las manos de los jugadores
        cout << "      # RONDA" << contadorRondas << endl;
        imprimirManoJugadores(nombresJugadores, manoJugadores, numJugadorTurno);

        //MODIFICACION PARA DEFENSA
        gallinean = contarCartasDeValor(manoJugadores[0], "Q");
        if(gallinean == 4 ){
            tieneGallinean = true;
        }

        gallinean =  contarCartasDeValor(manoJugadores[1], "Q");
        if(gallinean ==4){

            tieneGallinean =true;
        }



        cout << "-----> TURNO DE " << nombresJugadores[numJugadorTurno-1] << " <-----" << endl;

        int dado = tirarDado();

        ultimaAccion = dado;
        //ACORDE AL NUMERO DE DADO QUE HAYA SALIDO SE APLICA LA ACCION CORRESPONDIENTE
        accionDadoJugador(dado,manoJugadores[numJugadorTurno-1],mazo,manoJugadores[numOtroJugador-1],pasoTurno1, pasoTurno2,numJugadorTurno, ultimaAccion, sufrioRobo1,sufrioRobo2,cartasBloqueadas);

        mezclarMazo(mazo);

        ganadorJugadorNum = tieneCartasEnOrden(manoJugadores,cartasOrdenadas);

        if (ganadorJugadorNum == 1)
        {
            perdedorJugadorNum = 2;
        }
        else
        {
            perdedorJugadorNum = 1;
        }

        cartasDesordenadasPerdedor =   contarCartasDesordenadas(manoJugadores[perdedorJugadorNum-1], cartasOrdenadas);

        // CAMBIA EL TURNO
        if (numJugadorTurno == 1) // si era el turno del jugador 1 ahora es el del 2
        {
            numJugadorTurno = 2;
            numOtroJugador = 1;
        }
        else
        {
            // si era el turno del jugador 2 ahora es el del 1
            numJugadorTurno = 1;
            numOtroJugador = 2;
        }
        cout << endl ;
        contadorRondas++;
        system("pause");
    }
    system("cls");
    imprimirManoJugadores(nombresJugadores, manoJugadores, 0);


    cout << endl << nombresJugadores[ganadorJugadorNum-1] << " HA GANADO LA PARTIDA!!!" << endl;
    mostrarMenuPuntos(acumuladorPuntosJugador, cartasDesordenadasPerdedor, ultimaAccion,pasoTurno1,pasoTurno2,numJugadorTurno,sufrioRobo1,sufrioRobo2,ganadorJugadorNum,tieneGallinean );

}
