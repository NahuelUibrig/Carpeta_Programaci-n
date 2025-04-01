#include <stdio.h>
#include <string.h>

int main() {
    char nombre[50]; 
    FILE *archivo;
    archivo = fopen("nombres.bin", "rb"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return 1;
    }
    printf("\nNombres almacenados:\n");
    while (fread(nombre, sizeof(char), sizeof(nombre), archivo) == sizeof(nombre)) { 
        printf("%s\n", nombre); 
    }

    fclose(archivo); 
}