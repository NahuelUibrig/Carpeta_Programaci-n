#ifndef _DEF_H
#define _DEF_H

#define EJ1
#define EJ2

typedef struct qnode_t {
    struct qnode_t* up;
    struct qnode_t* down;
    struct qnode_t* right;
    struct qnode_t* left;
    int valor;
} qnode_t;

/* Comienzo de sus definiciones, macros y prototipos */
FILE* file;
    int i = 0;
    int* lista=0;
    int* temp=0;
    
void EncontrarInvertirImprimir(int* lista,int longitud);
void imprimirGrilla(qnode_t* first);

/* Fin de sus definiciones, macros y prototipos */

/* Funciones de la Catedra, NO TOCAR! */
qnode_t* CATEDRA_CrearGrilla(void);

#endif