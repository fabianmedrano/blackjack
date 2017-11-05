#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int retiradas = 0;
int totalCartas =54; 

//saca hasta el numero sumerior incluyendolo -- apartir del uno (0 = violacion del segmento)
int obtenerPosicion(){
	int aleatorio;
    srand(time(NULL));
    aleatorio =(rand () %((totalCartas - retiradas)-1+1) )+ 1;
    retiradas++;
    printf(" retiradas %i , total cartas %i\n \n",retiradas , (totalCartas - retiradas));
    return aleatorio;
}