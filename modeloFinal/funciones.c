/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"
#include <stdio.h>
#include <string.h>


void sumarMultiplo(){
    FILE* file;
    int i = 0,j=0,fin=0,sumaMultiplo=0;
    

    file = fopen("lista.bin", "rb+");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    int* lista = malloc(sizeof(int));
    if (lista == NULL) {
        perror("Error de asignación de memoria");
        return;
    }

    while (fread(&lista[i], sizeof(int), 1, file)) {
        i++;
        lista = realloc(lista, (i + 1) * sizeof(int));
       
    }

    ////////////////////////////////////////////////////
    fin=lista[i-1];
    for(j=0;j<i-1;j++){
        if(lista[j]%fin==0){
            sumaMultiplo+=lista[j];
        }
    }
    printf("\nSuma de multiplos: %d \n", sumaMultiplo);
    //////////////////////////////////////////////////// 
    
   
    fclose(file);
    free(lista);
    
}
/*
void buscoNumero(){
    FILE* file;
    int i = 0,j=0,sumaAnterior=0,numero=0,promedio=0,corrido=0,nuevoNumero=0;
    

    file = fopen("lista.bin", "rb+");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    int* lista = malloc(sizeof(int));
    if (lista == NULL) {
        perror("Error de asignación de memoria");
        return;
    }

    while (fread(&lista[i], sizeof(int), 1, file)) {
        i++;
        lista = realloc(lista, (i + 1) * sizeof(int));
       
    }

    ////////////////////////////////////////////////////
    for(j=0;j<i-1;j++){
            sumaAnterior+=lista[j];
            if(j>9&& sumaAnterior%j==0){
                promedio=sumaAnterior/j;
            }
            
            if(promedio!=0){
                corrido=lista[j]>1;
                if(corrido*0xb00010000>0){
                    nuevoNumero=lista[j]+corrido*0xb00001000;
                    printf("\nNumero anterior: %d \n", lista[j]);
                    printf("\nNuevo numero: %d \n", nuevoNumero);
                    return;
                }
                else {
                    nuevoNumero=lista[j]-corrido*0xb00001000;
                    printf("\nNumero anterior: %d \n", lista[j]);
                    printf("\nNuevo numero: %d \n", nuevoNumero);
                    return;
                }
                

            }

    }
    //////////////////////////////////////////////////// 
    
   
    fclose(file);
    free(lista);
    
}*/




void imprimirBinario(int num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" ");  // Separar por byte para mejor lectura
    }
}

void buscoNumero() {
    FILE* file = fopen("lista.bin", "rb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    // Leer todos los números del archivo
    int* lista = malloc(sizeof(int));
    if (lista == NULL) {
        perror("Error de asignación de memoria");
        fclose(file);
        return;
    }

    int i = 0;
    while (fread(&lista[i], sizeof(int), 1, file) == 1) {
        i++;
        int* temp = realloc(lista, (i + 1) * sizeof(int));
        if (temp == NULL) {
            perror("Error de realloc");
            free(lista);
            fclose(file);
            return;
        }
        lista = temp;
    }
    fclose(file);

    int encontrado = 0;
    int suma = 0;
    int promedio = 0;
    int numeroOriginal = 0;
    int numeroModificado = 0;

    // Buscar el primer número que cumpla la condición
    for (int j = 10; j < i; j++) {
        suma = 0;
        for (int k = 0; k < j; k++) {
            suma += lista[k];
        }

        if (suma % j == 0) {
            promedio = suma / j;
            numeroOriginal = lista[j];

            // Mostrar número original
            printf("Número original: %d\nBinario: ", numeroOriginal);
            imprimirBinario(numeroOriginal);
            printf("\n");

            // Modificar el 4to bit para que sea igual al 5to
            int bit5 = (numeroOriginal >> 4) & 1;

            if (bit5 == 1)
                numeroModificado = numeroOriginal | (1 << 3); // poner bit 4 en 1
            else
                numeroModificado = numeroOriginal & ~(1 << 3); // poner bit 4 en 0

            // Mostrar número modificado
            printf("Número modificado: %d\nBinario: ", numeroModificado);
            imprimirBinario(numeroModificado);
            printf("\n");

            // Contar repeticiones del número original en la lista
            int repeticiones = 0;
            for (int m = 0; m < i; m++) {
                if (lista[m] == numeroOriginal)
                    repeticiones++;
            }
            printf("El número %d se repite %d veces en la lista.\n", numeroOriginal, repeticiones);

            encontrado = 1;
            break; // solo el primero
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún número que cumpla la condición.\n");
    }

    free(lista);
}
