#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

 //extern int maxPuntaje ;

void jugar(string nombresJugadores[], int& acumuladorPuntosJugador, int& ganadorJugadorNum);

void mostrarCreditos();

void cargarNombres(string[]);

void dibujarCara(int puntos);


int tirarDado();

void dibujarCaraDado(int puntos);


vector<string>  crearMazo();

void mezclarMazo(vector<string>& mazo);

vector<string> repartirCartasJugador(vector<string>& mazo);

int contarCartasDeValor(const vector<string>& manoJugador, const string& valor);

//int contarCartasDeValor(const vector<string>& manoJugador, const string& valor);

int determinarJugadorQueComienza(vector<string> manoJugadores[]);

void accionDadoJugador(int num, vector<string>& manoJugadorTurno, vector<string>& mazo, vector<string>& manoOtroJugador, bool& pasoTurno1, bool& pasoTurno2,int& numJugadorTurno, int& ultimaAccion,bool& sufrioRobo1,bool& sufrioRobo2,vector<char>& cartasBloqueadas);

void accionDado1(vector<string>& manoJugador,vector<string>& mazo, vector<char>& cartasBloqueadas);

void accionDado2(vector<string>& manoJugador,vector<string>& mazo, vector<char>& cartasBloqueadas);

void accionDado3(vector<string>& manoJugadorTurno,vector<string>& manoOtroJugador,bool& sufrioRobo1, bool& sufrioRobo2, int& numJugadorTurno, vector<char>& cartasBloqueadas);

void accionDado4(vector<string>& manoJugador, vector<char>& cartasBloqueadas);

void accionDado5(vector<string>& manoJugador, vector<char>& cartasBloqueadas);

void accionDado6(vector<string>& manoJugadorTurno, vector<string>& manoOtroJugador, vector<string>& mazo, bool& pasoTurno1, bool& pasoTurno2,int& numJugadorTurno, int& ultimaAccion, bool& sufrioRobo1, bool& sufrioRobo2, vector<char>& cartasBloqueadas);

int tieneCartasEnOrden(const vector<string> manoJugadores[], const vector<string>& cartasOrdenadas);

void imprimirManoJugadores(string nombresJugadores[], vector<string> manoJugadores[], int numJugadorTurno);

int contarCartasDesordenadas(const vector<string> manoJugador, const vector<string>& cartasOrdenadas);

void mostrarMenuPuntos(int& acumuladorPuntosJugador, int& cartasDesordenadasPerdedor, int ultimaAccion,bool& pasoTurno1, bool& pasoTurno2,int& numJugadorTurno,bool& sufrioRobo1, bool& sufrioRobo2, int ganadorJugadorNum,bool& tieneGallinean);

void mostrarEstadisticas(string nombresJugadores[],string& nombre, int& acumuladoPuntosJugador, int ganadorJugadorNum, int& maxPuntaje);
#endif // FUNCIONES_H_INCLUDED
