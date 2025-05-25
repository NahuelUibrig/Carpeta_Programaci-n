#include <stdio.h>
#include <stdlib.h>

#include "definiciones.h"

/* Puede descomentar las siguientes lineas si lo necesita para compilar su programa */
#include "Catedra.c"
#include "funciones.c"

int main(void)
{

#ifdef EJ1
    printf("\n===== EJERCICIO 1 =====\n");
FILE* file;
    int cantidad=0;
    int* temp;
    int* lista;
    int* encontrado;

    file = fopen("lista.bin", "rb+");
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

    numeroRepetido(lista,cantidad);
    imprimirNumerosMenores(lista,cantidad);

    free(lista);
#endif

#ifdef EJ2
    printf("\n===== EJERCICIO 2 =====\n");
    int largo=0;
    int alto=0;

    qnode_t *first = CATEDRA_CrearGrilla();
    printf("\nGrilla sin modificar:\n\n");
    imprimirGrilla(first,&largo,&alto);
    printf("\n");
    printf("largo de la lista %d \n", largo);
    printf("alto de la lista %d \n", alto);
    modificarGrilla(first);
    printf("\nGrilla modificada:\n\n");
    imprimirGrilla(first,&largo,&alto);
    printf("\n");

#endif

    return 0;
}