#ifndef definiciones
#include <stdio.h>
#include <stdlib.h>
#define definiciones

/* Declaracion de autoria
 * Fecha :
 * Autor :
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct dNode {
    int data;
    struct dNode *next;
    struct dNode *prev;
} dNode;

/* Puede comentar o des-comentar los siguientes define a medida que lo necesite*/
/*#define EJ1
#define EJ2*/
#define EJ3



/* ============= Comienzo de sus prototipos ============= */
FILE* file;
int i = 0;
int* lista=0;
int* temp=0;
void imprimirLista(int* lista, int i);
void sumarMultiplos(int* lista, int i);
void cambiarLista(int* lista, int i);
////////////////////////////////////////////////////////////
void buscarNodoRoto(dNode**primerDnode,dNode**ultimoDNode);
////////////////////////////////////////////////////////////
int largo=0;
void imprimeListaSimple(Node *primerNode);
Node *crearNodo(int nuevoDato);
Node *creaListaSimple(int lista_gap[], int largo);
void fusionarListasOrdenando(Node** primerNode,Node* primerNodePropio);
void intercambioData(Node* a, Node* b);
void bubbleSortLista(Node* head);

/* ===============  Fin de sus prototipos =============== */


/* Prototipos de Catedra_3.c (NO USAR) */

int lista_gap[] = {30, 33, 36, 39};

dNode * CATEDRA_create_dNode(int data);
dNode* CATEDRA_insDFirst(dNode* primer_dNode, int new_data);
void CATEDRA_CrearListaDoble(dNode **primerNodo, dNode **ultimoNodo);

Node* CATEDRA_createNode(int data);
Node* CATEDRA_insFirst(Node* PrimerNode, int new_data);
Node* CATEDRA_CrearListaSimple(void);
#endif