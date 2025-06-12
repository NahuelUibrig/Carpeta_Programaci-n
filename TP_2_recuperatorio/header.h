#ifndef header
#define header


#include <stdint.h>

typedef enum {
    Expirado = 0,
    Inactivo,
    Activo,
} UserStatus_t;

typedef enum {
    NoDocente = 0,
    Alumno,
    Admin,
    Docente,
} UserType_t;

typedef struct {
    char name[50];
    unsigned short antiguedad;
    char PassWord[50];
    unsigned int dni;
    uint8_t tipoStatus; // tipo - status 
} Usuario_t;






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
int IniciarSesion(Usuario_t *usuario_logeado);
int CambiarNombreClave(Usuario_t *usuario);
int VerEstudiantes();
int CambiarTipoUsuario();
int modify_integers(int a, int *b, int **c);

#endif