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
void numeroRepetido(int* lista,int cantidad);
void imprimirNumerosMenores(int* lista,int cantidad);
void imprimirGrilla(qnode_t *first,int* largo, int* alto);
void modificarGrilla(qnode_t *first);
/* Fin de sus definiciones, macros y prototipos */

/* Funciones de la Catedra, NO TOCAR! */
qnode_t* CATEDRA_CrearGrilla(void);

#endif