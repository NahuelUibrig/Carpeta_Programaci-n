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
    char sangria[100]="";
    if (actual == NULL || *pasos > 10){
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

void shortestPath(Node_t* primerNodo,Node_t* ultimoNodo,int* pasos,int *distancia,int *menorDistancia){
    Node_t* actual=primerNodo;
    int visitado=0,fin=0;
    char sangria[100]="",sangria2[100]="";
    if (actual == NULL || *pasos > 20){
        return;
    }

    for (int j = 0; j < (*pasos)+1; j++) { 
    strcat(sangria,"         ");
    }

    for (int h = 0; h < 5-(*pasos); h++) { 
    strcat(sangria2,"         ");
    }

    if (actual->connections[0].node == NULL&&
        actual->connections[1].node == NULL&&
        actual->connections[2].node == NULL&&
        actual!=ultimoNodo) {
            printf("%c\n", actual->name);
    }
    
    

    if(actual==ultimoNodo){
        printf("%c %s(Dist: %d)\n", actual->name,sangria2,*distancia); 
        if(*distancia<*menorDistancia){
            *menorDistancia=*distancia;
                
        }
        fin=1;
        (*pasos)--; 
        return;

    }

    for (int i = 0; i < 3; i++) {
        if (actual->connections[i].node != NULL) {
            visitado++;
            *distancia+=actual->connections[i].dist;
            if(visitado>1){
                printf("%s",sangria);
            }
            if(fin==0){
                    printf("%c - %d -> ", actual->name, actual->connections[i].dist);
            }
        
            (*pasos)++;
            shortestPath(actual->connections[i].node, ultimoNodo, pasos, distancia, menorDistancia);
            
            *distancia -= actual->connections[i].dist;
        }
    }

    if (*pasos == 0) {
        printf("Menor distancia: %d\n", *menorDistancia);
    }
    (*pasos)--; 
    
}

void skipNode(Node_t* primerNodo,Node_t*nodoSkip){
Node_t* actual=primerNodo;
Node_t* first=NULL;
Node_t* second=NULL;
int dist=0;

if (primerNodo == NULL || nodoSkip == NULL){
    return;
} 


    for (Node_t* actual = primerNodo; actual != NULL;) { 
        for (int i = 0; i < 3; i++) {
            if (actual->connections[i].node == nodoSkip) {
                first = actual;
                second = actual->connections[i].node->connections[0].node;
                dist = actual->connections[i].dist+actual->connections[i].node->connections[0].dist;
                createConnection(first, second, dist);
                free(nodoSkip);
                return;
            }
            skipNode(actual,nodoSkip);
        }
        
    }

}




