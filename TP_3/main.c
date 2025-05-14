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
    Node_t* G = createNode('G');
    Node_t* H = createNode('H');
    Node_t* I = createNode('I');


    createConnection(X, A, 9);
    createConnection(A, B, 2);
    createConnection(A, C, 3);
    createConnection(B, F, 5);
    createConnection(B, H, 3); //nuevo
    createConnection(H, F, 2); //nuevo
    createConnection(C, D, 1);
    createConnection(C, E, 7);
    createConnection(C, I, 7); //nuevo
    createConnection(I, F, 7); //nuevo
    createConnection(D, F, 1);
    createConnection(E, F, 5);
    createConnection(A, G, 5); //nuevo
    createConnection(G, F, 5); //nuevo

    /* Begin USER functions */
    showgraph(X,&pasos);  
    printf("\n\n");
    shortestPath(X,F,&pasos,&distancia,&menorDistancia);
    /* End USER functions */
    free(A);
    free(B);
    free(C);
    free(D);
    free(E);
    free(F);

    return 0;
}
