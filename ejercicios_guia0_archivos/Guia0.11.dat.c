#include <stdio.h>
#include <string.h>

int main() {
    char nombre[50]; 
    FILE *archivo;
    archivo=fopen("nombres.dat", "wb"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return 1;
    }
    printf("Ingrese nombres (escriba 'Fin' para terminar):\n");
    while (1) { // Bucle infinito hasta que se ingrese "Fin"
        fgets(nombre, sizeof(nombre), stdin);
        nombre[strcspn(nombre, "\n")] = '\0';
        if (strcmp(nombre, "fin") == 0) // Si el usuario ingresa "Fin", salimos del bucle
            break;
        fwrite(nombre, sizeof(char), sizeof(nombre), archivo); // Escribimos el nombre en el archivo binario   
    }
    fclose(archivo); 

    printf("\nNombres guardados en nombres.dat\n");
    archivo = fopen("nombres.dat", "rb"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return 1;
    }
    printf("\nNombres almacenados:\n");
    while (fread(nombre, sizeof(char), sizeof(nombre), archivo) == sizeof(nombre)) { 
        printf("%s\n", nombre); 
    }

    fclose(archivo); 
    return 0;
}
