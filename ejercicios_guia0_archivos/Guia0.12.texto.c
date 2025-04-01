#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *archivo;
    char texto[200];
    int linea=0;
    archivo = fopen("Texto.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    while (fgets(texto, sizeof(texto), archivo) != NULL) {
        linea++;
    }
    fclose(archivo); // Cerrar archivo
    printf("El archivo tiene %d líneas.\n", linea);
    return 0;
}