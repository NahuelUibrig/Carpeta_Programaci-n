#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

Node_t* createNode(char name) {
    Node_t* nuevoNodo = (Node_t*)malloc(sizeof(Node_t));
    if (!nuevoNodo) {
        printf("Error en la creacion del Node_t\n");
        exit(1);
    }
    for (int i = 0; i < 3; i++) {
        nuevoNodo->connections[i].dist = 0;
        nuevoNodo->connections[i].node = NULL;
    }
    nuevoNodo->name = name;

    return nuevoNodo;
}

void createConnection(Node_t* First, Node_t* Second, int dist) {
    for (int i = 0; i < 3; i++) {
        if (First->connections[i].node == NULL) {
            First->connections[i].node = Second;
            First->connections[i].dist = dist;
            return;
        }
    }
    perror("No se permiten mas conexiones");

    return;
}

void showgraph(Node_t* primerNodo,int* pasos){
    Node_t* actual=primerNodo;
    int visitado=0;
    char sangria[100]=" ";
    if (actual == NULL || (*pasos)++ > 10){
        return;
    }

    
    if (actual->connections[0].node == NULL&&
        actual->connections[1].node == NULL&&
        actual->connections[2].node == NULL) {
            printf("%c\n", actual->name);
     }
    
    for (int j = 0; j < *pasos; j++) { 
    strcat(sangria,"         ");
    }

    for (int i = 0; i < 3; i++) {
        if (actual->connections[i].node != NULL) {
            visitado++;
            if(visitado>1){
                printf("%s",sangria);
            }
            printf("%c - %d -> ", actual->name, actual->connections[i].dist);
            (*pasos)++;
            showgraph(actual->connections[i].node, pasos);
        }
    }
    (*pasos)--;
}





