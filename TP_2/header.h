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
    char nombre[10];
    char clave[10];
  }usuario_t;


int CrearUsuario();
int IniciarSesion();
int CambiarNombreClave();
int VerEstudiantes();
int CambiarNombreTipoUsuario();

#endif