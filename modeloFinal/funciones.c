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

int buscoNumero(){
    FILE* file;
    int i = 0,j=0,sumaAnterior=0,numero=0,promedioEntero=0;
    float promedio=0;
    

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
            promedio=(float)sumaAnterior/j;
            promedioEntero=1;
            if(j>9&&){


            }

    }
    return numero;
    //////////////////////////////////////////////////// 
    
   
    fclose(file);
    free(lista);
    
}
