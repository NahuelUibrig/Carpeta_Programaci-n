#include <stdio.h>
#include <string.h>
#include "header.h"

usuario_t usuario;
status_t estado;
tipo_usuario_t tipo_usuario;

int CrearUsuario(){
    FILE *archivo;
    archivo=fopen("credenciales.bin", "ab"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return 1;
    }
    printf("Se creara un nuevo usuario, por favor introduzca la informacion necesaria\n\n");
    printf("Nombre de usuario:\n\n");
    fgets(usuario.nombre, sizeof(usuario.nombre), stdin);
    usuario.nombre[strcspn(usuario.nombre, "\n")] = 0; // Eliminar '\n'
    if (usuario.nombre[0] == '\0') {
        printf("El nombre no puede estar vacío.\n");
        fclose(archivo);
        return 1;
    }
    printf("\n\n");
    printf("Clave de usuario:\n\n");
    fgets(usuario.clave, sizeof(usuario.clave), stdin);
    usuario.clave[strcspn(usuario.clave, "\n")] = 0; // Eliminar '\n'
    if (usuario.clave[0] == '\0') {
        printf("La clave no puede estar vacía.\n");
        fclose(archivo);
        return 1;
    }
    printf("\n\n");
    printf("Tipo de usuario (0=Administrador, 1=Docente, 2=No Docente, 3=Alumno):\n\n> ");
    scanf("%hhu", &tipo_usuario);
    if (tipo_usuario > 15) {
        printf("Tipo inválido\n");
        fclose(archivo);
        return 1;
    }
    
    printf("\n\n");
    printf("Estado (0=Activo, 1=Inactivo, 2=Expirado):\n> ");
    scanf("%d", &estado);
    if (estado > 15) {
        printf("Estado inválido\n\n");
        fclose(archivo);
        return 1;
    }
    usuario.tipo_usuario_status = (tipo_usuario << 4) | estado;
    while (getchar() != '\n'); // Limpia el buffer de entrada


    fwrite(&usuario, sizeof(usuario_t),1, archivo);
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

