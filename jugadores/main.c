#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "LogicaJuego.h"
#include "MemoriaCompartida.h"

pthread_t esperaCambio;

int turnoAnterior;

void esperarCambio(){
	int sinCambio =1;
	while(sinCambio){

		if(turnoAnterior != partesJuego->turno){
			sinCambio = 0;
			turnoAnterior = partesJuego->turno;
		}
		
	 usleep (1000000);
 	}
}

void juego(){
	int estadoDelJuego =1; 
	

	while(estadoDelJuego){

		if(partesJuego->turno != 0 ){
			printf("turno jugador %i\n", partesJuego->turno );

			if(partesJuego->judadoresJuego.ultimo->jugador.numero == partesJuego->turno){
				partesJuego->turno =0;
			}else{
				partesJuego->turno = partesJuego->turno +1;
			}

		}else{
			printf("turno de la casa\n" );
		}

		pthread_create(&esperaCambio , NULL ,(void *) &esperarCambio , NULL ) ;
		pthread_join ( esperaCambio , NULL ) ;
	}

}


void prepararJuego(){
	crearJugadores(&partesJuego->judadoresJuego, 2);
	mostrarJugadores(&partesJuego->judadoresJuego);


	vaciaListaCarta(&partesJuego->cartasJuego);
	crearCartas(&partesJuego->cartasJuego);
	mostrarCartas(&partesJuego->cartasJuego);
	repartirCartas(&partesJuego->cartasJuego ,&partesJuego->judadoresJuego);
	mostrarJugadores(&partesJuego->judadoresJuego);
}

void main(){
	crearMemoriaConpartida();
	prepararJuego();
	juego();

	liberarMemoria();




	
}