/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"
#include <stdlib.h>
#include <string.h>
void numeroRepetido(int* lista,int cantidad){
    int i,j=0,actual=0,vecesRecorrida=0,vecesActual=0,vecesEncontradoFinal=0,numeroEncontrado=0,contador=0;
    int numeroEncontradoMenosSig=0,numeroEncontradoMasSig=0,numeroNuevo=0;
    
    ///////////////imprimo lista parcial///////////////////
    printf("\n");
    /*
    for(i=0;i<cantidad;i++){
        actual=lista[i];
        for(j=0;j<cantidad;j++){
            if(lista[j]==actual){
                vecesRecorrida++;
                if(vecesEncontradoFinal<vecesRecorrida){
                    vecesEncontradoFinal=vecesRecorrida;
                    numeroEncontrado=actual;
                }
            } 
        }
    }
    */
    for(i = 0; i < cantidad; i++) {
        actual = lista[i];
        vecesActual = 0;
        vecesRecorrida++;
        for(j = 0; j < cantidad; j++) {
            
            if(lista[j] == actual) {
                vecesActual++;
            }
        }
        if(vecesActual > vecesEncontradoFinal) {
            vecesEncontradoFinal = vecesActual;
            numeroEncontrado = actual;
        }
    }


    if(numeroEncontrado!=0){
    printf("Número mas repetido en decimal: %d\nNumero mas repetido en Binario: ", numeroEncontrado);
        for (int i = 15; i >= 0; i--) {
            printf("%d", (numeroEncontrado >> i) & 1);
        }     
        printf("\n");
    numeroEncontradoMenosSig=(numeroEncontrado<<8);
    numeroEncontradoMasSig=(numeroEncontrado>>8);
    numeroNuevo=numeroEncontradoMasSig+numeroEncontradoMenosSig;
    printf("Número nuevo en decimal: %d\nNumero nuevo en Binario: ", numeroNuevo);
    for (int i = 15; i >= 0; i--) {
        printf("%d", (numeroNuevo >> i) & 1);
    }     
    printf("\n");


    }
    printf("Se recorrio la lista %d veces \n", vecesRecorrida);

}

void imprimirNumerosMenores(int* lista,int cantidad){
    int i=0,j=0,actual=0,valorNumero=0,encontrado=0,noEncontrado=0;
    printf("\nNumeros menores a 100 que no se encuentran en la lista:\n\n--> ");

    for(valorNumero=0;valorNumero<100;valorNumero++){
        
        for(i=0;i<cantidad;i++){
            if(valorNumero==lista[i]){
                encontrado=1;
            }
        }

        if(encontrado!=1){
           printf("%d ", valorNumero);
        }
        encontrado=0;
    }
    printf("\n");
   
}


void imprimirGrilla(qnode_t* first,int* largo, int* alto){
    qnode_t* actual=first;
    qnode_t* siguiente=NULL;

    int columnas=0;

    if (actual == NULL){
            return;
        }
    siguiente=actual->down;
    while (actual!=NULL) {
        printf("%d ",actual->valor);
        actual = actual->right;
        columnas++;
    }
    if(columnas>*largo){
        *largo=columnas;
    }
    
    (*alto)++;
    printf("\n");
    imprimirGrilla(siguiente,largo,alto);

}

void modificarGrilla(qnode_t *first){
    qnode_t* actual=first;
    qnode_t* siguiente=NULL;
    int abajo=0,arriba=0,derecha=0,izquierda=0,suma=0;
    int i=1,columnas=0;

    if (actual == NULL){
            return;
    }

    siguiente=actual->down;
    while (actual!=NULL) {
        
        if(actual->down!=NULL){
            abajo=actual->down->valor;
        }
        if(actual->up!=NULL){
            arriba=actual->up->valor;
        }
        if(actual->right!=NULL){
            derecha=actual->right->valor;
        }
        if(actual->left!=NULL){
            izquierda=actual->left->valor;
        }
        suma=abajo+arriba+derecha+izquierda;
        if(suma>80){
            //printf("Se actualizara el valor %d",actual->valor);
            actual->valor=(actual->valor)/2;
            //printf(" ahora es %d\n",actual->valor);
        }
        actual = actual->right;
       
    }

    modificarGrilla(siguiente);
}