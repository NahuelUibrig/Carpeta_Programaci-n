#include "header.h"

int main(void)
{
  int distanciaTotal=0;
  int distanciaTotal1=0;
  int distanciaTotal2=0;
  /* Use esta linea para probar sus funciones!/* 
  
   * La misma genera la siguiente lista:
   * A <- 6 -> b <- 12 -> 3 <- 1 -> # <- 19 ->   <- 7 -> z <- 9 -> 0 <- 2 -> % <- 19 ->
   * x <- 20 -> ! <- 30 -> A -> ...
   * La vuelta es de 125
   */
  //dnode_t *first = CATEDRA_crear_lista_corta();
/* 
  Use esta linea para resolver el cuestionario! */
   dnode_t *first = CATEDRA_crear_lista_POSTA();
  dnode_t* end;
  end->name='c';
  sumarDistancias(first,distanciaTotal);
  distanciaCorta(first,end,distanciaTotal1,distanciaTotal2);
}
