#ifndef definiciones
#define definiciones

//#define EJ1
#define EJ2

typedef struct {
    int num1;
    int num2;
    unsigned int num3;
} file_struct;

typedef struct Node node_t;

struct Node {
    node_t* next;
    int data;
};

typedef struct {
    node_t* nodoLista1;
    node_t* nodoLista2;
    node_t* nodoLista3;
} superNode_t;

/* ============= Comienzo de sus prototipos ============= */
unsigned int* lista[]={0};
unsigned int longitud=0;
int largo=0;
unsigned int leer_archivo(unsigned int** lista);
void imprimirLista(unsigned int* lista, unsigned int longitud);
///////////////////////////////////////////////
void encuentroLista(superNode_t* first);
int listasNoCirculares(superNode_t* first);
//void ordenarYliberar(superNode_t* first);
/* ===============  Fin de sus prototipos =============== */

#endif