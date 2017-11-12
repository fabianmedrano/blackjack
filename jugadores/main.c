#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

//#include "LogicaJuego.h"
#include "MemoriaCompartida.h"

pthread_t esperaCambio;

int turnoAnterior;

Jugador * jugadorSeleccionado;

typedef struct PartesJuegolocal{
    ListaJugador judadoresJuego;
	ListaCarta cartasJuego;
}JuegoLocal;

JuegoLocal partesJuegoLocal;

void tomarJugador(){
	printf("hola 1\n");
	jugadorSeleccionado = NULL;
	printf("hola 1\n");

	if( auxiliar->jugador.tomado == 0){
		auxiliar->jugador.tomado = 1;
		jugadorSeleccionado = &auxiliar->jugador;
		printf("Eres el jugador %i\n", jugadorSeleccionado->numero);
		auxiliar = NULL;
	}

	if(jugadorSeleccionado == NULL){
		printf("No puede jugar, ya estan todos\n");
		pthread_exit(NULL);
	}

}

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

		if(partesJuego.turno != 0 ){
			printf("turno jugador %i\n", partesJuego.turno );
			if(partesJuego.numeroDeJugadores == partesJuego.turno){
				partesJuego.turno =0;
			}else{
				partesJuego.turno = partesJuego.turno +1;
			}
		}else{
			printf("turno de la casa\n" );
		}
		pthread_create(&esperaCambio , NULL ,(void *) &esperarCambio , NULL ) ;
		pthread_join ( esperaCambio , NULL ) ;
	}

}


void prepararJuego(){
	turnoAnterior =1;
}



void main(){
	crearMemoriaConpartida();
	prepararJuego();
	tomarJugador();
	juego();

	liberarMemoria();	
}