#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "LogicaJuego.h"
#include "MemoriaCompartida.h"




pthread_t esperaCambio;



int turnoAnterior;

typedef struct PartesJuegolocal{
    ListaJugador judadoresJuego;
	ListaCarta cartasJuego;
}JuegoLocal;

JuegoLocal partesJuegoLocal;

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
	int estadoDelJuego = 1; 


	while(estadoDelJuego){

		if(partesJuego.turno == 0){
			printf("turno  de la casa\n" );
			partesJuego.turno = partesJuego.turno +1;;

		}else{
			printf("turno jugador %i\n", partesJuego.turno );
		}
		pthread_create(&esperaCambio , NULL ,(void *) &esperarCambio , NULL ) ;
		pthread_join ( esperaCambio , NULL ) ;
	}
}

void prepararJuego(){
	crearJugadores(&partesJuegoLocal.judadoresJuego, 2);
	mostrarJugadores(&partesJuegoLocal.judadoresJuego);

	vaciaListaCarta(&partesJuegoLocal.cartasJuego);
	crearCartas(&partesJuegoLocal.cartasJuego);
	mostrarCartas(&partesJuegoLocal.cartasJuego);
	repartirCartas(&partesJuegoLocal.cartasJuego ,&partesJuegoLocal.judadoresJuego);
	mostrarJugadores(&partesJuegoLocal.judadoresJuego);
	partesJuego.turno =1;
	turnoAnterior =1;
}

void main(){
	prepararJuego();
	crearMemoriaConpartida();
	prepararJuego();
	//juego();

	liberarMemoria();
}