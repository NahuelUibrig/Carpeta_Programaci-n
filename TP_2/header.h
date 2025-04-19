#ifndef header
#define header

typedef enum{
    administrador=0,
    docente,
    no_docente,
    alumno
  }tipo_usuario_t;
  
typedef enum{
    activo=0,
    inactivo,
    expirado
  }status_t;
  
  typedef struct{
    unsigned char tipo_usuario_status;
    char nombre[20];
    char clave[20];
  }usuario_t;

typedef enum {
    fallo = 0,
    funciono = 1
  } funcion_t;


int CrearUsuario();
int IniciarSesion(usuario_t *usuario_logeado);
int CambiarNombreClave(usuario_t *usuario);
int VerEstudiantes();
int CambiarNombreTipoUsuario();

#endif