#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

//#include "LogicaJuego.h"
#include "MemoriaCompartida.h"
// El programa jugador solo usa la lista de cartas
pthread_t esperaCambio;
pthread_t esperaCarta;


int turnoAnterior;

Jugador * jugadorSeleccionado;

typedef struct PartesJuegolocal{
    Jugador jugadorJuego;
	ListaCarta cartasJuego;

}JuegoLocal;

JuegoLocal partesJuegoLocal;

void esperarCarta(){


	if(partesJuego.cartaTomada == 0){

	}
}

void tomarJugador(){
	int cartasPasadas;
	printf("hola 1\n");
	jugadorSeleccionado = NULL;
	printf("hola 1\n");


	if( partesJuego.turno >= partesJuego.numeroDeJugadores){
		partesJuegoLocal.jugadorJuego.numero = partesJuego.turno ; // se le asigna  un  numero al jugador
		printf("Eres el jugador %i\n", partesJuegoLocal.jugadorJuego.numero);
	
		for(  cartasPasadas =0; cartasPasadas <2 ; cartasPasadas++){
			 // es perar a que la casa pase la carta
			pthread_create(&esperaCarta , NULL ,(void *) &esperarCarta , NULL ) ;
			pthread_join ( esperaCarta , NULL ) ;
			///////////////////////////////
			// aqui debe el jugador de resivir sus cartas
			insertarCarta(&partesJuegoLocal.cartasJuego, partesJuego.cartasDePaso.numero,partesJuego.cartasDePaso.tipo,partesJuego.cartasDePaso.nombre);
					
			partesJuego.cartaTomada =1; //  la casa debe dar otra carta cuando cartaTomada es = a 1
		}
		
		partesJuego.turno =partesJuego.turno+1;//cuanto el turno cambia la casa debe preparar se para pasar las cartas al proximo jugador
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
	vaciaListaCarta(&partesJuegoLocal.cartasJuego);
	turnoAnterior =1;
}



void main(){
	crearMemoriaConpartida();
	prepararJuego();
	tomarJugador();
	juego();

	liberarMemoria();	
}