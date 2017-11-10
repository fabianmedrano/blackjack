#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "ListaJugador.h"

void crearCartas(ListaCarta *lista){

	char * tipo[4] = {"corazones", "Oro", "Bastos", "Trebol"};
	char * nombre[14]  ={"1", "2", "3","4", "5", "6", "7", "8", "9", "10", "J", "Q", "K","As"};
	int i , j;
	for(i =0; i <14 ; i++){
		for (j = 0; j < 4; j++){
			if( i <10 ){
				insertarCarta(lista, i+1,tipo[j],nombre[i]);
			}else{
				insertarCarta(lista, 10,tipo[j],nombre[i]);
			}
			
		}
	}	
}

void repartirCartas(ListaCarta *listaCarta ,ListaJugador *listaJugador){
	NodoJ *indiceJugadores = listaJugador->primero;
	int i =0;
	int posicion =0;
	while(indiceJugadores != NULL){
		for (i =0; i<2;i++ ){
			posicion=obtenerPosicion();
			printf("--------------  %i  ---\n", posicion+1);
			ingresarABaraja(listaCarta ,&indiceJugadores->jugador.cartas ,posicion);
		}
		indiceJugadores = indiceJugadores->siguiente;
	}
}

void crearJugadores(ListaJugador *lista, int jugadores){
	vaciaListaJugador(lista);
	
	int i;
	for(i =0; i<jugadores ;i++){
		insertarJugador(lista,i );
	}
}