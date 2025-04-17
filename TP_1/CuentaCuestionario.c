#include <stdio.h>
typedef struct{
    struct h{            /* 20 bytes   */
      float i;             /* 4 bytes    */
      double j;        /*  8 bytes   */
      char k[8];       /*  8 bytes  */
    }l;
  
    long long b;         /* 8 bytes */
    unsigned short a; /* 2 bytes */
  
    union c{                 /* 2 bytes  */
      char d;                 /* 1 byte   */ 
      char e[2];             /* 2 bytes  */
      char f;                  /* 1 byte   */
    }g;
  
  }cuestionario_a_t;
  int main(){
    printf("%lu", sizeof(cuestionario_a_t));  // usar %lu con sizeof
    return 0;

  }
  