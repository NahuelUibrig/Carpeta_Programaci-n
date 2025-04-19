#include <stdio.h>
#include <string.h>
#include "header.h"


int main(){
    int opcion=-1,subopcion=-1;
    usuario_t usuario;
    status_t estado;
    tipo_usuario_t tipo_usuario;
    
    while(1){

        printf("=== Menú Principal ===\n\n");
        printf("0) Salir\n");
        printf("1) Crear Usuario\n");
        printf("2) Iniciar Sesion\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpiar \n
        switch (opcion){
            case 0:
                printf("Saliendo del programa...\n");
                return 0; // Termina todo
            case 1:
            CrearUsuario();
            break;
            case 2:  
            if (IniciarSesion(&usuario)==funciono) {
        
                tipo_usuario = usuario.tipo_usuario_status >> 4;
                printf("\nSesión iniciada como ");
                switch (tipo_usuario) {
                    case administrador: printf("Administrador\n"); break;
                    case docente: printf("Docente\n"); break;
                    case no_docente: printf("No Docente\n"); break;
                    case alumno: printf("Alumno\n"); break;
                    default: printf("Desconocido\n"); break;
                }
                subopcion = -1
                while (subopcion != 0) {
                printf("=== Menú Principal (");
                switch (tipo_usuario) {
                    case administrador: printf("Administrador"); 
                    break;
                    case docente: printf("Docente"); 
                    break;
                    case no_docente: printf("No Docente"); 
                    break;
                    case alumno printf("Alumno"); 
                    break;
                    default: printf("Desconocido"); 
                    break;
                }
                printf(") ===\n");

                printf("1. Crear Usuario\n");
                printf("2. Cambiar Nombre/Contraseña\n");
                if (tipo_usuario == administrador || tipo_usuario == docente) 
                    printf("3. Ver estudiantes\n");
            
                if (tipo_usuario == administrador) 
                    printf("4. Cambiar Status y Tipo de usuario\n");
                printf("0) Cerrar sesión\n");
                printf("Ingrese opción: ");
                scanf("%d", &subopcion);
                getchar(); // limpiar \n

                switch (subopcion) {
                    case 1:
                        CrearUsuario();
                        break;
                    case 2:
                        CambiarNombreClave(&usuario);
                        break;
                    case 3:
                        if (tipo_usuario == administrador || tipo_usuario == docente)
                            VerEstudiantes();
                        else
                            printf("No tiene permisos para esta opción.\n");
                        break;
                    case 4:
                        if (tipo_usuario == administrador)
                            CambiarNombreTipoUsuario();
                        else
                            printf("Solo el administrador puede hacer esto.\n");
                        break;
                    case 0:
                        printf("Sesión cerrada.\n");
                        break;
                    default:
                        printf("Opción no válida.\n");
                }

                }
            } 
            break;
            default:
            break;
        }
    }
    return 0;
}


