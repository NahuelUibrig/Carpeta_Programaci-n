#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pasos=0,distancia=0,menorDistancia=100;
    Node_t* X = createNode('X');
    Node_t* A = createNode('A');
    Node_t* B = createNode('B');
    Node_t* C = createNode('C');
    Node_t* D = createNode('D');
    Node_t* E = createNode('E');
    Node_t* F = createNode('F');

    createConnection(X, A, 9);
    createConnection(A, B, 2);
    createConnection(A, C, 3);
    createConnection(B, F, 5);
    createConnection(C, D, 1);
    createConnection(C, E, 7);
    createConnection(D, F, 1);
    createConnection(E, F, 5);
    
    

    /* Begin USER functions */

    printf("\n-------------------------------------------------------------------------------------------------\n");

    printf("\n-Grafo de nodos inicial: \n\n");

    showgraph(X,&pasos);  

    printf("\n-------------------------------------------------------------------------------------------------\n");

    printf("\n-Distancias entre Nodos: \n\n");

    shortestPath(X,F,&pasos,&distancia,&menorDistancia);

    printf("\n-------------------------------------------------------------------------------------------------\n");
    
    printf("\n-Grafo luego de skipear Nodo D: \n\n");

    skipNode(X, D, X);
      
    printf("\n-Grafo con Nodo C skipeado luego de skipear Nodo D: \n\n");

    skipNode(X, C, X);

    //skipNode(Nodo inicio que se usa recursivamente, Nodo a saltear, Nodo inicio);

    printf("\n-------------------------------------------------------------------------------------------------\n");

    
    /* End USER functions */
    free(X);
    free(A);
    free(B);
    //free(C);
    //free(D);
    free(E);
    free(F);
    return 0;
}
