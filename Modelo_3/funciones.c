/* Declaracion de autoria
 * Fecha :
 * Autor :
 */

#include "definiciones.h"
#include <stdio.h>
/* Utilice este archivo para escribir sus funciones */

/*========== Ejercicio 1 ==========*/
void imprimirLista(int* lista, int longitud){
    int i=0;
    for(i=0;i<longitud;i++){
        printf("%d ",lista[i]);
    }
}
void sumarMultiplos(int* lista, int longitud){
    int i=0,numero=0,suma=0;
    numero=lista[longitud-1];
    for(i=0;i<longitud;i++){
        if(lista[i]%numero==0){
            suma=suma+lista[i];
        }
    }
    printf("La suma de multiplos da: %d \n\n",suma);
}
void cambiarLista(int* lista, int longitud){
    int i=0,numero=0,mascara=0b00010000;
    numero=lista[longitud-1];
    for(i=0;i<longitud;i++){
        if(lista[i]%numero!=0){
            lista[i]=lista[i]|mascara;
        }
    }
}
/*========== Ejercicio 2 ==========*/
/*
void buscarNodoRoto(dNode**primerDnode,dNode**ultimoDnode){
dNode* actualInicio=*primerDnode;
dNode* actualFinal=*ultimoDnode;


while(actualInicio!=NULL){
    if(actualInicio->next==NULL&&actualInicio!=*ultimoDnode){
        printf("Caso next roto\n\n");
        printf("valor de nodo roto: %d \n\n",actualInicio->data);
        if(actualInicio->prev!=NULL){
            printf("valor de nodo previo al roto: %d \n\n",actualInicio->prev->data);
        }
        printf("valor de nodo siguiente al roto: NULL \n\n");
        while(actualFinal!=NULL&&actualFinal->prev!=NULL){

            if(actualFinal->prev==actualInicio){
                printf("Lista modificada\n\n");
                actualFinal->prev=NULL;
                *primerDnode = actualFinal;
                *ultimoDnode = actualInicio;
                (*primerDnode)->prev = *ultimoDnode;
                (*ultimoDnode)->next = *primerDnode;
                printf("Fin función\n");
                return;
            }
            actualFinal=actualFinal->prev;
        }
        printf("Fin función\n");
        return;
        
    } 
    actualInicio=actualInicio->next;
}
actualInicio = *primerDnode;
while(actualFinal!=NULL){
    if(actualFinal->prev==NULL&&actualFinal!=*primerDnode){
        printf("Caso prev roto\n\n");
        printf("valor de nodo roto: %d \n\n",actualFinal->data);
        if(actualFinal->next!=NULL){
            printf("valor de nodo siguiente al roto: %d \n\n",actualFinal->next->data);
        }
        printf("valor de nodo previo al roto: NULL \n\n");
        while(actualInicio!=NULL&&actualInicio->next!=NULL){
 
            if(actualInicio->next==actualFinal){
                printf("Lista modificada\n\n");
                actualInicio->next = NULL;
                *primerDnode = actualFinal;
                *ultimoDnode = actualInicio;
                (*primerDnode)->prev = *ultimoDnode;
                (*ultimoDnode)->next = *primerDnode;
                printf("Fin función\n");
                return;
            }
            actualInicio=actualInicio->next;
        }
        printf("Fin función\n");
        return;
        
    }
    actualFinal=actualFinal->prev;
}

printf("Fin función\n");
}

 */

void buscarNodoRoto(dNode** primerDnode, dNode** ultimoDnode) {
    // Inicializo punteros de recorrido
    dNode* actualInicio = *primerDnode;    // Empiezo desde el primer nodo
    dNode* actualFinal  = *ultimoDnode;     // Empiezo desde el último nodo

    // ===== Bloque: caso 'next' roto =====
    while (actualInicio != NULL) {
        if (actualInicio->next == NULL && actualInicio != *ultimoDnode) {
            printf("Caso next roto\n\n");                              // Detecté un 'next' roto
            printf("valor de nodo roto: %d \n\n", actualInicio->data); // Muestro el dato del nodo roto
            if (actualInicio->prev != NULL) {
                printf("valor de nodo previo al roto: %d \n\n", actualInicio->prev->data);
            }
            printf("valor de nodo siguiente al roto: NULL \n\n");         // next está en NULL

            // Recorro desde el final hacia atrás para encontrar el enlace faltante
            while (actualFinal != NULL && actualFinal->prev != NULL) {
                if (actualFinal->prev == actualInicio) {
                    printf("Lista modificada\n\n");                       // Encontré el punto complementario
                    actualFinal->prev = NULL;                               // Nuevo primer nodo: rompo prev
                    *primerDnode       = actualFinal;                       // Actualizo primer puntero
                    *ultimoDnode       = actualInicio;                      // Actualizo último puntero
                    (*primerDnode)->prev = *ultimoDnode;                    // Cierro circularidad: prev del primero
                    (*ultimoDnode)->next = *primerDnode;                    // Cierro circularidad: next del último
                    printf("\nFin función\n");                              // Termino función
                    return;
                }
                actualFinal = actualFinal->prev;                           // Sigo retrocediendo
            }
            printf("\nFin función\n");                                  // No encontré complemento
            return;
        }
        actualInicio = actualInicio->next;                                // Avanzo hacia adelante
    }

    // ===== Bloque: caso 'prev' roto =====
    actualInicio = *primerDnode;                                          // Reinicio puntero de inicio
    while (actualFinal != NULL) {
        if (actualFinal->prev == NULL && actualFinal != *primerDnode) {
            printf("Caso prev roto\n\n");                               // Detecté un 'prev' roto
            printf("valor de nodo roto: %d \n\n", actualFinal->data);  // Muestro el dato del nodo roto
            if (actualFinal->next != NULL) {
                printf("valor de nodo siguiente al roto: %d \n\n", actualFinal->next->data);
            }
            printf("valor de nodo previo al roto: NULL \n\n");           // prev está en NULL

            // Recorro desde el inicio hacia adelante para encontrar el enlace faltante
            while (actualInicio != NULL && actualInicio->next != NULL) {
                if (actualInicio->next == actualFinal) {
                    printf("Lista modificada\n\n");                     // Encontré el punto complementario
                    actualInicio->next = NULL;                            // Nuevo último nodo: rompo next
                    *ultimoDnode       = actualInicio;                    // Actualizo último puntero
                    *primerDnode       = actualFinal;                     // Actualizo primer puntero
                    (*primerDnode)->prev = *ultimoDnode;                  // Cierro circularidad: prev del primero
                    (*ultimoDnode)->next = *primerDnode;                  // Cierro circularidad: next del último
                    printf("\nFin función\n");                            // Termino función
                    return;
                }
                actualInicio = actualInicio->next;                         // Sigo avanzando
            }
            printf("\nFin función\n");                                  // No encontré complemento
            return;
        }
        actualFinal = actualFinal->prev;                                // Retrocedo hacia atrás
    }

    printf("\nFin función\n");                                          // No se detectó roto
}


/*========== Ejercicio 3 ==========*/
void imprimeListaSimple(Node *primerNode){
    Node *current = primerNode;
    printf("Imprimo lista simple:\n\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
}

Node *creaListaSimple(int vector[], int largo){

    Node *primero = crearNodo(vector[0]); // crea mi primer nodo , obligatoriamente 
    Node *current = primero;

    for (int i = 1; i < largo; i++)
    {
        current->next = crearNodo(vector[i]);
        current = current->next;
    }

    return primero;
}
/* 
int calcularLargo_vector(int vector[]){
    int i = 0;
    while (vector[i] != 0 )
    {
        i++;
    }
    return i;
    
}
*/
Node *crearNodo(int nuevoDato){
    Node *nuevoNodo = (Node *)malloc(sizeof(Node)); // Con malloc le damos el espacio a mi nuevo nodo
                                                    //  a su vez me devuelve la posicion donde me reservo y esa posicion es donde va a estar
                                                    //  mi nuevo nodo.
    if (!nuevoNodo) // No hay nuevo nodo , es lo mismo que poner nuevoNodo = NULL
    {
        printf("No se pudo crear nuevo nodo");
        exit(1);
    }
    // Ya tengo creado  mi nuevo nodo

    nuevoNodo->next = NULL;
    nuevoNodo->data = nuevoDato;

    return nuevoNodo; // me devuelva la direccion del puntero
}

void fusionarListasOrdenando(Node** primerNode,Node* primerNodePropio){
    Node* actual=*primerNode;
    Node* actualNuevo=primerNodePropio;
    
    while(actual->next!=NULL){
        actual=actual->next;
    }
    actual->next=actualNuevo;
    
    bubbleSortLista(*primerNode);
        
}

void intercambioData(Node* a, Node* b) {
    int tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

void bubbleSortLista(Node* primero) {
    if (!primero) return;  // Si la lista está vacía, no hay nada que hacer

    int huboCambios;
    Node *actual, *ordenadoHasta = NULL;

    do {
        huboCambios = 0;
        actual = primero;

        // Recorremos hasta el último que ya está en su lugar
        while (actual->next != ordenadoHasta) {
            if (actual->data > actual->next->data) {
                intercambioData(actual, actual->next); // Si están desordenados, los cambio
                huboCambios = 1;  // Marcamos que hicimos un cambio
            }
            actual = actual->next; // Seguimos con el que sigue
        }

        ordenadoHasta = actual; // Este ya quedó ordenado, no lo miramos más
    } while (huboCambios); // Seguimos mientras sigan habiendo cambios
}



