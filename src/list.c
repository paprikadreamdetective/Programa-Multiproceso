#include "../include/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new(LIST *list) {
    list->head = NULL;
    list->size = 0;
    return;
}

void new_node(NODE *node) {
    node->next = NULL;
}

int size(LIST *list) {
    return(list->size);
}

int IsEmpty(LIST list) {
    if(list.head == NULL)
        return(1);
    else
        return(0);
}

void insert(LIST *list, char t_name[50], int t_id) {
    // Nodo correspondiente a la creacion de la cabeza de la lista
    NODE *head_list = list->head;
    // Nodo actual que nos servira para encontrar el punto de inserccion
    NODE *current_node = head_list;
    // Nodo anterior que sirve como referencia para hacer insercciones
    NODE *previous_node = head_list;
    // Un nodo auxiliar para poder accesar a los campos y modificarlos
    NODE *aux;

    if(IsEmpty(*list) == 1) {
        head_list = (NODE*)malloc(sizeof(NODE));
        new_node(head_list);
        strcpy(head_list->data.archivo, t_name);
        head_list->data.ID = t_id;
        list->head = head_list;
        list->size++;
        return;
    }
        /*Encontrar el punto de inserccion*/
    // En este punto se recorre la lista tomando como referencia el ID de los elementos
    // para saber donde insertarlo de manera ordenada y para poder generar el siguiente elemento
    // y asi insertarlo en el caso que le corresponda, ya sea en medio o en la cola de la lista.
    while(current_node != NULL && t_id > current_node->data.ID) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    aux = (NODE*)malloc(sizeof(NODE));
    new_node(aux); /*Se genera un nuevo NODE*/
    if(previous_node == current_node) {
        strcpy(aux->data.archivo, t_name);
        aux->data.ID = t_id;
        aux->next = head_list; // Se inserta el nodo aux al inicio de la lista
        head_list = aux;        // Se actualiza la cabeza de la lista
        list->size++;
    } else {
        strcpy(aux->data.archivo, t_name);
        aux->data.ID = t_id;
        aux->next = current_node;
        previous_node->next = aux; // Se inserta al nodo aux despues de previous_node
        list->size++;              // el cual sirvio como referencia para saber donde hacer la
    }                               // la inserccion.
    list->head = head_list; // Por ultimo, se actualiza la cabeza de la lista que se recibe como
}                           // como parametro en la funcion

void erase(LIST *list, int index) {
    NODE *head_list = list->head;
    NODE *current_node = head_list;
    NODE *previous_node = head_list;
    if(IsEmpty(*list) == 1) {
        printf(">> Lista vacia. \n");
        printf(">> No hay ningun archivo procesandose. \n");
        return;
    }
    /*Entrar en la lista y encontrar el elemento a borrar*/
    while(current_node != NULL && index != current_node->data.ID) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    /*Si el dato no se encuentra: */
    if(current_node == NULL) {
        printf("\n");
        printf(">> Proceso no encontrado. \n");
        return;
    }
    /*Si el dato se encuentra: */
    if(previous_node == current_node) {
        head_list = head_list->next;/*Borrar un elemento de la cabeza*/
        printf("\n");
        printf(">> Proceso terminado: \n");
    } else {
        previous_node->next = current_node->next; /*Borrar elemento que no sea la cabeza*/
        printf("\n");
        printf(">> Proceso terminado: \n");
    }
    free(current_node);
    list->head = head_list;
    list->size--;
}

void search(LIST *list, int index) {
    NODE *current_node = list->head;
    while(current_node != NULL && index != current_node->data.ID)
        current_node = current_node->next;
    if(current_node) {
        printf("---------------------------------------------\n");
        printf(">>      Archivo: %s\n", current_node->data.archivo);
        printf(">>           ID: %d\n", current_node->data.ID);
        printf("---------------------------------------------\n");
    } else {
        printf("\n");
        printf(">> Proceso no encontrado. \n");
    }
}

void display(LIST *list) {
    NODE *aux = list->head;
    DATA dat;
    if(IsEmpty(*list) == 1) {
        printf(">> Lista vacia. \n");
        printf(">> No hay ningun archivo procesandose. \n");
    } else {
        printf(">> Lista de archivos en proceso. \n");
        printf(">> Numero de archivos procesandose en la lista: %d\n", size(list));
        while(aux != NULL) {
            dat = aux->data;
            printf("------------------------------------------\n");
	    printf(">>      Archivo: %s\n", dat.archivo);
	    printf(">>          PID: %d\n", dat.ID);
            printf("------------------------------------------\n");
            aux = aux->next;
        }
    }
}

