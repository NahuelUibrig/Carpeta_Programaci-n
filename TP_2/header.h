#ifndef header
#define header

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

typedef enum {
    fallo = 0,
    funciono = 1
  } funcion_t;


int CrearUsuario();
int IniciarSesion(usuario_t *usuario_logeado);
int CambiarNombreClave(usuario_t *usuario);
int VerEstudiantes();
int CambiarTipoUsuario();

#endif