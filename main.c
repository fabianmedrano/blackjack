#include <stdio.h>
#include <stdlib.h>
#include "LogicaJuego.h"

ListaJugador judadoresJuego;
ListaCarta cartasJuego;

void main(){
	crearJugadores(&judadoresJuego, 5);
	mostrarJugadores(&judadoresJuego);


	vaciaListaCarta(&cartasJuego);
	crearCartas(&cartasJuego);
	mostrarCartas(&cartasJuego);
	repartirCartas(&cartasJuego ,&judadoresJuego);
	mostrarJugadores(&judadoresJuego);
	
}


