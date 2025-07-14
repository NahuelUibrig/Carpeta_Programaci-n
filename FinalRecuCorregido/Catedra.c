#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"

node_t *createLista(int *lista, int size, int isCircular)
{
    node_t *newNode, *prevNode, *firstNode;

    firstNode = malloc(sizeof(node_t));
    prevNode = firstNode;

    for (int i = 0; i < size - 1; i++)
    {
        newNode = malloc(sizeof(node_t));
        prevNode->data = lista[i];
        prevNode->next = newNode;
        prevNode = newNode;
    }
    if (isCircular)
    {
        prevNode->data = lista[size - 1];
        prevNode->next = firstNode;
    }
    else
    {
        prevNode->data = lista[size - 1];
        prevNode->next = NULL;
    }
    return firstNode;
}

superNode_t *CATEDRA_CrearListas()
{
    int lista1[] = {9, 9, 2, 6, 2, 4, 8, 4, 5, 5, 8, 6, 2, 4, 1, 5, 5, 6};
    int lista2[] = {5, 8, 9, 2, 2, 2, 6, 1, 5, 8, 2, 8, 7, 6, 3, 9, 5, 8, 9};
    int lista3[] = {5, 6, 7, 3, 5, 2, 4, 7, 3, 4, 7, 9, 6, 2, 1, 7, 8, 3, 3, 3};

    superNode_t *first = malloc(sizeof(superNode_t));

    first->nodoLista1 = createLista(lista1, sizeof(lista1) / sizeof(lista1[0]), 1);
    first->nodoLista2 = createLista(lista2, sizeof(lista2) / sizeof(lista2[0]), 1);
    first->nodoLista3 = createLista(lista3, sizeof(lista3) / sizeof(lista3[0]), 0);

    return first;
}
