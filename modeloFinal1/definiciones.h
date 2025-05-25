#ifndef definiciones
#define definiciones

/* Declaracion de autoria
 * Fecha : 09/11/24
 * Autor : 
 */

typedef struct dNode{
    int data;
    struct dNode *next;
    struct dNode *prev;
}dNode;


/* Puede comentar o des-comentar los siguientes define a medida que lo necesite*/
#define EJ1
#define EJ2
#define EJ3


int lista_corta[] = {5, 10, 7, 20, 19, 15, 11, 2, 6, 0}; 

/* Comienzo de sus prototipos */
void imprimoLista(int* lista,int cantidad);
void imprimoListaModificada(int* lista,int cantidad);
void imprimoNumero(int* lista,int cantidad);
void imprimoCiclo(dNode* primerNodo);
void crearListaCircular(dNode*primerNodo,dNode*ultimoNodo);
void verificarCircularidad(dNode* primerNodo);
/* Fin de sus prototipos */
dNode * CATEDRA_create_dNode(int data);
dNode* CATEDRA_insDFirst(dNode* primer_dNode, int new_data);
void CATEDRA_CrearListaDoble(dNode **primerNodo, dNode **ultimoNodo);

#endif