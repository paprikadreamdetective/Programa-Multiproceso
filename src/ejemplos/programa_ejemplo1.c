/*
* Programa que ilustra la instalación de una rutina de atención a señal
*
* loop infinito.
*/

#include <stdio.h>
#include <unistd.h> /* funciones unix, como getpid() */
#include <signal.h> /* signal name macros, y el prototipo signal()*/


/* ESta rutina es el manejador de la señal */

void cacha_int(int sig_num) {
	/* reinstala el manejador de la señal de  nuevo para cachar la siguiente vez */
	signal (SIGINT, cacha_int);
	printf ("NO hagas eso !!\n");
	fflush (stdout);
}

int main(int argc, const char *argv[]) {
	/* PONER LA RUTINA cacha_int COMO MANEJADOR DE LA SEÑAL INT (ctrl-c)*/
	signal (SIGINT, cacha_int);
	/*ENTRAMOS A UN BUCLE INFINITO*/
	for (;;)
		pause ();
	return (0);
}




