#include <stdio.h>
#include <stdlib.h>
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
