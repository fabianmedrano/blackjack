#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "LogicaJuego.h"
#include "MemoriaCompartida.h"
// El programa jugador solo usa la lista de cartas
pthread_t esperaCambio;
pthread_t esperaCarta;


int turnoAnterior;

<<<<<<< HEAD

typedef struct PartesJuegolocal{
    Jugador jugadorJuego;
	ListaCarta cartasJuego;
}JuegoLocal;

JuegoLocal partesJuegoLocal;

void esperarCarta(){
	int sinCambio =1;
	while(sinCambio){
		usleep (1000000);
		if(0 == partesJuego.cartaTomada){
			sinCambio = 0;
			
		}
 	}	
}

void tomarJugador(){
	int cartasPasadas;
	printf("hola 1\n");
	printf("hola 1\n");

	if( partesJuego.turno >= partesJuego.numeroDeJugadores){
		if(partesJuegoLocal.jugadorJuego.numero == 0 ){
			partesJuegoLocal.jugadorJuego.numero = partesJuego.turno ; // se le asigna  un  numero al jugador
			printf("turno %i\n", partesJuego.turno  );
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
		}
	}else{

		printf("No puede jugar, ya estan todos\n");
		pthread_exit(NULL);
	}

}

=======
>>>>>>> parent of b48d258... intento de mas de dos procesos
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
		if(partesJuego.turno != 0 ){
			printf("turno jugador %i\n", partesJuego.turno );
			if(partesJuego.numeroDeJugadores == partesJuego.turno){
				partesJuego.turno =0;
=======
		if(partesJuego->turno != 0 ){
			printf("turno jugador %i\n", partesJuego->turno );

			if(partesJuego->judadoresJuego.ultimo->jugador.numero == partesJuego->turno){
				partesJuego->turno =0;
>>>>>>> parent of b48d258... intento de mas de dos procesos
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
<<<<<<< HEAD
	vaciaListaCarta(&partesJuegoLocal.cartasJuego);
	turnoAnterior = 1;
	partesJuegoLocal.jugadorJuego.numero = 0;
}
=======
	crearJugadores(&partesJuego->judadoresJuego, 2);
	mostrarJugadores(&partesJuego->judadoresJuego);
>>>>>>> parent of b48d258... intento de mas de dos procesos

void esperarInicioJuego(){
	int sinCambio =1;
	while(sinCambio){

		if(0 == partesJuego.estado){
			sinCambio = 0;
		}
	 usleep (1000000);
 	}
}

	vaciaListaCarta(&partesJuego->cartasJuego);
	crearCartas(&partesJuego->cartasJuego);
	mostrarCartas(&partesJuego->cartasJuego);
	repartirCartas(&partesJuego->cartasJuego ,&partesJuego->judadoresJuego);
	mostrarJugadores(&partesJuego->judadoresJuego);
}

void main(){
	crearMemoriaConpartida();
	prepararJuego();
<<<<<<< HEAD
	//tomarJugador();
	//esperarInicioJuego();
=======
>>>>>>> parent of b48d258... intento de mas de dos procesos
	juego();

	liberarMemoria();




	
}