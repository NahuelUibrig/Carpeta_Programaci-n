/* Modelo Parcial */

/* Consideraciones Generales
 * - Escriba su código sobre este archivo.
 * - Las funciones deben estar definidas en el archivo funciones.c
 */

/* Declaracion de autoria
 * Fecha : 
 * Autor :
 */

#include "Catedra_1.c"
#include "definiciones.h"
#include "funciones.c"


int main() {
#ifdef EJ1
    printf("\n\n================== Ejercicio 1 ==================\n\n");
    
    /* Comienzo de su codigo */
    FILE* file;
    int cantidad=0;
    int* temp;
    int* lista;

        file = fopen("archivo.bin", "rb+");
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

            while (fread(&lista[cantidad], sizeof(int), 1, file) == 1) {
                cantidad++;
                temp = realloc(lista, (cantidad + 1) * sizeof(int));
                if (temp == NULL) {
                    perror("Error de realloc");
                    free(lista);
                    fclose(file);
                    return 3;
                }
                lista = temp;
            }
            fclose(file);

    imprimoLista(lista,cantidad);
    imprimoListaModificada(lista,cantidad);
    imprimoNumero(lista,cantidad);

    free(lista);
    /* Fin de su codigo */
#endif

#ifdef EJ2
    printf("\n\n================== Ejercicio 2 ==================\n\n");
    dNode* primerNodo;
    dNode* ultimoNodo;
    CATEDRA_CrearListaDoble(&primerNodo, &ultimoNodo);
    imprimoCiclo(primerNodo);
    eliminoCiclo(primerNodo);
    verificarCircularidad(primerNodo);
    crearListaCircular(primerNodo,ultimoNodo);
    verificarCircularidad(primerNodo);

    /* Comienzo de su codigo */



    /* Fin de su codigo */
#endif

#ifdef EJ3
    printf("\n\n================== Ejercicio 3 ==================\n\n");

    /* Comienzo de su codigo */

    /* Fin de su codigo */
#endif
    return 0;
}