#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaCarta.h"

typedef struct StructJugador{
    int numero;
	ListaCarta cartas;
}Jugador;

typedef struct NodoJugador{
    Jugador jugador;
    struct NodoJugador * siguiente;
}NodoJ;

typedef struct{
    NodoJ * ultimo;
    NodoJ * primero;
}ListaJugador;

void vaciaListaJugador(ListaJugador *lista){
    lista->primero = NULL;
    lista->ultimo = NULL;
}

int esVaciaListaJugador(ListaJugador * lista){
   return !(lista->primero == NULL);// 0 si esta vacia
}

void insertarJugador(ListaJugador *lista, int numero){
    NodoJ * nuevo;
    if((nuevo = (NodoJ *) malloc(sizeof(NodoJ))) == NULL){
        fprintf(stderr, "malloc termino inesperadamente\n");
    }else{
        nuevo->jugador.numero = numero;
        vaciaListaCarta(&nuevo->jugador.cartas);
  
        nuevo->siguiente = NULL;
        if(lista->primero == NULL && lista->ultimo == NULL){
            lista->primero = nuevo;
            lista->ultimo = nuevo;
        }else{
            lista->ultimo->siguiente = nuevo;
			lista->ultimo = lista->ultimo->siguiente;
        }
    }
}

void eliminarJugador(ListaJugador * lista, Jugador *jugador){

	NodoJ* auxiliar = lista->primero;
	NodoJ* anterior = auxiliar;
	
	if(esVaciaListaJugador(lista)){
		if( & auxiliar->jugador == jugador){//si es el primer elemento
			if(lista->primero == lista->ultimo){//si solo hay uno
				vaciaListaJugador(lista);		
			}else{//si hay mas de uno
				lista->primero = lista->primero->siguiente;
			}
		}else{// si no es el primero
			while(auxiliar != NULL){
				if(&auxiliar->jugador == jugador){
					if(auxiliar == lista->ultimo){ // si es el ultimo
						anterior->siguiente = NULL;
					}else{//si no es el ultimo
						anterior->siguiente = auxiliar->siguiente;
					}
					auxiliar = NULL;
				}
				anterior = auxiliar;
				auxiliar = auxiliar->siguiente;
			}
		}
	}
}

void mostrarJugadores(ListaJugador *lista){
	NodoJ * indiceJugador =lista->primero;
	NodoC * indiceCarta = NULL;
	while(indiceJugador != NULL){
		printf("Jugador %i, %i\n",indiceJugador->jugador.numero ,esVaciaListaCarta(&indiceJugador->jugador.cartas));
		indiceCarta = indiceJugador->jugador.cartas.primero;
		while(indiceCarta != NULL){
			printf("%i\n",indiceCarta->carta.numero );
			indiceCarta =indiceCarta->siguiente;
		}
		indiceJugador = indiceJugador->siguiente;
	}
}
