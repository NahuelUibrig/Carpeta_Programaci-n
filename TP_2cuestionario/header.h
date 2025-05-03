#ifndef header
#define header
#include<stdlib.h>
#include <stdint.h>

typedef enum {
  no_docente = 0,
  alumno,
  administrador,
  docente,
} tipo_usuario_t;
/*
typedef enum{
    administrador=1,
    docente,
    no_docente,
    alumno
  }tipo_usuario_t;
 */
  
  typedef enum {
    expirado = 0,
    inactivo,
    activo,
} estado_t;
/*
typedef enum{
    activo=1,
    inactivo,
    expirado
  }estado_t;
  */
 typedef struct {
  char nombre[50];
  char clave[50];
  unsigned int DNI;
  uint8_t tipo_usuario_estado; // tipo - status 
} usuario_t;

 /*
  typedef struct{
    unsigned char tipo_usuario_estado;
    char nombre[20];
    char clave[20];
  }usuario_t;
  */
  
typedef enum {
    fallo = 0,
    funciono = 1
  } funcion_t;


int CrearUsuario();
int IniciarSesion(usuario_t *usuario_logeado);
int CambiarNombreClave(usuario_t *usuario);
int VerNoDocentesExpirados();
int CambiarTipoUsuario();

#endif