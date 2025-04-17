#include <stdio.h>
#include <string.h>
#include "header.h"

usuario_t usuario;
status_t estado;
tipo_usuario_t tipo_usuario;

int CrearUsuario(){
    FILE *archivo;
    int tipo_temp,estado_temp;
    archivo=fopen("credenciales.bin", "ab"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return 1;
    }
    printf("Se creara un nuevo usuario, por favor introduzca la informacion necesaria\n\n");

    /////////////////////////////NOMBRE DE USUARIO/////////////////////////////
    printf("Nombre de usuario:\n");
    fgets(usuario.nombre, sizeof(usuario.nombre), stdin);
    usuario.nombre[strcspn(usuario.nombre, "\n")] = 0; // Eliminar '\n'
    if (usuario.nombre[0] == '\0') {
        printf("El nombre no puede estar vacío.\n");
        fclose(archivo);
        return 1;
    }
    printf("\n\n");
    /////////////////////////////CLAVE DE USUARIO/////////////////////////////
    printf("Clave de usuario:\n");
    fgets(usuario.clave, sizeof(usuario.clave), stdin);
    usuario.clave[strcspn(usuario.clave, "\n")] = 0; // Eliminar '\n'
    if (usuario.clave[0] == '\0') {
        printf("La clave no puede estar vacía.\n");
        fclose(archivo);
        return 1;
    }
    printf("\n\n");
    /////////////////////////////TIPO DE USUARIO/////////////////////////////
    printf("Tipo de usuario (0=Administrador, 1=Docente, 2=No Docente, 3=Alumno):\n> ");
    scanf("%d", &tipo_temp);
    if (tipo_temp < 0 || tipo_temp > 3) {
        printf("Tipo inválido\n");
        fclose(archivo);
        return 1;
    }
    tipo_usuario = (tipo_usuario_t)tipo_temp;
    printf("\n\n");
    /////////////////////////////ESTADO DE USUARIO/////////////////////////////
    printf("Estado (0=Activo, 1=Inactivo, 2=Expirado):\n> ");
    scanf("%d", &estado_temp);
    if (estado_temp < 0 || estado_temp > 2) {
        printf("Estado inválido\n\n");
        fclose(archivo);
        return 1;
    }
    estado = (status_t)estado_temp;
    usuario.tipo_usuario_status = (tipo_usuario << 4) | estado;
    while (getchar() != '\n'); // Limpia el buffer de entrada


    fwrite(&usuario, sizeof(usuario_t),1, archivo);
    fclose(archivo); 
    printf("\nNuevo usuario creado y guardado en credenciales.bin\n");
   
    return 0;
}


int IniciarSesion(){

}
/*
int CambiarNombreClave(){

}
int VerEstudiantes(){

}
int CambiarNombreTipoUsuario(){

}

*/

