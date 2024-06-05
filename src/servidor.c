#include <stdio.h> /* funciones de I/O standard */
#include <unistd.h> /* funciones estándar de unix como alarm() */
#include <signal.h> /* nombres de macros de señales, y el prototipo de signal() */
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/servidor.h"
#include "../include/list.h"

#define MAX 10
int numArchs = 0;
LIST *listaArchivos;

char *archivos[] = {"notas.txt", "imagen.jpg", 
			"reporte.doc", "libro.pdf", 
			"logo.png", "instalador.exe", 
			"cancion.mp3", "pagina.html", 
			"programa.cpp", "tabla.csv"};

void cachaSenial(int sig) {
	signal(SIGUSR1, cachaSenial);
	int status;
	pid_t terminated_pid = waitpid(-1, &status, WNOHANG);
	if (terminated_pid == 0)
		terminated_pid = waitpid(-1, &status, 0);
	printf("Numero de archivo: %d \n", numArchs);
	printf("Señal recibida por el padre %d \n", terminated_pid);
	printf("Status: %d \n", WEXITSTATUS(status));
	erase(listaArchivos, terminated_pid);
	numArchs--;	
}

void procesarArchivo() {
	if (numArchs == MAX) {
		printf("[ - Servidor saturado - ]\n");
		printf("Intentar mas tarde\n");
                sleep(2);                  
	} else {
                //srand(time(NULL));
		char idArchivo[50];
		numArchs++;
     		pid_t pid = fork();
		int k = rand() % 10;
		//snprintf(idArchivo, sizeof(idArchivo), "%d", numArchs);	
		insert(listaArchivos, archivos[k], pid);
        	if (pid == 0) { 
                	srand(time(NULL));
                	int random = ((rand() % 30) + 40);
			printf("Procesando archivo %d \n", numArchs);
			sleep(random);                  
			kill(getppid(), SIGUSR1);
                	exit(0);
		}
	}
}

void mostrarArchivos() {
	display(listaArchivos);
}

void principal() {
	signal(SIGUSR1, cachaSenial);
	int opcion;
	int n;
	listaArchivos = (LIST*)malloc(sizeof(LIST));
	new(listaArchivos);
	do {
		system("clear");
		printf("\t Servidor \n");
		printf("\t 1) Procesar nuevo archivo\n");
		printf("\t 2) Mostrar lista de archivos en proceso\n");
		printf("\t 3) Terminar\n");
		printf("\t\n");
		printf("\t Digite una opcion: ");
		scanf("%d", &opcion);
		printf("\n");
		switch (opcion) {
			case (1):
				procesarArchivo();	
				break;
			case (2):
				do {
					mostrarArchivos();
					printf("\n");
					printf("\t [0] Actualizar \n");
					printf("\t [1] Salir \n");
					printf("\t Digite una opcion: ");
					scanf("%d", &n);
				} while(n != 1);
				break;
			case (3):
				printf("\t Esperando a que los archivos se terminen de procesar ...\n");
				while (wait(NULL) != -1);
				printf("\t\n >> Fin del procesamiento.\n");
				break;
			default:
				break;
				break;
		}
	} while(opcion < 3);
	free(listaArchivos);
}
