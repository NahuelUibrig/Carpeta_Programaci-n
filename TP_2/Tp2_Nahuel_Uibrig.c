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
        case 2:  // Iniciar sesión
        if (IniciarSesion(&usuario)) {
        // Ahora que el usuario inició sesión correctamente,
        // usamos sus datos para saber qué menú mostrar

        tipo_usuario = usuario.tipo_usuario_status >> 4;  // Obtenemos los primeros 4 bits
        if (tipo_usuario == administrador) {
            printf("Sesión iniciada como Administrador\n\n");
            // Mostrar menú para administrador
        } else if (tipo_usuario == docente) {
            printf("Sesión iniciada como Docente\n\n");
            // Mostrar menú para docente
        } else if (tipo_usuario == alumno) {
            printf("Sesión iniciada como Alumno\n\n");
            // Menú alumno
        } else {
            printf("Sesión iniciada como Usuario no docente\n\n");
            // Menú no docente
        }
        } else {
        // IniciarSesion devolvió fallo
        printf("No se pudo iniciar sesión. Verifique sus credenciales o estado.\n");
        }
        break;
    }

    
    return 0;
}