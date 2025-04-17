#include <stdio.h>
#include <string.h>
#include "header.h"

usuario_t usuario;

int CrearUsuario(){
    FILE *archivo;
    archivo=fopen("credenciales.bin", "wb"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return 1;
    }
    printf("Se creara un nuevo usuario, por favor introduzca la informacion necesaria\n\n");
    printf("Nombre de usuario:\n\n");
    fgets(usuario.nombre, sizeof(usuario.nombre), stdin);
    fwrite(usuario.nombre, sizeof(char), sizeof(usuario.nombre), archivo);
    printf("\n\n");
    printf("Clave de usuario:\n\n");
    fgets(usuario.clave, sizeof(usuario.clave), stdin);
    fwrite(usuario.clave, sizeof(char), sizeof(usuario.clave), archivo);
    printf("\n\n");
    printf("Tipo de usuario:\n\n");
    fgets(usuario.clave, sizeof(usuario.clave), stdin);
    fwrite(usuario.clave, sizeof(char), sizeof(usuario.clave), archivo);

    fclose(archivo); 
    printf("\nNuevo usuario creado y guardado en credenciales.bin\n");
   
    return 0;
}

/*
int IniciarSession(){

}
int CambiarNombreClave(){

}
int VerEstudiantes(){

}
int CambiarNombreTipoUsuario(){

}

*/

