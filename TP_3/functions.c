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

    if (*pasos == -1) {
        printf("\nMenor distancia: %d\n", *menorDistancia);
    }
    (*pasos)--; 
    
}


void skipNode(Node_t* primerNodo,Node_t*nodoSkip,Node_t*raiz){
    Node_t* actual=primerNodo;
    Node_t* first=NULL;
    Node_t* second=NULL;
    int dist=0,pasos=0;
    static int noRecursiva=0;
    if (actual == NULL || nodoSkip == NULL){
    return;
    } 
    

    // Paso 1: recorrer recursivamente primero, sin modificar
    for (int i = 0; i < 3; i++) {
        first = actual->connections[i].node;
        if (first != NULL && first != nodoSkip) {
            noRecursiva=0;
            skipNode(first, nodoSkip,raiz);
        }
    }
    
    // Paso 2: luego de recorrer, ver si alguna conexión apunta a nodoSkip
    for (int i = 0; i < 3; i++) {
        if (actual->connections[i].node == nodoSkip) {
            second = actual->connections[i].node->connections[0].node;
            if(second!=NULL){
                dist = actual->connections[i].dist+actual->connections[i].node->connections[0].dist;
                actual->connections[i].node = NULL;
                actual->connections[i].dist = 0;
                actual->connections[i].node = second;
                actual->connections[i].dist = dist; 
                if(noRecursiva==0){
                pasos=0;
                showgraph(raiz,&pasos);   
                }
                noRecursiva++;
                if(nodoSkip->connections[1].node!=NULL){                      //Si algun nodo se queda sin conexion, se convierte en nodo origen.
                    showgraph(nodoSkip->connections[1].node,&pasos);          //Se imprime nuevo camino de nodo origen.
                }
                if(nodoSkip->connections[2].node!=NULL){                      
                    showgraph(nodoSkip->connections[2].node,&pasos);          
                }
                free(nodoSkip);

            }else{
                    printf("\n El nodo siguiente al destino no existe\n");
            }
                  
        }
    
    }
    
}









