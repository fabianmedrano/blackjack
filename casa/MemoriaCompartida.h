#include <sys/types.h>  
#include <sys/ipc.h>
#include <errno.h>
#include <sys/shm.h> /* shm*  */

#define FILEKEY "/bin/cat"

#define KEY 1300

int key =0;
int id_zone =0;

typedef struct PartesJuego{
	Carta cartasDePaso;
	int estado;
	int numeroDeJugadores;
	int cartaTomada ;
   	int turno;
}Juego;

<<<<<<< HEAD
  partesJuego;

void  crearMemoriaConpartida(){
	key = ftok(FILEKEY, KEY);
	id_zone = shmget (key, sizeof(Juego), 0777 | IPC_CREAT);
	printf ("ID zone shared memory: %i\n", id_zone);
	
	partesJuego = *(Juego *)shmat (id_zone,0 , 0);
=======

Juego  *partesJuego;

void  crearMemoriaConpartida(){
	key = ftok(FILEKEY, KEY);
   
   id_zone = shmget (key, sizeof(Juego), 0777 | IPC_CREAT);

   printf ("ID zone shared memory: %i\n", id_zone);

   partesJuego = (Juego *)shmat (id_zone,0 , 0);

>>>>>>> parent of b48d258... intento de mas de dos procesos
}

void liberarMemoria(){
	shmdt ((Juego  *)&partesJuego);
   shmctl (id_zone, IPC_RMID, (struct shmid_ds *)NULL); 
}