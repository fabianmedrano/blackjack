#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "LogicaJuego.h"
#include "MemoriaCompartida.h"

pthread_t esperaCambio;
pthread_t esperaTomarCarta;


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

	NodoJ * indiceJugador = partesJuegoLocal.judadoresJuego->primero->siguiente;
	NodoC * indiceCartas;

	while (indiceJugador != NULL){
		indiceCartas = indiceJugador->jugador.cartas->primero
		while(indiceCartas != NULL){
			partesJuego.cartasDePaso.numero = indiceCartas.carta.numero ;
			partesJuego.cartasDePaso.tipo = indiceCartas.carta.tipo;
			partesJuego.cartasDePaso.nombre = indiceCartas.carta.nombre;
			partesJuego.cartaTomada = 0;

			pthread_create(&esperaTomarCarta , NULL ,(void *) &esperarATomarCarta , NULL ) ;
			pthread_join ( esperaTomarCarta , NULL ) ;
		}

		indiceJugador = indiceJugador->siguiente;
	}



	//int cartasPasadas;
//	if( partesJuego.turno >= partesJuego.numeroDeJugadores){
		//if(partesJuegoLocal.jugadorJuego.numero == 0 ){
		//	partesJuegoLocal.jugadorJuego.numero = partesJuego.turno ; // se le asigna  un  numero al jugador
		//	printf("Eres el jugador %i\n", partesJuegoLocal.jugadorJuego.numero);
/*
			for(  cartasPasadas = 0; cartasPasadas < 2 ; cartasPasadas++){
				 // es perar a que la casa pase la carta
				pthread_create(&esperaCarta , NULL ,(void *) &esperarCarta , NULL ) ;
				pthread_join ( esperaCarta , NULL ) ;
				///////////////////////////////
				// aqui debe el jugador de resivir sus cartas
				insertarCarta(&partesJuegoLocal.cartasJuego, partesJuego.cartasDePaso.numero,partesJuego.cartasDePaso.tipo,partesJuego.cartasDePaso.nombre);
						
				partesJuego.cartaTomada =1; //  la casa debe dar otra carta cuando cartaTomada es = a 1
			}
			partesJuego.turno =partesJuego.turno+1;//cuanto el turno cambia la casa debe preparar se para pasar las cartas al proximo jugador


	//	}
	}else{

		printf("No puede jugar, ya estan todos\n");
		pthread_exit(NULL);
	}
*/
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