#include <stdio.h>
#include <stdlib.h>

#include "Catedra.c"
#include "definiciones.h"
#include "funciones.c"

int main(void)
{

#ifdef EJ1
    printf("\n ==== EJERCICIO 1 ==== \n");
   
    longitud=leer_archivo(&lista);
    printf("%d ",longitud);
    printf("\n\n");
    printf("Lista original = \n\n");
    imprimirLista(lista,longitud);
    printf("\n\n");
    printf("Numeros repetidos mas de 2 veces\n\n");
    modificarLista(lista,longitud);
    printf("Lista modificada = \n\n");
    imprimirLista(lista,longitud);
    printf("\n\n");
    EliminoUltimo(&lista,&longitud);
    printf("Lista modificada menos ultimo valor = \n\n");
    imprimirLista(lista,longitud);
    printf("\n\n");
    EliminoPrimero(&lista,&longitud);
    printf("Lista modificada menos primer valor = \n\n");
    imprimirLista(lista,longitud);
    printf("\n\n");

#endif

#ifdef EJ2
    printf("\n ==== EJERCICIO 2 ==== \n");

    superNode_t *first = CATEDRA_CrearListas();
    encuentroLista(first);
    largo=listasNoCirculares(first);
    encuentroLista(first);  ///Comprobacion
    //ordenarYliberar(first);
#endif

    return 0;
}