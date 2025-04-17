#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
int MaxMinProm(int*array,int largo,int*max,int*min,int*prom);
int main() {
    int max,min;
    float prom;
    int largo=sizeof(lista)/sizeof(lista[0]);
    printf("Calculando Max, Min y Promedio de LISTA");
    printf("\n\n");
    MaxMinProm(lista,largo,&max,&min,&prom);
    printf("Despues del intercambio:   \n x=%d, y=%d",x,y);
    printf("\n\n");
    return 0;
}
int MaxMinProm(int*array,int largo,int*max,int*min,int*prom){
    int suma=0;
    *max=array[0];
    *min=array[0];
    for(int i=0;i<largo;i++){
        suma+=array[i];
        if(array[i]<*max){
            *max=array[i];
        }
        if(array[i]<*min){
            *min=array[i];
        }
    }
    *prom =(float)suma/largo;

}