#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "definiciones.h"

dNode * CATEDRA_create_dNode(int data){
    dNode* new_dNode = (dNode*)malloc(sizeof(dNode));

    if (!new_dNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    new_dNode->data = data;
    new_dNode->next = NULL;
    new_dNode->prev = NULL;
    return new_dNode;
}


dNode* CATEDRA_insDFirst(dNode* primer_dNode, int new_data){
    dNode* new_dNode = CATEDRA_create_dNode(new_data);
    if (primer_dNode == NULL) {
        return new_dNode;
    }
    dNode* current = primer_dNode;
    new_dNode->next = current;
    new_dNode->prev = NULL;
    current-> prev = new_dNode;
    return new_dNode;
}

void CATEDRA_CrearListaDoble(dNode **primerNodo, dNode **ultimoNodo){
    int aux_lista[] = {54, 141, 186, 0, 239, 28, 75, 159, 7, 27};
    int lista_size = sizeof(aux_lista)/sizeof(aux_lista[0]);
    /* creo lista doble */
    *primerNodo = NULL;
    for (int i = lista_size; i > 0; i--)
        *primerNodo = CATEDRA_insDFirst(*primerNodo, aux_lista[i-1]);

    dNode* actual = *primerNodo;
    while(actual->next != NULL)
        actual = actual->next; 
    
    *ultimoNodo = actual;

    /* rompo lista doble */
    srand(time(NULL));
    int random  = (rand() % (lista_size - 2)) + 1; 

    actual = *primerNodo;
    for (int i = 0; i < random; i++){
        if (actual->next != NULL)
            actual = actual->next;
    }
    if (random%2 == 0){
        actual->next = actual->prev;
    }
    else{
        if (actual->prev != NULL)
            actual->prev = actual->next;
    }    
}