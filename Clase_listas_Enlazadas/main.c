#include <stdio.h>
#include <stdlib.h>
#include "def.h"

int main() {
    Nodo* PrimerNodo = NULL;
    Nodo* UltimoNodo = NULL;
    insFirst(&PrimerNodo,&UltimoNodo, 10);
    insFirst(&PrimerNodo,&UltimoNodo, 20);
    insFirst(&PrimerNodo,&UltimoNodo, 30);
    insFirst(&PrimerNodo,&UltimoNodo, 40);
    insFirst(&PrimerNodo,&UltimoNodo, 50);

    printf("\nLista enlazada doble: \n");
    printLista(PrimerNodo);
    printListaReversed(UltimoNodo);
    delLast(&PrimerNodo,&UltimoNodo);

    printf("\nLista enlazada: \n");
    printLista(PrimerNodo);

    // freeList(&PrimerNodo);
    return 0;
}

Nodo* createNodo(int nuevoDato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("No se pudo crear el nodo");
        exit(1);
    }

    nuevoNodo->next = NULL;
    nuevoNodo->prev = NULL;
    nuevoNodo->dato = nuevoDato;

    return nuevoNodo;
}

void insFirst(Nodo** PrimerNodo,Nodo** UltimoNodo, int nuevoDato) {
    Nodo* nuevoNodo = createNodo(nuevoDato);

    if (*PrimerNodo == NULL) {
        *PrimerNodo = nuevoNodo;
        *UltimoNodo = nuevoNodo;
        return;
    }
    Nodo* actual = *PrimerNodo;
    nuevoNodo->next = actual;
    nuevoNodo->prev = NULL;
    actual->prev = nuevoNodo;
    *PrimerNodo = nuevoNodo;
}

void printLista(Nodo* PrimerNodo) {
    Nodo* actual = PrimerNodo;

    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->next;
    }
    printf("NULL\n");
}

void printListaReversed(Nodo* UltimoNodo) {
    Nodo* actual = UltimoNodo;
    
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->prev;
    }
    printf("NULL\n");
   
    
}

void delLast(Nodo** PrimerNodo, Nodo** UltimoNodo) {
    if (*PrimerNodo == NULL) {
        printf("La lista está vacía\n");
        return;
    }

    // Solo un nodo
    if ((*PrimerNodo)->next == NULL) {
        free(*PrimerNodo);
        *PrimerNodo = NULL;
        *UltimoNodo = NULL;
        return;
    }

    Nodo* actual = *UltimoNodo;
    Nodo* anterior = actual->prev;

    anterior->next = NULL;
    *UltimoNodo = anterior;
    free(actual);
}


