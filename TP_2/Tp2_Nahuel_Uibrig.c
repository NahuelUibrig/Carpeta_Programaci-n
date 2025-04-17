#include <stdio.h>
#include <string.h>
#include "header.h"

tipo_usuario_t tipo_usuario;

int main(){
    int opciones=0;
    
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
        IniciarSesion();
        if(tipo_usuario=0){
            printf("Secion iniciada como Administrador\n\n");
            printf("=== Menú Principal (admin) ===\n\n");

            
        }
        break;
    }

    
    return 0;
}