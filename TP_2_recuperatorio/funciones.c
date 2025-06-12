#include <stdio.h>
#include <string.h>
#include "header.h"

/*

int CrearUsuario(){
    usuario_t usuario;
    estado_t estado;
    tipo_usuario_t tipo_usuario;
    char nombre_ingresado[20];
    FILE *archivo;
    int tipo_temp,estado_temp;
    archivo=fopen("credenciales.bin", "ab+"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return fallo;
    }
    printf("Se creara un nuevo usuario, por favor introduzca la informacion necesaria\n\n");

    /////////////////////////////NOMBRE DE USUARIO/////////////////////////////
    printf("Nombre de usuario: ");
    fgets(nombre_ingresado, sizeof(nombre_ingresado), stdin);
    nombre_ingresado[strcspn(nombre_ingresado, "\n")] = 0; // Eliminar '\n'
    if (nombre_ingresado[0] == '\0') {
        printf("El nombre no puede estar vacío.\n");
        fclose(archivo);
        return fallo;
    }
    while (fread(&usuario, sizeof(usuario_t), 1, archivo)) {
        if(strcmp(usuario.nombre, nombre_ingresado) == 0){
            printf("El nombre de ya se encuentra utilizado, proba otro.\n");
            fclose(archivo);
            return fallo;
            
        }
    }
    strcpy(usuario.nombre, nombre_ingresado);
    printf("\n");
    /////////////////////////////CLAVE DE USUARIO/////////////////////////////
    printf("Clave de usuario: ");
    fgets(usuario.clave, sizeof(usuario.clave), stdin);
    usuario.clave[strcspn(usuario.clave, "\n")] = 0; // Eliminar '\n'
    if (usuario.clave[0] == '\0') {
        printf("La clave no puede estar vacía.\n");
        fclose(archivo);
        return fallo;
    }
    printf("\n");
    /////////////////////////////TIPO DE USUARIO/////////////////////////////
    printf("Tipo de usuario (1 = Administrador, 2 = Docente, 3 = No Docente, 4 = Alumno): ");
    scanf("%d", &tipo_temp);
    getchar(); // limpiar \n
    if (tipo_temp < administrador || tipo_temp > alumno) {
        printf("Tipo inválido\n");
        fclose(archivo);
        return fallo;
    }
    tipo_usuario = (tipo_usuario_t)tipo_temp;
    printf("\n\n");
    /////////////////////////////ESTADO DE USUARIO/////////////////////////////
    printf("Estado (1 = Activo, 2 = Inactivo, 3 = Expirado): ");
    scanf("%d", &estado_temp);
    getchar(); // limpiar \n
    if (estado_temp < activo || estado_temp > expirado) {
        printf("Estado inválido\n\n");
        fclose(archivo);
        return fallo;
    }
    estado = (estado_t)estado_temp;
    usuario.tipo_usuario_estado = (tipo_usuario << 4) | estado;
    fwrite(&usuario, sizeof(usuario_t),1, archivo);
    fclose(archivo); 
    printf("\nNuevo usuario creado y guardado en credenciales.bin\n");
   
    return funciono;
}


int IniciarSesion(usuario_t *usuario_logeado){
    usuario_t usuario;
    estado_t estado;
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
    printf("\n");
    
    while (fread(&usuario, sizeof(usuario_t), 1, archivo)) {
        if (strcmp(usuario.nombre, nombre_ingresado) == 0 && strcmp(usuario.clave, clave_ingresada) == 0) {
            estado=usuario.tipo_usuario_estado & 0b00001111;
            
            switch (estado)
            {
            case activo:
                *usuario_logeado = usuario;
                fclose(archivo);
                printf("El usuario se encuentra activo.\n\n");
                return funciono;
            
            case inactivo:
                printf("El usuario esta inactivo.\n\n");
                fclose(archivo);
                return fallo;
            
            case expirado:
                printf("El usuario esta expirado.\n\n");
                fclose(archivo);
                return fallo;
        
            default:
                printf("El usuario tiene un estado desconocido.\n\n");
                return fallo;
            } 
        } 
    }
        printf("Nombre o clave incorrectos.\n\n");
        fclose(archivo);
        return fallo;
}

int CambiarNombreClave(usuario_t *usuario_logeado){
    usuario_t usuario;
    char nombre_cambio[20];
    char clave_cambio[20];
    char clave_ingresada[20];
    int opcion,pos_usuario=-1,indice=0, intento = 0; 
    FILE *archivo;

    printf("¿Qué dato desea cambiar? (1 = Nombre, 2 = Clave) : ");
    scanf("%d", &opcion);
    getchar(); // limpiar \n
    printf("\n\n");
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

        if (strcmp(usuario_logeado->clave, clave_ingresada) == 0) {
            printf("\nClave correcta.\n\n");

            archivo = fopen("credenciales.bin", "rb+");
            if (archivo == NULL) {
                perror("Error al abrir el archivo");
                return fallo;
            }

            while (fread(&usuario, sizeof(usuario_t), 1, archivo)) {
                if(opcion ==1 && strcmp(usuario.nombre, nombre_cambio) == 0 && strcmp(usuario.nombre, usuario_logeado->nombre) != 0){
                    fclose(archivo);
                    printf("El nombre ya se encuentra utilizado, proba otro.\n\n");
                    return fallo;  
                }

                if (strcmp(usuario.nombre, usuario_logeado->nombre) == 0 &&
                    strcmp(usuario.clave, usuario_logeado->clave) == 0) {
                        pos_usuario=indice;// lo uso para guardar la posicion del usuario logeado
                    }
                    indice++;
            }
            if (pos_usuario == -1) {
                fclose(archivo);
                printf("No se encontró el usuario en el archivo.\n\n");
                return fallo;
            }
            
            fseek(archivo, pos_usuario * sizeof(usuario_t), SEEK_SET);// Voy a la posicion donde guarde el usuario logeado
            fread(&usuario, sizeof(usuario_t), 1, archivo); // leer para modificar

            if (opcion == 1) {
                strcpy(usuario.nombre, nombre_cambio);
                strcpy(usuario_logeado->nombre, nombre_cambio);
            } else {
                strcpy(usuario.clave, clave_cambio);
                strcpy(usuario_logeado->clave, clave_cambio);
            }

            // Volver atrás y escribir el struct modificado
            fseek(archivo, -sizeof(usuario_t), SEEK_CUR);
            fwrite(&usuario, sizeof(usuario_t), 1, archivo);
            fclose(archivo);

            printf("Dato actualizado correctamente.\n\n");
            return funciono;
        } else {
            printf("\nClave incorrecta, Intento %d/3\n", intento + 1);
            intento++;
        }
    }

    printf("Demasiados intentos fallidos.\n\n");
    return fallo;
}


int VerEstudiantes(){
    usuario_t usuario;
    tipo_usuario_t tipo_usuario;
    estado_t estado;
    FILE *archivo;
    int estudiantes_existen=0;
    archivo=fopen("credenciales_RC2.bin", "rb"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return fallo;
    }
    printf("\n\n==================estudiantes====================\n\n"); 
    while (fread(&usuario, sizeof(usuario_t), 1, archivo)) {
        tipo_usuario = usuario.tipo_usuario_estado >> 4;
        estado = usuario.tipo_usuario_estado & 0b00001111;
        if(tipo_usuario==alumno){
            printf("nombre: %s\n",usuario.nombre); 
            switch(estado){
            case activo:
                printf("Estado: Activo\n");
                break;
            case inactivo:
                printf("Estado: Inactivo\n");
                break;
            case expirado:
                printf("Estado: Expirado\n");
                break;
            default:
                break;
            }
            estudiantes_existen++;
        
        }
    }
    if(estudiantes_existen!=0){
        printf("Se encontraron %d estudiantes\n\n",estudiantes_existen);
        return funciono;
    }
    else{
        printf("No se encontraron estudiantes en el archivo\n\n");
        return fallo;
    }
        
}

int CambiarTipoUsuario(){
    usuario_t usuario;
    estado_t estado;
    tipo_usuario_t tipo_usuario;
    char nombre_ingresado[20];
    int nuevo_estado=0, nuevo_tipo=0;
    FILE *archivo;

    printf("Ingrese el nombre de usuario\n");
    fgets(nombre_ingresado, sizeof(nombre_ingresado), stdin);
    nombre_ingresado[strcspn(nombre_ingresado, "\n")] = 0; // Eliminar '\n'
    printf("Ingrese el nuevo estado de usuario (1 = Activo, 2 = Inactivo, 3 = Expirado) : ");
    scanf("%d", &nuevo_estado);
    printf("\n\n");
    if (nuevo_estado < activo || nuevo_estado > expirado) {
        printf("Estado inválido\n");
        return fallo;
    }
    printf("Ingrese el nuevo tipo de usuario ");
    printf("(1 = Administrador, 2 = Docente, 3 = No docente, 4 = Alumno) : ");
    scanf("%d", &nuevo_tipo);
    printf("\n\n");
    if (nuevo_tipo < administrador || nuevo_tipo > alumno) {
        printf("Tipo inválido\n");
        return fallo;
    }
    getchar(); // limpiar \n
    archivo = fopen("credenciales.bin", "rb+");
            if (archivo == NULL) {
                perror("Error al abrir el archivo");
                return fallo;
            }
    while (fread(&usuario, sizeof(usuario_t), 1, archivo)) {
        if (strcmp(usuario.nombre, nombre_ingresado) == 0) {
            usuario.tipo_usuario_estado = (nuevo_tipo << 4) | nuevo_estado;
            fseek(archivo, -sizeof(usuario_t), SEEK_CUR);
            fwrite(&usuario, sizeof(usuario_t), 1, archivo);
            fclose(archivo);
            printf("Estado y tipo de usuario actualizados correctamente.\n");
            return funciono;
        }
    }
    printf("No se encontro el nombre de usuario en el archivo.\n");
    fclose(archivo);
    return fallo;

}
*/
int VerEstudiantes(){
    Usuario_t usuario;
    UserType_t tipo_usuario;
    UserStatus_t estado;
    FILE *archivo;
    int alumnosNoActivos=0;
    long long suma=0;
    unsigned int promedio=0,diferenciaMayor=0,diferencia=0,dniCercano;
    char nombreCercano[50];
    archivo=fopen("credenciales_RC2.bin", "rb"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return fallo;
    }
    printf("\n\n==================estudiantes====================\n\n"); 
    while (fread(&usuario, sizeof(Usuario_t), 1, archivo)) {
        tipo_usuario = usuario.tipoStatus >> 4;
        estado = usuario.tipoStatus & 0b00001111;
        if(tipo_usuario==Alumno){
            printf("nombre: %s\n",usuario.name); 
            switch(estado){
            case Activo:
                printf("Estado: Activo\n\n");
                alumnosNoActivos++;
                suma=suma+usuario.dni;
                break;
            case Inactivo:
                printf("Estado: Inactivo\n");
                break;
            case Expirado:
                printf("Estado: Expirado\n");
                
                break;
            default:
                break;
            }
            
        
        }
    }
    promedio=suma/alumnosNoActivos;
    
    fclose(archivo);
    archivo=fopen("credenciales_RC2.bin", "rb"); 
    if (archivo == NULL) { 
        perror("Error al abrir el archivo");
        return fallo;
    }
    while(fread(&usuario, sizeof(Usuario_t), 1, archivo)){
        tipo_usuario = usuario.tipoStatus >> 4;
        estado = usuario.tipoStatus & 0b00001111;
        if(tipo_usuario==Alumno&&estado==Activo){  
             
            if(usuario.dni<promedio){
                diferencia=promedio-usuario.dni;  
                      
            }
            else{
                diferencia=usuario.dni-promedio;
                
            }
            if(diferenciaMayor<diferencia){
                diferenciaMayor=diferencia;
                strcpy(nombreCercano,usuario.name);
                dniCercano=usuario.dni;
            }
            
        }
        
    }
    
    if(alumnosNoActivos!=0){
        printf("Se encontraron %d alumnos con estado activo\n\n",alumnosNoActivos);
        
        printf("El promedio de DNI de los alumnos activos es de: %d\n\n",promedio);
        printf("%s, DNI: %d\n\n", nombreCercano, dniCercano);
        return funciono;
    }
    else{
        printf("No se encontraron estudiantes en el archivo\n\n");
        return fallo;
    }
        
}



int modify_integers(int a, int *b, int **c){
int array[4]={1,2,3,4};
int* ptr=array+2;
printf("valor que apunta%d \n\n",*ptr);
a=5;
b=10;
c=15;
}