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
    int aux_lista[] = {12, 16, 92, 89, 68, 71, 67, 30, 14, 83, 56, 75};
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
        actual->next = NULL;
    }
    else{
        if (actual->prev != NULL)
            actual->prev = NULL;
    }    
}

Node* CATEDRA_createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Node* CATEDRA_insFirst(Node* PrimerNode, int new_data) {
    Node* newNode = CATEDRA_createNode(new_data);
    if (PrimerNode == NULL) {
        return newNode;
    }
    Node* current = PrimerNode;
    newNode->next = current;
    return newNode;
}

Node* CATEDRA_CrearListaSimple(void){ 
    int aux_lista[] = {21, 24, 27, 42, 45, 48, 51, 54, 57, 60};
    int lista_size = sizeof(aux_lista)/sizeof(aux_lista[0]);
    Node* nuevo_Node = NULL;
    for (int i = lista_size; i > 0; i--){
        nuevo_Node = CATEDRA_insFirst(nuevo_Node, aux_lista[i-1]);
    }
    return nuevo_Node;
}