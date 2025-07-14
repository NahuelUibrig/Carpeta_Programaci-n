#include <stdio.h>
#include <stdlib.h>

#include "Catedra.c"
#include "definiciones.h"
#include "funciones.c"

int main(void)
{

#ifdef EJ1
    printf("\n ==== EJERCICIO 1 ==== \n");
   
    longitud=leer_archivo(lista);
    printf("%d ",longitud);
    imprimirLista(*lista,longitud);
    
    

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