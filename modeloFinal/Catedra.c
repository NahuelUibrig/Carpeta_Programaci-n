#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"

int tl[] = {2, 51, 88, 945, 12, 1, 1, 1, -6, 8, -2, 89, 45, 31, 27};
int hl[] = {2, 15, -88, 495, 12, 94, 175, 1, -6, 8, -2, 89, 45, 31, 27};

Node* nn(int h, int t) {
    Node* nn = (Node*)malloc(sizeof(Node));

    if (!nn) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    nn->data.humedad = h;
    nn->data.temp = t;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

void CATEDRA_CrearListaDoble(Node** primerNodo, Node** ultimoNodo) {
    int ls = sizeof(tl) / sizeof(tl[0]);
    Node* c = NULL;
    *primerNodo = nn(hl[0], tl[0]);
    c = *primerNodo;

    for (int i = 1; i < ls; i++) {
        Node* n = nn(hl[i], tl[i]);
        c->next = n;
        n->prev = c;
        c = n;
    }
    *ultimoNodo = c;
}
