#include <stdio.h>
#include <string.h>

int main() {
    FILE *archivo;
    char texto[200], palabra[50];
    int cant = 0;

    // Abrir el archivo en modo lectura
    archivo = fopen("Texto.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leer la palabra a buscar
    printf("Ingrese la palabra a buscar: ");
    scanf("%s", palabra);

    // Leer línea por línea
    while (fgets(texto, sizeof(texto), archivo) != NULL) {
        // Usamos un puntero para recorrer la línea
        char *pos = texto;

        // Buscar todas las ocurrencias de la palabra en la línea
        while ((pos = strstr(pos, palabra)) != NULL) {
            cant++;  // Incrementar el contador por cada ocurrencia
            pos++;    // Mover el puntero hacia adelante para seguir buscando
        }
    }

    fclose(archivo);  // Cerrar el archivo

    printf("La palabra '%s' se repite %d veces en el archivo.\n", palabra, cant);

    return 0;
}