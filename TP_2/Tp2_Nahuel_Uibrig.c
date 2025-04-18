#include <stdio.h>
#include <string.h>
#include "header.h"


int main(){
    int opciones=0;
    usuario_t usuario;
    status_t estado;
    tipo_usuario_t tipo_usuario;
    
    printf("=== Menú Principal ===\n\n");
    printf("1) Crear Usuario\n");
    printf("2) Iniciar Sesion\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opciones);
    switch (opciones){
        case 1:
        CrearUsuario();
        break;
        case 2:  
        if (IniciarSesion(&usuario)==funciono) {
        
        tipo_usuario = usuario.tipo_usuario_status >> 4;
        if (tipo_usuario == administrador) {
            printf("Sesión iniciada como Administrador\n\n");

        } else if (tipo_usuario == docente) {
            printf("Sesión iniciada como Docente\n\n");
        } else if (tipo_usuario == alumno) {
            printf("Sesión iniciada como Alumno\n\n");
        } else {
            printf("Sesión iniciada como Usuario no docente\n\n");
        }
        } 
        break;
        default:
        break;
    }

    printf("=== Menú Principal ===\n\n");
    printf("1) Crear Usuario\n");
    printf("2) Iniciar Sesion\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opciones);


    // Menú dependiendo del tipo de usuario
    printf("=== Menú Principal (%s) ===\n", usuario_t(usuario.tipo));
    printf("1. Crear Usuario\n");
    printf("2. Cambiar Nombre/Contraseña\n");
    if (usuario.tipo == administrador || currentUser.tipo == docente) {
     printf("3. Ver estudiantes\n");
    }
    if (currentUser.tipo == administrador) {
     printf("4. Cambiar Status y Tipo de usuario\n");
    }
    printf("0. Cerrar Sesión\n");
    printf("Ingrese opción: ");
     scanf("%d", &opciones);
    getchar(); // limpiar el buffer






    switch (opciones){
        case 1:
        CrearUsuario();
        break; 
        case 2:
        break; 
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;   
        default:
        break;
     }

    
    return 0;
}