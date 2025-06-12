/* Modelo Parcial */

/* Consideraciones Generales
 * - Escriba su código sobre este archivo.
 * - Las funciones deben estar definidas en el archivo funciones.c
 */

/* Declaracion de autoria
 * Fecha :
 * Autor :
 */

#include "definiciones.h"
#include "funciones.c"
#include "Catedra_3.c"

int main() {
#ifdef EJ1
    printf("\n\n========== Ejercicio 1 ==========\n\n");
    
    /* Comienzo de su codigo */
    file = fopen("archivo.bin", "rb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leer todos los números del archivo
    lista = malloc(sizeof(int));
    if (lista == NULL) {
        perror("Error de asignación de memoria");
        fclose(file);
        return 2;
    }

    
    while (fread(&lista[i], sizeof(int), 1, file) == 1) {
        i++;
        int* temp = realloc(lista, (i + 1) * sizeof(int));
        if (temp == NULL) {
            perror("Error de realloc");
            free(lista);
            fclose(file);
            return 3;
        }
        lista = temp;
    }
    printf("Lista original:\n\n");
    imprimirLista(lista,i);
    printf("\n\n");
    sumarMultiplos(lista,i);
    cambiarLista(lista,i);
    printf("\n\n");
    printf("Lista modificada:\n\n");
    imprimirLista(lista,i);

    fclose(file);
    free(lista);
    /* Fin de su codigo */
#endif

#ifdef EJ2
    printf("\n\n========== Ejercicio 2 ==========\n\n");
    dNode *primerDNode, *ultimoDNode;
    CATEDRA_CrearListaDoble(&primerDNode, &ultimoDNode);

    /* Comienzo de su codigo */

    /* Fin de su codigo */
#endif

#ifdef EJ3
    printf("\n\n========== Ejercicio 3 ==========\n\n");
    Node *primerNode = CATEDRA_CrearListaSimple();
    /* Comienzo de su codigo */


    /* Fin de su codigo */
#endif
    return 0;
}
