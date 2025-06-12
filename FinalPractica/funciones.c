/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"
#include <stdio.h>

void EncontrarInvertirImprimir(int* lista, int longitud){
    int listaRepeticiones[100]={0};
    int i=0,numeroRepetido=0,numeroMasRepetido=0,numeroCorridoIzquierda=0,numeroCorridoDerecha=0,numeroModificado=0,recorridas=0;
    for (i = 0; i < longitud ; i++) {
        listaRepeticiones[lista[i]]++;
    }
    recorridas++;
    for(i = 0; i < 101 ; i++){
        if(numeroRepetido<listaRepeticiones[i]){
            numeroRepetido=listaRepeticiones[i];
            numeroMasRepetido=i;
        } 
    }
    
    printf("\n\n");

    printf("El numero mas repetido en decimal es: %d\nEn Binario: ", numeroMasRepetido);
    for (int i = 15; i >= 0; i--) {
        printf("%d", (numeroMasRepetido >> i) & 1);
    }     
    printf("\n");

    numeroCorridoDerecha = numeroMasRepetido>>8;
    numeroCorridoIzquierda = numeroMasRepetido<<8;
    numeroModificado= numeroCorridoDerecha | numeroCorridoIzquierda;
    
    
    // Mostrar número modificado
    printf("Número modificado en decimal es: %d\nEn Binario: ", numeroModificado);
    for (int i = 15; i >= 0; i--) {
        printf("%d", (numeroModificado >> i) & 1);
    }  

    printf("\n\nEl numero de veces que se recorrio la lista es: %d\n\n",recorridas);
    printf("Los numero del 0 al 100 que no aparecen en la lista son:\n\n");
    for(i = 0; i < 101 ; i++){
        if(listaRepeticiones[i]==0){
            printf("%d ", i);
        }
    }
    printf("\n");

}

void imprimirGrilla(qnode_t* first){
    qnode_t* actual=first;
    qnode_t* actualAbajo=first;
    qnode_t* actualModificado=first;
    qnode_t* actualAbajoModificado=first;
    int alto=0,largo=0,suma=0,abajo=0,izquierda=0,derecha=0,arriba=0;
    while(actualAbajo!=NULL){
        actual=actualAbajo;
        while(actual!=NULL){
            printf("%d ",actual->valor);
            if(alto==0){
                largo++;
            }
            actual=actual->right;
        }
        printf("\n");
        actualAbajo=actualAbajo->down;
        alto++;
    }
    printf("\n");
    printf("la grilla tiene de alto: %d y de largo: %d\n\n", alto, largo);
    printf("Grilla luego de ser modificada\n\n");

    while(actualAbajoModificado!=NULL){
        actualModificado=actualAbajoModificado;
        while(actualModificado!=NULL){
            
            if(actualModificado->down!=NULL){
                abajo=actualModificado->down->valor;
            }

            if(actualModificado->up!=NULL){
                arriba=actualModificado->up->valor;
            }

            if(actualModificado->right!=NULL){
                derecha=actualModificado->right->valor;
            }

            if(actualModificado->left!=NULL){
                izquierda=actualModificado->left->valor;
            }

            suma=arriba+abajo+izquierda+derecha;
            if(suma>80){
                actualModificado->valor=actualModificado->valor/2;
            }
            printf("%d ",actualModificado->valor);
            actualModificado=actualModificado->right;
        }
        printf("\n");
        actualAbajoModificado=actualAbajoModificado->down;
    }
    
    
}