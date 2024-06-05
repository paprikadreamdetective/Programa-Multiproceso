/*
* Programa que ilustra el uso de alarmas
*
* El programa instala una rutina de atención a la interrupcion ALRM.
* Pide datos al usuario y si la alarma "suena" antes de que el usuario
* haya contestado se termina.
*
*/
#include <stdio.h> /* funciones de I/O standard */
#include <unistd.h> /* funciones estándar de unix como alarm() */
#include <signal.h> /* nombres de macros de señales, y el prototipo de signal() */
#include <stdlib.h>
char usuario[40]; /* buffer para leer el buffer de usuario */
/* define el manejador de la alarma */
void cacha_alarma(int sig_num) {
	printf("Expiró el tiempo de espera ... ciao!!! ...\n\n");
	exit(0);
}
int main(int argc, char* argv[]) {
	/* Poner el manejador para la señal ALRM */
	signal(SIGALRM, cacha_alarma);
	/* Pide datos al usuario */
	printf("Usuario? : ");
	fflush(stdout);
	/* arranca la alarma de 30 segundos */
	alarm(30);
	/* Espera la entrada del usuario */
	scanf("%s", usuario);
	/* apagar la alarma una vez que el usuario dio su nombre */
	alarm(0);
	printf("Usuario: '%s'\n", usuario);
	return 0;
}
