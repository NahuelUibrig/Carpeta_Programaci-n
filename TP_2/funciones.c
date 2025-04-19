#include <stdio.h>
#include <string.h>
#include "header.h"



int CrearUsuario(){
    usuario_t usuario;
    status_t estado;
    tipo_usuario_t tipo_usuario;
    FILE *archivo;
    int tipo_temp,estado_temp;
    archivo=fopen("credenciales.bin", "ab"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return fallo;
    }
    printf("Se creara un nuevo usuario, por favor introduzca la informacion necesaria\n\n");

    /////////////////////////////NOMBRE DE USUARIO/////////////////////////////
    printf("Nombre de usuario:\n");
    fgets(usuario.nombre, sizeof(usuario.nombre), stdin);
    usuario.nombre[strcspn(usuario.nombre, "\n")] = 0; // Eliminar '\n'
    if (usuario.nombre[0] == '\0') {
        printf("El nombre no puede estar vacío.\n");
        fclose(archivo);
        return fallo;
    }
    printf("\n");
    /////////////////////////////CLAVE DE USUARIO/////////////////////////////
    printf("Clave de usuario:\n");
    fgets(usuario.clave, sizeof(usuario.clave), stdin);
    usuario.clave[strcspn(usuario.clave, "\n")] = 0; // Eliminar '\n'
    if (usuario.clave[0] == '\0') {
        printf("La clave no puede estar vacía.\n");
        fclose(archivo);
        return fallo;
    }
    printf("\n");
    /////////////////////////////TIPO DE USUARIO/////////////////////////////
    printf("Tipo de usuario (0=Administrador, 1=Docente, 2=No Docente, 3=Alumno):\n> ");
    scanf("%d", &tipo_temp);
    getchar(); // limpiar \n
    if (tipo_temp < 0 || tipo_temp > 3) {
        printf("Tipo inválido\n");
        fclose(archivo);
        return fallo;
    }
    tipo_usuario = (tipo_usuario_t)tipo_temp;
    printf("\n\n");
    /////////////////////////////ESTADO DE USUARIO/////////////////////////////
    printf("Estado (0=Activo, 1=Inactivo, 2=Expirado):\n> ");
    scanf("%d", &estado_temp);
    getchar(); // limpiar \n
    if (estado_temp < 0 || estado_temp > 2) {
        printf("Estado inválido\n\n");
        fclose(archivo);
        return fallo;
    }
    estado = (status_t)estado_temp;
    usuario.tipo_usuario_status = (tipo_usuario << 4) | estado;


    fwrite(&usuario, sizeof(usuario_t),1, archivo);
    fclose(archivo); 
    printf("\nNuevo usuario creado y guardado en credenciales.bin\n");
   
    return funciono;
}


int IniciarSesion(usuario_t *usuario_logeado){
    usuario_t usuario;
    status_t estado;
    char nombre_ingresado[20];
    char clave_ingresada[20];
    FILE *archivo;
    int tipo_temp,estado_temp;
    archivo=fopen("credenciales.bin", "rb"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return fallo;
    }
    printf("Ingrese nombre de usuario: ");
    fgets(nombre_ingresado, sizeof(nombre_ingresado), stdin);
    nombre_ingresado[strcspn(nombre_ingresado, "\n")] = 0; // Eliminar '\n'
    printf("\n");
    printf("Ingrese clave: ");
    fgets(clave_ingresada, sizeof(clave_ingresada), stdin);
    clave_ingresada[strcspn(clave_ingresada, "\n")] = 0; // Eliminar '\n'
    
    while (fread(&usuario, sizeof(usuario_t), 1, archivo)) {
        if (strcmp(usuario.nombre, nombre_ingresado) == 0 && strcmp(usuario.clave, clave_ingresada) == 0) {
            estado=usuario.tipo_usuario_status & 0x0F;
            if (estado == activo) {
                *usuario_logeado = usuario;
                fclose(archivo);
                printf("El usuario se encuentra activo\n");
                return funciono;
            }
            else {
                fclose(archivo);
                if (estado == inactivo)
                    printf("El usuario está inactivo.\n");
                else if (estado == expirado)
                    printf("El usuario está expirado.\n");
                else
                    printf("El usuario tiene un estado desconocido.\n");

                return fallo;
            }
        } 
    }
        printf("Nombre o clave incorrectos\n");
        return fallo;
}

int CambiarNombreClave(usuario_t *usuario_logeado){
    usuario_t usuario;
    char nombre_cambio[20];
    char clave_cambio[20];
    char clave_ingresada[20];
    int opcion = 0, intento = 0;
    FILE *archivo;

    printf("¿Qué dato desea cambiar?\n1) Nombre\n2) Clave\n> ");
    scanf("%d", &opcion);
    getchar(); // limpiar \n

    if (opcion != 1 && opcion != 2) {
        printf("Opción inválida.\n");
        return fallo;
    }

    if (opcion == 1) {
        printf("Ingrese el nuevo nombre: ");
        fgets(nombre_cambio, sizeof(nombre_cambio), stdin);
        nombre_cambio[strcspn(nombre_cambio, "\n")] = 0; // Eliminar '\n'
        if (strlen(nombre_cambio) == 0) {
            printf("El nombre no puede estar vacio.\n");
            return fallo;
        }
    } else {
        printf("Ingrese la nueva clave: ");
        fgets(clave_cambio, sizeof(clave_cambio), stdin);
        clave_cambio[strcspn(clave_cambio, "\n")] = 0; // Eliminar '\n'
        if (strlen(clave_cambio) == 0) {
            printf("La clave no puede estar vacia.\n");
            return fallo;
        }
    }

    // Verificar clave actual
    while (intento < 3) {
        printf("Ingrese su clave actual para confirmar: ");
        fgets(clave_ingresada, sizeof(clave_ingresada), stdin);
        clave_ingresada[strcspn(clave_ingresada, "\n")] = 0; // Eliminar '\n'

        if (strcmp((*usuario_logeado).clave, clave_ingresada) == 0) {
            printf("Clave correcta.\n");

            archivo = fopen("credenciales.bin", "rb+");
            if (archivo == NULL) {
                perror("Error al abrir el archivo");
                return fallo;
            }

            while (fread(&usuario, sizeof(usuario_t), 1, archivo)) {
                if (strcmp(usuario.nombre, (*usuario_logeado).nombre) == 0 &&
                    strcmp(usuario.clave, (*usuario_logeado).clave) == 0) {

                    if (opcion == 1) {
                        strcpy(usuario.nombre, nombre_cambio);
                        strcpy((*usuario_logeado).nombre, nombre_cambio);
                        
                    } else {
                        strcpy(usuario.clave, clave_cambio);
                        strcpy((*usuario_logeado).clave, clave_cambio);
                        
                    }

                    // Volver atrás un struct y sobrescribir
                    fseek(archivo, -sizeof(usuario_t), SEEK_CUR);
                    fwrite(&usuario, sizeof(usuario_t), 1, archivo);
                    fclose(archivo);

                    printf("Dato actualizado correctamente.\n");
                    return funciono;
                }
            }

            fclose(archivo);
            printf("No se encontro el usuario en el archivo.\n");
            return fallo;
        } else {
            printf("Clave incorrecta, Intento %d/3\n", intento + 1);
            intento++;
        }
    }

    printf("Demasiados intentos fallidos.\n");
    return fallo;
}
/*

int VerEstudiantes(){

}
int CambiarNombreTipoUsuario(){

}

*/

