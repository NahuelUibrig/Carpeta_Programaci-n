/* Declaracion de autoria
 * Fecha :
 * Autor :
 */

#include "definiciones.h"
#include <stdio.h>
/* Utilice este archivo para escribir sus funciones */

/*========== Ejercicio 1 ==========*/
void imprimirLista(int* lista, int longitud){
    int i=0;
    for(i=0;i<longitud;i++){
        printf("%d ",lista[i]);
    }
}
void sumarMultiplos(int* lista, int longitud){
    int i=0,numero=0,suma=0;
    numero=lista[longitud-1];
    for(i=0;i<longitud;i++){
        if(lista[i]%numero==0){
            suma=suma+lista[i];
        }
    }
    printf("La suma de multiplos da: %d \n\n",suma);
}
void cambiarLista(int* lista, int longitud){
    int i=0,numero=0,mascara=0b00010000;
    numero=lista[longitud-1];
    for(i=0;i<longitud;i++){
        if(lista[i]%numero!=0){
            lista[i]=lista[i]|mascara;
        }
    }
}
/*========== Ejercicio 2 ==========*/

/*========== Ejercicio 3 ==========*/


