#ifndef header
#define header

#include <stdint.h>

typedef enum {
    Expirado = 0,
    Inactivo,
    Activo,
} estado_t;

typedef enum {
    NoDocente = 0,
    Alumno,
    Admin,
    Docente,
} tipo_usuario_t;

typedef struct {
    char Name[50];
    char Password[50];
    unsigned int DNI;
    uint8_t TipoStatus; // tipo - status 
} usuario_t;

/*

typedef enum{
    administrador=1,
    docente,
    no_docente,
    alumno
  }tipo_usuario_t;
  
typedef enum{
    activo=1,
    inactivo,
    expirado
  }estado_t;
  
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
int VerEstudiantes();
int CambiarTipoUsuario();
int VerNoDocentes();

#endif