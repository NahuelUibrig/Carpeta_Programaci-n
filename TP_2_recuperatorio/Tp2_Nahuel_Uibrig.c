#include <stdio.h>
#include <string.h>
#include "header.h"


int main(){
    int a=2,b=2,c=3;
    Usuario_t usuario;
    UserStatus_t estado;
    UserType_t tipo_usuario;
    
    VerEstudiantes();
    printf("antes de modificar %d %d %d \n\n",a,b,c);
    modify_integers(a,b,c);
    printf("despues de modificar %d %d %d \n\n",a,b,c);
    /*
    while(1){

        printf("======= Menú Principal ======\n\n");
        printf("0) Salir\n");
        printf("1) Crear Usuario\n");
        printf("2) Iniciar Sesion\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpiar \n
        printf("\n");
        switch (opcion){       
            case 0:
                printf("Saliendo del programa...\n\n");
                return 0; 
            case 1:
                CrearUsuario();
            break;
            case 2:  
                if (IniciarSesion(&usuario)==funciono) {
                    tipo_usuario = usuario.tipo_usuario_estado >> 4;
                    printf("Sesión iniciada como ");
                    switch (tipo_usuario) {
                        case administrador: printf("Administrador\n"); break;
                        case docente: printf("Docente\n"); break;
                        case no_docente: printf("No Docente\n"); break;
                        case alumno: printf("Alumno\n"); break;
                        default: printf("Desconocido\n"); break;
                    }
                    subopcion = -1;
                    while (subopcion != 0) {
                    printf("\n===== Menú Principal (");
                    switch (tipo_usuario) {
                        case administrador: printf("Administrador"); 
                        break;
                        case docente: printf("Docente"); 
                        break;
                        case no_docente: printf("No Docente"); 
                        break;
                        case alumno: printf("Alumno"); 
                        break;
                        default: printf("Desconocido"); 
                        break;
                    }
                    printf(") =====\n");
                    printf("0) Cerrar sesion\n");
                    printf("1) Crear Usuario\n");
                    printf("2) Cambiar Nombre o Clave\n");
                    if (tipo_usuario == administrador || tipo_usuario == docente) 
                        printf("3) Ver estudiantes\n");
                    if (tipo_usuario == administrador) 
                    printf("4) Cambiar Estado y Tipo de usuario\n\n");
                    printf("Ingrese opción: ");
                    scanf("%d", &subopcion);
                    printf("\n\n");
                    getchar(); // limpiar \n

                    switch (subopcion) {
                        case 0:
                            printf("Sesion cerrada.\n");
                            subopcion=0;
                            break;
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
                                CambiarTipoUsuario();
                            else
                                printf("Solo el administrador puede hacer esto.\n");
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
    */
}


