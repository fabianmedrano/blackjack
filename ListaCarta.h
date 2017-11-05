#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StructCarta{
    int numero;
 	char *tipo;
	char *nombre;
	
	int id;
}Carta;

typedef struct NodoLista{
    Carta carta;
    struct NodoLista * siguiente;
}NodoC;

typedef struct{
    NodoC * ultimo;
    NodoC * primero;
}ListaCarta;

void vaciaListaCarta(ListaCarta *lista){
    lista->primero = NULL;
    lista->ultimo = NULL;
}

int esVaciaListaCarta(ListaCarta * lista){
   return !(lista->primero == NULL);// 0 si esta vacia
}

void insertarCarta(ListaCarta *lista, int numero,char *tipo,char * nombre){
    NodoC * nuevo;
    if((nuevo = (NodoC *) malloc(sizeof(NodoC))) == NULL){
        fprintf(stderr, "malloc termino inesperadamente\n");
    }else{
        nuevo->carta.numero = numero;
        nuevo->carta.nombre= nombre;
        nuevo->carta.tipo = tipo;
        
        nuevo->siguiente = NULL;
        if(lista->primero == NULL && lista->ultimo == NULL){
            nuevo->carta.id = 0; // <-------------
            lista->primero = nuevo;
            lista->ultimo = nuevo;
        }else{
        	nuevo->carta.id = lista->ultimo->carta.id +1;// <-----------
            lista->ultimo->siguiente = nuevo;
			lista->ultimo = lista->ultimo->siguiente;
        }
    }
}

void eliminarCarta(ListaCarta * lista, Carta *carta){

	NodoC* auxiliar = (NodoC *) malloc(sizeof(NodoC));
	NodoC* anterior = (NodoC *) malloc(sizeof(NodoC));
	

	auxiliar = lista->primero;
	anterior = auxiliar;
	
	if(esVaciaListaCarta(lista)){

		printf("%i --\n", ( & auxiliar->carta == carta));
		if( & auxiliar->carta == carta){//si es el primer elemento
			printf(" ----------\n");
			if(lista->primero == lista->ultimo){//si solo hay uno
				vaciaListaCarta(lista);		
			}else{//si hay mas de uno
				lista->primero = lista->primero->siguiente;
			}
		}else{// si no es el primero
			while(auxiliar != NULL){
				printf("%i..\n", ( & auxiliar->carta == carta));
				if(&auxiliar->carta == carta){
					if(auxiliar == lista->ultimo){ // si es el ultimo
						anterior->siguiente =NULL;
					}else{//si no es el ultimo
						anterior->siguiente = auxiliar->siguiente;
					}
				}
				anterior = auxiliar;
				auxiliar = auxiliar->siguiente;
			}
		}
	}
}
void mostrarCarta(Carta * carta){
	printf("-carta %s -tipo %s -valor  %i -id %i \n",carta->nombre, carta->tipo, carta->numero,carta->id );
}
void ingresarABaraja(ListaCarta *lista,ListaCarta *cartasJugador ,int posicion){
	NodoC * auxiliar = lista->primero;
	int i ;
	for( i =0;i <=posicion;i++){
		auxiliar = auxiliar->siguiente;
	}
	mostrarCarta(&auxiliar->carta);

	insertarCarta(cartasJugador, auxiliar->carta.numero,auxiliar->carta.tipo,auxiliar->carta.nombre);
	eliminarCarta(lista, &auxiliar->carta);
}

void mostrarCartas(ListaCarta * lista){
	NodoC * auxiliar = lista->primero;
	while(auxiliar != NULL){
		printf("-carta %s -tipo %s -valor  %i -id %i \n",auxiliar->carta.nombre, auxiliar->carta.tipo, auxiliar->carta.numero,auxiliar->carta.id );
		auxiliar = auxiliar->siguiente;
	}
}
