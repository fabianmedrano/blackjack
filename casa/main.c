#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "LogicaJuego.h"
#include "MemoriaCompartida.h"

pthread_t esperaCambio;
pthread_t esperaTomarCarta;

/*
* cuando un jugador pida una carta 
* la casa debe de tomar una carta random,
* insertarla en la lista local del jugador al que le correspode el turno
* cambiar carta tomada a 0 para que el gugador la tome
* el jugador debe cambiar carta tomada a 1, para indicar que la tomo
* y el juego debe de seguir (aumentar el turno)
*
*/

int turnoAnterior;

typedef struct PartesJuegolocal{
    ListaJugador judadoresJuego;
	ListaCarta cartasJuego;
}JuegoLocal;

JuegoLocal partesJuegoLocal;
/////////////////
/////////////////
void esperarATomarCarta(){
	int sinCambio =1;
	while(sinCambio){
		usleep (1000000);
		if(1 == partesJuego.cartaTomada){
			sinCambio = 0;
		}
 	}	
}

void pasarJugador(){

	NodoJ * indiceJugador = partesJuegoLocal.judadoresJuego.primero->siguiente;
	NodoC * indiceCartas;

	while (indiceJugador != NULL){

		indiceCartas = indiceJugador->jugador.cartas.primero;

		while(indiceCartas != NULL){

			partesJuego.cartasDePaso.numero = indiceCartas->carta.numero ;
			partesJuego.cartasDePaso.tipo = indiceCartas->carta.tipo;
			partesJuego.cartasDePaso.nombre = indiceCartas->carta.nombre;
			partesJuego.cartaTomada = 0;

			pthread_create(&esperaTomarCarta , NULL ,(void *) &esperarATomarCarta , NULL ) ;
			pthread_join ( esperaTomarCarta , NULL ) ;
		}
		// esperar al siguiente jugador
		//esperaCambio (); 

		indiceJugador = indiceJugador->siguiente;
	}
}

////////////////
////////////////
void esperarCambio(){
	int sinCambio =1;
	while(sinCambio){

		if(turnoAnterior != partesJuego.turno){
			sinCambio = 0;
			turnoAnterior = partesJuego.turno;
		}
		
	 usleep (1000000);
 	}
}


void juego(){
	int estadoDelJuego =1; 

	while(estadoDelJuego){
<<<<<<< HEAD
		if(partesJuego.turno == 0){
=======

		if(partesJuego->turno == 0){
>>>>>>> parent of b48d258... intento de mas de dos procesos
			printf("turno  de la casa\n" );
			partesJuego.turno = partesJuego.turno +1;;

		}else{
			printf("turno jugador %i\n", partesJuego.turno );
		}
		pthread_create(&esperaCambio , NULL ,(void *) &esperarCambio , NULL ) ;
		pthread_join ( esperaCambio , NULL ) ;
		//pthread_exit(NULL);
	}
}

void prepararJuego(){
<<<<<<< HEAD
	crearJugadores(&partesJuegoLocal.judadoresJuego, 2);
	mostrarJugadores(&partesJuegoLocal.judadoresJuego);

	vaciaListaCarta(&partesJuegoLocal.cartasJuego);
	crearCartas(&partesJuegoLocal.cartasJuego);
	mostrarCartas(&partesJuegoLocal.cartasJuego);
	repartirCartas(&partesJuegoLocal.cartasJuego ,&partesJuegoLocal.judadoresJuego);
	mostrarJugadores(&partesJuegoLocal.judadoresJuego);

	partesJuego.estado  = 0;
	partesJuego.numeroDeJugadores = 0;
	partesJuego.cartaTomada = 0;

	partesJuego.turno = 1;
	turnoAnterior = 1;
=======
	crearJugadores(&partesJuego->judadoresJuego, 2);
	mostrarJugadores(&partesJuego->judadoresJuego);

	vaciaListaCarta(&partesJuego->cartasJuego);
	crearCartas(&partesJuego->cartasJuego);
	mostrarCartas(&partesJuego->cartasJuego);
	repartirCartas(&partesJuego->cartasJuego ,&partesJuego->judadoresJuego);
	mostrarJugadores(&partesJuego->judadoresJuego);
>>>>>>> parent of b48d258... intento de mas de dos procesos
}

void main(){
	//printf("turno  de la casa" );
	crearMemoriaConpartida();
	//printf("turno  de la casa" );
	prepararJuego();
	//pasarJugador();
	juego();
	printf("turno jugador %i\n", partesJuego.turno );
	liberarMemoria();
}