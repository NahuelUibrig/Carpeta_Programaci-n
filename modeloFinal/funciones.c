/* Declaracion de autoria
 * Fecha : 
 * Autor : 
 */

/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"
#include <stdio.h>
#include <string.h>

/*================== Funciones Ejercicio 1 ==================*/

void imprimoLista(int* lista,int cantidad){
    FILE* file;
    int j=0,suma=0;
    float promedio=0;
    
    ///////////////imprimo lista y promedio///////////////////
    for(j=0;j<cantidad;j++){
        suma+=lista[j];
        printf(" %d \n", lista[j]);
        
    }
    promedio=(float)suma/(cantidad);
    printf(" %0.1f \n", promedio);
    
}


void imprimoListaModificada(int* lista,int cantidad){
    FILE* file;
    int j=0;
    int* lista1;
    
    ////////////////modificar lista////////////////////////
    lista1 = malloc(cantidad * sizeof(int));
    if (lista1 == NULL) {
        perror("Error de asignación de memoria");
        return;
    }


    for(j=0;j<cantidad;j++){
        if(j+1!=cantidad&&lista[j+1]%2!=0){
            lista1[j]=lista[j]*5;
        }else{
            lista1[j]=lista[j]; 
        }
         
    }
     
    ///////////////imprimo lista nueva///////////////////
    printf("\n"); 
    for(j=0;j<cantidad;j++){
        printf(" %d \n", lista1[j]);  
    }

    free(lista1);
    
}

void imprimoNumero(int* lista,int cantidad){
    FILE* file;
    int j=0,h=0,suma=0,encontrado=0;
    float promedio=0;
   
    
    ////////////////////promedio///////////////////////
    for(j=0;j<cantidad;j++){
        suma+=lista[j];
    }
    promedio=(float)suma/(cantidad);
    printf("\nNumero encontrado:\n");
    
    
    for(j=0;j<cantidad;j++){
        if(lista[j]>promedio*2&&encontrado==0){
            if(((lista[j] >> 2) & 1)==0){
                printf("\n %d \n", lista[j]);
                encontrado=1;
            }
        }
        
    }
    
}


/*================== Funciones Ejercicio 2 ==================*/

void imprimoCiclo(dNode* primerNodo){

dNode* actual=primerNodo;

while (actual != NULL) {
        if (actual->next != NULL && actual->next == actual->prev) {
            printf("Nodo con ciclo encontrado:\n");
            printf("Valor del nodo: %d\n", actual->data);
            if (actual->next != NULL) {
                printf("Valor next: %d\n", actual->next->data);
            } else {
                printf("Valor next -1\n");
            }
            if (actual->prev != NULL) {
                printf("Valor prev: %d\n", actual->prev->data);
            } else {
                printf("Valor prev: -1\n");
            }
            return;
        }
        
        actual = actual->next;
    }
        

    printf("No se encontró un ciclo en la lista.\n");
}

void eliminoCiclo(dNode* primerNodo) {
    dNode* actual = primerNodo;

    while (actual != NULL) {
        // Detectar ciclo: next y prev apuntan al mismo nodo
        if (actual->next != NULL && actual->next == actual->prev) {

            // Buscar el nodo cuyo prev es el nodo actual (el que tiene el ciclo)
            dNode* siguienteReal = primerNodo;
            while (siguienteReal != NULL && siguienteReal->prev != actual) {
                siguienteReal = siguienteReal->next;
            }

            if (siguienteReal != NULL) {
                // Reconectar correctamente
                actual->next = siguienteReal;
                siguienteReal->prev = actual;
                printf("Ciclo eliminado y reconectado correctamente.\n");
            } else {
                // No se encontró siguiente lógico, cortar el ciclo
                actual->next = NULL;
                printf("Ciclo eliminado, pero no se pudo reconectar.\n");
            }

            return;
        }

        actual = actual->next;
    }

    printf("No se encontró un ciclo en la lista.\n");
}



void crearListaCircular(dNode* primerNodo, dNode* ultimoNodo) {
    if (primerNodo == NULL || ultimoNodo == NULL) {
        printf("No se puede crear lista circular: nodos inválidos.\n");
        return;
    }

    primerNodo->prev = ultimoNodo;
    ultimoNodo->next = primerNodo;

    printf("\nLista circular creada.\n");
}
void verificarCircularidad(dNode* primerNodo) {
    dNode* actual = primerNodo;
    int pasos = 0;

    if (primerNodo == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    do {
        printf("%d -> ", actual->data);
        actual = actual->next;
        pasos++;

        if (pasos > 50) {  // para evitar bucles infinitos si hay errores
            printf(" (demasiados pasos, puede que haya un bucle infinito)\n");
            return;
        }
    } while (actual != primerNodo);

    printf("(vuelta al inicio)\n");
}

/*================== Funciones Ejercicio 3 ==================*/
