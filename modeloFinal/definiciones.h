#ifndef definiciones
#define definiciones

#define EJ1
#define EJ2

typedef struct {
    int temp;
    int humedad;
} data_t;

typedef struct Node Node;

struct Node {
    Node* next;
    Node* prev;
    data_t data;
};

/* ============= Comienzo de sus prototipos ============= */

/* ===============  Fin de sus prototipos =============== */

/* ============ Prototipos Catedra (NO USAR) ============ */
void CATEDRA_CrearListaDoble(Node** primerNodo, Node** ultimoNodo);
void sumarMultiplo();
int buscoNumero();
#endif