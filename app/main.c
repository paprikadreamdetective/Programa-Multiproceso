#include <stdio.h> /* funciones de I/O standard */
#include <unistd.h> /* funciones estándar de unix como alarm() */
#include <signal.h> /* nombres de macros de señales, y el prototipo de signal() */
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/list.h"
#include "../include/servidor.h"

int main() {
	principal();
	return(0);

}


