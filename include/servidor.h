/*#include <stdio.h> 
#include <unistd.h>  funciones estándar de unix como alarm() 
#include <signal.h>  nombres de macros de señales, y el prototipo de signal() 
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/list.h"*/

#define MAX 10
/*int numArchs = 0;
LIST *listaArchivos;

char *archivos[] = {"notas.txt", "imagen.jpg", 
			"reporte.doc", "libro.pdf", 
			"logo.png", "instalador.exe", 
			"cancion.mp3", "pagina.html", 
			"programa.cpp", "tabla.csv"};*/

void cachaSenial(int sig);

void procesarArchivo();

void mostrarArchivos();

void principal();
