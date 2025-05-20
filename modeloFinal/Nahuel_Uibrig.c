/* Modelo Parcial 
 * - Escriba su código sobre este archivo.
 * - Las funciones deben estar definidas en el archivo funciones.c
*/

/* Declaracion de autoria
 * Fecha :
 * Autor :
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "Catedra.c"
#include "definiciones.h"
#include "funciones.c"

int main() {
#ifdef EJ1
    /* Comienzo de su codigo */
    sumarMultiplo();
    buscoNumero();
    /* Fin de su codigo */
#endif

#ifdef EJ2
    Node* primerNodo;
    Node* ultimoNodo;
    CATEDRA_CrearListaDoble(&primerNodo, &ultimoNodo);

    /* Comienzo de su codigo */
    printf("\nLista antes del cambio\n");
    imprimoLista(primerNodo, ultimoNodo);
    eliminarHumedad(&primerNodo,&ultimoNodo);
    printf("\nLista despues del cambio\n");
    imprimoLista(primerNodo, ultimoNodo);
    imprimoListaCondicionada(primerNodo, ultimoNodo);
    printf("\nLista nueva\n");
    crearListaSimple(primerNodo,ultimoNodo);
    

    /* Fin de su codigo */
#endif

    return 0;
}
