typedef struct Nodo {
    struct Nodo* next;
    struct Nodo* prev;
    int dato;
} Nodo;

void delLast(Nodo** PrimerNodo, Nodo** UltimoNodo);
void insFirst(Nodo** PrimerNodo,Nodo** UltimoNodo, int nuevoDato);
void printLista(Nodo* PrimerNodo);
void printListaReversed(Nodo* UltimoNodo);
Nodo* createNodo(int nuevoDato);