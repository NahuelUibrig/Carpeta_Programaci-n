#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
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
    showgrap(X);
    /* End USER functions */
    free(A);
    free(B);
    free(C);
    free(D);
    free(E);
    free(F);

    return 0;
}
