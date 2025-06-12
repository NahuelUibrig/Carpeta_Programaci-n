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
    
    file = fopen("lista.bin", "rb");
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
    
    EncontrarInvertirImprimir(lista,i);
    fclose(file);
    free(lista);
#endif

#ifdef EJ2
    printf("\n===== EJERCICIO 2 =====\n");

    qnode_t *first = CATEDRA_CrearGrilla();
    imprimirGrilla(first);
    

#endif

    return 0;
}